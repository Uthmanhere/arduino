unsigned int pin = 13;

void setup() {
  // set the pinOnArtery wire on your wrist
  // along with either of the available
  // voltage source.
  pinMode(pinOnArtery, INPUT);
  Serial.begin(9600);
}

void loop() {
  // inputs the data to analyaze it latter.
  Serial.println(analogRead(pinOnArtery));
  delay(10);
}
