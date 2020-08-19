#define trigPin 13
#define echoPin 12
void setup()
{
    Serial.begin (9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}
void loop()
{
    long duration, distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);

    distance = duration * 17 / 1000;
    // 초속 340mm이므로

    if (distance >= 200 || distance <= 0)
    {
        Serial.println("거리를 측정할 수 없음");
    }
    else
    {
        Serial.pint(distance);
        Serial.println(" cm");
    }
    delay(500);
}