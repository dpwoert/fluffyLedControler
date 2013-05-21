int prevFlex[20];

void flex(){
	//get sensor value
	int sensor = flexSensor();
}

int flexSensor(){
	//read raw sensor data
	int value = analogRead(pinFlex);
	Serial.println(value);

	//convert
	int converted = map(value, 512, 614, 0, 100);

	return converted;
}

void checkActivity(){

	//read current sensor value
	prevFlex[0] = flexSensor();

	//move all one place
	byte i;
	for (i=19; i>0; i--) {
		prevFlex[i] = prevFlex[i-1];
	}
}