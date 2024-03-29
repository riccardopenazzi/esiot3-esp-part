#include <Arduino.h>
#include <Wire.h>
#include <WiFi.h>

#define ECHO_PIN 33
#define TRIG_PIN 32

long duration, distance;

const char *ssid = "ASUS";
const char *psw = "lucia1999";

void setup_wifi();

void setup()
{
	Serial.begin(9600);
	pinMode(TRIG_PIN, OUTPUT);
	pinMode(ECHO_PIN, INPUT);

	setup_wifi();
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

void setup_wifi()
{

	delay(10);

	Serial.println(String("Connecting to ") + ssid);

	WiFi.mode(WIFI_STA);
	WiFi.begin(ssid, psw);

	while (WiFi.status() != WL_CONNECTED)
	{
		delay(500);
		Serial.print(".");
	}

	Serial.println("");
	Serial.println("WiFi connected");
	Serial.println("IP address: ");
	Serial.println(WiFi.localIP());
}
