#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <stdlib.h>
#include <Servo.h>

Servo servo;
LiquidCrystal_I2C lcd(0x27,16,2);

int cur_hour, cur_minute, cur_second, count, amount =0;
int next_hour, next_minute, next_second = 0;
int left_hour, left_minute, left_second = 0;

const int setTimepin = A0;

int sensorValue = 0;
int button = 13;
int button2 = 10;
int flag, flag2, flag3 = 0;

int PLAYE = 9;  //재생 9번
int REC = 8;  // 녹음 8번


int returnTime()
{
  if (cur_second == 60) 
  {   
    cur_second = 0;
    cur_minute += 1;
  }

  if (cur_minute == 60)
  {
    cur_minute = 0;
    cur_hour += 1;
  }

  cur_second += 1;

  return cur_hour,cur_minute,cur_second;
}


int setNextHour(int value)
{
  next_hour = map(value, 0, 1000, 0, 8); 
  
  return next_hour;
}


int setNextMinute(int value)
{
  next_minute = map(value, 0, 1000, 0, 59);
  if (next_minute == 60)
  {
    next_minute = 59;
  }
  
  return next_minute;
}

int setNextSecond(int value)
{
  next_second = map(value, 0, 1000, 0, 59);

  if (next_second == 60)
  {
    next_second = 59;
  }

  return next_second;
}

int setAmount(int value)
{
  int lower_amount = map(value, 0, 1000, 1,20);
  amount = lower_amount*10;

  return amount;
}

void flag3_2(int sensorValue)
{
  lcd.clear();
  lcd.print("set meal's");
  lcd.setCursor(0, 1);
  lcd.print("Amount :");

  amount = setAmount(sensorValue);

  lcd.print(amount);
  lcd.print("g");
}

void flag_1()
{
  lcd.clear();
  lcd.print("Give right now?");

  if (flag2 == 1)
  {
    timeToMeal();
    flag2 = 0;
  } 
}

void flag_2(int sensorValue)
{
  lcd.clear();
  lcd.print("set Next Hour :");
  lcd.setCursor(0, 1);

  
  next_hour = setNextHour(sensorValue);

  lcd.print(next_hour);
  lcd.print("H 0M 0S");
}

void flag_3(int sensorValue)
{
  lcd.clear();
  lcd.print("set Next Minute :");
  lcd.setCursor(0, 1);

  next_minute = setNextMinute(sensorValue);
  lcd.print(next_hour);
  lcd.print("H ");
  lcd.print(next_minute);
  lcd.print("M 0S");
}


void flag_4(int sensorValue)
{
  lcd.clear();
  lcd.print("set Next second");
  lcd.setCursor(0, 1);

  next_second = setNextSecond(sensorValue);

  lcd.print(next_hour);
  lcd.print("H ");
  lcd.print(next_minute);
  lcd.print("M ");
  lcd.print(next_second);
  lcd.print("S");
}


void flag_5()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("left Time is");
  lcd.setCursor(0, 1);

  cur_hour, cur_minute, cur_second = returnTime();
  int left_hour = next_hour - cur_hour;
  int left_minute = next_minute - cur_minute;
  int left_second = next_second - cur_second;


  if (left_second < 0)
  {
    left_second = 60 + left_second;
    left_minute = left_minute - 1;
  }

  if (left_minute < 0)
  {
    left_minute = 60 + left_minute;
    left_hour = left_hour - 1;
  }
  
  lcd.print(left_hour);
  lcd.print("H ");

  lcd.print(left_minute);
  lcd.print("M ");

  lcd.print(left_second);
  lcd.print("S ");

  if ((left_hour == 0) && (left_minute == 0) && (left_second == 0))
  {
    timeToMeal();

    cur_hour = 0;
    cur_minute = 0;
    cur_second = 0;
    count = 0;

  }

  Serial.print(left_hour);
  Serial.print(",");
  Serial.print(left_minute);
  Serial.print(",");
  Serial.print(left_second);
  Serial.println(",");
  
}


