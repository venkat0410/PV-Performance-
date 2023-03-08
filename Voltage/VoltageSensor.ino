
#define VoltageSensor A0

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
  adc_value = analogRead(VoltageSensor);

  adc_voltage = adc_value * (5.0/1024.0);

  input_voltage = adc_voltage / 0.2;
  Serial.print("V1 = ");
  Serial.println(input_voltage, 2);

  delay(500);

  

}
