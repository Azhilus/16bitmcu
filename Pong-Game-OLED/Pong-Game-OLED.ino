#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeMono12pt7b.h>

// Define the OLED screen dimensions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Define the reset pin for the OLED display
#define OLED_RESET -1

// border box
int boundaryX = 0;
int boundaryY = 0;
int boundaryWidth = 128;
int boundaryHeight = 64;

// Create an instance of the Adafruit SSD1306 display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// ball object
class Ball {
public:
  int x;
  int y;
  int radius;
  float velocityX;
  float velocityY;
  Ball(int x, int y, int r)
  {
    this->x = x;
    this->y = y;
    this->radius = r;

    this->velocityX = 0;
    this->velocityY = 0;
  }

  void draw()
  {
    display.drawCircle(this->x, this->y, this->radius, WHITE);
  }

  void update()
  {
    this->x += (int)this->velocityX;
    this->y += (int)this->velocityY;
  }
};

class Bat
{
public:
  int x;
  int y;
  int width;
  int height;
  Bat(int x, int y, int w, int h)
  {
    this->x = x;
    this->y = y;
    this->width = w;
    this->height = h;
  }

  void draw()
  {
    display.fillRect(this->x, this->y, this->width, this->height, WHITE);
  }
};

Ball* myBall = new Ball(64, 32, 2);
Bat* rightBat = new Bat(120, 20, 2, 20);
Bat* leftBat = new Bat(8, 20, 2, 20);

void resetGame()
{
  myBall = new Ball(64, 32, 2);
  rightBat = new Bat(120, 20, 2, 20);
  leftBat = new Bat(8, 20, 2, 20);

  myBall->velocityX = 1;
  myBall->velocityY = -2;
}


void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // display.setFont(&FreeMono12pt7b);

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

  // Display the number 1234567890 at (10, 50)
  // display.setTextSize(1);
  // display.setTextColor(WHITE);
  // display.setCursor(10, 50);
  // display.println(1234567890);
  // display.display();
  // delay(2000);

  myBall->velocityX = 1;
  myBall->velocityY = 2;
}

void loop() {
  display.clearDisplay(); // clear display

  displayRect(boundaryX, boundaryY, boundaryWidth, boundaryHeight);

  if(myBall->x + myBall->radius >= rightBat->x && myBall->y <= rightBat->y + rightBat->height && myBall->y >= rightBat->y) // condition to check collision with right bat
  {
    myBall->velocityX *= -1;
  }

  if(myBall->x - myBall->radius <= leftBat->x && myBall->y <= leftBat->y + leftBat->height && myBall->y >= leftBat->y) // condition to check collision with left bat
  {
    myBall->velocityX *= -1;
  }

  if(myBall->x + myBall->radius >= boundaryX + boundaryWidth || myBall->x - myBall->radius <= boundaryX) // condition to check left and right boundaries
  {
    display.setTextSize(2);
    display.setTextColor(BLACK, WHITE);
    display.setCursor(0, SCREEN_HEIGHT/2);

    if(myBall->velocityX < 0) // means it went out from the left and player 2 won
    {
      display.println("PLAYER 2 WON");
    }
    else // means it went out from right side and player 1 won
    {
      display.println("PLAYER 1 WON");
    }

    delay(3000);
    resetGame();
  }

  if(myBall->y + myBall->radius >= boundaryY + boundaryHeight || myBall->y - myBall->radius <= boundaryY) // condition to check top and bottom boundaries
  {
    myBall->velocityY *= -1;
  }

  myBall->draw();
  myBall->update();

  rightBat->draw();
  leftBat->draw();

  // move the bats according to the incoming ball
  if(myBall->velocityX < 0) // means its coming towards left
  {
    if(myBall->x < SCREEN_WIDTH/2) // we start moving the left bat only when ball is in the left half
    {
      int predictY = myBall->y - (myBall->velocityY * (myBall->x - leftBat->x) / myBall->velocityX);

      // if predicted ball is going out of screen then its gonna bounce so we take an image of that prediction inside the boundary box
      if(predictY > SCREEN_HEIGHT)
      {
        predictY = SCREEN_HEIGHT - (predictY - SCREEN_HEIGHT);
      }
      else if(predictY < 0)
      {
        predictY *= -1;
      }

      // int diffY = leftBat->y - predictY;

      leftBat->y = predictY - leftBat->height/2;

      leftBat->y = max(0, leftBat->y);

      leftBat->y = min(leftBat->y, SCREEN_HEIGHT - leftBat->height);
    }
  }
  else // means its going towards right
  {
    if(myBall->x > SCREEN_WIDTH/2) // ball is in right half
    {
      int predictY = myBall->y - (myBall->velocityY * (myBall->x - rightBat->x) / myBall->velocityX);

      // if predicted ball is going out of screen then its gonna bounce so we take an image of that prediction inside the boundary box
      if(predictY > SCREEN_HEIGHT)
      {
        predictY = SCREEN_HEIGHT - (predictY - SCREEN_HEIGHT);
      }
      else if(predictY < 0)
      {
        predictY *= -1;
      }

      // int diffY = rightBat->y - predictY;

      rightBat->y = predictY - rightBat->height/2;

      rightBat->y = max(0, rightBat->y);

      rightBat->y = min(rightBat->y, SCREEN_HEIGHT - rightBat->height);
    }
  }

  display.display(); // show the display buffer
}

void displayRect(int x, int y, int width, int height)
{
  display.drawRect(x, y, width, height, WHITE);
}


