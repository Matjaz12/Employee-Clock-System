#include <WiFi.h>
#include <SPI.h> //include the SPI bus library
#include <MFRC522.h> //include the RFID reader library
#define SS_PIN 5
#define RST_PIN 22
#define LOOP_DELAY 1000
#define BAUD_RATE  115200

// Communication

const char* ssid = "enter_your_ssid";
const char* password =  "enter_your_password"; 
const uint16_t port = 8090;
const char * host = "enter_host_ip_addr";

void connectToWiFi()
{
  /*
    Function connects to the local network,
    using ssid and password of network
  */
  WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.println("...");
    }
  
    Serial.print("WiFi connected with IP: ");
    Serial.println(WiFi.localIP());
}

bool hasConnected(WiFiClient& client)
{
  /*
    Function checks if client has successfully connected to the host server
  */
  if (!client.connect(host, port)) 
      return false;
  return true;
}

void sendData(WiFiClient& client, String msg)
{
  /*
    Function sends the data to the host server
  */
  client.print(msg);
}

// System Input

byte readCard[4];
String MasterTag = "20C3935E";
String tagID = "";
MFRC522 mfrc522(SS_PIN, RST_PIN);


void intializeRFID()
{
  /*
  Function intilaizes objects for Radio-frequency identification
  */
  SPI.begin();
  mfrc522.PCD_Init();
}

bool isTagReadyToRead()
{
  /*
  Function check if tag is ready to read from
  */
  if ( ! mfrc522.PICC_IsNewCardPresent())  //If a new PICC placed to RFID reader continue
    return false;
  
  if ( ! mfrc522.PICC_ReadCardSerial())  //Since a PICC placed get Serial and continue
    return false;

  return true;
}

String getTagId()
{
  /*
  Function reads the block of data that holds Unique ID of the tag
  the MIFARE PICC in use, uses a 4byte Unique ID!
  the function adds the 4bytes of data to outID String object and returns it
  */
  String outID = "";

  for(uint8_t i{0} ; i < 4 ; i++)
  {
      outID.concat(String(mfrc522.uid.uidByte[i],HEX));
  }
  outID.toUpperCase();
  mfrc522.PICC_HaltA(); // Stop reading

  return outID;
}

char* convertToCharString(String message)
{
    unsigned int length = message.length();
    char output[length + 1];
    for(unsigned int i{0}; i < length; i++)
    {
      output[i] = message[i];
    }
    output[length + 1] = '\n';
    return output;
}

// Main Funcitonality

void setup()
{
  Serial.begin(BAUD_RATE);
  connectToWiFi();
  intializeRFID();
}

void loop()
{
    String data = ""; // reintilize data -> if system did not establish a connection with server, user has to scan the tag again!
    while(isTagReadyToRead())
    {
        data = getTagId();
    }
    if(data.length() > 0)
    {
        // if we succesfully read data try sending the data to the server
     
        //put data in correct form so server understands it
        String action = "CLOCKIN[";
        action = action + data + "]"; 
    
        WiFiClient client; // create a client
        if(hasConnected(client))
        { 
            Serial.println("Connection to host succesful");
            //delay(1000);
            //char* msg = convertToCharString(action);
            sendData(client,action);
        }
        else 
        {
            Serial.println("Connection to host failed");
        }
        client.stop(); // shot down client
    }
}
