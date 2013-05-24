int prevFlex[20];
int multiplyer = 0;

//smoothnes - http://playground.arduino.cc/main/smooth (Paul Badger 2007)
float filterVal;       // this determines smoothness  - .0001 is max  1 is off (no smoothing)
float smoothedVal;     // this holds the last loop value just use a unique variable for every different sensor that needs smoothing
float smoothedVal2;   // this would be the buffer value for another sensor if you needed to smooth two different sensors - not used in this sketch


void flex(){
	//get sensor value
	int sensor = flexSensor();
	Serial.println(sensor);
	multiplyer = map(sensor, threshold, 100, 0, 100);
	if(multiplyer < 0) multiplyer = 0;
	else if(multiplyer > 100) multiplyer = 100;

	smoothedVal =  smooth(multiplyer, 0.75, smoothedVal);

	//Serial.println(sensor);

	byte i;
	for (i=0; i<NROFPIXELS; i++) {
		setColor(i, randomColor, smoothedVal);
	}
}

int smooth(int data, float filterVal, float smoothedVal){


  if (filterVal > 1){      // check to make sure param's are within range
    filterVal = .99;
  }
  else if (filterVal <= 0){
    filterVal = 0;
  }

  smoothedVal = (data * (1 - filterVal)) + (smoothedVal  *  filterVal);

  return (int)smoothedVal;
}

int flexSensor(){
	//read raw sensor data
	int value = analogRead(pinFlex);
	//Serial.println(value);

	//convert
	int converted = map(value, 300, 350, 100, 0);
    //Serial.println(converted);

	return converted;
}

void checkActivity(){
	//save all
	saveActivity();

	int avgDelta = 0;
	int delta;
	byte i;
	for (i=0; i<18; i++) {
		delta = prevFlex[i] / prevFlex[i+1];
		delta = abs(delta);
	}
	avgDelta = avgDelta/19;

	randomColor = random(0,5);
}

void saveActivity(){

	//read current sensor value
	prevFlex[0] = flexSensor();

	//move all one place
	byte i;
	for (i=19; i>0; i--) {
		prevFlex[i] = prevFlex[i-1];
	}
}