void timeToMeal()
{
  lcd.clear();
  lcd.print("It's time");
  lcd.setCursor(0, 1);
  lcd.print("to meal");

  for (int i =0; i < 2; i++)
  {
    lcd.noDisplay();
    delay(500);
    lcd.display();
    delay(500);
  }
  play();
  moveMotor();
}

void play()
{
  digitalWrite(PLAYE,HIGH);
  delay(10);
  digitalWrite(PLAYE,LOW);
}

void rec()
{
  digitalWrite(REC,HIGH);
  delay(3000);
  digitalWrite(REC,LOW);
}

void moveMotor()
{
  for (int i=0; i<71; i++)
  {
    servo.write(i);
    delay(10);
  }

  delay((amount/20)*1000);

  for (int i=70; i>-1; i--)
  {
    servo.write(i);
    delay(10);
  }
}

void setup()
{
  lcd.init();
  lcd.backlight();
  pinMode(button, INPUT);
  pinMode(button2, INPUT);

  servo.attach(5);
  servo.write(0);

  Serial.begin(9600);
}


void loop()
{
  bool button_1 = digitalRead(button);
  bool button_2 = digitalRead(button2); 

  sensorValue = analogRead(setTimepin);

  if (button_1 == HIGH)
  {
    flag += 1;
  }

  if (button_2 == HIGH)
  {
    flag2 = 1;
    flag3 += 1;
  }

  switch (flag) 
  {
    case 1:
        flag_1();
        break;
    case 2:
        flag_2(sensorValue);
        break;
    case 3:
        flag_3(sensorValue);
        break;
    case 4:
        flag_4(sensorValue);
        break;
    case 5:
        flag_5();
        break;
    case 6:
        flag = 1;
        break;
  }

  switch (flag3) 
  {
    case 2:
        flag3_2(sensorValue);
        break;
    case 3:
        lcd.clear();
        lcd.print("Amount is ");
        lcd.print(amount);
        lcd.print("g");

        Serial.print(amount);
        Serial.println(",88,88,");

        for (int i =0; i < 2; i++)
        {
          lcd.noDisplay();
          delay(500);
          lcd.display();
          delay(500);
        }

        flag3 = 0;
        break;
  }
  
  // Serial connect 
  if (Serial.available() > 0)
  {
    String input = Serial.readStringUntil('\n');
    if (input.equals("right now"))
    { 
      flag = 0;  

      cur_hour, cur_minute, cur_second= 0;
      left_hour, left_minute, left_second = 0;

      Serial.print(left_hour);
      Serial.print(",");
      Serial.print(left_minute);
      Serial.print(",");
      Serial.print(left_second);
      Serial.print(",");

      timeToMeal();

      flag = 5;
      
    }
    else if (input.equals("rec"))
    {
      digitalWrite(REC,HIGH);
      delay(3000);
      digitalWrite(REC,LOW);
    }
    else if (input.equals("play"))
    {
      digitalWrite(PLAYE,HIGH);
      delay(10);
      digitalWrite(PLAYE,LOW);
    }
    else if (input.equals("reset"))
    {
      flag = 0;
      
      cur_hour, cur_minute, cur_second= 0;
      left_hour, left_minute, left_second = 0;

      Serial.print(left_hour);
      Serial.print(",");
      Serial.print(left_minute);
      Serial.print(",");
      Serial.print(left_second);
      Serial.print(",");
      Serial.print("reset");
      Serial.println(",");
    }
    else if (input.length() <= 3) 
    {
      amount = input.toInt();
      flag3 = 3;
    }
    else
    { 
      if (flag != 5)
      {
        next_hour = input.substring(0,input.indexOf('H')).toInt();
        next_minute = input.substring(input.indexOf('H') + 1, input.indexOf('M')).toInt();
        next_second = input.substring(input.indexOf('M') + 1, input.indexOf('S')).toInt();
        
        flag = 5;
      }
      //aaa
      else if (flag == 5)
      {
        Serial.println("99,99,99,");
        flag = 0;
      }
            
    }
  }

  lcd.display();
  delay(1000);
}
