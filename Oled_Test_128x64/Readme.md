# OLED Display with Adafruit SSD1306 and GFX Library

This Arduino sketch demonstrates the usage of the Adafruit SSD1306 and GFX libraries to control a 128x64 OLED display. The code includes various examples to showcase text rendering, font size manipulation, and displaying numbers on the OLED screen.
![Oled_test](https://github.com/Azhilus/16bitmcu/assets/66466976/f0c5025b-e6c8-44fb-9a75-58756a0bf295)

## Board Compatibility

This code is compatible with various Arduino boards, including but not limited to Arduino Uno, NodeMCU, and others.
## Prerequisites

Before uploading the code to your Arduino board, make sure you have the following:

- Arduino IDE installed on your computer.
- The Adafruit GFX and SSD1306 libraries installed in your Arduino IDE. You can install these libraries through the Library Manager in the Arduino IDE.

## Hardware Setup

1. Connect your OLED display to the Arduino using the I2C protocol. Typically, this involves connecting the SDA and SCL pins on the OLED display to the corresponding pins on your Arduino board.

2. Make sure the OLED_RESET pin is connected to the reset pin on your Arduino or left unconnected if not needed.

## Uploading the Code

1. Open the `Oled_Test_128x64.ino` file in the Arduino IDE.

2. Select your Arduino board and port from the Tools menu.

3. Click the upload button to upload the code to your Arduino board.

## Understanding the Code

- The code initializes the OLED display and demonstrates different text rendering options, including font size manipulation and displaying numbers.

- The comments in the code provide explanations for each section, helping you understand how to use the Adafruit SSD1306 and GFX libraries for your own projects.

## Troubleshooting

- If you encounter issues during compilation or upload, double-check that the required libraries are installed in your Arduino IDE.

- Ensure that the OLED display is properly connected to the Arduino board and that the I2C communication is set up correctly.

## Contributing

If you have improvements or additional features to suggest, feel free to fork the repository, make your changes, and submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

Happy Tinkering!
