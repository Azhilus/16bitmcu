#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#define TFT_CS   4
#define TFT_RST  16
#define TFT_DC   5

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  Serial.begin(9600);
  Serial.print(F("Hello! ST77xx TFT Test"));
  tft.initR(INITR_144GREENTAB);

  tft.setRotation(2);
  Serial.println(F("Initialized"));

  tft.fillScreen(ST77XX_BLACK);
  delay(500);

  tft.fillScreen(ST77XX_BLACK);
  displayText(ST77XX_WHITE);
  delay(2000);
}

void loop() {
}

void displayText(uint16_t color) {
  tft.setCursor(0, 0);
  tft.setTextColor(color);
  tft.setTextWrap(true);

  const char *Text = "Hello, I am AzHilus";
  
  tft.print(Text);
  tft.setCursor(0, 10);
  tft.setTextColor(ST77XX_RED);
  tft.setTextSize(1);
  tft.println("AzHilus");
  tft.setTextColor(ST77XX_YELLOW);
  tft.setTextSize(2);
  tft.println("AzHilus");
  tft.setTextColor(ST77XX_GREEN);
  tft.setTextSize(3);
  tft.println("AzHilus");
  tft.setTextColor(ST77XX_BLUE);
  tft.setTextSize(4);
  tft.println("AzHilus");
}
