# Controlling-devices-from-HTTP

-> Light + TV <br>
**Hardware components:** <br>
ESP8266, 1838T Infrared Receiver, Infrared Sender(infrared emitting diode,IR333C-A), any NPN transistor 

Check out this website for circuit wiring details: https://www.instructables.com/id/Universal-Remote-Using-ESP8266Wifi-Controlled/

This project can interface with Amazon Alexa (and iOS using IP address) via https://tehpsyc.pythonanywhere.com/ 
Note: Port forward your router and change the internal IP address to external IP address on IR Controller Device Setup 

Example: 
Internal IP: http://10.0.0.107/5/on
Change it to external IP + Port 80: http://25.68.180.15:80/5/on 
  
**Controling a servo motor with ESP8266:** https://www.microcontroller-project.com/servo-motor-with-nodemcu-web-control.html <br>
HTML converter: https://amzdatastudio.com/user/html-converter

Datatsheet for 1838T IR: http://wiki.epalsite.com/index.php?title=1838T_Infrared_Receiver
