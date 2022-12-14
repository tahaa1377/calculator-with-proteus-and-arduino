#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
{'7','8','9', '/'},
{'4','5','6','x'},
{'1','2','3','-'},
{'*','0','=','+'}
};
byte rowPins[ROWS] = {13, 12, 11, 10}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7, 6}; //connect to the column pinouts of the keypad

int a=0,b=0,a_digit=1,b_digit=1;
bool turn_first=true;
char ope='=';

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int KeyCheck = 0;

void setup()
{
Serial.begin(9600);

}

  void hesab(){
    if(ope == '+'){
      Serial.print(a + b);
    }else if(ope == '-'){
      Serial.print(a - b);
    }else if(ope == '/'){
      Serial.print(a / b);
    }else if(ope == '*'){
      Serial.print(a * b);
    }
    
  }

  void calc(int x){
    
    if(turn_first){
        a=a*a_digit;
        a+=x;
        a_digit*=10;
    }else{
        b+=b*b_digit;
        b+=x;
        b_digit*=10;
    }
    
  }

void loop()
{


char key = keypad.getKey();

if (key)
{
if(key == '1'){KeyCheck = 1; Serial.print("1");

calc(1);
}


if(key == '2'){KeyCheck = 1; Serial.print("2");
calc(2);
}
if(key == '3'){KeyCheck = 1; Serial.print("3");
calc(3);
}

if(key == '4'){KeyCheck = 1; Serial.print("4");
calc(4);
}
if(key == '5'){KeyCheck = 1; Serial.print("5");
calc(5);
}
if(key == '6'){KeyCheck = 1; Serial.print("6");
calc(6);
}

if(key == '7'){KeyCheck = 1; Serial.print("7");
calc(7);
}
if(key == '8'){KeyCheck = 1; Serial.print("8");
calc(8);
}
if(key == '9'){KeyCheck = 1; Serial.print("9");
calc(9);
}

if(key == '0'){KeyCheck = 1; Serial.print("0");
calc(0);
}

if(key == '='){
     Serial.print("=");
  KeyCheck = 1;
 hesab();
  }

  if(key == 'x'){
       Serial.print("*");
  KeyCheck = 1;
  turn_first=false;
  ope = '*';
  }

  if(key == '+'){
  KeyCheck = 1;
   Serial.print("+");
  turn_first=false;
    ope = '+';
  }

    if(key == '-'){
  KeyCheck = 1;
     Serial.print("-");
  turn_first=false;
    ope = '-';
  }

    if(key == '/'){
         Serial.print("/");
  KeyCheck = 1;
  turn_first=false;
    ope = '/';

  }

if(KeyCheck == 0){Serial.print(key);}
KeyCheck = 0;
}

}
