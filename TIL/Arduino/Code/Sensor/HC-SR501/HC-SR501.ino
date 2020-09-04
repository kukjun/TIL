int people = 2;

void setup() {
  pinMode(people, INPUT);
  Serial.begin(9600);
}

void loop() {
  delay(1000);
  int sensor = anRead(people);
  Serial.println(sensor);
}
