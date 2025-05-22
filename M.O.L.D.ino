#include <DHT11.h>
#include <LCD_I2C.h>

// Pin definitions
#define DHTPIN 2
#define FAN_PIN 3
#define GREEN_LED_PIN 4
#define FLOAT_SWITCH_PIN 7
#define RED_LED_PIN 8

// Humidity thresholds
#define HUMID_HIGH 55
#define HUMID_SAFE 54

// Sensor and LCD objects
DHT11 dht11(DHTPIN);
LCD_I2C lcd(0x27, 16, 2); // I2C address for 16x2 LCD

void setup() {
  Serial.begin(9600);

  // Configure pins
  pinMode(FAN_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(FLOAT_SWITCH_PIN, INPUT_PULLUP);  // Float switch is normally open


  // Initialize LCD
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Dehumidifier");
  delay(1000);
}

void loop() {
  int temperature = 0;
  int humidity = 0;

  // Read DHT11 data
  int result = dht11.readTemperatureHumidity(temperature, humidity);

  // Read float switch
  bool waterHigh = (digitalRead(FLOAT_SWITCH_PIN) == LOW);

  // Red LED if float switch is triggered
  if (waterHigh) {
    digitalWrite(RED_LED_PIN, LOW);
  } else {
    digitalWrite(RED_LED_PIN, HIGH);
  }

  if (result == 0) {
    // Display values on Serial Monitor
    Serial.print("Temp: ");
    Serial.print(temperature);
    Serial.print(" C\tHumidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    // Update LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperature);
    lcd.print("C");

    lcd.setCursor(0, 1);
    lcd.print("Humidity: ");
    lcd.print(humidity);
    lcd.print("%");

    // Fan control based on humidity
    if (humidity >= HUMID_HIGH) {
      digitalWrite(FAN_PIN, HIGH);
    } else {
      digitalWrite(FAN_PIN, LOW);
    }

    // Green LED for safe humidity
    if (humidity < HUMID_SAFE) {
      digitalWrite(GREEN_LED_PIN, HIGH);
    } else {
      digitalWrite(GREEN_LED_PIN, LOW);
    }

  } else {
    // Sensor failed
    Serial.println("Sensor Error!");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!");
  }

  delay(2000);
}
