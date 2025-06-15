#include <HX711.h>
#include <LiquidCrystal_I2C.h>

// Load cell sensor pins
#define LOADCELL_DOUT_PIN 4
#define LOADCELL_SCK_PIN 15

// Buzzer pin
#define BUZZER_PIN 26

// Initialize the HX711 load cell amplifier
HX711 scale;

// Initialize the LCD display
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Variables
float ivBtl, per;
bool alarmActive = false;
unsigned long lastAlarmTime = 0;
int i;

void setup() {
  Serial.begin(115200);

  // Set up the load cell sensor
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(3000.f);  // Calibration factor for the load cell
  scale.tare();  // Reset the scale to 0

  // Set up the LCD display
  lcd.init();
  lcd.backlight();

  // Set up the buzzer pin
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // Read the weight from the load cell sensor (calibration)
  ivBtl = scale.get_units(10) * -1.5;  // Convert from grams to milliliters

  // Calculate the percentage of the remaining solution
  per = (ivBtl / 500.0) * 100.0;  // Assuming the full bag contains 500 ml

  // Display the IV bag volume and percentage on the LCD
  lcd.setCursor(0, 0);
  lcd.print("IV Btl: ");
  lcd.print(ivBtl, 2);
  lcd.print(" ml");
  lcd.setCursor(0, 1);
  lcd.print("per: ");
  lcd.print(per, 2);
  lcd.print("%");

  // Check if the solution level has dropped to 50%
  if (per <= 50.0 && !alarmActive) {
    alarmActive = true;
    lastAlarmTime = millis();
    for (int i = 0; i < 6; i++) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(500);
    digitalWrite(BUZZER_PIN, LOW);
    delay(500);
    }
  }

  // Repeat the alarm every 30sec if the solution level is still below 50%
  if (alarmActive && (millis() - lastAlarmTime) >= 30000) {
    lastAlarmTime = millis();
    for (int i = 0; i < 3; i++){
    digitalWrite(BUZZER_PIN, HIGH);
    delay(700);  // Sound the buzzer for 1 seconds
    digitalWrite(BUZZER_PIN, LOW);
    delay(200);
    }
  }

  delay(1000);  // Wait for 1 second before the next loop
}
