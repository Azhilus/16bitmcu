# PONG GAME (auto play) on OLED Display with Adafruit SSD1306 and GFX Library

This Arduino sketch demonstrates the pong game with the usage of the Adafruit SSD1306 and GFX libraries to control a 128x64 OLED display.

<img src="https://github.com/thoughtlessnerd/16bitmcu/assets/79973672/cc763430-15c4-472a-b5de-5dcebcb00a1b" alt="Oled_test" width="300">

## Board Compatibility

This code is compatible with various Arduino boards, including but not limited to Arduino Uno, NodeMCU, and others.
## Prerequisites

Before uploading the code to your Arduino board, make sure you have the following:

- Arduino IDE installed on your computer.
- The Adafruit GFX and SSD1306 libraries installed in your Arduino IDE. You can install these libraries through the Library Manager in the Arduino IDE.

## Hardware Setup

1. Connect your OLED display to the Arduino using the I2C protocol. Typically, this involves connecting the SDA and SCK pins on the OLED display to the corresponding pins on your Arduino board.

2. Make sure the OLED_RESET pin is connected to the reset pin on your Arduino or left unconnected if not needed.

## Uploading the Code

1. Open the `Pong-Game-OLED.ino` file in the Arduino IDE.

2. Select your Arduino board and port from the Tools menu.

3. Click the upload button to upload the code to your Arduino board.

## Understanding the Code

- The code initializes the OLED display first.

- There's a Ball object and Bat object.

- ### Ball object
  - It has `x`, `y`, `radius`, `velocityX` and `velocityY` as members.
  - It also has the `draw()` method that puts the draw buffer into the OLED display so that it can be displayed there.
  - Then there's an `update()` method which updates the `x` and `y` values according to the `velocityX` and `velocityY`.

- ### Bat object
  - It has `x`, `y`, `height` and `width` as members.
  - It has the `draw()` method as well that puts the draw buffer into the OLED display so that it can be displayed there.
 
- in the `loop()` function, on every call we check if the ball is colliding with any of the bats

- we also predict the incoming ball's `y` position when it will reach the same `x` position as the bat so that we can position the bat accordingly
![image](https://github.com/thoughtlessnerd/16bitmcu/assets/79973672/dbcb220a-681f-479b-873a-675f9193134e)


- if somehow the bat misses the ball then after a 3 second delay the game will restart

- The comments in the code provide explanations for each section, helping you understand how to use the Adafruit SSD1306 and GFX libraries for your own projects.

## Troubleshooting

- If you encounter issues during compilation or upload, double-check that the required libraries are installed in your Arduino IDE.

- Ensure that the OLED display is properly connected to the Arduino board and that the I2C communication is set up correctly.

## Contributing

If you have improvements or additional features to suggest, feel free to fork the repository, make your changes, and submit a pull request.

## License

This project is licensed under the MIT License.

Happy Tinkering!

Created with ❤ by [Thoughtlessnerd](https://github.com/thoughtlessnerd) :)
