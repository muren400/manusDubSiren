/***********************************************************************
*This program is free software: you can redistribute it and/or modify
*it under the terms of the GNU General Public License as published by
*the Free Software Foundation, either version 3 of the License, or
*(at your option) any later version.
*
*This program is distributed in the hope that it will be useful,
*but WITHOUT ANY WARRANTY; without even the implied warranty of
*MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*GNU General Public License for more details.
***********************************************************************
*/

#define AUDIOOUT 12
#define RATEIN 0
#define PITCHIN 1
#define INTIN 2

//defines the lowest pitch during a cycle
int pitch = 200;
//multiplies the the lowest pitch by x > 1
float variation = 1;
//increase or decrease the variation by this value for each step
float addition = 0.04;
//defines the rate of the "LFO"
int rate = 10;
//variation maximum, thus the highest pitch
byte topvalue = 2;
//"LFOs" waveform: 0 for triangle, 1 for square
byte waveform = 0;


void setup(){
	//set audio out pin to output mode
	pinMode(AUDIOOUT, OUTPUT);	
}

void loop(){

	//get pitch value
	pitch = analogRead(PITCHIN) * 2;
	//gest rate value
	rate = (int)analogRead(RATEIN)/50;
	//get intensity value
	topvalue = analogRead(INTIN)/50;

	//if squarewave is selected
	if(waveform){
		//if the trianglewave is decreasing
		if(addition < 0){
			//highest pitch
			tone(AUDIOOUT, pitch*topvalue);
		}
		//else
		else{
			//lowest pitch
			tone(AUDIOOUT, pitch);
		}
	}

	//triangle wave is selected
	else{
		//pitch depends on variation value
		tone(AUDIOOUT, (int)pitch*variation);
	}

	//add or subtract from variation value
	variation += addition;

	//if topvalue is reached start subtracting; if 1 is reached, start adding again
	if(variation > topvalue ||  variation < 1){
		addition *= -1;
	}

	//this is a little workaround necessary due to the intensity pot
	//i guess i have to think of a better solution though.
	//but i'm not in the mood to eplain this right now...
	if(variation > topvalue){
		variation = topvalue - addition;
	}

	if(variation < 1){
		variation = 1;
	}

	//wait for a little bit, then go on to the next step
	delay(rate);
}