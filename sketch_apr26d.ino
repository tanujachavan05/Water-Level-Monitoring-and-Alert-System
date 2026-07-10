// Pins
int trigPin = 9;
int echoPin = 10;

int waterSensorPin = A0;

int buzzerPin = 8;

int redLED = 6;
int greenLED = 5;
int yellowLED = 4;

int buttonPin = 7;

// Variables
long duration;
int distance;
int waterValue;

bool buzzerMute = false;
bool lastButtonState = HIGH;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(buzzerPin, OUTPUT);

  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {

  // 🔘 Button → toggle buzzer mute
  bool currentState = digitalRead(buttonPin);

  if (lastButtonState == HIGH && currentState == LOW) {
    buzzerMute = !buzzerMute;
    delay(200);
  }
  lastButtonState = currentState;

  // 📡 Ultrasonic
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // 💧 Water Sensor
  waterValue = analogRead(waterSensorPin);
#include <SoftwareSerial.h>

// ---------------- GSM ----------------
SoftwareSerial sim800(10, 11);   // Arduino RX=10, TX=11

// ---------------- Pins ----------------
int trigPin = 9;
int echoPin = 12;      // Changed from 10 to avoid conflict

int waterSensorPin = A0;

int buzzerPin = 8;

int redLED = 6;
int greenLED = 5;
int yellowLED = 4;

int buttonPin = 7;

// ---------------- Variables ----------------
long duration;
int distance;
int waterValue;

bool buzzerMute = false;
bool lastButtonState = HIGH;
bool smsSent = false;

// ---------------- Setup ----------------
void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(buzzerPin, OUTPUT);

  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
  sim800.begin(9600);

  delay(3000);

  Serial.println("Smart Water Level Monitoring System");
}

// ---------------- Loop ----------------
void loop() {

  // Button → Toggle buzzer
  bool currentState = digitalRead(buttonPin);

  if (lastButtonState == HIGH && currentState == LOW) {
    buzzerMute = !buzzerMute;
    delay(200);
  }

  lastButtonState = currentState;

  // Ultrasonic
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  // Water Sensor
  waterValue = analogRead(waterSensorPin);

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm | Water: ");
  Serial.println(waterValue);

  // ---------------- DANGER ----------------
  if ((distance > 0 && distance < 10) || (waterValue > 400)) {

    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);

    if (!buzzerMute)
      digitalWrite(buzzerPin, HIGH);
    else
      digitalWrite(buzzerPin, LOW);

    // Send SMS only once
    if (!smsSent) {
      sendSMS();
      smsSent = true;
    }

  }

  // ---------------- SAFE ----------------
  else {

    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, HIGH);

    digitalWrite(buzzerPin, LOW);

    buzzerMute = false;

    // Reset SMS flag
    smsSent = false;
  }

  delay(500);
}

// ---------------- Send SMS ----------------
void sendSMS() {

  Serial.println("Sending SMS...");

  sim800.println("AT");
  delay(1000);

  sim800.println("AT+CMGF=1");
  delay(1000);

  sim800.println("AT+CMGS=\"+91XXXXXXXXXX\"");   // Replace with your number
  delay(1000);

  sim800.println("⚠ ALERT!");
  sim800.println("Water level is HIGH.");
  sim800.println("Please take immediate action.");

  delay(500);

  sim800.write(26);   // CTRL+Z to send SMS

  delay(5000);

  Serial.println("SMS Sent");
}