/*****************************************************
 * Date: 13 july 2018
 * Written by: Usman Ali Butt
 * Modified by Anni Yang 11/29/2019
 * Property off: www.microcontroller-project.com
 * ***************************************************/
 
#include <ESP8266WiFi.h>
#include <Servo.h>
Servo servo;
 
const char* ssid = "?";
const char* password = "?";  

WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(10);
  servo.attach(2); //Gpio-2 of nodemcu with pwm pin of servo motor
  servo.write(1500);//initiate servo
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

if (request.indexOf("/Req=open") != -1)  {

  openblinds();
  
}
if (request.indexOf("/Req=close") != -1)  {  
  
  closeblinds();
  
}

  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<h1 align=center>Servo motor control over WiFi</h1><br><br>");
  client.println("<br><br>");
  client.println("<a href=\"/Req=open\"\"><button>open</button></a>");
  client.println("<a href=\"/Req=close\"\"><button>close</button></a>");

  client.println("</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}

void openblinds()
{
  servo.writeMicroseconds(1300);  // Update the servo based on servoState (1300 = right)
  delay(10000); //10000 = 10 seconds.  Change this value to change the number of revolutions 
  servo.writeMicroseconds(1500); // Stop servo
}

void closeblinds()
{
  servo.writeMicroseconds(1700);  // Update the servo based on servoState (1700 = left)
  delay(10000);
  servo.writeMicroseconds(1500);  // Stop servo
}
