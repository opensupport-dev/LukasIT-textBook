#include "DHT.h"  // DHT11 라이브러리를 사용하기 위해서 

#include <Wire.h> // I2C통신을 사용하기 위한 라이브러리를 가져옵니다.
#include <LiquidCrystal_I2C.h> // i2c lcd를 사용하기 위한 라이브러리를 가져옵니다.

#define DHTPIN 2     // DHT11 의 out 핀에 연결하기 위한 아두이노 핀 번호 2번 설정
#define DHTTYPE DHT11   // DHT온습도 센서들인 DHT11, DHT22, DHT21 중 여러가지 타입 중 DHT11을 사용

// DHT11 라이브러리에서 DHT를 사용한다고 명시하는 것인데 여기서는 DHT11온습도센서를 
// dht로 선언하여 사용한다고 설정하고 센서에서 제공하는 기능을(함수,메소드) 가져다 쓰기위한 초기화
DHT dht(DHTPIN, DHTTYPE);

// LCD address는 0x27 이고 16x2라인의 LCD입니다.
LiquidCrystal_I2C lcd(0x27,16,2);  

void setup() { //<-- 프로그램 시작 시 최초에 한번 시작하는 기능들.

  lcd.init();       // lcd를 설정합니다. // lcd.begin(); 
  lcd.backlight();  // 백라이트를 켜줍니다.
  lcd.clear();      // lcd 화면을 지웁니다.
  
  Serial.begin(9600);   // 시리얼모니터를 9600속도롤 사용하기로 설정
  Serial.println("DHT11 temperature!"); // 시리얼모니터에 ""를 나타냄

  dht.begin();  // dht로 선언한 DHT11 기능을 시작하도록 설정함
}

void loop() { // <-- 프로그램 시작 하고 매번 이 기능을 수행함

  delay(2500); // DHT11온습도 센서의 센서 값을 읽는 사이에 2.5초간 시간의 기다림이 필요함
  
  // 기본적으로 섭씨 단위로 dht 온습도 센서의 온도값을 읽어 변수 t에 저장
  float c = dht.readTemperature();

  // 위에서 읽은 온습도 값 중에 제대로 읽히지 않은 값이 있는지 확인
  if (isnan(c)) {
    Serial.println("Failed to read from DHT sensor!"); // 시리얼모니터에 "" 나타냄
    return; // 아래 코드를 수행하지 않고 그냥 빠져나옴
  }
  
  Serial.print("Temperature: ");
  Serial.print(c); // 변수 c값 (섭씨 온도값)을 나타냄
  Serial.println(" *C ");

  lcd.clear(); // lcd의 화면을 지웁니다.
  lcd.setCursor(0, 0);            // lcd의 0,0을 지정합니다.
  lcd.print("DHT Temperature!");  // "" 문장을 출력합니다.
  lcd.setCursor(0, 1);            // lcd의 0,1을 지정합니다.
  lcd.print("Temp:");      // Temp 라는 문장을 출력합니다.
  lcd.setCursor(9, 1);           // lcd의 9,1을 지정합니다.
  lcd.print(c);                   // c의 값(온도값)을 출력합니다.
  lcd.setCursor(14, 1);           // lcd의 14,1을 지정합니다.
  lcd.print("*C");                 // "*C" 라는 온도단위를 출력합니다
  lcd.display();                  // 설정된 내용들을 lcd에 출력합니다.
}

