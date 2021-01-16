#include <Wire.h> // I2C통신을 사용하기 위한 라이브러리를 가져옵니다.
#include <LiquidCrystal_I2C.h> // i2c lcd를 사용하기 위한 라이브러리를 가져옵니다.

LiquidCrystal_I2C lcd(0x27,16,2);  // LCD address는 0x27 이고 16x2라인의 LCD입니다.

int count;
void setup()
{
  lcd.init();       // lcd를 설정합니다. // lcd.begin(); 
  lcd.backlight();  // 백라이트를 켜줍니다.
  lcd.clear();      // lcd 화면을 지웁니다.
  count = 0;
}


void loop()
{
  lcd.clear();                                        // lcd의 화면을 지웁니다.
  lcd.setCursor(0, 0);                            // lcd의 0,0을 지정합니다.
  lcd.print("hello, world!");                     // hello, world! 라는 문장을 출력합니다.
  lcd.setCursor(0, 1);                            // lcd의 0,1을 지정합니다.
  lcd.print(count);                                     // count의 값을 출력합니다.
  lcd.display();                                     // 설정된 내용들을 lcd에 출력합니다.
  delay(1000);                                       // 1초동안 기다립니다.
  count ++;    
}

