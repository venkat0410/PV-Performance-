#define VoltageSensor A1
#define CurrentSensor A5
int adc_value = 0;
float adc_voltage = 0.0;
float input_voltage = 0.0;
double Vout = 0;
double Current = 0;

void setup()
{ 
  Serial.begin(9600);
  Serial.println("V & I Parameters of Photovoltaic Panel");
}
 
void loop()
{
for(int i = 0; i < 1000; i++)
  {
    Vout = (Vout + ((5.0 * analogRead(CurrentSensor))/1024.0));   
    delay(1);
  }
adc_value = analogRead(VoltageSensor);
  adc_voltage = adc_value * (5.0/1024.0);
  input_voltage = adc_voltage / 0.2;
Vout = Vout /1000;
Current = (Vout - 2.5)/ 0.1;                   
  Serial.print("V1 = ");
  Serial.println(input_voltage, 2);                        
  Serial.print("I1 = ");                  
  Serial.print(Current,2);
  Serial.println(" Amps");                             
  delay(1000); 
}
