
#define CurrentSensor A0
double Vout = 0;
double Current = 0;

void setup()
{ 
  Serial.begin(9600);
}
 
void loop()
{
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
  delay(1000); 
}
