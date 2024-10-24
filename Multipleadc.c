const int potPin1 = A0; // First potentiometer pin
const int potPin2 = A1; // Second potentiometer pin

int sensorValue1 = 0;
int sensorValue2 = 0;
float voltage1 = 0.0;
float voltage2 = 0.0;

void setup()
{
  Serial.begin(9600);
}

void displayBinary(int value, int numBits)
{
  for (int i = numBits - 1; i >= 0; i--) {
    int bit = (value >> i) & 1;
    Serial.print(bit);
  }
}

void loop()
{
  sensorValue1 = analogRead(potPin1);
  sensorValue2 = analogRead(potPin2);

  voltage1 = (sensorValue1 / 1023.0) * 5.0;
  voltage2 = (sensorValue2 / 1023.0) * 5.0;

  Serial.print("Potentiometer 1 Voltage: ");
  Serial.print(voltage1, 2);
  Serial.print("V | Sensor Value  ");
  Serial.print(sensorValue1);
  Serial.print(" (binary): ");
  displayBinary(sensorValue1, 10);
  Serial.print(" | Potentiometer 2 Voltage: ");
  Serial.print(voltage2, 2);
  Serial.print("V | Sensor Value  ");
  Serial.print(sensorValue2);
  Serial.print(" (binary): ");
  displayBinary(sensorValue2, 10);
  Serial.println();

  delay(5000);
}
