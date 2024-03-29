#include <Arduino.h>
#include <Wire.h>

#define ECHO_PIN 33
#define TRIG_PIN 32

long duration, distance;

void setup()
{
	Serial.begin(9600);
	pinMode(TRIG_PIN, OUTPUT);
	pinMode(ECHO_PIN, INPUT);
}

void loop()
{
	digitalWrite(TRIG_PIN, LOW);
	delayMicroseconds(2);
	digitalWrite(TRIG_PIN, HIGH);
	delayMicroseconds(10);
	digitalWrite(TRIG_PIN, LOW);

	duration = pulseIn(ECHO_PIN, HIGH);
	distance = duration / 58.2;
	Serial.println("Distance: " + String(distance));
	delay(1000);
}
