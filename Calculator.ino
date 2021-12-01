//Download and add Libraries
#include <LiquidCrystal.h>
#include <Keypad.h>

const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns

// Define the Keymap
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {7 , 6 , 5 , 4};
byte colPins[COLS] = {3 , 2 , 1 , 0};

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

long Num1, Num2, Number;
char key, action;
boolean result = false;

void setup() {
  lcd.begin(16, 2); //We are using a 16*2 LCD display
  lcd.print("Welcome to"); //Display a intro message
  lcd.setCursor(0, 1);   // set the cursor to column 0, row 1
  lcd.print("TechIO"); //Display a intro message

  delay(2000); //Wait so the display can show info
  lcd.clear(); //Then clean it
}

void loop() {

  key = kpd.getKey(); //storing pressed key value in a char

  if (key != NO_KEY)
    DetectButtons();

  if (result == true)
    CalculateResult();

  DisplayResult();
}

void DetectButtons()
{
  lcd.clear(); //Then clean it
  if (key == '*') //If cancel Button is pressed
  {
    Number = Num1 = Num2 = 0;
    result = false;
  }

  if (key == '1') //If Button 1 is pressed
  { 
    if (Number == 0)
      Number = 1;
    else
      Number = (Number * 10) + 1; //Pressed twice
  }

  if (key == '4') //If Button 4 is pressed
  { 
    if (Number == 0)
      Number = 4;
    else
      Number = (Number * 10) + 4; //Pressed twice
  }

  if (key == '7') //If Button 7 is pressed
  { 
    if (Number == 0)
      Number = 7;
    else
      Number = (Number * 10) + 7; //Pressed twice
  }


  if (key == '0') //Button 0 is Pressed
  { 
    if (Number == 0)
      Number = 0;
    else
      Number = (Number * 10) + 0; //Pressed twice
  }

  if (key == '2') //Button 2 is Pressed
  { 
    if (Number == 0)
      Number = 2;
    else
      Number = (Number * 10) + 2; //Pressed twice
  }

  if (key == '5') //Button 5 is Pressed
  {
    if (Number == 0)
      Number = 5;
    else
      Number = (Number * 10) + 5; //Pressed twice
  }

  if (key == '8') //Button 8 is Pressed
  { 
    if (Number == 0)
      Number = 8;
    else
      Number = (Number * 10) + 8; //Pressed twice
  }


  if (key == '#') //Button # is Pressed
  { 
    Num2 = Number;
    result = true;
  }

  if (key == '3') //Button 3 is Pressed
  { 
    if (Number == 0)
      Number = 3;
    else
      Number = (Number * 10) + 3; //Pressed twice
  }

  if (key == '6') //Button 6 is Pressed
  { 
    if (Number == 0)
      Number = 6;
    else
      Number = (Number * 10) + 6; //Pressed twice
  }

  if (key == '9') //Button 9 is Pressed
  { 
    if (Number == 0)
      Number = 9;
    else
      Number = (Number * 10) + 9; //Pressed twice
  }

  if (key == 'A' || key == 'B' || key == 'C' || key == 'D') //Detecting Buttons on Column 4
  {
    Num1 = Number;
    Number = 0;
    if (key == 'A')
    {
      Serial.println ("Addition");
      action = '+';
    }
    if (key == 'B')
    {
      Serial.println ("Subtraction");
      action = '-';
    }
    if (key == 'C')
    {
      Serial.println ("Multiplication");
      action = '*';
    }
    if (key == 'D')
    {
      Serial.println ("Division");
      action = '/';
    }

    delay(100);
  }

}

void CalculateResult()
{
  if (action == '+')
    Number = Num1 + Num2;

  if (action == '-')
    Number = Num1 - Num2;

  if (action == '*')
    Number = Num1 * Num2;

  if (action == '/')
    Number = Num1 / Num2;
}

void DisplayResult()
{
  lcd.setCursor(0, 0);   // set the cursor to column 0, row 0
  lcd.print(Num1);
  lcd.print(action);
  lcd.print(Num2);

  if (result == true)
  {
    lcd.print(" =");  //Display the result
    lcd.print(Number);
  }

  lcd.setCursor(0, 1);   // set the cursor to column 0, row 1
  lcd.print(Number); //Display the result
}
