int dataPin = 11;        //Define which pins will be used for the Shift Register control
int latchPin = 8;
int clockPin = 12;
int s1 = 10;
int switchState = 0;

int stateA[3] = {0x1F,0xFF,0xF0}; //The array for storing the 
                        // byte #3 value
int stateC[3] = {0x7C,0xFF,0x87};  //The array for storing the 
                        // byte #2 value
int stateB[3] = {0x90,0x48,0x24};  //The array for storing the 
                        // byte #1 value

int stateD[3] = {0x1F,0xFF,0x0C}; //The array for storing the 
                        // byte #3 value
int stateF[3] = {0x1F,0xFF,0x0C};  //The array for storing the 
                        // byte #2 value
int stateE[3] = {0x90,0x48,0x24};  //The array for storing the 
                        // byte #1 value

void setup()
{
    pinMode(dataPin, OUTPUT);       //Configure each IO Pin
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(s1, INPUT_PULLUP);
}

void loop()
{
    switchState = digitalRead(s1);
    if (switchState == LOW) {
    
        for (int x = 0; x < 3; x++)         //Array Index
        {
        digitalWrite(latchPin, LOW);            //Pull latch LOW to start sending data
        shiftOut(dataPin, clockPin, LSBFIRST, stateC[x]);         //Send the data byte 1
        shiftOut(dataPin, clockPin, LSBFIRST, stateB[x]);         //Send the data byte 2
        shiftOut(dataPin, clockPin, LSBFIRST, stateA[x]);         //Send the data byte 3
        digitalWrite(latchPin, HIGH);           //Pull latch HIGH to stop sending data
        delay(3);
        }
    } else {

        for (int x = 0; x < 3; x++)         //Array Index
        {
        digitalWrite(latchPin, LOW);            //Pull latch LOW to start sending data
        shiftOut(dataPin, clockPin, MSBFIRST, stateF[x]);         //Send the data byte 1
        shiftOut(dataPin, clockPin, MSBFIRST, stateD[x]);         //Send the data byte 2
        shiftOut(dataPin, clockPin, MSBFIRST, stateE[x]);         //Send the data byte 3
        digitalWrite(latchPin, HIGH);           //Pull latch HIGH to stop sending data
        delay(3);
        }
    }    
}
