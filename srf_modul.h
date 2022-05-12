
#ifndef SRF_MODUL_HPP
#define SRF_MODUL_HPP

//#include "rgb_lights.h"
#include "time_modul.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "main_menu.h"
class Srf_modul: public m_RGB_LIGHTS, public Main_menu {

  private:
    const uint8_t trig_pin=13;
    const uint8_t echo_pin=12;
    long duration;
    int distanceCm, distanceInch;
    //const Time_modul *time_modul;
    LiquidCrystal_I2C *lcd_srf;
  public:
    Srf_modul(): lcd_srf (new LiquidCrystal_I2C (0x3f,16,2)){
    }
    void settings(){
      lcd_srf->init(); //initializate display
     
      pinMode(trig_pin, OUTPUT); // set pin to input without using built in pull up resistor
      pinMode(echo_pin, INPUT);
      //Serial.begin(BAUD_RATE);
      lcd_srf->init();
      lcd_srf->backlight();//To Power ON the back light
      delay(4900);
    }
    
    ~Srf_modul(){
      delete lcd_srf;
      }
    
    void loops() {
      m_RGB_color(255,255,255); // raspberyy
      digitalWrite(trig_pin, LOW); //sets the digital pin 13 off
      delayMicroseconds(2);
      digitalWrite(trig_pin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trig_pin, LOW);
      
      this->duration = pulseIn(echo_pin, HIGH); //Arduino pin on which you want to read Allowed data types: int. High pulse
      this->distanceCm= duration*0.034/2;
      this->distanceInch = duration*0.0133/2;
      
      lcd_srf->setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
      lcd_srf->print("Distance:"); // Print distance on the scrren
      lcd_srf->print(distanceCm); // Prints the distance value from the sensor
      lcd_srf->print("  cm");
      delay(10);
      lcd_srf->setCursor(0,1);
      lcd_srf->print("Distance: ");
      lcd_srf->print(distanceInch);
      lcd_srf->print("inch");
      delay(4900);
      lcd_srf->clear();   
      
    }
};
#endif
 
