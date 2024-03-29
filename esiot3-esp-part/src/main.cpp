#include <Arduino.h>
#include <Wire.h>
#include <WiFi.h>

#define ECHO_PIN 33
#define TRIG_PIN 32
#define GREEN_LED 18
#define RED_LED 19

long duration, distance;

const char *ssid = "ASUS";
const char *psw = "lucia1999";

void sonar_monitor();
void setup_wifi();
void check_network();

void setup()
{
	Serial.begin(9600);
	pinMode(TRIG_PIN, OUTPUT);
	pinMode(ECHO_PIN, INPUT);
	pinMode(GREEN_LED, OUTPUT);
	pinMode(RED_LED, OUTPUT);
	digitalWrite(RED_LED, HIGH);
	setup_wifi();
}

void loop()
{
	check_network();
	sonar_monitor();
}

void sonar_monitor()
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
	}
	Serial.println("WiFi connected");
	digitalWrite(GREEN_LED, HIGH);
}

void check_network()
{
	if (WiFi.status() == WL_CONNECTED)
	{
		digitalWrite(RED_LED, LOW);
		digitalWrite(GREEN_LED, HIGH);
	}
	else
	{
		digitalWrite(GREEN_LED, LOW);
		digitalWrite(RED_LED, HIGH);
	}
}