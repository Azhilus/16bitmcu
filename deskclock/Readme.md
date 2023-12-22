# WiFi Desk Clock with OLED Display

This Arduino sketch creates a WiFi-enabled desk clock using an OLED display (Adafruit SSD1306) and utilizes the NTPClient library for time synchronization. Additionally, it fetches real-time weather information from the OpenWeatherMap API and displays it on the OLED screen.

<img src="https://github.com/Azhilus/16bitmcu/assets/66466976/bf6e5d31-f0b6-4a12-a149-4b6f75876a1d" alt="Oled_test" width="300">

## Board Compatibility

This code is designed to work with ESP8266-based boards, such as NodeMCU, and is compatible with the Arduino IDE.

## Prerequisites

Before uploading the code to your ESP8266 board, ensure you have the following:

- Arduino IDE installed on your computer.
- The required libraries installed in your Arduino IDE, including:
  - Adafruit GFX Library
  - Adafruit SSD1306 Library
  - NTPClient Library
  - ESP8266WiFi Library
  - ArduinoJson Library
  - ESP8266HTTPClient Library

You can install these libraries through the Library Manager in the Arduino IDE.

## Hardware Setup

1. Connect your OLED display to the ESP8266 board using the I2C protocol. Typically, connect the SDA and SCL pins on the OLED display to the corresponding pins on your ESP8266 board.

2. Ensure the board is powered appropriately.

## Uploading the Code

1. Open the `wifi_deskclock.ino` file in the Arduino IDE.

2. Select your ESP8266 board and port from the Tools menu.

3. Click the upload button to upload the code to your ESP8266 board.

## Configuration

Replace the following placeholders in the code with your own information:

```cpp
const char *ssid = "your_wifi_ssid";       // Replace with your Wi-Fi network SSID
const char *password = "your_wifi_password"; // Replace with your Wi-Fi network password
String Location = "City, Country";           // Replace with your desired location
String API_Key = "your_openweathermap_api_key"; // Replace with your OpenWeatherMap API key
```

## Understanding the Code

The code initializes the OLED display, connects to Wi-Fi, and fetches time using the NTPClient library. It also fetches weather information from the OpenWeatherMap API using the ESP8266HTTPClient and ArduinoJson libraries. The comments in the code provide explanations for each section, helping you understand the integration of various libraries for creating a WiFi-enabled desk clock.

## Troubleshooting

If you encounter issues during compilation or upload, double-check that the required libraries are installed in your Arduino IDE. Ensure that the OLED display is properly connected to the ESP8266 board, and the I2C communication is set up correctly.

## Contributing

If you have improvements or additional features to suggest, feel free to fork the repository, make your changes, and submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

Happy Tinkering!
