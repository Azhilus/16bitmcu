#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Constants for OLED display
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Replace with your Wi-Fi credentials
const char *ssid = "YourWiFiSSID";
const char *password = "YourWiFiPassword";

const long utcOffsetInSeconds = 19800; // UTC offset in seconds (5 hours and 30 minutes)

// Arrays to store days and months names
char days[7][12] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
char month[12][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  delay(2000);

  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.setTextColor(WHITE);

  // Display startup message
  delay(2500);
  display.display();
  display.clearDisplay();

  display.setCursor(3, 28);
  display.setTextSize(2);
  display.setTextColor(WHITE);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);

  display.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(800);
    display.print(".");
    display.display();
  }
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.clearDisplay();
  timeClient.begin(); // Initialize NTP client
}

void loop() {
  timeClient.update(); // Update NTP client
  displayTimeDate();   // Display time and date on OLED
  delay(100);
}

void displayTimeDate() {
  String meridiem;
  int hour;

  unsigned long epochTime = timeClient.getEpochTime();
  struct tm *ptm = gmtime((time_t *)&epochTime);

  // Extract date and time components
  int date = ptm->tm_mday;
  int monthNum = ptm->tm_mon + 1;
  int year = ptm->tm_year + 1900;
  String day = days[timeClient.getDay()];
  int minute = timeClient.getMinutes();
  int second = timeClient.getSeconds();

  // Convert 24hr format to 12hr format
  if (timeClient.getHours() >= 12) {
    meridiem = "PM";
    hour = timeClient.getHours() - 12;
  } else {
    meridiem = "AM";
    hour = timeClient.getHours();
  }

  if (hour == 0) {
    hour = 12;
  }

  // Display time and date on OLED
  display.clearDisplay();

  display.setTextSize(2);
  display.setCursor(5, 10);
  display.print(day);

  display.setTextSize(3);
  display.setCursor(58, 6);
  if (date < 10) display.print(0);
  display.print(date);

  display.setTextSize(1);
  display.setCursor(97, 8);
  display.print(month[monthNum - 1]);
  display.setCursor(97, 20);
  display.print(year);

  display.setCursor(5, 39);
  display.setTextSize(3);
  if (hour < 10) display.print(0);
  display.print(hour);
  display.print(":");
  if (minute < 10) display.print(0);
  display.print(minute);

  display.setTextSize(2);
  display.setCursor(100, 37);
  if (second < 10) display.print(0);
  display.print(second);

  display.setTextSize(1);
  display.setCursor(100, 55);
  display.print(meridiem);
  display.display();
}
