#include "keyPad.h"
#include "LiquidCrystal.h"
#include "calculator.h"


_startkeypad smartPad (keChar, rowPins, colPins, nb_);
LiquidCrystal lcd (4, 5, 6, 7, 8, 9);
char keyChar [4][4]
{
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}

};

char keyPressed = smartPad.getKey();


char getchoice()
{
    char choice = '\0';
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("1.ADD   2.SUB");
    lcd.setCursor(0,1);
    lcd.print("3.MULT   4.DIV");
    delay(2000);

    if(keyPressed == keyChar[0][0] || keyPressed ==keyChar[0][1] || keyPressed ==keyChar[1][0] || keyPressed==keyChar[1][1])
    {
        choice = keyPressed;
    }
   return choice;
   
}

int doArithmetics(const char &choice)
{
    switch (_choice)
    {
    case keyPressed == keyChar[0][0] :
        doAddition();
        break;

    case keyPressed == keyChar[0][1] :
        doSubtraction();
        break;
    
    case keyPressed == keyChar[1][0] :
        doMultiplication();
        break;
    
    case keyPressed == keyChar[1][0] :
        doDivision();
        break;
    
    
    default:
        lcd.print("TRY AGAIN");
        break;
    }
    
}

char &checkOperator()
{
   static char _operator = smartPad.getKey();

    switch (_operator)
    {
        case '+':
        lcd.print('+');
        return (_operator);
        delay(1000);
        break;
        
        case '-':
        lcd.print('-');
        return (_operator);
        delay(1000);
        break;

         case '*':
        lcd.print('*');
        return (_operator);
        delay(1000);
        break;

         case '/':
        lcd.print('/');
        return (_operator);
        delay(1000);
        break;

        default: 
        lcd.print("SYNTAX ERROR");
        return ('\0');
        delay(1000);
        

         
    }
}

long doAddition()
{
    int answer;
    int16_t getValue;
    lcd.setCursor(1, 15);
    char getchoice();
    
    for (size_t v { }; v < 17; v++)
    {
      getValue = uint16_t (keyPressed);
      char num1 = getValue; 
        lcd.print(num1);
        delay(1000);
        checkOperator();
        char num2 = getValue;
        lcd.print(num2);
        delay(1000);
        checkOperator();


        if (keyPressed == '=')
        {
            answer = (num1 + num2);
            lcd.print(answer);
            delay(1000);
        
        }

    }
 lcd.clear();
 lcd.setCursor(1, 15);  
}

