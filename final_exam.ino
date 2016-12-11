#include <Adafruit_NeoPixel.h>
#include "bell.h"

const int buttonPin=2;//touch button D2
const int humanHotSensor=4;//PIR传感器D4
const int LEDPIN=6;//LED

const int buttonTouched=0;
int looptimes=0;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(2, LEDPIN, NEO_GRB + NEO_KHZ800); 


bool checkexist(){
	Serial.println("checking");
	for(int i=0;i<30;i++){
		int humanHotState = digitalRead(humanHotSensor);
		if(!humanHotState)return 0;
		delay(100);
	}
	return 1;
}

void alert(){
	Serial.println("alerting");
	strip.setPixelColor(0, strip.Color(255, 0, 0));//红光
	strip.show();   //LED显示
	play();
	strip.setPixelColor(0, strip.Color(0, 0, 0));//红光
	strip.show();
	noTone(buzzer_pin);
}

void setup(){
	Serial.begin(9600);
	pinMode(buttonPin,INPUT);
	pinMode(humanHotSensor, INPUT);
	strip.begin(); //准备对灯珠进行数据发送
	strip.show(); //初始化LED为关的状态
}



void loop(){
	int buttonState;
	bool flag=0;
	buttonState=digitalRead(buttonPin);
	Serial.println(buttonState);
	if(buttonState==buttonTouched)flag=checkexist();
	if(flag)alert();else return;
	delay(100);
}