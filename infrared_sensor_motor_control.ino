int infrared = 4;   // 적외선 센서 핀
int motorA1 = 5;    // 모터 핀1
int motorA2 = 6;    // 모터 핀2

int speedForward = 110;   // 정회전 속도
int speedBackward = 150;  // 역회전 속도

// 연속 감지 확인 변수
int detectCount = 0;

// 20번 이상 연속 감지될 때만 동작
int detectThreshold = 20;

void setup() {

  // 센서 입력 설정
  pinMode(infrared, INPUT);

  // 모터 출력 설정
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
}

void loop() {

  // 적외선 센서 값 읽기
  int state = digitalRead(infrared);

  // ------------------------
  // 물체 감지 시
  // ------------------------
  if(state == 0){

    detectCount++;

    // 순간적인 오작동 방지
    delay(50);

  } else {

    // 감지 안되면 초기화
    detectCount = 0;
  }
  
  // ------------------------
  // 일정 횟수 이상 감지될 경우만 압축 실행
  // ------------------------
  if(detectCount >= detectThreshold){

    // 압축 실행 전 잠시 대기
    delay(3000);

    // ------------------------
    // 정회전 (압축)
    // ------------------------
    analogWrite(motorA1, speedForward);
    analogWrite(motorA2, 0);

    delay(300);

    // ------------------------
    // 모터 정지
    // ------------------------
    analogWrite(motorA1, 0);
    analogWrite(motorA2, 0);

    delay(4000);

    // ------------------------
    // 역회전 (원위치 복귀)
    // ------------------------
    analogWrite(motorA1, 0);
    analogWrite(motorA2, speedBackward);

    delay(600);

    // ------------------------
    // 모터 완전 정지
    // ------------------------
    analogWrite(motorA1, 0);
    analogWrite(motorA2, 0);

    // 감지 횟수 초기화
    detectCount = 0;

    // ------------------------
    // 재작동 제한 시간
    // ------------------------
    delay(3000);
  }

  // ------------------------
  // 감지되지 않을 경우
  // ------------------------
  else {

    analogWrite(motorA1, 0);
    analogWrite(motorA2, 0);
  }
}










