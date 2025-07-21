#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET 4
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

unsigned long whiteUpdateTime = 0;
unsigned long blackUpdateTime = 0;
int whiteTime = 600; // 10 minutes in seconds
int blackTime = 600;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.display();  
}

void loop() {
  if (millis() - whiteUpdateTime >= 1000 && whiteTime > 0) {
    whiteTime--;
    whiteUpdateTime = millis();
    displayTime(whiteTime, blackTime);
  }
  if (millis() - blackUpdateTime >= 1000 && blackTime > 0) {
    blackTime--;
    blackUpdateTime = millis();
    displayTime(whiteTime, blackTime);
  }
}

void displayTime(int whiteSeconds, int blackSeconds) {

  //white time
  int whiteMinutes = whiteSeconds / 60;
  int ws = whiteSeconds % 60;
  //black time
  int blackMinutes = blackSeconds / 60;
  int bs = blackSeconds % 60;

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  // Player 1 timer (white)
  display.setCursor(0, 0);
  display.print("WHITE: ");
  display.print(whiteMinutes);
  display.print(":");
  if (ws < 10) display.print("0");
  display.print(ws);

  // Player 2 timer (black)
  display.setCursor(0, 48);
  display.print("BLACK: ");
  display.print(blackMinutes);
  display.print(":");
  if (bs < 10) display.print("0");
  display.print(bs);

  display.display();
}
