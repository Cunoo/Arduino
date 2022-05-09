#ifndef DHT_MODUL_HPP
#define DHT_MODUL_HPP

#include "DHT.h"
#include <LiquidCrystal_I2C.h>
#include "rgb_lights.h"
 #include "main_menu.h"
 
class dht_modul : public m_RGB_LIGHTS, public Main_menu{
  private:
    uint8_t DHTTYPE;  //type pin where is used
    uint8_t DHTPIN; // pin where module is used
    const DHT *dht; // dht modul
    LiquidCrystal_I2C *lcd_dht; //lcd
    
  public:

    dht_modul(): lcd_dht (new LiquidCrystal_I2C (0x3f,16,2)), dht (new DHT (DHTPIN, DHTTYPE)){
      set_dht_pin(A0); // setter
      set_dht_type(DHT11);  //setter
      };
    
    void settings(){
      
      lcd_dht->init(); //inicialize display
      lcd_dht->backlight();//To Power ON the back light
      Serial.println(F("DHTxx test!"));
    
      dht->begin(); // inicialize compomnent
      delay(4900);
      }
    uint8_t get_dht_pin(){
      return this->DHTPIN;
     }
    uint8_t set_dht_pin(uint8_t dht_pin){
        return this->DHTPIN = dht_pin;
     }
     
    uint8_t get_dht_type(){
      return this->DHTTYPE;
     }

    uint8_t set_dht_type(uint8_t dhttype ){
      return this->DHTTYPE = dhttype;
     }
     
    void loops(){
        m_RGB_color(255,0,255); //color for light
       
        float h = this->dht->readHumidity(); //reading humidity from senzor
        float t = this->dht->readTemperature(); // reading temperature from senzor, Celzius are set for default
        // if we want show farenheit 
        //float f = dht.readTemperature(true);
      
        // Check if any reads failed and exit early (to try again).
        if (isnan(h) || isnan(t)){
          Serial.println(F("Failed to read from DHT sensor!"));
          return;
        }
        
      
        // Compute heat index in Fahrenheit (the default)
        //float hif = dht.computeHeatIndex(f, h);
        // Compute heat index in Celsius (isFahreheit = false)
        //float hic = dht.computeHeatIndex(t, h, false);
        lcd_dht->setCursor(0,0); //inicialize displaz fisrt bar
        //Serial.print(F(" Humidity: "));
        //Serial.print(h);
        lcd_dht->print(F("Humidity: "));
        lcd_dht->print(h);
        lcd_dht->print("%");
        lcd_dht->setCursor(0,1); //inicialize second bar
        lcd_dht->print(F("Temp: "));
        lcd_dht->print(t);
        delay(4900);
        lcd_dht->clear();   //clearing lcd monitor from data
      }
  
  
  
  
};
#endif
