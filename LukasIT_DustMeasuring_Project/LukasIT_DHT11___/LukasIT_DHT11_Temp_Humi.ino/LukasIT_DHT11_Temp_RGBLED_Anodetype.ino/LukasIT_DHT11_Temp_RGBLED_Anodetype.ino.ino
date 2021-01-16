#include "DHT.h"  // DHT11 라이브러리를 사용하기 위해서 

#define DHTPIN 2     // DHT11 의 out 핀에 연결하기 위한 아두이노 핀 번호 2번 설정

#define DHTTYPE DHT11   // DHT온습도 센서들인 DHT11, DHT22, DHT21 중 여러가지 타입 중 DHT11을 사용

int R = 9 ;  // 아두이노 9번핀을 R이라고 설정
int G = 10 ; // 아두이노 10번핀을 G이라고 설정
int B = 11 ; // 아두이노11번 핀을 B이라고 설정

// DHT11 라이브러리에서 DHT를 사용한다고 명시하는 것인데 여기서는 DHT11온습도센서를 
// dht로 선언하여 사용한다고 설정하고 센서에서 제공하는 기능을(함수,메소드) 가져다 쓰기위한 초기화
DHT dht(DHTPIN, DHTTYPE);

void setup() { //<-- 프로그램 시작 시 최초에 한번 시작하는 기능들.

  pinMode(R,OUTPUT); // R핀, 그러니까 아두이노 9번핀을 '출력'으로 설정
  pinMode(G,OUTPUT); // G핀, 그러니까 10번핀을 '출력'으로 설정
  pinMode(B,OUTPUT); // B핀, 그러니까 11번 핀을 '출력'으로 설정
  
  Serial.begin(9600);   // 시리얼모니터를 9600속도롤 사용하기로 설정
  Serial.println("DHT11 Temperature!"); // 시리얼모니터에 ""를 나타냄

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

  if( c > 24) //<-- 섭씨 24도가 올라가면 Blue LED가 켜짐
  { 
    digitalWrite(R,HIGH);    // R핀,,아두이노 9번핀에 양극(+) 전원을 출력
    digitalWrite(G,HIGH);    // G핀,,아두이노 10번핀에 양극(+) 전원을 출력
    digitalWrite(B,LOW); // B핀,,그러니까 아두이노 11번핀에 음극(-) 전원을 출력
  }
  else
  { //<-- 온도가 섭씨 24도 아래이면 Green LED가 꺼짐
    digitalWrite(R,HIGH);    // R핀,,아두이노 9번핀에 양극(+) 전원을 출력
    digitalWrite(G,LOW);    // G핀,,아두이노 10번핀에 음극(-) 전원을 출력
    digitalWrite(B,HIGH); // B핀,,그러니까 아두이노 11번핀에 양극(+) 전원을 출력
  }
}

