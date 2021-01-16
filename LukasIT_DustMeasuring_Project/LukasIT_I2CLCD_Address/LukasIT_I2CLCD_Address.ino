#include <Wire.h> // I2C통신을 위한 라이브러리를 사용함

//LCD Address: 0x27

void setup() //<-- 프로그램 시작 시 처음 한번만 실해하는 기능들
{
  Wire.begin(); // I2C통신을 설정합니다.

  Serial.begin(9600); // 시리얼모니터 속도를 9600으로 설정하고 시작합니다.
  while (!Serial);    // 시리얼모니터가 동작완료될 때까지 대기함.       
  Serial.println("\nI2C Scanner"); // ""을 출력
}

void loop() //<-- 프로그램 시작 후 매번 수행하는 기능들
{
  byte error, address; // 어드레스(주소)를 알아내기 위한 변수들 선언
  int nDevices;
  Serial.println("Scanning..."); // ""을 출력
  nDevices = 0;
  for(address = 1; address < 127; address++ )//<-- 주소값을 1에서 127까지 1씩 증가시키면서 아래기능 수행 
  {
    Wire.beginTransmission(address); // 주어진 어드레스(주소)값으로 LCD와 I2C통신을 시도함
    error = Wire.endTransmission();  // I2C 통신 결과를 알려준다.

    if (error == 0) // 통신결과가 에러가 없음
    {
      Serial.print("I2C device found at address 0x");
      if (address<16) 
        Serial.print("0");
      Serial.print(address,HEX); // I2C LCD와 통신 결과 후 알아낸 LCD주소값을 출력합니다.
      Serial.println("  !");

      nDevices++;
    }
    else if (error==4) //통신결과가 에러가 있슴
    {
      Serial.print("Unknow error at address 0x");
      if (address<16) 
        Serial.print("0");
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0) //<-- 주소값을 알아내지 못했을 경우
    Serial.println("No I2C devices found\n");
  else  //<-- 주소값을 알아낸 경우
    Serial.println("done\n");

  delay(5000);  // 5초를 기다림
}

