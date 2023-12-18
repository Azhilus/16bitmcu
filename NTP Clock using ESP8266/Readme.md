# Internet Clock with NodeMCU and OLED Display

This Arduino sketch demonstrates the creation of an internet-connected clock using a NodeMCU board, Adafruit SSD1306 OLED display, and the NTPClient library. The clock displays the current time and date, synchronized with an NTP server.

<img src="https://github.com/Azhilus/16bitmcu/assets/66466976/4884518c-6735-4bd0-9186-21ce030cf9d8" alt="NTPCLOCK" width="300">

## Board Compatibility

This code is designed to work with the NodeMCU board, but it can be adapted for other ESP8266-based boards as well.

## Prerequisites

Before uploading the code to your NodeMCU board, make sure you have the following:

- Arduino IDE installed on your computer.
- The NTPClient, ESP8266WiFi, WiFiUdp, Wire, Adafruit GFX, and Adafruit SSD1306 libraries installed in your Arduino IDE. You can install these libraries through the Library Manager in the Arduino IDE.

## Hardware Setup

1. Connect your NodeMCU board to the OLED display using the I2C protocol. Connect the SDA and SCL pins on the OLED display to the corresponding pins on the NodeMCU board.

2. Make sure the OLED_RESET pin is connected to the reset pin on your NodeMCU board or left unconnected if not needed.

3. Replace the placeholder Wi-Fi credentials with your own in the code.

## Uploading the Code

1. Open the `ntpclockoled128x64.ino` file in the Arduino IDE.

2. Select the NodeMCU board and port from the Tools menu.

3. Click the upload button to upload the code to your NodeMCU board.

## Understanding the Code

- The code initializes the NodeMCU, connects to Wi-Fi, and retrieves the current time from an NTP server using the NTPClient library.

- The OLED display is controlled using the Adafruit SSD1306 and GFX libraries, showcasing the time and date in a visually appealing format.

- Detailed comments in the code provide explanations for each section, aiding in understanding and customization for your projects.

## Troubleshooting

- If you encounter issues during compilation or upload, ensure that the required libraries are installed in your Arduino IDE.

- Double-check the Wi-Fi credentials and ensure the NodeMCU board is properly connected to the OLED display.

## Contributing

If you have improvements or additional features to suggest, feel free to fork the repository, make your changes, and submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

Happy Tinkering!
