#define ENERGIA_PLATFORM 0

#include <aJSON.h>
#include <WiFi.h>
#include <Wire.h>
#include <BMA222.h>
#include "SPI.h"
#include "Adafruit_TMP006.h"

#include "M2XStreamClient.h"

char ssid[] = "UCF_DEMO"; //  your network SSID (name)
char pass[] = "UCF_UCF_IOT";    // your network password (use for WPA, or use as key for WEP)
//int keyIndex = 0;            // your network key Index number (needed only for WEP)

int status = WL_IDLE_STATUS;

char deviceId[] = "8d4011b4b7b1acea472e7489b3b163e3"; // Device you want to push to
char streamName_t[] = "temperature"; // Stream you want to push temperature to
char streamName_z[] = "acceleration_z"; // Stream you want to push accleration_z to
char m2xKey[] = "31b158f2c5a9779e6b149bc076a75c48"; // Your M2X access key

BMA222 mySensor;

Adafruit_TMP006 tmp006(0x41);  // start with a diferent i2c address!

WiFiClient client;

M2XStreamClient m2xClient(&client, m2xKey);

void setup() {

  Serial.begin(9600);

  // you can also use tmp006.begin(TMP006_CFG_1SAMPLE) or 2SAMPLE/4SAMPLE/8SAMPLE to have
  // lower precision, higher rate sampling. default is TMP006_CFG_16SAMPLE which takes
  // 4 seconds per reading (16 samples)
  if (! tmp006.begin()) {
    Serial.println("No sensor found");
    while (1);
  }
  
  mySensor.begin();
  uint8_t chipID = mySensor.chipID();
  Serial.print("chipID: ");
  Serial.println(chipID);

  delay(10);
  
  // attempt to connect to Wifi network:
  Serial.print("Attempting to connect to Network named: ");
  // print the network name (SSID);
  Serial.println(ssid); 
  // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
  WiFi.begin(ssid, pass);
  while ( WiFi.status() != WL_CONNECTED) {
    // print dots while we wait to connect
    Serial.print(".");
    delay(300);
  }
  
  Serial.println("\nYou're connected to the network");
  Serial.println("Waiting for an ip address");
  
  while (WiFi.localIP() == INADDR_NONE) {
    // print dots while we wait for an ip addresss
    Serial.print(".");
    delay(300);
  }

  Serial.println("\nIP Address obtained");
  
  // you're connected now, so print out the status  
  printWifiStatus();
  
}

void loop() {

  //tmp006.wake();
  //tmp006.sleep();
      
  float x = mySensor.readXData()/65.0;
  Serial.print("Accel X: ");
  Serial.print(x);

  float y = mySensor.readYData()/65.0;
  Serial.print(", Y: ");
  Serial.print(y);

  float  z = mySensor.readZData()/65.0;
  Serial.print(", Z: ");
  Serial.println(z);

  float objt = tmp006.readObjTempC();
  Serial.print("Object Temperature: "); Serial.print(objt); Serial.println("*C");
  float diet = tmp006.readDieTempC();
  Serial.print("Die Temperature: "); Serial.print(diet); Serial.println("*C");

  int response = m2xClient.updateStreamValue(deviceId, streamName_t, objt);
  Serial.print("M2x client response code: ");
  Serial.println(response);

  if (response == -1)
    while (1)
    ;

  response = m2xClient.updateStreamValue(deviceId, streamName_z, z);
  Serial.print("M2x client response code: ");
  Serial.println(response);

  if (response == -1)
    while (1)
    ;

  delay(5000);
}

void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}
