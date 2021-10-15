//____________________________________________________________________________________________________________________________________________
// Written by Kevin L. Turner, previous contributions from Gar Waterman & Aaron Winder
// The Pennsylvania State University, Dept. of Biomedical Engineering
// https://github.com/KL-Turner
//____________________________________________________________________________________________________________________________________________
//
//   Purpose: Drive IOS IOSIOScamera exposure and dual color LED lighting given the input counter and modification switch between TTL pulses 
//            originating from LabIEW. The IOS IOSIOScamera trigger will serve as the switch for the Arduino. When the trial is over and there's a
//            temporary save-delay, a BK Precision 4017a Frequency Generator will immediately pick-up the 60 Hz flashing so that there is no
//            noticeable gap in stimuli to the animal.
//
//   Last Updated: 10/15/21
//____________________________________________________________________________________________________________________________________________

// Initializes pins to be represented by a variable (int <variable name> = <pin #>).
int blueLEDs = 3;             // blue LEDs output pin (4 T-Cube LED drivers attached to a BNC breakout board).
int greenLEDs = 5;           // green LEDs output pin (4 T-Cube LED drivers attached to a BNC breakout board).
int labviewTrialState = 7;    // Input from LabVIEW to indicate when data acquisition is running
int IOScam = 9;               // IOS camera output pin
int inputSource = 11;          // Waveform Generator - Square wave with adjustable frequency. Serves as the Input for times between trials.
int monitor = 13;             // For debugging/testing

// State variables.  See the void loop() function for a detailed explanation of each variable state's function.
int counterState = 0;
int prevCounterState = 0;
int prevBlueState = 0;
int prevGreenState = 0;
int trialState = 0; 
int prevTrialState = 0;

// The setup routine runs only once when the Arduino is turned on, sketch is uploaded to the board, or is reset.
void setup()
{
  pinMode(IOScam,OUTPUT);                // IOS camera (pin 9) as an Output
  pinMode(blueLEDs,OUTPUT);              // blue LEDs (pin 3) is an Output.
  pinMode(greenLEDs,OUTPUT);             // green LEDs (pin 12) is an Output
  pinMode(labviewTrialState,INPUT);      // LabVIEW trial state (pin 1) is an Input.
  pinMode(inputSource,INPUT);            // inputSource (pin 0) is an Input via the Waveform Generator.
  pinMode(monitor,OUTPUT);
}

// The loop routine runs continuously, i.e. functions are not simultaneous, they run in order.
void loop()
{
  trialState = digitalRead(labviewTrialState);  // Looks at the state of the trial, so that it knows where to acquire its input
  digitalWrite(monitor, trialState);            // For testing purposes
  if (trialState == HIGH)
  {
    inputSource = 10;
    if (prevTrialState == 0)
    {
      prevBlueState = 1;                        // Ensure that the first flash of every new trial is from green LEDs
      prevGreenState = 0;
    }
    prevTrialState = 1;
  }
  else
  {
    inputSource = 11;
    prevTrialState = 0;
  }
  counterState = digitalRead(inputSource);      // Reads state of counter pin and stores it in the 'counterState' variable
  if (counterState != prevCounterState)         // Checks if the counter state that was just read is different from previous
  {
    if (counterState == HIGH)                   
    {
      if (prevBlueState == 0) 
      {
        if (trialState == HIGH)                 // Only send pulse to IOScamera if the trial is running
        {
          digitalWrite(IOScam,HIGH);
        }
        else                                    // If trial is not running ensure only lows are sent to the IOS camera
        {
          digitalWrite(IOScam,LOW);
        }
        digitalWrite(blueLEDs,HIGH);           // Sending HIGH signal to blue LEDs regardless of trialState
        prevBlueState = 1;                      // Conforms the state variable of blue LEDs to what its state is (blue LEDs is HIGH, so state variable changed to 1)
        prevGreenState = 0;                     // Conforms the state variable of greenL EDs to what its state is (green LEDs is LOW, so state variable changed to 0)
      }
      else 
      {
        if (trialState == HIGH)
        {
          digitalWrite(IOScam,HIGH); 
        }
        else
        {
          digitalWrite(IOScam,LOW);
        }
        digitalWrite(greenLEDs,HIGH); 
        prevBlueState = 0;                      // Conforms the state variable of blue LEDs to what its state is (blue LEDs is LOW, so state variable changed to 0)
        prevGreenState = 1;                     // Conforms the state variable of green LEDs to what its state is (blue LEDs is HIGH, so state variable changed to 1)
      }      
       else 
      {
        if (trialState == HIGH)
        {
          digitalWrite(IOScam,HIGH); 
        }
        else
        {
          digitalWrite(IOScam,LOW);
        }
        digitalWrite(greenLEDs,HIGH); 
        prevBlueState = 0;                      // Conforms the state variable of blue LEDs to what its state is (blue LEDs is LOW, so state variable changed to 0)
        prevGreenState = 0;                     // Conforms the state variable of green LEDs to what its state is (blue LEDs is HIGH, so state variable changed to 1)
        Prev
      }      
    }
    else
    {
      if (trialState == HIGH)
      {
        digitalWrite(IOScam,LOW);
      }
      else
      {
        digitalWrite(IOScam,LOW); 
      }
      digitalWrite(blueLEDs,LOW); 
      digitalWrite(greenLEDs,LOW);  
    }
    prevCounterState = counterState;             // Stores the current state of the counter to the last counter state variable
  }
}
