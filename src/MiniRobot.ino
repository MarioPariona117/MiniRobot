// #include<iostream>
#define trigPin1 5
#define echoPin1 4
#define trigPin2 7
#define echoPin2 6
#define trigPin3 12
#define echoPin3 11

long double duration, distance, RightSensor, BackSensor, FrontSensor, LeftSensor;

typedef long double ld;

void setup(){
    Serial.begin (9600);

    // left sensor
    pinMode(trigPin1, OUTPUT);
    pinMode(echoPin1, INPUT);
    // front sensor
    pinMode(trigPin2, OUTPUT);
    pinMode(echoPin2, INPUT);
    // right sensor
    pinMode(trigPin3, OUTPUT);
    pinMode(echoPin3, INPUT);
}

void loop() {
    // RightSensor = SonarSensor(trigPin1, echoPin1);;
    // LeftSensor = SonarSensor(trigPin2, echoPin2);;
    FrontSensor = SonarSensor(trigPin3, echoPin3);
    Serial.println(int(FrontSensor));
    // Serial.print(LeftSensor);
    // Serial.print(" - ");
    // Serial.print(FrontSensor);
    // Serial.print(" - ");
    // Serial.println(RightSensor);
}

ld SonarSensor(int trigPin,int echoPin){
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    ld duration = pulseIn(echoPin, HIGH);
    ld distance = (duration/2) / 29.1;
    return distance;
}