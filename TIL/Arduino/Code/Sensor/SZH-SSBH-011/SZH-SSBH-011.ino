int light = A0;

void setup() {
  pinMode(light, INPUT);
  Serial.begin(9600);
}

void loop() {
  delay(1000);
  int sensor = analogRead(light);
  Serial.println(sensor);
}
