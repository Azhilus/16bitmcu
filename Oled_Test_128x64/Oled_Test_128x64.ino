#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Define the OLED screen dimensions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Define the reset pin for the OLED display
#define OLED_RESET -1

// Create an instance of the Adafruit SSD1306 display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Initialize the OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    // If display initialization fails, enter an infinite loop
    for (;;);
  }

  // Display Adafruit splash screen for 1 second
  display.display();
  delay(1000);

  // Clear the display buffer
  display.clearDisplay();

  // Set text size to 1 and display "AzHilus" at (10, 0)
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(10, 0);
  display.println("AzHilus");
  display.display(); 
  delay(2000);

  // Set text size to 2 and display enlarged "AzHilus" at (10, 14)
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10, 14);
  display.println("AzHilus");
  display.display(); 
  delay(2000);

  // Display inverted "AzHilus" at (10, 35)
  display.setTextSize(1);
  display.setTextColor(BLACK, WHITE);
  display.setCursor(10, 35);
  display.println("AzHilus");
  display.display();
  delay(2000);

  // Display the number 1234567890 at (10, 50)
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(10, 50);
  display.println(1234567890);
  display.display();
  delay(2000);
}

void loop() {
  // Empty loop as there is no continuous action in this example
}
