#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET 4

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Button pins
const int whiteButtonPin = 10;
const int blackButtonPin = 11;

// Game state
int whiteTime = 600; // seconds
int blackTime = 600; // seconds
bool whiteTurn = true;

// Timing
unsigned long lastTick = 0;
unsigned long lastButtonTime = 0;
const unsigned long debounceDelay = 200;

void setup() {
  pinMode(whiteButtonPin, INPUT_PULLUP);
  pinMode(blackButtonPin, INPUT_PULLUP);

  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 failed to initialize"));
    while (true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Press any side");
  display.display();
}

void loop() {
  unsigned long currentMillis = millis();

  // Handle button input
  if (digitalRead(whiteButtonPin) == LOW && whiteTurn && (currentMillis - lastButtonTime > debounceDelay)) {
    whiteTurn = false;
    lastButtonTime = currentMillis;
  }

  if (digitalRead(blackButtonPin) == LOW && !whiteTurn && (currentMillis - lastButtonTime > debounceDelay)) {
    whiteTurn = true;
    lastButtonTime = currentMillis;
  }

  // Handle countdown
  if (currentMillis - lastTick >= 1000) {
    if (whiteTurn && whiteTime > 0) {
      whiteTime--;
    } else if (!whiteTurn && blackTime > 0) {
      blackTime--;
    }
    lastTick = currentMillis;
    displayTime(whiteTime, blackTime);
  }

  // Win condition
  if (whiteTime <= 0 || blackTime <= 0) {
    display.clearDisplay();
    display.setCursor(0, 0);
    if (whiteTime <= 0) {
      display.println("Black Wins!");
    } else {
      display.println("White Wins!");
    }
    display.display();
    while (true); // Stop loop
  }
}

void displayTime(int whiteSeconds, int blackSeconds) {
  int wm = whiteSeconds / 60;
  int ws = whiteSeconds % 60;
  int bm = blackSeconds / 60;
  int bs = blackSeconds % 60;

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  // White time
  display.setCursor(0, 0);
  display.print("WHITE: ");
  display.print(wm);
  display.print(":");
  if (ws < 10) display.print("0");
  display.print(ws);
  if (whiteTurn) display.print(" <--");

  // Black time
  display.setCursor(0, 16);
  display.print("BLACK: ");
  display.print(bm);
  display.print(":");
  if (bs < 10) display.print("0");
  display.print(bs);
  if (!whiteTurn) display.print(" <--");

  display.display();
}
