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
  Serial.println("test Code.");
  
}

void loop() {
  delay(1000);

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

  if(h<50)
  {
   
  }
}
