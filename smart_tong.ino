#include <Servo.h>
Servo tong;

//30cm이내로 누군가 접근을 하면 서보 모터가 120도까지 회전을 한 후 2초간 대기
//30cm보다 멀어지면 서보 모터가 0도로 천천히 되돌아 온다.
#define trig 2
#define echo 3
#define R 5
#define G 6
#define B 11
#define s_pin 7
float d1;
int state=0;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  tong.attach(s_pin);
  tong.write(0);
}

void loop() {
  get_d1();
  if(state==0 && d1<=30){
    open1();
    state=1; //뚜껑 열린 상태
  }else if(state==1 && d1>30){
    close1();
    state=0; //뚜껑 닫힌 상태
  }
}

void get_d1(){
  digitalWrite(trig, HIGH);
  delay(0.01);
  digitalWrite(trig, LOW);
  d1=pulseIn(echo, HIGH)*0.017; //cm단위의 거리 측정
  Serial.print(d1);
  Serial.println("cm");
}

void open1(){
  tong.attach(s_pin);
  analogWrite(R, 0);
  analogWrite(G, 200);
  analogWrite(B, 200);
  for(int i=0; i<=120; i+=5){
    tong.write(i);
    delay(20);
  }
  delay(2000);
}

void close1(){
  analogWrite(R, 200);
  analogWrite(G, 0);
  analogWrite(B, 200);
  for(int i=120; i>=0; i-=1){
    tong.write(i);
    delay(10);
  }
  analogWrite(R, 0);
  analogWrite(G, 0);
  analogWrite(B, 0);
  tong.detach();
}
