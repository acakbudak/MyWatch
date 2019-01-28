#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <TimeLib.h>
#include <DS1307.h>

// OLED display TWI address
#define OLED_ADDR   0x3C  

Adafruit_SSD1306 display(-1);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

DS1307 clock;
RTCDateTime dt;

int sayac;
int sayac1;
int sayac2;
int sayac3;
int z;

void setup() {
  // initialize and clear display
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  clock.begin();
   delay(1000);
  display.clearDisplay();
  display.display();
  
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);

  Serial.begin(9600);
 
  
}

void loop() {
  display.clearDisplay();
  
  
  int t=analogRead(A0);
  int u=analogRead(A1);
  int p=analogRead(A2);
  Serial.println(sayac);
  
 
 if(sayac3==0){ /*boş zamandaki saat ekranı*/
  
  dt = clock.getDateTime();
  display.clearDisplay();
  
  display.setTextSize(2);       //size of the text that will follow              
  display.setTextColor(WHITE);  //its color            
  display.setCursor(20,25);      //position from where you want to start writing           
  display.print(dt.hour); //text todisplay
  display.print(":");
  display.print(dt.minute);
  display.print(":");
  display.print(dt.second);
  display.display();
  delay(1000);
  if(p>500){
         sayac3=1;
           for(int r=5 ; r<40; r++){
            display.clearDisplay();
            display.drawCircle(55, 30, r, WHITE);
            display.display();
           
           }
            }
  
  return;   
 }
 
   if(sayac1==0 && sayac==0 && p>500){/*Zamanlayıcı Seçimi*/
         sayac1++;
         p=0;
          }
                 if(sayac==1 && p>500){
                         sayac1=2;
                         sayac2=0;
                         }

    

  
  switch(sayac1){             // menüler
  
     case 0:{    /* Ana ekran menüsü */
     display.setTextColor(WHITE);
     display.setTextSize(2);
     display.setCursor(45,0);
     display.println("MENU");
  
     display.setTextColor(WHITE);
     display.setTextSize(1);
     display.setCursor(17,20);
     display.println("Zamanlayici");

     display.setTextColor(WHITE);
     display.setTextSize(1);
     display.setCursor(17,29);
     display.println("Tarih");
     display.display();

  
          if(t>400){
             sayac++;
            delay(200);
            }
            
              //satır başlarındaki cursor
              switch(sayac){
               case 0:{
               display.drawFastVLine(10, 20,8, WHITE);
               display.drawFastVLine(11, 21,6, WHITE);
               display.drawFastVLine(12, 22,4, WHITE);
               display.drawFastVLine(13, 23,2, WHITE);
               display.display();
                break;
                 }
 
               case 1:{
               display.drawFastVLine(10, 29,8, WHITE);
                display.drawFastVLine(11, 30,6, WHITE);
               display.drawFastVLine(12, 31,4, WHITE);
               display.drawFastVLine(13, 32,2, WHITE);
                display.display();
                 break;
                 }
               case 2:{
                display.drawFastVLine(10, 38,8, WHITE);
                display.drawFastVLine(11, 39,6, WHITE);
                display.drawFastVLine(12, 40,4, WHITE);
                 display.drawFastVLine(13, 41,2, WHITE);
               display.display();
               break;
                 }
             case 3:{
                sayac=0;
                break;
                }
              }
              

   break;
  }

  case 1: { /* Zamanlayıcı ekarnı */
     display.setTextColor(WHITE);
     display.setTextSize(2);
     display.setCursor(0,0);
     display.println("Zamanlama");
  
     display.setTextColor(WHITE);
     display.setTextSize(1);
     display.setCursor(17,20);
     display.println("10 Dakika");

     display.setTextColor(WHITE);
     display.setTextSize(1);
     display.setCursor(17,29);
     display.println("20 Dakika");
     display.display();

     display.setTextColor(WHITE);
     display.setTextSize(1);
     display.setCursor(17,38);
     display.println("Zaman Ayari");
     display.display();

  
          if(t>400){
             sayac2++;
            delay(200);
            }
         
              //satır başlarındaki cursor
              switch(sayac2){
               case 0:{
               display.drawFastVLine(10, 20,8, WHITE);
               display.drawFastVLine(11, 21,6, WHITE);
               display.drawFastVLine(12, 22,4, WHITE);
               display.drawFastVLine(13, 23,2, WHITE);
               display.display();
                break;
                 }
 
               case 1:{
               display.drawFastVLine(10, 29,8, WHITE);
                display.drawFastVLine(11, 30,6, WHITE);
               display.drawFastVLine(12, 31,4, WHITE);
               display.drawFastVLine(13, 32,2, WHITE);
                display.display();
                 break;
                 }
               case 2:{
                display.drawFastVLine(10, 38,8, WHITE);
                display.drawFastVLine(11, 39,6, WHITE);
                display.drawFastVLine(12, 40,4, WHITE);
                 display.drawFastVLine(13, 41,2, WHITE);
               display.display();
               break;
                 }
             case 3:{
                sayac2=0;
                break;
                }
              }

    break;
  }

  
 

   

} 
    if(u>400){ /* geri tusu */
    sayac=0;
    sayac1=0;
   }
   

        if(sayac2==0 && p>500){
      for(int i=0; i<6000 ; i++){
          if(i<60){
            display.clearDisplay();
            display.setTextColor(WHITE);
            display.setTextSize(2);
            display.setCursor(10,20);
            display.println("10 Dakika");
            display.println("kaldi");
            display.display();
          }
             if(i>=60 && i<120){
              display.clearDisplay();
              display.setTextColor(WHITE);
              display.setTextSize(2);
              display.setCursor(10,20);
              display.println("9 Dakika kaldi");
              display.display();


             }
              if(i>=120 && i<180){
              display.clearDisplay();
              display.setTextColor(WHITE);
              display.setTextSize(2);
              display.setCursor(10,20);
              display.println("8 Dakika kaldi");
              display.display();


             }

            delay(1000);
    }
  
  
  
  }


      
}
