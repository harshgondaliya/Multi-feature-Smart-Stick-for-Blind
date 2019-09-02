#include <NewTone.h>
#include <IRremote.h>
#define trigPin 2
#define echoPin 3
int distanceBuzzer = 8 ;
int waterSensor = 0;
int waterFlag =0;
int irFlag = 0;
int waterBuzzer = 6;
int irBuzzer = 9;
int RECV_PIN = 11;
int last_flag=0;
long count=0;
int current_flag;
void ir_ring();
IRrecv irrecv(RECV_PIN);
decode_results results;

void ir_ring()
{
  digitalWrite(distanceBuzzer,LOW);
  const int songLength = 18;
  char notes[] = "cdfda ag cdfdg gf "; // a space represents a rest
  int beats[] = {1,1,1,1,1,1,4,4,2,1,1,1,1,1,1,4,4,2};
  int tempo = 150;  // Speed of tempo
  int i, duration;
  
  for (i = 0; i < songLength; i++) // step through the song arrays
  {
    if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
    }
    if (results.value==0xFF18E7){
      delay(100);
      break;
    }
    duration = beats[i] * tempo;  // length of note/rest in ms
    
    if (notes[i] == ' ')         // is this a rest? 
    {
      delay(duration);            // then pause for a moment
    }
    else                          // otherwise, play the note
    {
      NewTone(irBuzzer, frequency(notes[i]), duration);
      delay(duration);            // wait for tone to finish
    }
    delay(tempo/10);              // brief pause between notes
  }
}

int frequency(char note) 
{ 
  int i;
  const int numNotes = 8;      // number of notes we're storing
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};

  for (i = 0; i < numNotes; i++)   
  {
    if (names[i] == note)          
    {
      return(frequencies[i]);      
    }
  }
  return(0); 
}

void water_ring(){
    digitalWrite(waterBuzzer,HIGH);
    delay(100);
    digitalWrite(waterBuzzer,LOW);
    
}


void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(irBuzzer, OUTPUT);
  pinMode(waterSensor,INPUT);
  pinMode(waterBuzzer,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(distanceBuzzer,OUTPUT);
}

void loop() {  
  
  if (irrecv.decode(&results)) {
    count=count+1;
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value  
  }
  delay(500);
  if (count>=1){
  
  if (results.value!=0xFF18E7){
    irFlag=1;
     ir_ring(); 
  }
  else if(results.value != 0xFF9867){
    irFlag=0;
    analogWrite(irBuzzer,0);
  }
  else{
    irFlag=0;
  }
  }

  int waterSensorValue = analogRead(waterSensor);
  Serial.println(waterSensorValue); 
  if (waterSensorValue<=400){
    if (irFlag==0){
       water_ring();
       waterFlag=1;
    }
   else{
    analogWrite(waterBuzzer,0);
    waterFlag=0;
   }
  }
  else{
    analogWrite(waterBuzzer,0);
     waterFlag=0;
  }
  
  long distance,duration;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
// Calculating the distance
  distance= duration*0.034/2;
  Serial.println(distance);
  if (distance<=100){
    if (irFlag==0 && waterFlag==0){
      digitalWrite(distanceBuzzer,HIGH);
    }
    else{
      digitalWrite(distanceBuzzer,LOW);
    }
  }
  else{
    digitalWrite(distanceBuzzer,LOW);
  } 
}
