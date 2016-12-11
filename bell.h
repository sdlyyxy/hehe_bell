const int buzzer_pin=8;//buzzer_pin

int fre[12]={196,220,247,262,294,330,350,392,440,494,523,587};
int min=132;
int tri=min / 3 * 4;
int gap=10;

void delay_(int t){
	delay(t-gap);
	noTone(buzzer_pin);
	delay(gap);
}

void s(int a,int b){
	tone(buzzer_pin, fre[a+2]);
	delay_(min*b);
}

void trisound(int a,int b,int c){
	tone(buzzer_pin, fre[a+2]);delay_(tri);
	tone(buzzer_pin, fre[b+2]);delay_(tri);
	tone(buzzer_pin, fre[c+2]);delay_(tri);
}

void sl(int a,int b,float c){
	tone(buzzer_pin, fre[a+2]);
	delay_(int(min*b*c));
}

void play(){
	//delay_(800);
	s(3,3);s(4,1);s(5,10);s(1,2);s(3,3);s(4,1);s(5,12);s(1,2);s(1,2);s(6,6);s(6,2);s(6,4);s(7,3);s(8,1);s(5,12);s(4,2);s(3,2);s(2,6);s(-2,2);s(2,4);s(3,4);s(1,12);
}