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
