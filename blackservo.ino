#include <ESP8266WiFi.h>
#include <Servo.h>
Servo servo;
Servo servo1;
 
const char* ssid = "190WhiteStreet";
const char* password = "whitestreethouse190";
//char* shutterFlag = "ShutterOpened";
//char* blindsFlag = "BlindsClosed";  

WiFiServer server(80);
 
void setup() {
  //delay(10);
  Serial.begin(115200);
  delay(10);
  //servo.attach(2); //Gpio-2 of nodemcu with pwm pin of servo motor
  servo1.attach(2);
  //servo.write(90);//initiate servo
  servo1.writeMicroseconds(1500);
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address on serial monitor
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");    //URL IP to be typed in mobile/desktop browser
  Serial.print(WiFi.localIP());
  Serial.println("/");
 
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

//if (request.indexOf("/Req=openShutter") != -1)  {

//  openShutter();
  
//}
//if (request.indexOf("/Req=closeShutter") != -1)  {  
  
//  closeShutter();
  
//}
if (request.indexOf("/Req=openBlinds") != -1)  {

  openBlinds();
  
}
if (request.indexOf("/Req=closeBlinds") != -1)  {  
  
  closeBlinds();
  
}

  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<h1 align=center>Servo motor control over WiFi</h1><br><br>");
  //client.print("Current position  = ");
  //client.print(value); 
  client.println("<br><br>");
  //client.println("<a href=\"/Req=openShutter\"\"><button>ShutterON</button></a>");
  //client.println("<a href=\"/Req=closeShutter\"\"><button>ShutterOFF</button></a><br/>");
  client.println("<a href=\"/Req=openBlinds\"\"><button>BlindsON</button></a>");
  client.println("<a href=\"/Req=closeBlinds\"\"><button>BlindsOFF</button></a><br/>");

  client.println("</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}

void openShutter()
{
//  servo.writeMicroseconds(1300);  // Update the servo based on servoState (1300 = right)
//  delay(10000);
//  servo.writeMicroseconds(1500); // Stop servo
//    if ((shutterFlag == "ShutterClosed") && (blindsFlag == "BlindsClosed")){
      //servo.write(0);
      //delay(5000);
      //servo.write(90);
//      shutterFlag = "ShutterOpened";
//    }

}

void closeShutter()
{
//  servo.writeMicroseconds(1700);  // Update the servo based on servoState (1700 = left)
//  delay(10000);
//  servo.writeMicroseconds(1500);  // Stop servo
//    if ((shutterFlag == "ShutterOpened") && (blindsFlag == "BlindsClosed")){
      //servo.write(180);
      //delay(5000);
      //servo.write(90);
//      shutterFlag = "ShutterClosed";
//    }

}

void openBlinds()
{
//  servo.writeMicroseconds(1300);  // Update the servo based on servoState (1300 = right)
//  delay(10000);
//  servo.writeMicroseconds(1500); // Stop servo
    
//    if (shutterFlag == "ShutterOpened"){
      servo1.write(1300);
      delay(5000);      
      servo1.write(1500);
//      blindsFlag = "BlindsOpened";
//    }
//    else if (shutterFlag == "ShutterClosed"){
//      openShutter();
//      servo1.write(1700);
//      delay(5000);
//      servo1.write(1500);
//      blindsFlag = "BlindsOpened";
//    }
//    



}

void closeBlinds()
{
//  servo.writeMicroseconds(1700);  // Update the servo based on servoState (1700 = left)
//  delay(10000);
//  servo.writeMicroseconds(1500);  // Stop servo
    
//    if (blindsFlag == "BlindsOpened"){
      servo1.write(1700);
      delay(5000);
      servo1.write(1500);
//      blindsFlag = "BlindsClosed";
//    }
//    

}
