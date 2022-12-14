#include <Arduino.h>
#ifndef __KEYPAD__
#define __KEYPAD__

class _startkeypad
{
  public:
    _startkeypad() = default;
    _startkeypad(char **keyChar, const uint8_t* rowPin, const uint8_t* colPin, const uint8_t &nb_row, const uint8_t& nb_col); 

    char detectKey();
    char getKey();

    ~_startkeypad();

    char **keyChar;
    uint8_t *rowPins;
    uint8_t *colPins;
   
    // const int debounce = 10;
    // unsigned long timer = 0;
    // bool hold = 0;

   private:
    uint8_t nb_rows;
    uint8_t nb_cols;

   
};


#endif