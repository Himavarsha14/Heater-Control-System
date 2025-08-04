#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2       // DS18B20 data pin
#define HEATER_LED_PIN 6     // Yellow LED for HEATING
#define OVERHEAT_LED_PIN 7   // Red LED for OVERHEAT

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

enum State {
  IDLE,
  HEATING,
  STABILIZING,
  TARGET_REACHED,
  OVERHEAT
};

State currentState = IDLE;

void setup() {
  Serial.begin(9600);
  sensors.begin();
  pinMode(HEATER_LED_PIN, OUTPUT);
  pinMode(OVERHEAT_LED_PIN, OUTPUT);
}

void loop() {
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);

  // Determine system state
  if (tempC < 30) {
    currentState = IDLE;
  } else if (tempC >= 30 && tempC < 34) {
    currentState = HEATING;
  } else if (tempC >= 34 && tempC < 36) {
    currentState = STABILIZING;
  } else if (tempC >= 36 && tempC <= 45) {
    currentState = TARGET_REACHED;
  } else {
    currentState = OVERHEAT;
  }

  // Perform actions based on state
  switch (currentState) {
    case IDLE:
      digitalWrite(HEATER_LED_PIN, LOW);
      digitalWrite(OVERHEAT_LED_PIN, LOW);
      Serial.println("State: IDLE");
      break;
    case HEATING:
      digitalWrite(HEATER_LED_PIN, HIGH);
      digitalWrite(OVERHEAT_LED_PIN, LOW);
      Serial.println("State: HEATING");
      break;
    case STABILIZING:
      digitalWrite(HEATER_LED_PIN, LOW);
      digitalWrite(OVERHEAT_LED_PIN, LOW);
      Serial.println("State: STABILIZING");
      break;
    case TARGET_REACHED:
      digitalWrite(HEATER_LED_PIN, LOW);
      digitalWrite(OVERHEAT_LED_PIN, LOW);
      Serial.println("State: TARGET REACHED");
      break;
    case OVERHEAT:
      digitalWrite(HEATER_LED_PIN, LOW);
      digitalWrite(OVERHEAT_LED_PIN, HIGH);
      Serial.println("State: OVERHEAT! System shutting down.");
      break;
  }

  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.println(" °C");

  delay(1000);
}
