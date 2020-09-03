int motion = 2;

void setup() {
  pinMode(motion, INPUT);
  Serial.begin(9600);
}

void loop() {
  delay(1000);
  int sensor = digitalRead(motion);
  Serial.println(sensor);
}
