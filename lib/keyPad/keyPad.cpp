# include "keyPad.h"
#include <Arduino.h>


_startkeypad:: _startkeypad(char **keyChar, const uint8_t* rowPin, const uint8_t* colPin, const uint8_t &nb_row, const uint8_t& nb_col) 
: keyChar {keyChar}, rowPins {rowPin}, colPins {colPin}, nb_rows {nb_row}, nb_cols {nb_col}
{
        for(size_t r = 0; r < nb_row; r++)
        {
        rowPins[r] = rowPin[r];
        pinMode(rowPins[r], INPUT_PULLUP);
        digitalWrite(rowPins[r], 1);
        }
        for(size_t c {}; c < nb_col; c++)
        {
       colPins[c] = colPin[c];
       pinMode(colPins[c], INPUT_PULLUP);
       digitalWrite(colPins[c], 1);
        }
        
}

char _startkeypad:: detectKey()
{
    char result = '\0';
    for (size_t c = 0; c < nb_cols; c++)
     {
        // pinMode(colPins[c], OUTPUT);
        digitalWrite(colPins[c], LOW);

        for(size_t r = 0; r< nb_rows; r++)
        {  
            // pinMode(rowPins[r], INPUT_PULLUP);   
            if(digitalRead(!rowPins[r])) 
             {
                result = keyChar [r][c];
             }
             else 
             return result;
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