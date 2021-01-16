/***********************************************************************************************
    아두이노 우노를 이용한 미세먼지 측정 프로젝트
  -.해당 소스는 출처 표기후 개인 또는 교육에 사용 가능한 오픈 소스입니다.
  -.상업적 이용을 원하시면 승인후 사용 가능합니다.
  -.아래 소스는 인터넷에서 수집한 정보로 기초로 수정한 소스 입니다.
  -.소스는 아두이노 교육 목적으로 제공되며 정확성,신뢰성을 보장 하지는 않습니다.
  -.해당 소스를 사용하여 발생하는 모든 문제는 사용자 본인에게 책임이 있습니다.
  -.인터넷을 검색 하시면 더많은 다양한 예제를 보실수 있을 겁니다.
  -.소스코딩은 메일로 문의 하시기 바랍니다.
  -.문의: lukasit.kr / e-mail: chaindapp@gmail.com
  -.Created/Modify by Jaehong Park
/*---------------------------------------------------------------------------------------------------*
  /* DSM501A 먼지 센서 사용시 주의할 점.
  센서 주변의 빛에 의해 적외선 센서가 영향받지 않도록 빛을 차단하는 케이스 필요.
  센서가 측정하는 공기질에 영향을 주는 바람, 대류현상을 차단하도록
  설치 센서의 경우 내부에 작은 히터가 들어가 있습니다.
  히터에 의한 상승기류를 이용한 측정장치이므로
  히터 부위가 광학부위보다 아래쪽에 위치하도록 설치해야 합니다.
  가변 저항부분을 손대(조절하면)면 안된다(센서 오류발생함).
  ---------------------------------------------------------------------------------------------------*
*/
// * 1~5 번호는 먼지센서 본체 콘넥터에 표기 되어있습니다
// 1,4핀은 여기서 사용되지 않습니다.
// Pin_2 of DSM501A -- Arduino D3
// Pin_3 of DSM501A -- Arduino 5V
// Pin_5 of DSM501A -- Arduino GND


#include<string.h> // 사칙연산 계산을 위해 라이브러리를 사용함.

unsigned long duration;  //지속시간
unsigned long starttime; //시작시간
unsigned long curtime;   //종료시간
unsigned long sampletime_ms = 30000; // 30초 = 먼지 측정 주기(간격)-조정하세요 ; (1초=1000으로 설정)
unsigned long lowpulseoccupancy = 0; //지속시간 누적
float ratio = 0;
float concentration = 0; // using spec sheet curve
float pcsPerCF = 0;  //입자당 CF를 0으로 초기화
float ugm3 = 0;  //세제곱미터(큐빅 미터)당 마이크로 그램(㎍/㎥)
int i = 0;

int DSM501A_pin = 3;//DSM501A 미세먼지센서의 2번핀의 출력을 아두이노 3번핀에 연결

void setup() //<-- 프로그램 시작시 맨 처음 한번 기능들을 수행
{
  Serial.begin(9600); //시리얼 통신 데이타를 확인할수 있습니다.
  Serial.println("DSM501A Dust senser start,..please wait for 30sec !\n");
  delay(3000);
  
  starttime = millis(); //시작 값을 아두이노로부터 읽어 들인다.- 초 단위로 사용

  pinMode(DSM501A_pin, INPUT); // 핀은 입력으로 설정
}

void loop() //<-- 프로그램 동작시 매번 반복적으로 수행하는 기능들
{
  /*--------- 먼지 센서 값을 검출 계산 --------------------------------------------*/
  duration = pulseIn(DSM501A_pin, LOW); // LOW펄스가 들어온 시간을 계산
  lowpulseoccupancy = lowpulseoccupancy + duration; // LOW펄스가 들어온 시간을 누적하여 계산
  curtime = millis(); //아두이노 내부, 현재 시간;
  if ((curtime - starttime) >= sampletime_ms) //대기시간 > = 30s
  {
    ratio = lowpulseoccupancy / (sampletime_ms * 10.0);  // 비율 정수값 0=>100

    /* DSM501A 미세먼지 센서 스펙의 곡선 방정식 */
    concentration = 1.1 * pow(ratio, 3) - 3.8 * pow(ratio, 2) + 520 * ratio + 0.62;
    
    pcsPerCF = concentration * 100;  // 입자 농도에 100을 곱하면 입자당 CF값
    
    /* 원본: ugm3 = pcsPerCF / 13000;  //입자당 CF를 나누면 세제곱미터당 마이크로그램 미세먼지 값 */
    ugm3 = pcsPerCF / 800;  //입자당 CF를 나누면 세제곱미터당 마이크로그램 미세먼지 값

    Serial.print("duration:");
    Serial.print(duration);
    Serial.print(" / ");
    Serial.print("ugm3:");
    Serial.println(ugm3); // 미세먼지 농도 값을 츨력
   
    Serial.print("lowpulseoccupancy:");
    Serial.print(lowpulseoccupancy);
    Serial.print(" / ");
    Serial.print("ratio:");
    Serial.print(ratio);
    Serial.print(" / ");
    Serial.print("concentration:");
    Serial.print(concentration);
    Serial.print(" / ");
    Serial.print(" pcs/0.01cf:");
    Serial.println(pcsPerCF);
    Serial.print("f-concentration:");
    Serial.println(float(concentration/500));
    Serial.println("\n");
    lowpulseoccupancy = 0;
    starttime = millis();
  }
  
  delay(1000); // 1초 대기
}

