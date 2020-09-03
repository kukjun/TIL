int sound = A0;

void setup() {
  pinMode(sound, INPUT);
  Serial.begin(9600);
}

void loop() {
  delay(1000);
  int sensor = analogRead(sound);
  Serial.println(sensor);
}
