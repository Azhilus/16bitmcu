#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Replace with your WiFi credentials
const char *ssid = "your_wifi_ssid";
const char *password = "your_wifi_password";

// Replace with the desired location and OpenWeatherMap API key
String Location = "city,country_code";
String API_Key = "your_openweathermap_api_key";

void setup(void)
{
  // Initialize serial communication
  Serial.begin(9600);
  delay(1000);

  // Initialize OLED display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  Wire.setClock(400000L);
  display.clearDisplay();
  display.setTextColor(WHITE, BLACK);
  display.setTextSize(1);
  display.setCursor(16, 0);
  display.println("Weather Station");
  display.display();

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting.");
  display.setCursor(0, 24);
  display.println("Connecting...");
  display.display();

  // Wait for WiFi connection
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Connected");
  display.print("Connected");
  display.display();
  delay(1000);
}

void loop()
{
  // Check WiFi connection
  if (WiFi.status() == WL_CONNECTED)
  {
    WiFiClient client;
    HTTPClient http;

    // Make HTTP request to OpenWeatherMap API
    http.begin(client, "http://api.openweathermap.org/data/2.5/weather?q=" + Location + "&APPID=" + API_Key);
    int httpCode = http.GET();

    if (httpCode > 0)
    {
      // Parse JSON response
      String payload = http.getString();
      DynamicJsonBuffer jsonBuffer(512);
      JsonObject &root = jsonBuffer.parseObject(payload);

      // Check if JSON parsing is successful
      if (!root.success())
      {
        Serial.println(F("Parsing failed!"));
        return;
      }

      // Extract weather data
      float temp = (float)(root["main"]["temp"]) - 273.15;
      int humidity = root["main"]["humidity"];
      float pressure = (float)(root["main"]["pressure"]) / 1000;
      float wind_speed = root["wind"]["speed"];
      int wind_degree = root["wind"]["deg"];

      // Print weather data to serial monitor
      Serial.printf("Temperature = %.2f°C\r\n", temp);
      Serial.printf("Humidity = %d %%\r\n", humidity);
      Serial.printf("Pressure = %.3f bar\r\n", pressure);
      Serial.printf("Wind speed = %.1f m/s\r\n", wind_speed);
      Serial.printf("Wind degree = %d°\r\n\r\n", wind_degree);

      // Display weather data on OLED screen
      display.setCursor(0, 16);
      display.printf("Temperature: %5.2f C\r\n", temp);
      display.printf("Humidity : %d %%\r\n", humidity);
      display.printf("Pressure : %.3fbar\r\n", pressure);
      display.printf("Wind speed : %.1f m/s\r\n", wind_speed);
      display.printf("Wind degree: %d", wind_degree);
      display.drawRect(109, 24, 3, 3, WHITE);
      display.drawRect(97, 56, 3, 3, WHITE);
      display.display();
    }

    // Close HTTP connection
    http.end();
  }

  // Wait for 1 minute before making the next request
  delay(60000);
}
