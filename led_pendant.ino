#include <Sprite.h>
#include <Matrix.h>
#define DIN 6
#define LOAD 5
#define CLK 4
// LED Pendant
// by Ashwin Narayan <http://www.ashwinnarayan.com>

// Demonstrates the use of the Matrix & Sprite libraries
// Displays animated waveform graphic on screen

// Created 17 August 2015

//Create a Matrix Instance
Matrix myLeds = Matrix(DIN, CLK, LOAD);
int numChips = 1;

/* create a new Sprite instance
   8 pixels wide, 4 pixels tall
*/
Sprite wave = Sprite(
  8, 4,
  B00011000,
  B00100100,
  B01000010,
  B10000001
);

void setup() {
  myLeds.clear();
}

void loop() {
  byte x, y;

  // light one LED at a time, scanning left to right
  // and top to bottom... useful for testing the matrix
  for (y=0; y<8; y++) {
    for (x=0; x<(numChips * 8); x++) {
      myLeds.write(x, y, HIGH);
      delay(50);
      myLeds.write(x, y, LOW);
    }
  }
}

