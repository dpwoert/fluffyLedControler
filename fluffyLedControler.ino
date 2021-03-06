/*
       .__     __        __     __         .__                         
  ____ |__|   |__| _____/  |_  |__| ____   |  | _____    _____ ______  
 /    \|  |   |  |/    \   __\ |  |/ __ \  |  | \__  \  /     \\____ \ 
|   |  \  |   |  |   |  \  |   |  \  ___/  |  |__/ __ \|  Y Y  \  |_> >
|___|  /__/\__|  |___|  /__/\__|  |\___  > |____(____  /__|_|  /   __/ 
     \/   \______|    \/   \______|    \/            \/      \/|__|    
with arduino
--------------------
Davey van der Woert
Jesse van Rheenen
Mathijs Bontje
*/

//Importing libaries
#include <SPI.h> //SPI voor LEDs

//Pins
int pinFlex = A0;

//ledwire config
const byte NROFPIXELS = 25; //No. leds
const byte NROFROWS = 4; //No. leds in a row
const byte NROFCOL = 4; //No. leds in a collumn
byte ledPixels[NROFPIXELS][3];

//timer
const byte FPS = 12; //FPS for timer
const long FLEX_INTERVAL = 5000; //milliseconds
unsigned long TIMER;
unsigned long TIMER_LED;
unsigned long TIMER_FLEX;

const byte threshold = 40; //need to get higher sensor data than this to trigger events
byte randomColor = 0;

void setup() {
  //start console for debugging
  Serial.begin(9600);

  //ledwire init with SPI 
  initColors();
  SPI.begin(); 
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE0);
  SPI.setClockDivider(SPI_CLOCK_DIV16);

  clearAllPixels();

  //Start timer
  TIMER_LED = millis();
  TIMER_FLEX = millis();

}

void loop() {
  //timer updaten
    TIMER = millis();

    int interval = 1000 / FPS;

    //(led) timer
    if(TIMER - TIMER_LED > interval){
      
      //Time reset
      TIMER_LED = millis();
      
      //get sensor data
      flex();

      //refresh leds
      showLedPixels();

    }

    //flex timer
    int delta = TIMER - TIMER_FLEX;
    if(delta > FLEX_INTERVAL){

      //Time reset
      TIMER_FLEX = millis();

      checkActivity();
      
      //int kleurtje = random(0,5);
      //colorFlash(kleurtje);

    }

}
