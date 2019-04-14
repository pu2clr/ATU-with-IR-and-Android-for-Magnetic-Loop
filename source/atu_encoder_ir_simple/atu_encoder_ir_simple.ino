
/* 
Magnetic Antenna Tuner controlled by Arduino via encoder and IR Remote Control
Similar to atu_encoder_ir.ino without LED indicators

By PU2CLR, 
Ricardo Lima Caratti
Jan, 2013
*/

#include <IRremote.h>
#include <Servo.h> 



#define IR_RECEIVER_PIN         6
#define SERVO_PIN               9

// Arduino IR remote control
// This constants depends of your remote control
// Debug it using Serial functions (Serial.println) and serial monitor to verify the values of your remote control.
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

#define MIN_PULSE    510
#define MAX_PULSE    2500
#define CENTER_PULSE (MIN_PULSE + (MAX_PULSE - MIN_PULSE) / 2)

#define FINE_TUNE_STEP     1
#define NORMAL_TUNE_STEP  10


int capacitorPosition = CENTER_PULSE;  // The capacitor starts in the center position;

int tuneStep = NORMAL_TUNE_STEP;       // The tune mode start in normal steps


Servo  capacitor;
int increment = 0;


void setup()  {

  // declare output pins  
  pinMode(SERVO_PIN, OUTPUT);

  irrecv.enableIRIn();             // enable IR reading  
  
  capacitor.attach(SERVO_PIN,MIN_PULSE,MAX_PULSE);   // attaches the servo   
  
  capacitor.writeMicroseconds( CENTER_PULSE );
  delay(1000);
  
  // Serial.begin (9600);
} 


void loop()  {
  
  
  increment = 0;
  
  
  // check infrared
  if (irrecv.decode(&results)) {
    // Serial.println(results.value);
    switch (results.value) {
      case BT_RIGHT_PRESSED:
      case BT_RIGHT_TOUCH:
           increment = tuneStep;
           break;
      case BT_LEFT_PRESSED:
      case BT_LEFT_TOUCH:
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
           break;       
      default:
            break;
    }
    
    irrecv.resume();  // Recebe o proximo valor
  }
  
  if ( increment ) {
    capacitorPosition += increment;
    if ( capacitorPosition < MIN_PULSE) {
         capacitorPosition = MIN_PULSE;
    }
    else if ( capacitorPosition > MAX_PULSE ) {
        capacitorPosition = MAX_PULSE;       
    }
    else {   
          capacitor.writeMicroseconds(capacitorPosition);
          delay(10);
    }  
  }  
                          
}

