int relay_pin = 3;

void setup() {
  pinMode(relay_pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int humidity = analogRead(A0);
  int humidity_percentage = map(humidity, 1023, 0, 0, 100);
  delay(100); // delay for sensor stabilization

  if (humidity_percentage > 30) {
    digitalWrite(relay_pin, HIGH); // water pump on
    Serial.println("Pump On");
  }else {
    digitalWrite(relay_pin, LOW); // water pump off
    Serial.println("Pump Off");
  }

  delay(10 * 60 * 1000); // program runs every 10 minutes
}