
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <ArtnetnodeWifi.h>
#include <Servo.h>

Servo myservo8;  // create servo object to control a servo
Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo
Servo myservo3;  // create servo object to control a servo
Servo myservo4;  // create servo object to control a servo
Servo myservo5;  // create servo object to control a servo
Servo myservo6;  // create servo object to control a servo
Servo myservo7;  // create servo object to control a servo

int val;  

const char* ssid = "house3";
const char* password = "6301266370";

WiFiUDP UdpSend;
ArtnetnodeWifi artnetnode;


boolean ConnectWifi(void)
{
  boolean state = true;
  int i = 0;

  WiFi.begin(ssid, password);
  Serial.println("");
 // Serial.println("Connecting to WiFi");

 // Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
 //   Serial.print(".");
    if (i > 20){
      state = false;
      break;
    }
    i++;
  }
  if (state) {
  //  Serial.println("");
  //  Serial.print("Connected to ");
  //  Serial.println(ssid);
  //  Serial.print("IP address: ");
  //  Serial.println(WiFi.localIP());
  } else {
  //  Serial.println("");
  //  Serial.println("Connection failed.");
  }
  
  return state;
}

void onDmxFrame(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t* data)
{
  boolean tail = false;
  
 // Serial.print("DMX: Univ: ");
 // Serial.print(universe, DEC);
//  Serial.print(", Seq: ");
//  Serial.print(sequence, DEC);
//  Serial.print(", Data (");
//  Serial.print(length, DEC);
//  Serial.print("): ");
  
 // if (length > 8) {
 //   length = 8;
  //  tail = true;
 // }
  // send out the buffer
 
  
  if (universe ==0){
  
  
  //  Serial.print(data[0]);
    val = map((data[0]), 0, 254, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
    myservo1.write(val); 
    Serial.print(val);
    Serial.print(" ");

  //  Serial.print(data[1]);
    val = map((data[1]), 0, 254, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
    myservo2.write(val);  
     Serial.print(val);
    Serial.print(" ");
  

  //  Serial.print(data[2]);
    val = map((data[2]), 0, 254, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
 myservo3.write(val);  
 Serial.print(val);
    Serial.println(" ");

 //    Serial.print(data[3]);
    val = map((data[3]), 0, 254, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
    
    myservo4.write(val);  
    Serial.print(val);
    Serial.print(" ");
  
  //Serial.print(data[4]);
    val = map((data[4]), 0, 254, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
    myservo5.write(val);  
    Serial.print(val);
    Serial.print(" ");

 // Serial.print(data[5]);
    val = map((data[5]), 0, 254, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
    myservo6.write(val);  
     Serial.print(val);
    Serial.println(" ");

//  Serial.print(data[6]);
    val = map((data[6]), 0, 254, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
    myservo7.write(val);  
    Serial.print(val);
    Serial.print(" ");

//  Serial.print(data[7]);
    val = map((data[7]), 0, 254, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
    myservo8.write(val);  
    Serial.print(val);
    Serial.println(" ");



  Serial.println();

  }
}













void setup()
{ myservo1.attach(D2);  
  myservo2.attach(D3);  
  myservo3.attach(D4);  
  myservo4.attach(D5); 
  myservo5.attach(D6);  
  myservo6.attach(D7); 
  myservo4.attach(D8);  
  myservo8.attach(D9); 
  // set-up serial for debug output
  Serial.begin(115200);
  ConnectWifi();
  // max. 17 characters
  artnetnode.setShortName("ESP-Art-Net Servo");
  // max. 63 characters
  artnetnode.setLongName("ESP8266 - Art-Net a 8 servos JOSEMI ");
  // set a starting universe if you wish, defaults to 0
  //artnetnode.setStartingUniverse(4);
  artnetnode.setNumPorts(4);
  artnetnode.enableDMXOutput(0);
  artnetnode.enableDMXOutput(1);
  artnetnode.enableDMXOutput(2);
  artnetnode.enableDMXOutput(3);
  artnetnode.begin();

  // this will be called for each packet received
  artnetnode.setArtDmxCallback(onDmxFrame);
}

void loop()
{
  // we call the read function inside the loop
  artnetnode.read();
}
