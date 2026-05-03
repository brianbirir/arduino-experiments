#include <LiquidCrystal.h>
#include <DHT_U.h>
#include <DHT.h>

// LCD pins <--> Arduino pins
const int RS = 11, EN = 12, D4 = 2, D5 = 3, D6 = 4, D7 = 5;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

// #define DHT11_PIN 7
int sensePin = A0; // Read DHT sensor data at analog pin A0
#define DHTTYPE DHT11
DHT dht(sensePin, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();;
  lcd.begin(16, 2);
}

void loop() {
  delay(5000);
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  lcd.clear();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    lcd.print("Failed");
    return;
  }

  Serial.print("Temp: "); Serial.println(t);
  Serial.print("Humidity: "); Serial.println(h);

  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(String(t, 1)); 
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(String(h, 1));
  lcd.print("%");
}