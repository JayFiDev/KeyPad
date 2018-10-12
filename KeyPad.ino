/*
   Keypad with Display
*/

#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "OneButton.h"
#include "Keyboard.h"


#define TFT_DC 9
#define TFT_CS 10
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

int counter = 0;
int aState;
int aLastState;

#define rect_start_x  20
#define rect_start_y 30
#define rect_size_x  80
#define rect_size_y  60

int max_pages = 3;
int current_page = 2;
bool updateDisplay = false;

char programming[9] = {'[', ']', '#', '(', ')', '<', '{', '}', '>'};

OneButton buttonR0C0(2, true);
OneButton buttonR0C1(3, true);
OneButton buttonR0C2(4, true); //switch between pages with doubleclick

OneButton buttonR1C0(5, true);
OneButton buttonR1C1(6, true);
OneButton buttonR1C2(7, true);

OneButton buttonR2C0(18, true);
OneButton buttonR2C1(19, true);
OneButton buttonR2C2(20, true);




void setup() {

  Serial.begin(115200);

  delay(5000);
  
  buttonR0C0.attachClick(clickR0C0);
  buttonR0C0.attachDoubleClick(doubleR0C0);
  buttonR0C1.attachClick(clickR0C1);
  buttonR0C2.attachClick(clickR0C2);
  buttonR0C2.attachDoubleClick(doubleR0C2);

  buttonR1C0.attachClick(clickR1C0);
  buttonR1C1.attachClick(clickR1C1);
  buttonR1C2.attachClick(clickR1C2);

  buttonR2C0.attachClick(clickR2C0);
  buttonR2C1.attachClick(clickR2C1);
  buttonR2C2.attachClick(clickR2C2);


  buttonR0C0.setClickTicks(200);
  buttonR0C1.setClickTicks(200);
  buttonR0C2.setClickTicks(200);
  
  buttonR1C0.setClickTicks(200);
  buttonR1C1.setClickTicks(200);
  buttonR1C2.setClickTicks(200);
  
  buttonR2C0.setClickTicks(200);
  buttonR2C1.setClickTicks(200);
  buttonR2C2.setClickTicks(200);
  
  tft.begin();
  tft.setRotation(3);
 
  drawProgramming();
  Keyboard.begin();

}

void loop() {

  buttonR0C0.tick();
  buttonR0C1.tick();
  buttonR0C2.tick();
  buttonR1C0.tick();
  buttonR1C1.tick();
  buttonR1C2.tick();
  buttonR2C0.tick();
  buttonR2C1.tick();
  buttonR2C2.tick();
  delay(1);

  if (updateDisplay == true)
  {
    updateDisplay = false;

    Serial.println(current_page);

    if (current_page == max_pages)
      current_page = 0;

    if(current_page < 0)
    {
      current_page = max_pages - 1;  
    }
    

    switch (current_page) {
      case 0:
        drawProgramming();
        break;
      case 1:
        drawFunctions();
        break;
      case 2: 
        drawWindow();
        break;
    
    }

  }
}

void drawProgramming()
{
 
  tft.fillScreen(ILI9341_BLACK);
  tft.fillRect(20, 5, 280, 20, ILI9341_BLUE);
  tft.setCursor(100, 8);
  tft.setTextColor(ILI9341_WHITE);  tft.setTextSize(2);
  tft.println("Programming");

  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < 3; i++) {
      tft.drawRect(rect_start_x + (i * 100) , rect_start_y + (j * 70), rect_size_x, rect_size_y, ILI9341_WHITE);
      tft.setCursor(rect_start_x + (i * 100) + rect_size_x / 2 - 10 , rect_start_y + (j * 70) + rect_size_y / 2 - 10 );
      tft.setTextColor(ILI9341_WHITE);  tft.setTextSize(3);
      tft.print(programming[j * 3 + i]);
    }
  }
}

