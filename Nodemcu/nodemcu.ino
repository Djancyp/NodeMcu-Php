#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <ArduinoJson.h>

int temp_sensor = 4;
int pin         = 5;
float temperature = 0;

OneWire oneWirePin(temp_sensor);
DallasTemperature sensors(&oneWirePin);

void setup() {
  pinMode(pin, OUTPUT);
  Serial.begin(115200); //Serial connection
  sensors.begin();
  
  WiFi.begin("BTHub4-GH5G", "da5692dec5");   //WiFi connection

  while (WiFi.status() != WL_CONNECTED) {  //Wait for the WiFI connection completion

    delay(500);
    Serial.println("Waiting for connection");

  }

}

void loop() {

 if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status
   sensors.requestTemperatures(); 
   int temperature = sensors.getTempCByIndex(0);
   HTTPClient http;    //Declare object of class HTTPClient

   http.begin("http://192.168.1.155/esp8266/light.json");      //Specify request destination
   http.addHeader("Content-Type", "application/x-www-form-urlencoded");  //Specify content-type header
   String sBody = "temp=" + String(temperature);
   //Serial.println(sBody);
   int httpCode = http.POST(sBody);   //Send the request
   String payload = http.getString();                  //Get the response payload

   //Serial.println(httpCode);   //Print HTTP return code
   Serial.println(payload);    //Print request response payload

      String result = payload;
   // Parse JSON
      int size = result.length() + 1;
      char json[size];
      result.toCharArray(json, size);
      StaticJsonBuffer<200> jsonBuffer;
      JsonObject& json_parsed = jsonBuffer.parseObject(json);
      if (!json_parsed.success())
      {
        Serial.println("parseObject() failed");
        return;
      }

      // Make the decision to turn off or on the LED
      if (strcmp(json_parsed["light"], "on") == 0) {
        digitalWrite(pin, HIGH); 
        Serial.println("LED ON");
      }
      else {
        digitalWrite(pin, LOW);
        Serial.println("LED OFF");
      }

   http.end();  //Close connection

 }
 if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status
   sensors.requestTemperatures(); 
   int temperature = sensors.getTempCByIndex(0);
   HTTPClient http;    //Declare object of class HTTPClient
   http.begin("http://192.168.1.155/esp8266/data.php");      //Specify request destination
   http.addHeader("Content-Type", "application/x-www-form-urlencoded");  //Specify content-type header
   String sBody = "temp=" + String(temperature);
   //Serial.println(sBody);
   int httpCode = http.POST(sBody);   //Send the request
   String payload = http.getString();                  //Get the response payload

   Serial.println(httpCode);   //Print HTTP return code
   Serial.println(payload);    //Print request response payload

   http.end();  //Close connection
 

 }else{

    Serial.println("Error in WiFi connection");   

 }

  delay(3000);  //Send a request every 30 seconds
}
