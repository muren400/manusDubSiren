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

/*#define LEDOUT 10
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
int rate = 100;
//variation maximum, thus the highest pitch
byte topvalue = 2;
//"LFOs" waveform: 0 for triangle, 1 for square
byte waveform = 1;


void setup(){
	//set audio out pin to output mode
	pinMode(AUDIOOUT, OUTPUT);
	pinMode(LEDOUT, OUTPUT);	
	Serial.begin(9600);
}

void loop(){

	//get pitch value
	//pitch = analogRead(0) * 2;
	//pitch = analogRead(PITCHIN) * 2;
	//get rate value
	rate = (int)analogRead(RATEIN)/50;
	//get intensity value
	//topvalue = analogRead(INTIN)/50;
	//topvalue = analogRead(0)/50;

	//if squarewave is selected
	if(waveform){
		//if the trianglewave is decreasing
		if(addition < 0){
			//highest pitch
			tone(AUDIOOUT, pitch*topvalue);
			//digitalWrite(LEDOUT, 255);
		}
		//else
		else{
			//lowest pitch
			tone(AUDIOOUT, pitch);
			//digitalWrite(LEDOUT, 0);
		}
	}

	//triangle wave is selected
	else{
		//pitch depends on variation value
		tone(AUDIOOUT, (int)pitch*variation);
	}

	int ppp = ((255)*(variation/topvalue));
	Serial.println(ppp);
	digitalWrite(LEDOUT, ppp);

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
}*/


int duration = 5000;
int position = 0;
byte direct = 255;

void setup() {                
  pinMode(4, OUTPUT);     
  pinMode(7, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(4, 0);
  digitalWrite(7, LOW);
}

void loop() {
  /*digitalWrite(7, HIGH);
  digitalWrite(13, HIGH);
	delay(1);          
  
  digitalWrite(7, LOW); 
  digitalWrite(13, LOW);*/
  //delay(1);      

  position++;

  tone(7, 440);
  delay(400);
  digitalWrite(4, 0);
  tone(7, 880);
  delay(200);
  digitalWrite(4, 1);
  tone(7, 392);
  delay(400);
  digitalWrite(4, 0);
  tone(7, 784);
  delay(200);
  digitalWrite(4, 1);
  tone(7, 523);
  delay(400);
  digitalWrite(4, 0);
  tone(7, 1047);
  delay(200);
  digitalWrite(4, 1);
  tone(7, 392);
  delay(400);
  digitalWrite(4, 0);
  tone(7, 784);
  delay(200);
  digitalWrite(4, 1);
  /*if(position == duration){
  	if(direct == 0){
  		direct = 1;
  		tone(7, 400, 200);
  	}
  	else{
  		direct = 0;
  		tone(7, 800, 400);
  	}
  	digitalWrite(4, direct);
  position = 0;
  }*/

}