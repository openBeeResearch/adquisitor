//Code for the QRE1113 Digital board
//Outputs via the serial terminal - Lower numbers mean more reflected
//3000 or more means nothing was reflected.

const int positions[2][25] = {
{22, 24, 26, 28, 37, 35, 33, 31, 49, 47, 45, 43, A0, A2, A4, A6, A8, A10, A12, A14, 53, 51, 10, 12, 41},
{23, 25, 27, 29, 36, 34, 32, 30, 48, 46, 44, 42, A1, A3, A5, A7, A9, A11, A13, A15, 52, 50, 11, 13, 40}
};

const int positionsAng[5] = {A15, A14, A13, A12, A11};
int n = 25;
int m = 5;
int i;
int k;
int Value; 

void setup(){
  Serial.begin(9600);
  
}


void loop(){
  
  Serial.print("S");

  Serial.print(",");


for (i = 0; i < n; i++){
  
      Value = readQD(positions[0][i]);    
      Serial.print(Value);
      Serial.print(","); 
      
      Value = readQD(positions[1][i]);    
      Serial.print(Value);
      Serial.print(",");
     
   }
   
 for (i = 0; i < m; i++){
      Value = analogRead(positionsAng[i])
      Serial.print(Value);
      Serial.print(",");
 
 }
    Serial.println();
 
  }
  



int readQD(int pin){
  //Returns value from the QRE1113 
  //Lower numbers mean more refleacive
  //More than 3000 means nothing was reflected.
  pinMode( pin, OUTPUT );
  digitalWrite( pin, HIGH );  
  delayMicroseconds(10);
  pinMode( pin, INPUT );

  long time = micros();

  //time how long the input is HIGH, but quit after 3ms as nothing happens after that
  while (digitalRead(pin) == HIGH && micros() - time < 3000); 
  int diff = micros() - time;

  return diff;
}
