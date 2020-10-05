#include <Adafruit_NeoPixel.h>
#include <DHT.h>

#define LIGHTPIN 6
#define button1 2
#define DHTPIN 7
#define trig 8
#define echo 9
#define speakerPin 10

#define DHTTYPE DHT11

int count = 0;
int length = 15;

char notes[] = "ccggaag ffeeddc ggffeed ggffeed ccggaag ffeeddc "; 
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
int tempo = 300;

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone); // 길고 짧은 것을 통해 스피커의 장조 높낮이를 조절.
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) { // 스피커의 음계를 조절.
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
  
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}


DHT dht (DHTPIN, DHTTYPE); // dht 오브젝트를 만든다.
Adafruit_NeoPixel strip = Adafruit_NeoPixel(4, LIGHTPIN, NEO_GRB + NEO_KHZ800); // 네오픽셀의 오브젝트를 만든다.

void setup() {
  strip.begin(); //네오픽셀 초기화를 위해 모든 LED OFF
  strip.show(); // 초기값 적용. 모든 LED 꺼짐
  dht.begin(); // dht 센서를 사용하기 위한 시작.
  Serial.begin(9600);
  pinMode(button1, INPUT_PULLUP); // 3.3V 연결, 버튼 누르면 LOW로 떨어지는건지 확인.
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(speakerPin, OUTPUT);
  

  attachInterrupt(0, swInterrupt, FALLING);
}

void loop()
{
  
  
  if(count%3 == 0) // 온습도 센서 작동
  {
    float h = dht.readHumidity();
    float t = dht.readTemperature();

    // 오류 출력
    if (isnan(h) || isnan(t)) {
      Serial.println("Failed to read from DHT sensor!");
      return; // 수정 else 추가
    }
    Serial.print("온습도 모드 동작.\n");
    delay(2000);
//    Serial.print(count);
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
        strip.show(); // show 한번만 사용 가능
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
  else if(count%3 == 1) // 초음파 센서 작동 switch 문으로 가능
  {
    Serial.print("초음파 모드 작동\n");
    delay(2000);
    digitalWrite(trig, LOW);
    digitalWrite(echo, LOW); // input pin이므로 사용하지 않아도 됨
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
   
    unsigned long duration = pulseIn(echo, HIGH); // 트리거 - 에코 센서로 도달하는데 걸린 시간 ( 에코가 HIGH였던 시간을 계산
   
    // 초음파의 속도는 초당 340미터를 이동하거나, 29마이크로초 당 1센치를 이동합니다.
    // 따라서, 초음파의 이동 거리 = duration(왕복에 걸린시간) / 29 / 2 입니다.
    float distance = duration / 29.0 / 2.0;
    Serial.print(distance);
    Serial.println("cm");
    if (distance >= 100) // 멀리 있는 사람도 보여야 하므로 4개 다 킴
    {
      strip.setPixelColor(0, 255, 0, 0);
      strip.setPixelColor(1, 255, 0, 0);
      strip.setPixelColor(2, 255, 0, 0);
      strip.setPixelColor(3, 255, 0, 0);
      strip.setBrightness(255); // 밝기 최대
      strip.show();
    }
    else if (distance >= 50) // 50cm 중간 2개만 킴
    {
      strip.setPixelColor(0, 255, 0, 0);
      strip.setPixelColor(1, 255, 0, 0);
      strip.setBrightness(200);
      strip.show();
    }
    else if (distance >= 10) // 10cm 가까움 1개만 킴
    {
      strip.setPixelColor(0, 255, 0, 0);
      strip.setBrightness(100);
      strip.show();
    }
    else // 너무 가까움 부저로 경고음 출력
    {
      tone(speakerPin, 440, 2000);
    }
    Serial.print("종료\n 2초 후 다시 실행합니다.\n");
    
    delay(2000);
    strip.clear();
    strip.show();
  }
  else if(count%3 == 2)
  {
    Serial.print("음악 모드 작동");
    delay(2000);

    rainbowCycle(10); // 다양한 색 실행 함수
    
    for (int i = 0; i < length; i++) {
      if (notes[i] == ' ') {
        delay(beats[i] * tempo);
      }
      else {
        playNote(notes[i], beats[i] * tempo);
      }
      delay(tempo / 2); 
  }
  Serial.print("종료\n 2초 후 다시 실행합니다.\n");
    
    delay(2000);
    strip.clear();
    strip.show(); 
  }
}

void swInterrupt() {
  delayMicroseconds(2000);
  if(digitalRead(button1) != LOW) return;
  
  count ++;
}

void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { 
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//255가지의 색을 나타내는 함수
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
