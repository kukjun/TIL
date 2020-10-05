# Neopixel 무드등 구현

온도와 습도에 따라 Neopixel 밝기나 행동을 변화시킨다.

[참고문서](http://lhdangerous.godohosting.com/wiki/index.php/%EB%84%A4%EC%98%A4%ED%94%BD%EC%85%80_(NeoPixel))

Neopixel 무드등을 구현할 수 있도록 한다.

#### 사용 센서

부저

buzzer_pin 

LED strip

온습도 센서

button

사운드 센서

### 목표 프로젝트

무드등 기능

시간에 따라 색을 변화시키는 기능을 추가한다.

사용자가 버튼을 누르면 기능을 3가지로 나누어서 구현한다.

켜기, 절전모드, 단일색모드를 구현할 수 있도록 한다.

노래를 추가할 수 있도록 한다.

가습 상태를 확인할 수 있도록 한다.

모드 변경은 버튼을 사용해서 구현한다.

* 버튼을 누르면 사운드 센서를 동작시켜 박수를 입력 받을 수 있도록 한다.

모드 변경은 사운드 센서를 사용해서 구현한다.

* 박수로 인식한다. 박수를 시간 간격을 두고 인식해서 박수 횟수에 따라 기능 구현이 달라지도록 한다.

#### 기본 상용 Mode

* 선택 기능 구현 + 단일 색 기능 구현

  ```C
  #include <Adafruit_NeoPixel.h>
  
  #define neo_pin 6
  #define dht_pin 7
  #define button1_pin 8
  #define button2_pin 9
  #define sound_pin 10
  #define buzzer_pin 11
  
  Adafruit_NeoPixel strip = Adafruit_NeoPixel(4, neo_pin, NEO_GRB + NEO_KHZ800);
  
  void setup() {
    strip.begin(); //네오픽셀 초기화를 위해 모든 LED OFF
    strip.show(); // 초기값 적용. 모든 LED 꺼짐
    pinMode(button1_pin, INPUT) // button1을 사용하도록 준비
    Serial.begin(9600);
  }
  
  void loop() {
      
  }
  ```

  

#### Mode

* 단일 색 기능 - Red, Blue, Yellow

  ```c
  #include <Adafruit_NeoPixel.h>
  
  #define neo_pin 6
  #define button01_pin 10 
  
  Adafruit_NeoPixel strip = Adafruit_NeoPixel(4, neo_pin, NEO_GRB + NEO_KHZ800);
  
  
  void setup() {
  	strip.begin(); //네오픽셀 초기화를 위해 모든 LED OFF
  	strip.show(); // 초기값 적용. 모든 LED 꺼짐
      pinMode(button1_pin, INPUT);
      Serial.begin(9600);
      
  }
  
  void loop() {
      
  }
  ```

* 과거 코드

  ```C
  #include <Adafruit_NeoPixel.h>
  #include <DHT.h>
  
  #define LIGHTPIN 6
  #define DHTPIN 7
  
  
  #define DHTTYPE DHT11
  
  DHT dht (DHTPIN, DHTTYPE); // dht 오브젝트를 만든다.
  Adafruit_NeoPixel strip = Adafruit_NeoPixel(4, LIGHTPIN, NEO_GRB + NEO_KHZ800); // 네오픽셀의 오브젝트를 만든다.
  
  void setup() {
    strip.begin(); //네오픽셀 초기화를 위해 모든 LED OFF
    strip.show(); // 초기값 적용. 모든 LED 꺼짐
    dht.begin(); // dht 센서를 사용하기 위한 시작.
    Serial.begin(9600);
  }
  
  void loop() {
    
    float h = dht.readHumidity();
    float t = dht.readTemperature();
  
    // 오류 출력
    if (isnan(h) || isnan(t)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print("%\n");
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print("*C\n\n");
  
    if(h <= 25) // 습도 0% ~ 25% 일 경우
    {
      if(t < 10)
      {
        strip.setPixelColor(0, 0, 0, 255); // 첫 번째 LED 파란색을 점등
        strip.show();
      }
      else if(t < 20)
      {
        strip.setPixelColor(0, 0, 255, 255);
        strip.show();
      }
      else if(t < 30)
      {
        strip.setPixelColor(0, 0, 255, 0);
        strip.show();
      }
      else if(t < 40)
      {
        strip.setPixelColor(0, 255, 255, 0);
        strip.show();
      }
      else if(t <50)
      {
        strip.setPixelColor(0, 255, 0, 0);
        strip.show();
      }
    }
  
      else if(h <= 50) // 습도 25 ~ 50% 일 경우
    {
      if(t < 10)
      {
        strip.setPixelColor(0, 0, 0, 255); // 첫 번째 LED 파란색을 점등
        strip.setPixelColor(1, 0, 0, 255); // 두 번째 LED 파란색을 점등
        strip.show();
      }
      else if(t < 20)
      {
        strip.setPixelColor(0, 0, 255, 255);
        strip.setPixelColor(1, 0, 255, 255);
        strip.show();
      }
      else if(t < 30)
      {
        strip.setPixelColor(0, 0, 255, 0);
        strip.setPixelColor(1, 0, 255, 0);
        strip.show();
      }
      else if(t < 40)
      {
        strip.setPixelColor(0, 255, 255, 0);
        strip.setPixelColor(1, 255, 255, 0);
        strip.show();
      }
      else if(t <50)
      {
        strip.setPixelColor(0, 255, 0, 0);
        strip.setPixelColor(1, 255, 0, 0);
        strip.show();
      }
    }
  
    else if(h <= 75) // 습도 50% ~ 75% 일 경우
    {
      if(t < 10)
      {
        strip.setPixelColor(0, 0, 0, 255); // 첫 번째 LED 파란색을 점등
        strip.setPixelColor(1, 0, 0, 255); // 두 번째 LED 파란색을 점등
        strip.setPixelColor(2, 0, 0, 255); // 세 번째 LED 파란색을 점등
        strip.show();
      }
      else if(t < 20)
      {
        strip.setPixelColor(0, 0, 255, 255);
        strip.setPixelColor(1, 0, 255, 255);
        strip.setPixelColor(2, 0, 255, 255);
        strip.show();
      }
      else if(t < 30)
      {
        strip.setPixelColor(0, 0, 255, 0);
        strip.setPixelColor(1, 0, 255, 0);
        strip.setPixelColor(2, 0, 255, 0);
        strip.show();
      }
      else if(t < 40)
      {
        strip.setPixelColor(0, 255, 255, 0);
        strip.setPixelColor(1, 255, 255, 0);
        strip.setPixelColor(2, 255, 255, 0);
        strip.show();
      }
      else if(t <50)
      {
        strip.setPixelColor(0, 255, 0, 0);
        strip.setPixelColor(1, 255, 0, 0);
        strip.setPixelColor(2, 255, 0, 0);
        strip.show();
      }
    }
  
  
     else if(h <= 100) // 습도 75% ~ 100%일 경우
    {
      if(t < 10)
      {
        strip.setPixelColor(0, 0, 0, 255); // 첫 번째 LED 파란색을 점등
        strip.setPixelColor(1, 0, 0, 255); // 두 번째 LED 파란색을 점등
        strip.setPixelColor(2, 0, 0, 255); // 세 번째 LED 파란색을 점등
        strip.setPixelColor(3, 0, 0, 255); // 네 번째 LED 파란색을 점등
        strip.show();
      }
      else if(t < 20)
      {
        strip.setPixelColor(0, 0, 255, 255);
        strip.setPixelColor(1, 0, 255, 255);
        strip.setPixelColor(2, 0, 255, 255);
        strip.setPixelColor(3, 0, 255, 255);
        strip.show();
      }
      else if(t < 30)
      {
        strip.setPixelColor(0, 0, 255, 0);
        strip.setPixelColor(1, 0, 255, 0);
        strip.setPixelColor(2, 0, 255, 0);
        strip.setPixelColor(3, 0, 255, 0);
        strip.show();
      }
      else if(t < 40)
      {
        strip.setPixelColor(0, 255, 255, 0);
        strip.setPixelColor(1, 255, 255, 0);
        strip.setPixelColor(2, 255, 255, 0);
        strip.setPixelColor(3, 255, 255, 0);
        strip.show();
      }
      else if(t <50)
      {
        strip.setPixelColor(0, 255, 0, 0);
        strip.setPixelColor(1, 255, 0, 0);
        strip.setPixelColor(2, 255, 0, 0);
        strip.setPixelColor(3, 255, 0, 0);
        strip.show();
      }
    }
    
    Serial.print("2초 뒤 다시 측정합니다.\n");
    
    delay(2000);
    strip.clear();
    strip.show();
  }
  ```

  

* 색 변환 모드

* 잠자기 모드

* 노래기능

추가적으로 필요한 센서

버튼

사운드 센서

uno 연결 단자  





만약 버튼을 누르면 모드 변경

초음파 센서를 이용해서 거리에 따라 LED 개수 변경

버튼을 누르면 모드 변경

색을 조금씩 변화시키면서 노래가 나오게 함