void drawFunctions()
{

  
  tft.fillScreen(ILI9341_BLACK);
  tft.fillRect(20, 5, 280, 20, ILI9341_BLUE);
  tft.setCursor(100, 8);
  tft.setTextColor(ILI9341_WHITE);  tft.setTextSize(2);
  tft.println("Functions");

  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < 3; i++) {
      tft.drawRect(rect_start_x + (i * 100) , rect_start_y + (j * 70), rect_size_x, rect_size_y, ILI9341_WHITE);
      tft.setCursor(rect_start_x + (i * 100) + rect_size_x / 2 - 25 , rect_start_y + (j * 70) + rect_size_y / 2 - 10 );
      tft.setTextColor(ILI9341_WHITE);  tft.setTextSize(2);
      
      switch(j * 3 + i){
        case 0:
        tft.print("CHRM");
        break;
        
        case 1:
        tft.print("F360");
        break;
        
        case 2:
        tft.print("MUTE");
        break;
        
        case 3:
        tft.print("CURA");
        break;
        
        case 4:
        tft.print("NEXT");
        break;
        
        case 5:
        tft.print("Vol+");
        break;
        
        case 6:
        tft.print("CALC");
        break;
        
        case 7:
        tft.print("NTPD");
        break;
        
        case 8:
        tft.print("Vol-");
        break;
        
          
      }
      
    }
  }
}


void drawWindow()
{
  tft.fillScreen(ILI9341_BLACK);
  tft.fillRect(20, 5, 280, 20, ILI9341_BLUE);
  tft.setCursor(100, 8);
  tft.setTextColor(ILI9341_WHITE);  tft.setTextSize(2);
  tft.println("Windows");

  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < 3; i++) {
      tft.drawRect(rect_start_x + (i * 100) , rect_start_y + (j * 70), rect_size_x, rect_size_y, ILI9341_WHITE);
      tft.setCursor(rect_start_x + (i * 100) + rect_size_x / 2 - 20 , rect_start_y + (j * 70) + rect_size_y / 2 - 10 );
      tft.setTextColor(ILI9341_WHITE);  tft.setTextSize(2);
  
      switch(j * 3 + i){
        case 0:
        tft.print("MIN");
        break;
        
        case 1:
        tft.print("MAX");
        break;
        
        case 2:
        tft.print("");
        break;
        
        case 3:
        tft.drawRect(rect_start_x + (i * 100) + 5 , rect_start_y + (j * 70) + 5, rect_size_x -10, rect_size_y-10, ILI9341_WHITE);
        tft.fillRect(rect_start_x + (i * 100) + 7 , rect_start_y + (j * 70) + 7, (rect_size_x-12)/2, rect_size_y-15, ILI9341_BLUE);
        break;
        
        case 4:
        tft.drawRect(rect_start_x + (i * 100) + 5 , rect_start_y + (j * 70) + 5, rect_size_x -10, rect_size_y-10, ILI9341_WHITE);
        tft.fillRect(rect_start_x + (i * 100) + 7 + 5 , rect_start_y + (j * 70) + 7 + 5, 55, rect_size_y-25, ILI9341_BLUE);
        break;
        
        case 5:
        tft.drawRect(rect_start_x + (i * 100) + 5 , rect_start_y + (j * 70) + 5, rect_size_x -10, rect_size_y-10, ILI9341_WHITE);
        tft.fillRect(rect_start_x + (i * 100) + 7 +33 , rect_start_y + (j * 70) + 7, (rect_size_x-12)/2, rect_size_y-15, ILI9341_BLUE);
        break;
        
        case 6:
        tft.drawRect(rect_start_x + (i * 100) + 5 , rect_start_y + (j * 70) + 5, rect_size_x -10, rect_size_y-10, ILI9341_WHITE);
        tft.fillRect(rect_start_x + (i * 100) + 7 , rect_start_y + (j * 70) + 7, (rect_size_x-12)/3, rect_size_y-15, ILI9341_BLUE);
        break;
        
        case 7:
        tft.drawRect(rect_start_x + (i * 100) + 5 , rect_start_y + (j * 70) + 5, rect_size_x -10, rect_size_y-10, ILI9341_WHITE);
        tft.fillRect(rect_start_x + (i * 100) + 7 + 22  , rect_start_y + (j * 70) + 7, (rect_size_x-12)/3, rect_size_y-15, ILI9341_BLUE);
        break;
        
        case 8:
        tft.drawRect(rect_start_x + (i * 100) + 5 , rect_start_y + (j * 70) + 5, rect_size_x -10, rect_size_y-10, ILI9341_WHITE);
        tft.fillRect(rect_start_x + (i * 100) + 7 + 44 , rect_start_y + (j * 70) + 7, (rect_size_x-12)/3, rect_size_y-15, ILI9341_BLUE);
        break;
        
          
      }
      
    }
  }
}


