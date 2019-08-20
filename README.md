# Controlling-devices-from-HTTP

Hardware components: ESP826, 1838T Infrared Receiver, Infrared Sender(infrared emitting diode,IR333C-A), any NPN transistor 

Check this website for circuit wiring details: https://www.instructables.com/id/Universal-Remote-Using-ESP8266Wifi-Controlled/

This project can interface with Alexa (and iOS using IP address) via https://tehpsyc.pythonanywhere.com/ 
Note: Port forward your router and change the internal IP address to external IP address on IR Controller Device Setup 

Example: 
Internal IP: http://10.0.0.107/5/on
Change it to external IP + Port 80: http://25.68.180.15:80/5/on 
  
