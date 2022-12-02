# include "keyPad.h"
#include <Arduino.h>


_startkeypad:: _startkeypad(const char **keyChar, const uint8_t* rowPin, const uint8_t* colPin, const uint8_t &nb_row, const uint8_t& nb_col) : //init list
{
    for(size_t r {}; r < nb_row; r++)
    {
        rowPins[r] = rowPin[r];
        pinMode(rowPins[r], INPUT_PULLUP);
        digitalWrite(rowPins[r], 1);
    }

    for(size_t c {}; c < nb_col; c++)
    {
       colPins[c] = colpin[c];
       pinMode(colPins[c], INPUT_PULLUP);
       digialWrite(colPins[c], 1);
    }

    for()
}

char _startkeypad:: detectkey()
/*the reason for this function detectkey(), just like the name implies is to detect the particular key that is pressed at a given time. 

1. since all pins are input and low, we can detect a particular keyChar when it is set high
2. that means we need to loop through the rows and the colomn to detect the pin state at each instace and Read the state of pin.
3. as such there should be a delay time before which the detected key would be (displayed). This function will be performed by getkey();
4. HOW THE HECK DO I DO ALL THIS
5. i need to use the digitalRead function
*/
{
    char result = '\0';
    for (size_t c = 0; c < nb_col; c++)
     {
        // pinMode(colPins[c], OUTPUT);
        digitalWrite(colPins[c], LOW);

        for(size_t r = 0; r< nb_row; r++)
        {  
            // pinMode(rowPins[r], INPUT_PULLUP);   
            if(digitalRead(rowPins[r], LOW)) 
             {
                result = keyChar [r][c];
             }
        }
    //   pinMode(colPins[c], INPUT);
    //   digitalWrite(colPins[r], HIGH);
     }
 return result;
}

  char _startkeypad::getKey()
  {
    char key = detectKey();
    delay(1000);

    if(detectKey() == key)
    {
        return key;
    }
    else
        return '\0';
  }