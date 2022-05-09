
#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include <Wire.h>


//LiquidCrystal_I2C lcd(0x3f,16,2);  // 0x3f address of display // columns // rows

class Main_menu{
  private:
    //Time_modul time_modul;
    //bmp_modul bmp_m;
    //Srf_modul *srf_module;
  public:
    virtual void loops() = 0;
    
      //time_init();
      //delay(2000);
      //dht_init();
      //delay(2000);
      //bmp_m.bmp_init();
      //delay(2000);
      //srf_module->srf_modul_init();
     virtual void settings() = 0; 
        //time_settings();
        //delay(2000);
        //dht_settings();
        //delay(2000);
        //bmp_m.bmp_settings();
        //delay(2000);
       // srf_module->srf_modul_settings();
        
        
        
        //bmp_m.bmp_settings();
        //dht_settings();
      
      
    Main_menu() /*: srf_module( new Srf_modul)*/{
    
      //time_modul->lcd_setter(lcd);
      //this-> time_modul;;
      }
 
      
    // void lcd_setter(LiquidCrystal_I2C *lcd){
      //  this->lcd = lcd;
     // }
   
    
    
 
 };

#endif
