
#ifndef TIME_MODUL_HPP
#define TIME_MODUL_HPP

#include "RTClib.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "rgb_lights.h"

//LiquidCrystal_I2C lcd(0x3f,16,2);  // 0x3f address of display // columns // rows
#include "main_menu.h"

class Time_modul: public Main_menu{
  private:
    const RTC_DS1307 rtc; //inicialize class
    const m_RGB_LIGHTS *m_rgb; //inicialize class
    const LiquidCrystal_I2C *lcd;  // 0x3f address of display // columns // rows

  public:

      Time_modul() : lcd (new LiquidCrystal_I2C (0x3f,16,2)), m_rgb(new m_RGB_LIGHTS){}
  
      void settings(){
        
        lcd->init(); //init for inicialize display
        Serial.println("test");
        lcd->begin (16,2);  // initialize the lcd 
        lcd->backlight();//To Power ON the back light
        if (!this->rtc.begin()){
          lcd->print("Couldn't find RTC");
          while (1);
        }
        if (!this->rtc.isrunning()){ // check if rtc module is running
          lcd->print("RTC is NOT running!");
        }
          rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));//auto update from computer time
          //rtc.adjust(DateTime(2022, 5, 4, 3, 0, 0));// to set the time manually 
        
        delay(4900);
      }
      ~Time_modul(){
        
        delete m_rgb;
        //delete lcd;
        
        };
     void loops(){
      m_rgb->m_RGB_color(255, 255, 125); //red
      DateTime now = this->rtc.now(); //create object with rtc module
      lcd->setCursor(0, 1); // second column on display
      lcd->print("TIME"); //printing data on the lcd screen
      lcd->print(" ");
      lcd->print(now.hour());
      lcd->print(':');
      lcd->print(now.minute());
      lcd->print(':');
      lcd->print(now.second());
      lcd->print("  ");
  
      lcd->setCursor(0, 0); // first column on display
      lcd->print("DATE");
      lcd->print(" ");
      //lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
      //lcd.print(" ");
      lcd->print(now.day());
      lcd->print('/');
      lcd->print(now.month());
      lcd->print('/');
      lcd->print(now.year());
      lcd->print("  ");
      delay(4900);
      lcd->clear();   
     }

     LiquidCrystal_I2C *lcd_getter(){
        return this->lcd;
      }
  
  
  
  
  };


#endif