void clickR0C0() {
  switch (current_page) {
    case 0:
      Keyboard.write(programming[0]);
      break;
    case 1:
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(KEY_F1);
      Keyboard.releaseAll( );
      break;
   case 2:
      Keyboard.press(KEY_RIGHT_SHIFT);
      Keyboard.press(KEY_F1);
      Keyboard.releaseAll( );
      break;      

  }

}


void doubleR0C0() {
  current_page--;
  updateDisplay = true;
}

void clickR0C1() {
  switch (current_page) {
    case 0:
      Keyboard.write(programming[1]);
      break;
    case 1:
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(KEY_F2);
      Keyboard.releaseAll( );
      break;
    case 2:
      Keyboard.press(KEY_RIGHT_SHIFT);
      Keyboard.press(KEY_F2);
      Keyboard.releaseAll( );
      break;
  }
}

void clickR0C2() {
  switch (current_page) {
    case 0:
      Keyboard.write(programming[2]);
      break;
    case 1:
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(KEY_F3);
      Keyboard.releaseAll( );
      break;
    case 2:
      Keyboard.press(KEY_RIGHT_SHIFT);
      Keyboard.press(KEY_F3);
      Keyboard.releaseAll( );
      break;
  }
}



void doubleR0C2() {
  current_page++;
  updateDisplay = true;
}

void clickR1C0() {
  switch (current_page) {
    case 0:
      Keyboard.write(programming[3]);
      break;
    case 1:
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(KEY_F4);
      Keyboard.releaseAll( );
      break;
    case 2:
      Keyboard.press(KEY_RIGHT_SHIFT);
      Keyboard.press(KEY_F4);
      Keyboard.releaseAll( );
      break;  
  }
}

void clickR1C1() {
  switch (current_page) {
    case 0:
      Keyboard.write(programming[4]);
      break;
    case 1:
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(KEY_F5);
      Keyboard.releaseAll( );
      break;
    case 2:
      Keyboard.press(KEY_RIGHT_SHIFT);
      Keyboard.press(KEY_F5);
      Keyboard.releaseAll( );
      break;      

  }
}

void clickR1C2() {
  switch (current_page) {
    case 0:
      Keyboard.write(programming[5]);
      break;
    case 1:
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(KEY_F6);
      Keyboard.releaseAll( );
      break;
    case 2:
      Keyboard.press(KEY_RIGHT_SHIFT);
      Keyboard.press(KEY_F6);
      Keyboard.releaseAll( );
      break;      
  }
}

void clickR2C0() {
  switch (current_page) {
    case 0:
      Keyboard.write(programming[6]);
      break;
    case 1:
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(KEY_F7);
      Keyboard.releaseAll( );
      break;
    case 2:
      Keyboard.press(KEY_RIGHT_SHIFT);
      Keyboard.press(KEY_F7);
      Keyboard.releaseAll( );
      break;      

  }
}

void clickR2C1() {
  switch (current_page) {
    case 0:
      Keyboard.write(programming[7]);
      break;
    case 1:
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(KEY_F8);
      Keyboard.releaseAll();
      break;
    case 2:
      Keyboard.press(KEY_RIGHT_SHIFT);
      Keyboard.press(KEY_F8);
      Keyboard.releaseAll( );
      break;      
  }
}

void clickR2C2() {
  Serial.println(current_page);
  switch (current_page) {
    case 0:
      Keyboard.write(programming[8]);
      break;
    case 1:
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press(KEY_F9);
      Keyboard.releaseAll( );
      break;
    case 2:
      Keyboard.press(KEY_RIGHT_SHIFT);
      Keyboard.press(KEY_F9);
      Keyboard.releaseAll( );
      break;      
  }
}

