//initial set up for the distance sensor 
void Distance::setup()
{
pinMode(triggerpin, OUTPUT); 
pinMode(echopin, INPUT);
float duration, distance; 
int distance = 0; 
}

void Distance::getDistance()
{
  
}
//trigger pin set up to read 
void Distance::setuptriggerpin()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
}
//measure distance function
int Distance::measure()
{
  duration = pulseIn(echoPin, HIGH); //in seconds
  if (duration != 0) 
  {
    distance = (duration*.0343)/2; 
  }
  return distance; 
}

 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
