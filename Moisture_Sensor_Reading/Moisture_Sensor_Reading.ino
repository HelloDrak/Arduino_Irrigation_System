const int SENSOR_HIGH = 560;
const int SENSOR_LOW = 0;

const int moistureSensor1 = A0;
const int moistureSensor2 = A1;
const int moistureSensor3 = A2;

const int relay1_Digital = 7;
const int relay2_Digital = 6;
const int relay3_Digital = 5;

int sensorValue1 = 1000;
int sensorValue2 = 1000;
int sensorValue3 = 1000;

const int PUMP_ON = HIGH;
const int PUMP_OFF = LOW;

void setup()
{

 Serial.begin(9600);
 
 pinMode(relay1_Digital, OUTPUT);
 pinMode(relay2_Digital, OUTPUT);
 pinMode(relay3_Digital, OUTPUT);

}

void loop()
{
  // read the value from the sensor
  sensorValue1 = analogRead(moistureSensor1);
  sensorValue2 = analogRead(moistureSensor2);
  sensorValue3 = analogRead(moistureSensor3);

  Serial.print("Sensor 1: ");
  Serial.print(sensorValue1);
  Serial.print("\t");
  Serial.print("Sensor 2: ");
  Serial.print(sensorValue2);
  Serial.print("\t");
  Serial.print("Sensor 3: ");
  Serial.print(sensorValue3);
  Serial.print("\t");
   Serial.print ("\n");
  
  plantsNeedWater(sensorValue1, sensorValue2, sensorValue3);

}

void plantsNeedWater(int P1, int P2, int P3)
{
  
  letsPump(P1, "Plant 1", relay1_Digital);
  letsPump(P2, "Plant 2", relay2_Digital);
  letsPump(P3, "Plant 3", relay3_Digital);
  
}

void letsPump(int sensorValue, String plantName, int pumpRelay)
{
    if (sensorValue > SENSOR_HIGH)
  {
    Serial.print ("Turning on pump for ... ");
    Serial.print(plantName);
    Serial.print ("\n");
    digitalWrite(pumpRelay, PUMP_ON);
    delay(8000);
    digitalWrite(pumpRelay, PUMP_OFF);
  }else{
//    Serial.print(plantName);
//    Serial.print (" is Hydrated!");
//    Serial.print ("\n");
    digitalWrite(pumpRelay, PUMP_OFF);
    delay(1000);

  }
}
