#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2   // DS18B20 DATA pin

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures();
  delay(750);   // DS18B20 conversion time

  float tempC = sensors.getTempCByIndex(0);

  // Print ONLY temperature in JSON format
  Serial.print("{\"temperature\":");
  Serial.print(tempC, 1);   // 1 decimal place
  Serial.println("}");

  delay(2000);
}
