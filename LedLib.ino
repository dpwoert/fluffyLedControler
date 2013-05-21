//alle pixels resetten
void clearAllPixels() {
  byte i;
  
  for (i=0; i<NROFPIXELS; i++) {
    ledPixels[i][0]=0;
    ledPixels[i][1]=0;
    ledPixels[i][2]=0;
  }  
}

//Ledsnoer refreshen
void showLedPixels() {
  byte i;

  for (i=0; i<NROFPIXELS; i++) {
    SPI.transfer(ledPixels[i][0]);
    SPI.transfer(ledPixels[i][1]);
    SPI.transfer(ledPixels[i][2]);
  } 
}

//whiteflash
void whiteFlash(){
  int i;
  for (i=0; i<NROFPIXELS; i++) {
    ledPixels[i][0]=255;
    ledPixels[i][1]=50;
    ledPixels[i][2]=55;
  } 
  showLedPixels();
}

//omzetten van x en y naar led pixel nr
int XYtoLedNr(int x, int y){

  int lednr = (y*(NROFCOL) + x)-NROFCOL;
  
  lednr = LED_VOLGORDE[lednr];
  
  if(lednr < 1){ lednr = 1; }
  
  return lednr-1; 
}
