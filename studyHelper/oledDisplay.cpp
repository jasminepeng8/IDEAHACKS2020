
#include "oledDisplay.h"

void oledDisplay::startup(void) {
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3D)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();

  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
  display.display();
  delay(2000);
  // display.display() is NOT necessary after every single drawing command,
  // unless that's what you want...rather, you can batch up a bunch of
  // drawing operations and then update the screen all at once by calling
  // display.display(). These examples demonstrate both approaches...
}

void oledDisplay::show(double minutes) {
  display.clearDisplay();

  display.setTextSize(1); 
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 13);      // how to set position on screen
  display.println(F("Number of attempts: ")); // how to print strings
  display.setCursor(58, 24);
  display.println(0);     // how to print numbers
  
  display.setCursor(35, 40);      
  display.println(F("Time Left: ")); 
  display.setCursor(50, 51);
  int m = minutes / 60000;
  int seconds = (minutes - (double)(m * 60000)) / 1000;
  display.println(m);     
  display.setCursor(58, 51);
   display.print(F(":"));     
  display.display();      
  display.setCursor(66, 51);
  display.print(seconds);     
  display.display();      
  delay(100);
}

void oledDisplay::endMessage(void)
{
  display.clearDisplay();

  display.setTextSize(1); 
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 28);      
  display.println(F("Congrats on making")); 
  display.setCursor(13, 36);      
  display.println(F("it to the end! (:"));
  display.display();      
  delay(5000);
}
