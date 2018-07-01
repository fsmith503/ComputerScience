/* 
 Franklin Smith Arduino LED Program
 Visit http://www.arduino.cc to learn about the Arduino.
 Version 2.0 6/2012 MDG
 */
int LEDR1 = 13;
int LEDR2 = 12;
int LEDR3 = 11;
int LEDR4 = 10;
int LEDR5 = 9;
int LEDL6 = 8;
int LEDL5 = 7;
int LEDL4 = 6;
int LEDL3 = 5;
int LEDL2 = 4;
int LEDL1 = 3;
int loopspeed = 1;

//int rand () {
//   //int i, n;
//   //int time_t = t;
//   //n = 1;
//   /* Intializes random number generator */
//   //srand((unsigned) time(&t));
//   int result = ("%d\n", rand() % 12);
//   //return(result);
//     selectors [11] = {LEDR1, LEDR2, LEDR3, LEDR4, LEDR5, LEDL6, LEDL5, LEDL4, LEDL3, LEDL2, LEDL1};
//   return(selectors[result]);
//  
//}

void setup()
{
  pinMode(LEDR1, OUTPUT);
  pinMode(LEDR2, OUTPUT);
  pinMode(LEDR3, OUTPUT);  
  pinMode(LEDR4, OUTPUT);
  pinMode(LEDR5, OUTPUT);
  pinMode(LEDL6, OUTPUT);
  pinMode(LEDL5, OUTPUT);
  pinMode(LEDL4, OUTPUT);  
  pinMode(LEDL3, OUTPUT);
  pinMode(LEDL2, OUTPUT);
  pinMode(LEDL1, OUTPUT);
 }

void loop()
{
  if(loopspeed > 1000){
      loopspeed = 0;
  }
  loopspeed = loopspeed + 1;
  digitalWrite(LEDR1, HIGH);   // Turn on the LED
  delay(loopspeed);              // Wait for one second
  digitalWrite(LEDR2, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR3, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR4, HIGH);   // Turn on the LED
  delay(loopspeed);              // Wait for one second
  digitalWrite(LEDR5, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL6, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL5, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL4, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL3, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL2, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL1, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR1, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR2, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR3, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR4, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR5, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL6, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL5, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL4, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL3, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL2, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL1, LOW);    // Turn off the LED

  digitalWrite(LEDL1, HIGH);   // Turn on the LED
  delay(loopspeed);              // Wait for one second
  digitalWrite(LEDL2, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL3, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL4, HIGH);   // Turn on the LED
  delay(loopspeed);              // Wait for one second
  digitalWrite(LEDL5, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL6, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR5, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR4, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR3, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR2, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR1, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL1, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL2, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL3, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL4, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL5, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL6, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR5, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR4, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR3, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR2, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR1, LOW);    // Turn off the LED

  for (int i = 0; i < 10; i++){
  digitalWrite(LEDL6, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR5, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR1, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL1, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL6, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR5, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR1, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL1, LOW);    // Turn off the LED  
  delay(loopspeed);
  }

  digitalWrite(LEDR1, HIGH);   // Turn on the LED
  delay(loopspeed);              // Wait for one second
  digitalWrite(LEDL1, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR2, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL2, HIGH);   // Turn on the LED
  delay(loopspeed);              // Wait for one second
  digitalWrite(LEDR3, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL3, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR4, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL4, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR5, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL5, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL6, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR1, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL1, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR2, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL2, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR3, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL3, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR4, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL4, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR5, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL5, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL6, LOW);    // Turn off the LED
  delay(loopspeed);

  for (int i = 0; i < 10; i++){
  digitalWrite(LEDL6, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR5, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL6, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR5, LOW);    // Turn off the LED  
  delay(loopspeed);
  }

  digitalWrite(LEDL6, HIGH);   // Turn on the LED
  delay(loopspeed);              // Wait for one second
  digitalWrite(LEDR5, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL5, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR4, HIGH);   // Turn on the LED
  delay(loopspeed);              // Wait for one second
  digitalWrite(LEDL4, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR3, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL3, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR2, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL2, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR1, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL1, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL6, LOW);   // Turn on the LED
  delay(loopspeed);              // Wait for one second
  digitalWrite(LEDR5, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL5, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR4, LOW);   // Turn on the LED
  delay(loopspeed);              // Wait for one second
  digitalWrite(LEDL4, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR3, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL3, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR2, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL2, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR1, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL1, LOW);    // Turn off the LED  
  delay(loopspeed);
  for (int i = 0; i < 10; i++){
  digitalWrite(LEDR1, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL1, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR1, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL1, LOW);    // Turn off the LED  
  delay(loopspeed);
  }

  //for (int i = 0; i < 10; i++){
  digitalWrite(LEDR1, HIGH);   // Turn on the LED
  delay(loopspeed);              // Wait for one second
  digitalWrite(LEDR1, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR2, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR2, LOW);   // Turn on the LED
  delay(loopspeed);              // Wait for one second
  digitalWrite(LEDR3, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR3, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR4, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR4, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR5, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR5, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL6, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL6, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL5, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL5, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL4, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL4, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL3, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL3, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL2, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL2, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL1, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL1, LOW);    // Turn off the LED 
  delay(loopspeed);
  digitalWrite(LEDL1, HIGH);   // Turn on the LED
  delay(loopspeed);              // Wait for one second
  digitalWrite(LEDL1, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL2, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL2, LOW);   // Turn on the LED
  delay(loopspeed);              // Wait for one second
  digitalWrite(LEDL3, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL3, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL4, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL4, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL5, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL5, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL6, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDL6, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR5, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR5, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR4, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR4, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR3, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR3, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR2, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR2, LOW);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR1, HIGH);    // Turn off the LED  
  delay(loopspeed);
  digitalWrite(LEDR1, LOW);    // Turn off the LED
  //}

  
  delay(0);// Wait for one second
}

/* 
 / Try changing the 1000 in the above delay() functions to
 / different numbers and see how it affects the timing. Smaller
 / values will make the loop run faster. 
 /   * Decrease the delay to 10 ms. Can you still see it blink?
 /         Find the smallest delay that you can still see a blink. What is this frequency?
 /   * Modify the code above to resemble a heartbeat.  
 */
