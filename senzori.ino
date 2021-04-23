#include "CO2Sensor.h"

CO2Sensor co2Sensor(A0, 0.99, 100);

const int sensor_pin = A1;
#include "DHT.h"

#define DHTPIN 2     

#define DHTTYPE DHT11   

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("=== Initialized ===");
  co2Sensor.calibrate();

   Serial.println(F("DHTxx test!"));
   dht.begin();
}

void loop() {
  int val = co2Sensor.read();
  Serial.print("CO2 value: ");
  Serial.println(val);

  float moisture_percentage;
  int sensor_analog;
  sensor_analog = analogRead(sensor_pin);
  Serial.print("Moisture Percentage = ");
  Serial.print(moisture_percentage);
  Serial.print("%\n\n");

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  
  }

  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F(" Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("C "));
 

  delay(1000);
}
