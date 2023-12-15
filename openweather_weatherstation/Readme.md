# ESP8266 Weather Station with OLED Display

This project enables you to build a weather station using an ESP8266 microcontroller and an OLED display. By connecting to the OpenWeatherMap API, the station retrieves weather data and displays it on the OLED screen. Follow the guide below for hardware setup, code installation, and customization options.

[Weather_Station](https://github.com/Azhilus/16bitmcu/assets/66466976/536006e6-b98c-4b2f-84fa-7332aca1f5a7){ width=300 }


## Hardware Requirements

1. **ESP8266 Board**: We'll use an ESP8266-based microcontroller, such as NodeMCU or Wemos D1 Mini.
2. **OLED Display (SSD1306)**: A 128x64 OLED display is used to visualize the weather data.
3. **WiFi Connection**: You need a stable WiFi connection to fetch weather data. Provide your WiFi SSID and password.
4. **OpenWeatherMap API Key**: Obtain an API key from [OpenWeatherMap](https://openweathermap.org/) to access weather data.

## Wiring Diagram

Connect the components as follows:

- Connect the SDA pin of the OLED display to the D2 pin on the ESP8266.
- Connect the SCL pin of the OLED display to the D1 pin on the ESP8266.
- If your OLED display has a reset pin, connect it to the RESET pin on the ESP8266.

## Arduino Setup

1. Install the Arduino IDE on your computer.
2. Install the required libraries: ESP8266WiFi, ESP8266HTTPClient, ArduinoJson, Adafruit_GFX, and Adafruit_SSD1306.
3. Open the provided Arduino sketch (`weather_station.ino`) in the Arduino IDE.
4. Replace placeholders in the sketch with your WiFi credentials and OpenWeatherMap API key.

## Code Explanation

The code initializes the OLED display, connects to WiFi, and fetches weather data from the OpenWeatherMap API. It then parses the JSON response and displays relevant weather information on the OLED screen.

## Uploading the Code

1. Select your ESP8266 board and port in the Arduino IDE.
2. Click the upload button to upload the code to your ESP8266 board.

## Monitor the Output

1. Open the serial monitor in the Arduino IDE to monitor the ESP8266's output.
2. The serial monitor will display connection status and fetched weather data.

## Troubleshooting

- If you encounter issues, double-check your wiring, WiFi credentials, and API key.
- Ensure that the required libraries are installed.

## Customize the Display

Feel free to modify the code to customize the display layout or add additional features based on your preferences.

## Enhancements and Contributions

If you have ideas for enhancements or improvements, feel free to fork the repository, make your changes, and submit a pull request.

## License

This project is licensed under the MIT License. Refer to the [LICENSE](LICENSE) file for details.

Happy Tinkering!
