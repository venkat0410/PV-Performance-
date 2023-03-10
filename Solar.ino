#include <Wire.h>
// Define voltage sensor analog input
#define SIGNAL_PIN A1
float adc_voltage = 0.0;
float in_voltage;
//voltage divider bias
float R1 = 30000.0;
float R2 = 7500.0;
//reference voltage of arduino or esp
float ref_voltage = 5;
int adc_value = 0;
//ACS712 current sensor
const int sensorIn = A5;      // pin where the OUT pin from sensor is connected on Arduino
int mVperAmp = 185;           // this the 5A version of the ACS712 -use 100 for 20A Module and 66 for 30A Module
int Watt = 0;
double Voltage = 0;
double VRMS = 0;
double AmpsRMS = 0;
void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);
  }
void loop() {
  //voltage sensor
  adc_value = analogRead(SIGNAL_PIN);
  adc_voltage  = (adc_value * ref_voltage) / 1023.0;
  in_voltage = adc_voltage / (R2 / (R1 + R2)) ;
  Serial.print("Input Voltage = ");
  Serial.print(in_voltage, 2);
  Serial.print(" V |");

  //acs712
  Voltage = getVPP();
  VRMS = (Voltage / 2.0) * 0.707; //root 2 is 0.707
  AmpsRMS = ((VRMS * 1000) / mVperAmp) - 0.3;
  Serial.print("Current = ");
  Serial.print(AmpsRMS, 2);
  Serial.print(" A |");

}

float getVPP()
{
  float result;
  int readValue;                // value read from the sensor
  int maxValue = 0;             // store max value here
  int minValue = 1023;          // store min value here ESP8266 ADC resolution

  uint32_t start_time = millis();
  while ((millis() - start_time) < 1000) //sample for 1 Sec
  {
    readValue = analogRead(sensorIn);
    // see if you have a new maxValue
    if (readValue > maxValue)
    {
      /*record the maximum sensor value*/
      maxValue = readValue;
    }
    if (readValue < minValue)
    {
      /*record the minimum sensor value*/
      minValue = readValue;
    }
  }

  // Subtract min from max
  result = ((maxValue - minValue) * 3.3) / 1023.0; //ESP8266 ADC resolution 1023

  return result;
}
