int infrared  = 4; // 적외선센서 핀
int motorA1 =  5;  // 모터 핀1
int motorA2  = 6;  // 모터 핀2
int speed = 255 ;   // 모터 스피드 (0 ~ 255)

void setup ( ) {  
  pinMode(infrared, INPUT);
  pinMode(motorA1 , OUTPUT); 
  pinMode(motorA2 , OUTPUT); 
}

void loop ( )  {
  int state = digitalRead(infrared); // 적외선 센서 상태 읽기

  // 센서가 감지(0)되면 모터가 일정 시간이 지나고, 정회전 후 역회전
  if(state == 0){
    delay(3000); // 기다리는 시간
    
    // 정회전
    analogWrite( motorA1 , 110); 
    analogWrite( motorA2 , 0); 
    delay(300);

    analogWrite( motorA1, 0);
    analogWrite(motorA2, 0);
    delay(500);
    
    // 역회전
    analogWrite( motorA1 , 0);
    analogWrite( motorA2 , 150);
    delay(600);
  }
  
  // 그 외의 상태. 중력에 의해 랙기어가 내려가지 않도록 하기 위해 속도를 줌
  else { 
  analogWrite ( motorA1 , 0);
  analogWrite ( motorA2 , 50);
  }
}
