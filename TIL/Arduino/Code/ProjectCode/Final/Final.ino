#include <Adafruit_NeoPixel.h>

#define neo_pin 6
#define button1_pin 2
#define button2_pin 3
boolean bLedOn = false

Adafruit_NeoPixel strip = Adafruit_NeoPixel(4, neo_pin, NEO_GRB + NEO_KHZ800);


void setup() {
  strip.begin(); //네오픽셀 초기화를 위해 모든 LED OFF
  strip.show(); // 초기값 적용. 모든 LED 꺼짐
  Serial.begin(9600);
  pinMode(button1_pin, INPUT_PULLUP);
  pinMode(button2_pin, INPUT_PULLUP);

  attachInterrupt(0, swIntertupt, CHANGE)
  attachInterrupt(1, 
    
}

void loop() {
  bool button1_pressed = false
  bool buttonInput_prev = false
  int count = 0;
  if (count == 0)
  {
    // LED 상태 1
     while (button1_pressed == false)
    {
      int buttonInput = digitalRead(button1_pin)
      if(buttonInput != buttonInput_prev)
      {
        button_pressing = true
        while
      }
    } 
  }
}

void BUTTON()
{
  if(digitalRead(button1_pin) == LOW)
  {
    if(Falg==0)
    {
      Flag = 1;
      Serial.println("\t\tPUSHED");;
      count++;
    }
    else
    {
      
    }
  }
  else
  {
    Flag =0;
    Serial.println("\t\t NO PUSHED");
  }
  
}
