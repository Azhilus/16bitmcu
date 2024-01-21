# TFT Display Test with Adafruit ST7735 on Arduino

This Arduino sketch demonstrates a simple display test for a TFT screen using the Adafruit ST7735 library. The code is designed to work with various Arduino boards and can be adapted to different TFT displays.

<img src="https://github.com/Azhilus/16bitmcu/assets/66466976/7f012556-eea8-4387-9870-e1bfaa47f878" alt="NTPCLOCK" width="300">

## Board Compatibility

This code is compatible with various Arduino boards, including but not limited to Arduino Uno, NodeMCU, and others.

## Prerequisites

Before uploading the code to your Arduino board, make sure you have the following:

- Arduino IDE installed on your computer.
- The Adafruit GFX and ST7735 libraries installed in your Arduino IDE. You can install these libraries through the Library Manager in the Arduino IDE.

## Hardware Setup

1. Connect your TFT display to the Arduino. Ensure that you have connected the required pins (CS, RST, DC, SDA, SCK) based on your specific display.

**Pin Connections for 1.44-inch ST7735 Display**

1. **VCC**: Connect to the 3.3V pin on NodeMCU.
2. **GND**: Connect to the GND pin on NodeMCU.
3. **LED**: Connect to the 3.3V pin (or adjust according to your display's requirements).
4. **RESET**: Connect to the RX pin on NodeMCU.
5. **DC (Data/Command)**: Connect to the A0 pin on NodeMCU.
6. **CS (Chip Select)**: Connect to the D2 pin on NodeMCU.
7. **SDA (Data Input)**: Connect to the D7 pin on NodeMCU.
8. **SCK (Clock)**: Connect to the D5 pin on NodeMCU.

## Uploading the Code

1. Open the `TFTTest.ino` file in the Arduino IDE.

2. Select your Arduino board and port from the Tools menu.

3. Click the upload button to upload the code to your Arduino board.

### Code Overview:

1. **Include Libraries:**
   ```cpp
   #include <Adafruit_GFX.h>
   #include <Adafruit_ST7735.h>
   #include <SPI.h>
   ```
   These lines include necessary libraries for graphics handling and TFT display communication.

2. **Define TFT Pins:**
   ```cpp
   #define TFT_CS   4
   #define TFT_RST  16
   #define TFT_DC   5
   ```
   These constants define the pin numbers for Chip Select (CS), Reset (RST), and Data/Command (DC) pins of the TFT display.

3. **TFT Object Initialization:**
   ```cpp
   Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
   ```
   An instance of the `Adafruit_ST7735` class is created with the specified CS, DC, and RST pins.

4. **Setup Function:**
   ```cpp
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
   ```
   - Serial communication is initiated at a baud rate of 9600.
   - The TFT display is initialized with specific settings (e.g., `INITR_144GREENTAB`) and rotation is set.
   - The display is cleared (filled with black) and then a function `displayText()` is called to show text on the screen.

5. **Loop Function:**
   ```cpp
   void loop() {
   }
   ```
   The `loop()` function is empty, indicating that the code inside it will be executed repeatedly. However, in this case, it's left blank as there's no need for continuous execution.

6. **Display Text Function:**
   ```cpp
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
   ```
   - Sets the cursor position at (0, 0) on the display.
   - Defines the text color and enables text wrapping.
   - Prints the initial text "Hello, I am AzHilus" on the display.
   - Prints variations of the text in different colors and font sizes.

### Code Flow:

1. **Initialization:**
   - Serial communication is initiated.
   - TFT display is initialized with specific settings.
   - Display rotation is set.

2. **Display Setup:**
   - The display is cleared to black.
   - `displayText()` function is called to show various text variations on the display.

3. **Loop:**
   - The `loop()` function is empty, indicating that the code inside it will be executed repeatedly (if needed).

4. **Display Text Function:**
   - Positions the cursor, sets text color, and enables text wrapping.
   - Prints initial text and variations in color and font size.

This code is a basic demonstration of how to initialize and use the Adafruit ST7735 library to display text on a TFT screen. Adjustments can be made to customize the displayed text and its attributes.

## Troubleshooting

- If you encounter issues during compilation or upload, double-check that the required libraries are installed in your Arduino IDE.

- Ensure that the TFT display is properly connected to the Arduino board, and verify the pin definitions in the code.

## Contributing

If you have improvements or additional features to suggest, feel free to fork the repository, make your changes, and submit a pull request.

## License

This project is licensed under the MIT License.

Happy Tinkering!
