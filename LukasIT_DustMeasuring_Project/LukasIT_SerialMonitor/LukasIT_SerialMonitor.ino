int R = 9 ;  // 아두이노 9번핀을 R이라고 설정
int G = 10 ; // 아두이노 10번핀을 G이라고 설정
int B = 11 ; // 아두이노11번 핀을 B이라고 설정

void setup() //<-- 프로그램 시작 시 맨처음에 한번 수행하는 함수 또는 기능
{
  pinMode(R,OUTPUT); // R핀, 그러니까 아두이노 9번핀을 '출력'으로 설정
  pinMode(G,OUTPUT); // G핀, 그러니까 10번핀을 '출력'으로 설정
  pinMode(B,OUTPUT); // B핀, 그러니까 11번 핀을 '출력'으로 설정

  Serial.begin(9600); //시리얼모니터와 통신 속도를 9600bps로 설정
}

void loop() //<-- 프로그램 수행 시 계속 반복되는 함수 또는 기능
{
  digitalWrite(R,HIGH); // R핀,,그러니까 아두이노 9번핀에 양극(+) 전원을 출력
  digitalWrite(G,0);    // G핀,,그러니까 아두이노 10번핀에 음극(-,GND) 전원을 출력
  digitalWrite(B,0);    // B핀,,아두이노 11번핀에 음극(-,GND) 전원을 출력

  Serial.println("Red LED ON"); //시리얼모니터에 ""문장을 출력
  
  delay(2000);  // 2000밀리초,,,그러니까 2초 동안 기다려라...

  digitalWrite(R,0);    // R핀,,아두이노 9번핀에 음극(-,GND) 전원을 출력
  digitalWrite(G,HIGH); // G핀,,그러니까 아두이노 10번핀에 양극(+) 전원을 출력
  digitalWrite(B,0);    // B핀,,아두이노 11번핀에 음극(-,GND) 전원을 출력

  Serial.println("Green LED ON"); //시리얼모니터에 ""문장을 출력
  
  delay(2000);  // 2000밀리초,,,그러니까 2초 동안 기다려라...

  digitalWrite(R,0);    // R핀,,아두이노 9번핀에 음극(-,GND) 전원을 출력
  digitalWrite(G,0);    // G핀,,아두이노 10번핀에 음극(-,GND) 전원을 출력
  digitalWrite(B,HIGH); // B핀,,그러니까 아두이노 11번핀에 양극(+) 전원을 출력

  Serial.println("Blue LED ON"); //시리얼모니터에 ""문장을 출력
  
  delay(2000);  // 2000밀리초,,,그러니까 2초 동안 기다려라...
}

