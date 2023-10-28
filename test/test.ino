#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <stdlib.h>
#include <Servo.h>

Servo servo;
LiquidCrystal_I2C lcd(0x27,16,2);

int cur_hour, cur_minute, cur_second, amount = 0;
int next_hour, next_minute, next_second = 0;
int left_hour, left_minute, left_second = 0;
int amount_flag, time_flag, flag = 0;

const int changeValuepin = A2;

int sensorValue = 0;

int ok_btn = A0;
int mode_btn = A1;
int ok_num, mode_num = 0;

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


int isOkPressed()
{
  bool ok_flag = digitalRead(ok_btn);

  if (ok_flag == HIGH)
  {
    return true;
  }
  return false;
}


int giveRightNow()
{
  left_hour, left_minute, left_second = 0;
  cur_hour, cur_minute, cur_second= 0;

  timeToMeal();
}

int setNextHour(int sensorValue)
{
  lcd.clear();
  lcd.print("set Next Hour :");
  lcd.setCursor(0, 1);

  next_hour = map(sensorValue, 0, 1000, 0, 8);

  lcd.print(next_hour);
  lcd.print("H 0M 0S");

  return isOkPressed();
}

int setNextMinute(int sensorValue)
{
  lcd.clear();
  lcd.print("set Next Minute :");
  lcd.setCursor(0, 1);

  next_minute = map(sensorValue, 0, 1000, 0, 59);
  if (next_minute == 60)
  {
    next_minute = 59;
  }

  lcd.print(next_hour);
  lcd.print("H ");
  lcd.print(next_minute);
  lcd.print("M 0S");

  return isOkPressed();
}


int setNextSecond(int sensorValue)
{
  lcd.clear();
  lcd.print("set Next second");
  lcd.setCursor(0, 1);

  next_second = map(sensorValue, 0, 1000, 0, 59);

  if (next_second == 60)
  {
    next_second = 59;
  }

  lcd.print(next_hour);
  lcd.print("H ");
  lcd.print(next_minute);
  lcd.print("M ");
  lcd.print(next_second);
  lcd.print("S");

  return isOkPressed();
}

int setMealTime(int sensorValue)
{
  if (setNextHour(sensorValue))
  {
    flag = 1;

    return false;
  }
  
  else if (flag == 1) 
  {
    if (setNextMinute(sensorValue))
    {
      flag = 2;
    }

    return false;
  }

  else 
  {
    bool setnextsecond = setNextSecond(sensorValue);
    if(setnextsecond)
    {
      flag = 0;
    }
    return setnextsecond;

  }
}

void getLeftTime()
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

  }

  Serial.print(left_hour);
  Serial.print(",");
  Serial.print(left_minute);
  Serial.print(",");
  Serial.print(left_second);
  Serial.println(",");
  
}

int setMealAmount(int sensorValue)
{
  lcd.clear();
  lcd.print("set meal's");
  lcd.setCursor(0, 1);
  lcd.print("Amount :");

  int lower_amount = map(sensorValue, 0, 1000, 1,20);
  amount = lower_amount*10;

  lcd.print(amount);
  lcd.print("g");

  return isOkPressed();
}

void timeToMeal()
{
  lcd.clear();
  lcd.print("It's time");
  lcd.setCursor(0, 1);
  lcd.print("to meal");

  for (int i=0; i<2; i++)
  {
    lcd.noDisplay();
    delay(500);
    lcd.display();
    delay(500);
  }

  playVoice();
  moveMotor();
}

void playVoice()
{
  digitalWrite(PLAYE,HIGH);
  delay(10);
  digitalWrite(PLAYE,LOW);
}

void recordVoice()
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

  pinMode(ok_btn, INPUT);
  pinMode(mode_btn, INPUT);

  servo.attach(5);
  servo.write(0);

  Serial.begin(9600);
}


void loop()
{
  bool mode_flag = digitalRead(mode_btn); 

  sensorValue = analogRead(changeValuepin);

  if (mode_flag == HIGH)
  {
    mode_num += 1;
  }

  switch (mode_num) 
  {
    case 1:
        if (time_flag == 0)
        {
          lcd.clear();
          lcd.print("Are you sure");
          lcd.setCursor(0,1);
          lcd.print("set Meal Time?");
        }

        if (isOkPressed())
        {
          time_flag = 1;
        }

        if (time_flag == 1) 
        { 
          bool setmealtime = setMealTime(sensorValue);
          if (setmealtime == true)
          {
            mode_num = 4;
            time_flag = 0;
          }
        } 

        break;
    case 2:
        if(amount_flag == 0)
        {
          lcd.clear();
          lcd.print("Are you sure");
          lcd.setCursor(0,1);
          lcd.print("set Meal Amount?");
        }

        if (isOkPressed())
        {
          amount_flag = 1;
        }

        if (amount_flag == 1) 
        { 
          bool setmealamount = setMealAmount(sensorValue);
          if (setmealamount == true)
          {
            mode_num = 4;
            amount_flag = 0;
          }
        }    
        break;
    case 3:
        lcd.clear();
        lcd.print("Are you sure");
        lcd.setCursor(0,1);
        lcd.print("give right now?");

        if (isOkPressed())
        {
          giveRightNow();
        }

        if ((next_hour == 0) && (next_minute == 0) && (next_second == 0))
        {
          lcd.clear();
          lcd.print("set Next Time");
        }
        else 
        {
          mode_num = 4;
        }
        break;
    case 4:
        getLeftTime();
        break;
    case 5:
        mode_num = 1;
        break;
    default:
        lcd.clear();
        lcd.print("밥 조");
        mode_num = 0;
  }
  
  // Serial connect 
  if (Serial.available() > 0)
  {
    String input = Serial.readStringUntil('\n');
    if (input.equals("right now"))
    { 
      cur_hour, cur_minute, cur_second= 0;
      left_hour, left_minute, left_second = 0;

      Serial.print(left_hour);
      Serial.print(",");
      Serial.print(left_minute);
      Serial.print(",");
      Serial.print(left_second);
      Serial.print(",");

      timeToMeal();

      if ((next_hour == 0) && (next_minute == 0) && (next_second == 0))
      {
        lcd.clear();
        lcd.print("set Next Time");
      }
      else 
      {
        mode_num = 4;
      }
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
      mode_num= 0;
      
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
      
      lcd.clear();
      lcd.print("Amount is ");
      lcd.print(amount);
      lcd.print('g')

      mode_num = 4;
    }
    else
    { 
      if (mode_num != 4)
      {
        next_hour = input.substring(0,input.indexOf('H')).toInt();
        next_minute = input.substring(input.indexOf('H') + 1, input.indexOf('M')).toInt();
        next_second = input.substring(input.indexOf('M') + 1, input.indexOf('S')).toInt();
        
        mode_num = 4;
      }
      //aaa
      else if (mode_num == 4)
      {
        Serial.println("99,99,99,");
      }
            
    }
  }

  lcd.display();
  delay(1000);
}