
#ifndef BMP_MODUL_HPP
#define BMP_MODUL_HPP

#include <Wire.h>
#include <Adafruit_BMP085.h>
#include "rgb_lights.h"
#include "time_modul.h"
#include "main_menu.h"
class bmp_modul: public m_RGB_LIGHTS, public Main_menu {
  private:
    
    const Adafruit_BMP085 bmp; //initialize class for using 
    float seaLevelPressure_hPa; // Atmospheric pressure //1013.25
    const m_RGB_LIGHTS *m_rgb;  //inicialize class for using 
    const Time_modul *time_modul; //inicialize class for using 
    LiquidCrystal_I2C *lcd_bmp;  // 0x3f address of display // columns // rows
  public:
  
    void settings(){
      
      lcd_bmp->init(); // inicialize display
      lcd_bmp->backlight();//To Power ON the back light
      if (!bmp.begin()) { 
        Serial.println("Could not find a valid BMP085 sensor, check wiring!"); // check if BMP sensor is conected
        while (1) {}
      }
      delay(4900);
      
    }
    bmp_modul(): time_modul( new Time_modul), m_rgb (new m_RGB_LIGHTS){ // constructor for inicialize classes with pointers
      lcd_bmp = time_modul->lcd_getter(); // getter for lcd liquid crystal
      set_seaLevelPressure_hPa(1013.25); // setter for pressure
      }
    ~bmp_modul(){ // destructor deleting data
      delete time_modul;
      delete m_rgb;
     } 
    void loops(){
      m_rgb->m_RGB_color(0,255,0); // set color
      lcd_bmp->print("sealevel: "); // printing on display
      lcd_bmp->print(bmp.readAltitude(getter_seaLevelPressure_hPa() * 100)); // calculate for sealevel
      //Serial.println(bmp.readAltitude(seaLevelPressure_hPa * 100));
      //Serial.println(bmp.readSealevelPressure());
      lcd_bmp->setCursor(0,1); // inicialize second bar to clearing
      lcd_bmp->print("                ");
      delay(4900);
      lcd_bmp->clear();    // clearing displaz
      }
     float set_seaLevelPressure_hPa(float seaLevel){ //setter
        return this->seaLevelPressure_hPa = seaLevel;
      }
     float getter_seaLevelPressure_hPa(){ // getter
        return this->seaLevelPressure_hPa;
     }
    
     
     
};

#endif
