int prevFlex[20];

void flex(){
	//get sensor value
	int sensor = flexSensor();
}

int flexSensor(){
	//read raw sensor data
	int value = analogRead(pinFlex);
	//Serial.println(value);

	//convert
	int converted = map(value, 300, 350, 0, 100);
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
