#include<WiFi.h> 
#include<HTTPClient.h>  

const char *ssid =  "galaxy";     // Enter your WiFi Name
const char *pass =  "qj9bn71j"; // Enter your WiFi Password#define VoltageSensor 36
#define CurrentSensor 34
#define VoltageSensor 36
WiFiClient client;
double Vout = 0;
double Current = 0;
int adc_value = 0;
float adc_voltage = 0.0;
float input_voltage = 0.0;
void setup() 
{
  Serial.begin(9600);
  Serial.println("V & I Parameters of Photovoltaic Panel");
}
void loop() 
{
    Serial.println("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");              // print ... till not connected
  }
  Serial.println("");
  Serial.println("WiFi connected");
  for(int i = 0; i < 1000; i++)
  {
    Vout = (Vout + ((5.0 * analogRead(CurrentSensor))/1024.0));   
    delay(1);
  }

Vout = Vout /1000;
Current = (Vout - 2.5)/ 0.1;                   
                          
  Serial.print("I1 = ");                  
  Serial.print(Current,2);
  Serial.println(" Amps");                             

  adc_value = analogRead(VoltageSensor);
  adc_voltage = adc_value * (5.0/1024.0);
  input_voltage = adc_voltage / 0.2;
  Serial.print("V1 = ");
  Serial.println(input_voltage, 2);
  delay(500);

  if (WiFi.status() == WL_CONNECTED) {  //Check WiFi connection status
    HTTPClient http;                    //Declare an object of class HTTPClient
      
    String url = "https://pv-performance.000webhostapp.com/api.php?voltage="+String(input_voltage) + "&current="+String(Current);
    Serial.println(url);
    http.begin(client, url);          //Specify request destination
    int httpCode = http.GET();            //Send the request
    if (httpCode > 0) {                   //Check the returning code
      String payload = http.getString();  //Get the request response payload
      Serial.println(payload);            //Print the response payload
    }
    http.end();  //Close connection
  }
}
