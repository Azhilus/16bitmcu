#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

// Wi-Fi credentials
const char *ssid = "your_wifi_ssid";  // Replace with your Wi-Fi network SSID
const char *password = "your_wifi_password";  // Replace with your Wi-Fi network password

// UTC offset in seconds (5 hours and 30 minutes for IST)
const long utcOffsetInSeconds = 19800;

// Arrays to store days and months names
char days[7][12] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
char month[12][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);  // NTP client for time synchronization
Adafruit_SSD1306 display(128, 64, &Wire, -1);  // OLED display initialization

// OpenWeatherMap API information
String Location = "City, Country";  // Replace with your desired location
String API_Key = "your_openweathermap_api_key";  // Replace with your OpenWeatherMap API key

// Function prototypes
void setup();
void loop();
void displayTimeDate();
void displayWeather();

void setup() {
  Serial.begin(115200);

  // Initialize OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  delay(2000);

  // Display initialization message
  display.clearDisplay();
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  delay(2500);
  display.display();
  display.clearDisplay();

  // Display Wi-Fi connection status
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.print("Connecting to Wi-Fi...");
  display.display();

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(800);
    display.print(".");
    display.display();
  }

  // Display Wi-Fi connection success
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Connected to Wi-Fi");
  display.display();
  delay(1000);

  // Initialize NTP client for time synchronization
  timeClient.begin();
}

void loop() {
  // Update NTP client for time synchronization
  timeClient.update();

  // Display time and date on OLED
  displayTimeDate();

  // Display weather information on OLED
  displayWeather();

  delay(100);
}

// Function to display time and date on OLED
void displayTimeDate() {
  String meridiem;
  int hour;

  // Get epoch time from NTP client
  unsigned long epochTime = timeClient.getEpochTime();
  struct tm *ptm = gmtime((time_t *)&epochTime);

  // Extract date and time components
  int date = ptm->tm_mday;
  int monthNum = ptm->tm_mon + 1;
  String day = days[timeClient.getDay()];
  int minute = timeClient.getMinutes();

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

  // Display date at the top right corner
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print(String(date) + " " + month[monthNum - 1]);

  // Display day at the top left corner
  display.setTextSize(1);
  display.setCursor(110, 0);
  display.print(day);

  // Display time at the center of the screen
  display.setTextSize(3);
  display.setCursor(6, 20);
  if (hour < 10) display.print(0);
  display.print(hour);
  display.print(":");
  if (minute < 10) display.print(0);
  display.print(minute);

  // Display meridiem
  display.setCursor(98, 27);
  display.setTextSize(2);
  display.print(meridiem);

  // Display city at the bottom right corner
  display.setTextSize(1);
  display.setCursor(98, 56);
  display.print(Location);

  display.display();
}

// Function to display weather information on OLED
void displayWeather() {
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;

    // Make HTTP request to OpenWeatherMap API
    http.begin(client, "http://api.openweathermap.org/data/2.5/weather?q=" + Location + "&APPID=" + API_Key);
    int httpCode = http.GET();

    if (httpCode > 0) {
      // Parse JSON response
      String payload = http.getString();
      DynamicJsonBuffer jsonBuffer(512);
      JsonObject &root = jsonBuffer.parseObject(payload);

      // Check if JSON parsing is successful
      if (!root.success()) {
        Serial.println(F("Parsing failed!"));
        return;
      }

      // Extract weather data
      float temp = (float)(root["main"]["temp"]) - 273.15;

      // Display temperature on OLED screen
      display.setTextSize(1);
      display.setCursor(0, 56);
      display.print(String(temp, 1) + " " + "C");

      display.display();
    }

    // Close HTTP connection
    http.end();
  }

  // Wait for 15 Seconds before making the next request
  delay(15000);
}
