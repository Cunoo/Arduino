#include "main_menu.h"
#include "bmp_modul.h"
#include "dht_modul.h"
#include "srf_modul.h"
#include "time_modul.h"


//array of pointers to classes polymorphism
Main_menu *arr[4] {
  new Time_modul(),
  new bmp_modul(),
  new Srf_modul(),
  new dht_modul()
};
//arr[0]= new Time_modul();


void setup() {
  
  Serial.begin(9600); // establish connection between arduino and pc

  //going through array
  for(int i = 0; i<4; i++){
    arr[i]->settings();
    
    //delay(5000);
    }
   
}

void loop() {
  
  for(int i = 0; i<4; i++){
    arr[i]->loops();
    
    
    //delay(5000);
    }
    
 }
