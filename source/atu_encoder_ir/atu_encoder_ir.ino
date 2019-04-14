/* 
Magnetic Antenna Tuner controlled by Arduino via encoder and IR Remote Control


By PU2CLR, 
Ricardo Lima Caratti
Jan, 2013
*/

#include <IRremote.h>
#include <Servo.h> 


#define GREEN_LED               3
#define YELLOW_LED              4
#define BLUE_LEFT_LED           7
#define BLUE_RIGHT_LED          5
#define IR_RECEIVER_PIN         6
#define SWITCH_ATU_FINE         8
#define SERVO_PIN               9
#define FINE_TUNE_LED          10

// Arduino IR remote control.
// See how you can know the code returned by your IR remote control on CheckYourRemoteControl
#define BT_RIGHT_PRESSED      2064      // right button keep pressed
#define BT_RIGHT_TOUCH          16      // right button single touch
#define BT_LEFT_PRESSED       2065      // left button keep pressed
#define BT_LEFT_TOUCH           17      // left button single touch
#define BT_UP_PRESSED         2080      // up button keep pressed
#define BT_UP_TOUCH             32      // up button single touch 
#define BT_DOWN_PRESSED       2081      // down button  keep pressed
#define BT_DOWN_TOUCH           33      // down button single touch
#define BT_ON_OFF_PRESSED     2060      // On/Off button keep pressed
#define BT_ON_OFF_TOUCH         12      // On/OFF button single touch
#define BT_AV_TV_PRESSED      2059      // AV/TV button keep pressed
#define BT_AV_TV_TOUCH          11      // AV/TV button sigle touch

IRrecv irrecv(IR_RECEIVER_PIN);
decode_results results;

// See you servo specification
#define MIN_PULSE    510
#define MAX_PULSE    2500
#define CENTER_PULSE (MIN_PULSE + (MAX_PULSE - MIN_PULSE) / 2)

// You might want modify this values depending on your servo and capacitor
#define FINE_TUNE_STEP     1
#define NORMAL_TUNE_STEP  15


int fineTune = 0;

int capacitorPosition = CENTER_PULSE;  // The capacitor starts on the center position;

int tuneStep = NORMAL_TUNE_STEP;       // The tune mode start in normal steps
int switchValue = 0;

unsigned long currentTime;

unsigned long loopTime;


const int pin_A = 12;  
const int pin_B = 11;  
unsigned char encoder_A;
unsigned char encoder_B;
unsigned char encoder_A_prev=0;


Servo  capacitor;
int increment = 0;


void setup()  {

  // declare output pins  
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(BLUE_LEFT_LED, OUTPUT);  
  pinMode(BLUE_RIGHT_LED, OUTPUT); 
  pinMode(FINE_TUNE_LED, OUTPUT); 
  pinMode(SERVO_PIN, OUTPUT);

  pinMode(SWITCH_ATU_FINE,INPUT);
  pinMode(pin_A, INPUT);
  pinMode(pin_B, INPUT);


  digitalWrite(FINE_TUNE_LED,LOW);

  currentTime = millis();
  loopTime = currentTime; 
  
  irrecv.enableIRIn();             // Start the IR receiver
  
  capacitor.attach(SERVO_PIN,MIN_PULSE,MAX_PULSE);   // attach the servo to the Arduino pin.   
  
  capacitor.writeMicroseconds( CENTER_PULSE );
  delay(1000);
 
} 


void switchTune() 
{
  fineTune = !fineTune;

  if (fineTune )  {
      digitalWrite(FINE_TUNE_LED, HIGH);
      tuneStep = FINE_TUNE_STEP;
  }
  else {
     digitalWrite(FINE_TUNE_LED, LOW);
     tuneStep = NORMAL_TUNE_STEP;
  } 

  delay(500);  
}      

void blink(int pin, int times) {
 int i;
  for (i = 0; i < times; i++ ) {
     digitalWrite(pin,HIGH);
     delay(15);
     digitalWrite(pin,LOW);
     delay(15);
  }
  digitalWrite(pin,LOW);  
}

void loop()  {
  
  
  increment = 0;
  
  // get the current elapsed time
  currentTime = millis();
  
  // check infrared
  if (irrecv.decode(&results)) {
    
    switch (results.value) {
      case BT_RIGHT_PRESSED:
      case BT_RIGHT_TOUCH:
           blink(BLUE_RIGHT_LED,1);
           increment = tuneStep;
           break;
      case BT_LEFT_PRESSED:
      case BT_LEFT_TOUCH:
           blink(BLUE_LEFT_LED,1);
           increment =  -tuneStep;
           break;
      case BT_UP_PRESSED:
      case BT_UP_TOUCH:
           increment = (tuneStep * -2);           
           break;
      case BT_DOWN_PRESSED:
      case BT_DOWN_TOUCH:   
           increment = (tuneStep * 2);   
           break; 
      case BT_ON_OFF_PRESSED:
      case BT_ON_OFF_TOUCH:
           capacitorPosition = CENTER_PULSE;     
           capacitor.writeMicroseconds( capacitorPosition );           
           break; 
      case BT_AV_TV_PRESSED:
      case BT_AV_TV_TOUCH:  
           switchTune(); 
           break;       
      default:
            break;
    }
    
    irrecv.resume();  // Ready to receive next value
  }
  else { // Check Encoder
    if(currentTime >= (loopTime + 5)) {
       // 5ms since last check of encoder = 200Hz  
       encoder_A = digitalRead(pin_A);    // Read encoder pins
       encoder_B = digitalRead(pin_B);   
       if((!encoder_A) && (encoder_A_prev)){
         // A has gone from high to low 
         if(encoder_B) {  
           // B is high so clockwise
           // increase the capacitorPosition, dont go over 255
           increment = tuneStep; 
           blink(BLUE_RIGHT_LED,1);
         }   
       else {
          // B is low so counter-clockwise      
          // decrease the capacitorPosition, dont go below 0
           increment = -tuneStep;    
           blink(BLUE_LEFT_LED,1);
        }   
      }   
      encoder_A_prev = encoder_A;     // Store value of A for next time    
      loopTime = currentTime;  // Updates loopTime
    }
    
  }
  
  if ( increment ) {
    capacitorPosition += increment;
    if ( capacitorPosition < MIN_PULSE) {
         blink(YELLOW_LED, 6);
         capacitorPosition = MIN_PULSE;
    }
    else if ( capacitorPosition > MAX_PULSE ) {
        blink(YELLOW_LED,6);
        capacitorPosition = MAX_PULSE;       
    }
    else {   
          digitalWrite(GREEN_LED, HIGH);
          capacitor.writeMicroseconds(capacitorPosition);
          delay(10);
          digitalWrite(GREEN_LED, LOW);
    }  
  }  
  
  
  // Other processing can be done here

  switchValue = digitalRead(SWITCH_ATU_FINE); 

  if ( switchValue == LOW) { 
     switchTune();
   } 
                           
}

