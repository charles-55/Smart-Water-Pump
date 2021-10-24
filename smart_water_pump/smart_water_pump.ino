//when the ultrasonic sensor detects that the water level is very low(which gives 3cm reading), the pump comes on;
//the leds are to show how full the water tank is;
const int trigPin=3; //assigns 'trig' of sensor to digitalPin 3
const int echoPin=4; //assigns 'echo' of sensor to digitalPin 4
int green = 6; //assigns gree terminal of led to digitalPin 6
int blue = 5; //assigns blue terminal of led to digitalPin 5
int red = 7; //assigns red terminal of led to digitalPin 7
int pumpcontrol = 8; //assigns the components controlling pump to digitalPin 8
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); //to set time rate for serial communication with board
  pinMode(trigPin, OUTPUT); //sets state of 'trigPin' to OUTPUT
  pinMode(echoPin, INPUT); //sets state of 'echoPin' to INPUT
pinMode(red, OUTPUT); //sets state of 'red' to OUTPUT
pinMode(green, OUTPUT);  //sets state of 'green' to OUTPUT
pinMode(blue, OUTPUT);  //sets state of 'blue' to OUTPUT
pinMode(pumpcontrol, OUTPUT);  //sets state of 'pumpcontrol' to OUTPUT
}

void loop() {
  // put your main code here, to run repeatedly:
long duration, distance; //declares 'duration' and 'distance' as number variables
  digitalWrite(trigPin, HIGH); //makes ultrasonic trigger to send out sound
  delayMicroseconds(10); //for ten microseconds
  digitalWrite(trigPin, LOW); //stops trigger signals
  duration = pulseIn(echoPin, HIGH); //duration now means the amount of time it takes for the echo to bounce back
  distance = (duration / 2) / 29.1; //calculates distance from duration using formula
  Serial.print(distance);  //prints distance to serial monitor 
  Serial.println("cm"); //prints 'cm' as value
  delay(200); //to set the distance to print only once every 200 microseconds (five times every second)
if (distance<=3){ //if the water is up to 3cm from the top of the bucket i.e. it is full
  //GREEN light comes on while all others remain off.
  digitalWrite(green, HIGH); 
  digitalWrite(blue, LOW);
  digitalWrite(red, LOW);
  digitalWrite(pumpcontrol, LOW);  //The pump stops pumping water.
  }
 
if ((distance>4)&&(distance<=6)){ //if the water is between 4cm and 6cm from the top of the bucket i.e. it is almost full
    //GREEN and BLUE lights come on together to give a 'cyan' or 'greenish-blue' colour while red remains off.
  digitalWrite(green, HIGH);
  digitalWrite(blue, HIGH);
  digitalWrite(red, LOW);
}
if ((distance>7)&&(distance<=11)){ //if the water is between 7cm and 11cm from the top of the bucket i.e. it is halfway full
    //BLUE light comes on while others remain off.
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);
  digitalWrite(red, LOW);}
if ((distance>12)&&(distance<=18)){ //if the water is between 12cm and 18m from the top of the bucket i.e. it is low
      //BLUE and RED lights come on together to give a 'magenta' or 'pinkish-purple' colour while green remains off.
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);
  digitalWrite(red, HIGH);
}
if(distance>19){ //if the water is more than 19cm from the top of the bucket i.e. it is empty or almost empty
  //RED light comes on while the others remain off.
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(red, HIGH);
  digitalWrite(pumpcontrol, HIGH);  //The pump begins to pump water until container is full.
}
}
