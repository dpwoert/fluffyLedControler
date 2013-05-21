//colors
byte colors[5][3];
const byte POMEGRANATE = 0;
const byte EMERLAND = 1;
const byte PETER_RIVER = 2;
const byte WISTERIA = 3;
const byte WHITE = 4;

void initColors(){
  //flat ui colors [http://flatuicolors.com]

  //red - pomegranate
  colors[0][0] = 192;
  colors[0][1] = 57;
  colors[0][2] = 43;

  //green - emerland
  colors[1][0] = 46;
  colors[1][1] = 204;
  colors[1][2] = 113;

  //blue - peter river
  colors[2][0] = 52;
  colors[2][1] = 152;
  colors[2][2] = 219;

  //purple - wisteria
  colors[3][0] = 142;
  colors[3][1] = 68;
  colors[3][2] = 173;

  //full/white
  colors[4][0] = 250;
  colors[4][1] = 250;
  colors[4][2] = 250;

}

void setColor(int pixel, int color){
  ledPixels[pixel][0] = colors[color][0];
  ledPixels[pixel][1] = colors[color][1];
  ledPixels[pixel][2] = colors[color][2];
}

//switching off all pixels
void clearAllPixels() {
  byte i;
  
  for (i=0; i<NROFPIXELS; i++) {
    ledPixels[i][0]=0;
    ledPixels[i][1]=0;
    ledPixels[i][2]=0;
  }  
}

//refresh
void showLedPixels() {
  byte i;

  for (i=0; i<NROFPIXELS; i++) {
    SPI.transfer(ledPixels[i][0]);
    SPI.transfer(ledPixels[i][1]);
    SPI.transfer(ledPixels[i][2]);
  } 
}

//whiteflash
void colorFlash(int color){
  int i;
  for (i=0; i<NROFPIXELS; i++) {
    ledPixels[i][0]=colors[color][0];
    ledPixels[i][1]=colors[color][1];
    ledPixels[i][2]=colors[color][2];
  } 
  showLedPixels();
}

//converting grid value to ledpixel value
int XYtoLedNr(int x, int y){

  int lednr = (y*(NROFCOL) + x)-NROFCOL;
  
  //lednr = LED_VOLGORDE[lednr];
  
  if(lednr < 1){ lednr = 1; }
  
  return lednr-1; 
}
