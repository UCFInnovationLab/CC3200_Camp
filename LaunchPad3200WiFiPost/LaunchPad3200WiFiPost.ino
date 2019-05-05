#define ENERGIA_PLATFORM 0

#include <aJSON.h>
#include <WiFi.h>
#include <Wire.h>
#include <BMA222.h>
#include "Adafruit_TMP006.h"

#include "M2XStreamClient.h"

char ssid[] = "dd-wrt"; //  your network SSID (name)
char pass[] = "BlackRabbit94";    // your network password (use for WPA, or use as key for WEP)
//int keyIndex = 0;            // your network key Index number (needed only for WEP)

int status = WL_IDLE_STATUS;

char streamName_t[] = "Name1_t"; // Stream you want to push temperature to
char streamName_a[] = "Name1_a"; // Stream you want to push accleration_z to

char deviceId_t[] = "8d4011b4b7b1acea472e7489b3b163e3"; // Device you want to push to
char deviceId_a[] = "20aed9816b16a127adf6db0bee9e4749"; // Device you want to push to

//char m2xKey[] = "31b158f2c5a9779e6b149bc076a75c48"; // Your M2X access key
char m2xKey[] = "242302ebabc7ead432d3fdac5d0e0ce7"; // Your M2X access key

  char fromTime[] = "2018-01-01T01:01:01.001Z"; // yyyy-mm-ddTHH:MM:SS.SSSZ
  char endTime[] = "2020-05-20T01:01:01.001Z"; // yyyy-mm-ddTHH:MM:SS.SSSZ

BMA222 mySensor;

Adafruit_TMP006 tmp006(0x41);  // start with a diferent i2c address!

WiFiClient client;

M2XStreamClient m2xClient(&client, m2xKey);

const int buttonPin = PUSH1;     // the number of the pushbutton pin
int buttonState = 0;             // variable for reading the pushbutton status

void setup() {

  // initialize the digital pin as an output.
  pinMode(RED_LED, OUTPUT); 

  digitalWrite(RED_LED, LOW);
  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);  
  
  Serial.begin(115200);

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
    //digitalWrite(YELLOW_LED, LOW);
  }

  //digitalWrite(YELLOW_LED, HIGH);
  //digitalWrite(GREEN_LED, LOW);
  
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

  digitalWrite(RED_LED, HIGH);

// read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {     
    delete_readings();  
  } 

  float  z = mySensor.readZData()/65.0;
  Serial.print("Accel Z: ");
  Serial.println(z);

  // Get the highest acceleration for this loop
  float hi_a=-1000;
  for (int i=0;i<10000;i++) {
    float  z = mySensor.readZData()/65.0;
    if (z>hi_a) hi_a=z;
  }

  digitalWrite(RED_LED, LOW);    // turn the LED off by making the voltage LOW
  
  float objt = tmp006.readObjTempC();
  if (objt > 50.0) objt = 50.0;
  if (objt < 0.0) objt = 0.0;
  Serial.print("Object Temperature: "); Serial.print(objt); Serial.println("*C");

  
  int response = m2xClient.updateStreamValue(deviceId_t, streamName_t, objt);
  Serial.print("M2x client response code: ");
  Serial.println(response);

  if (response == -1)
    while (1)
    ;

  response = m2xClient.updateStreamValue(deviceId_a, streamName_a, hi_a);
  Serial.print("M2x client response code: ");
  Serial.println(response);

  if (response == -1)
    while (1)
    ;

  //delay(5000);
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

void delete_readings() {


  Serial.println("Deleting temperature values from Server");
  // Delete values
  int response = m2xClient.deleteValues(deviceId_t, 
                                        streamName_t,
                                        fromTime,
                                        endTime);
  Serial.print("Response Code: ");
  Serial.println(response);

    Serial.println("Deleting Acceleration values from Server");
  // Delete values
  response = m2xClient.deleteValues(deviceId_a, 
                                        streamName_a,
                                        fromTime,
                                        endTime);
  Serial.print("Response Code: ");
  Serial.println(response);
  
}

void xloop() {
  tmp006.wake();
  tmp006.sleep();
      
  float x = mySensor.readXData()/65.0;
  Serial.print("Accel X: ");
  Serial.print(x);

  float y = mySensor.readYData()/65.0;
  Serial.print(", Y: ");
  Serial.print(y);

  float diet = tmp006.readDieTempC();
  Serial.print("Die Temperature: "); Serial.print(diet); Serial.println("*C");
}
