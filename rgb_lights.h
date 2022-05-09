
#ifndef RGB_LIGHTS_HPP
#define RGB_LIGHTS_HPP

class m_RGB_LIGHTS {
  private:
    const int redpin = 11; // pins where on arduino is used
    const int greenpin = 10;
    const int bluepin = 9;

  public:
    RGB_LIGHTS();

    void RGB_settings(){
      pinMode(this->redpin, OUTPUT); // inicializze pins...
      pinMode(this->greenpin, OUTPUT);
      pinMode(this->bluepin, OUTPUT);
      }
    void m_RGB_color(int red_light_value, int green_light_value ,int blue_light_value){
      analogWrite(this->redpin, red_light_value);
      analogWrite(this->greenpin, green_light_value);
      analogWrite(this->bluepin, blue_light_value);
    }
  
  
  
  
  
};

#endif
