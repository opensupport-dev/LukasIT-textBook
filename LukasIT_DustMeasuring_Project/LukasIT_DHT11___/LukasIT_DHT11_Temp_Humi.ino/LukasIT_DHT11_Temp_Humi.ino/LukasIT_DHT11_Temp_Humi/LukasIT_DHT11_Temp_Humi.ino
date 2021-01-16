#include "DHT.h"  // DHT11 라이브러리를 사용하기 위해서 

#define DHTPIN 2     // DHT11 의 out 핀에 연결하기 위한 아두이노 핀 번호 2번 설정

#define DHTTYPE DHT11   // DHT온습도 센서들인 DHT11, DHT22, DHT21 중 여러가지 타입 중 DHT11을 사용

// DHT11 라이브러리에서 DHT를 사용한다고 명시하는 것인데 여기서는 DHT11온습도센서를 
// dht로 선언하여 사용한다고 설정하고 센서에서 제공하는 기능을(함수,메소드) 가져다 쓰기위한 초기화
DHT dht(DHTPIN, DHTTYPE);

void setup() { //<-- 프로그램 시작 시 최초에 한번 시작하는 기능들.
  Serial.begin(9600);   // 시리얼모니터를 9600속도롤 사용하기로 설정
  Serial.println("DHT11 temp & humidity!"); // 시리얼모니터에 ""를 나타냄

  dht.begin();  // dht로 선언한 DHT11 기능을 시작하도록 설정함
}

void loop() { // <-- 프로그램 시작 하고 매번 이 기능을 수행함
  
  delay(2500); // DHT11온습도 센서의 센서 값을 읽는 사이에 2.5초간 시간의 기다림이 필요함

  float h = dht.readHumidity(); // dht의 센서값 중 습도를 읽어 변수 h에 저장
  
  // 기본적으로 섭씨 단위로 dht 온습도 센서의 온도값을 읽어 변수 t에 저장
  float c = dht.readTemperature();
  
  // 미국의 온도 단위인 Fahrenheit로 온도값을 읽어 변수 f에 저장 (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // 위에서 읽은 온습도 값 중에 제대로 읽히지 않은 값이 있는지 확인
  if (isnan(h) || isnan(c) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!"); // 시리얼모니터에 "" 나타냄
    return; // 아래 코드를 수행하지 않고 그냥 빠져나옴
  }

  // Fahrenheit (the default) 로 읽은 값을 heat index로 변환하여 변수 hif에 저장함
  float hif = dht.computeHeatIndex(f, h);
  
  // 섭씨 단위로 읽은 값을 heat index로 변환하여 변수 hic에 저장함
  float hic = dht.computeHeatIndex(c, h, false);

  Serial.print("Humidity: ");
  Serial.print(h); // 변수 h 값 (습도)을 나타냄
  Serial.print(" %\t");
  
  Serial.print("Temperature: ");
  Serial.print(c); // 변수 c값 (섭씨 온도값)을 나타냄
  Serial.print(" *C ");
  
  Serial.print(f); // 변수 f값 (Fahrenheit 온도값)을 나타냄
  Serial.print(" *F\t");
  
  Serial.print("Heat index: ");
  Serial.print(hic); //변수 hic값(섭씨 온도값을 이용한 heat index값)을 나타냄
  Serial.print(" *C ");
  
  Serial.print(hif); //변수 hif값(Fahrenheit 온도값을 이용한 heat index값)을 나타냄
  Serial.println(" *F");
}

