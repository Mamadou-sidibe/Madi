#include <LiquidCrystal.h>

#include <SPI.h>

#include <Arial14.h>
#include <Arial_Black_16_ISO_8859_1.h>
#include <Arial_black_16.h>
#include <DMD.h>
#include <MyBigFont.h> 
#include <SystemFont5x7.h>

#include <IRremote.h> // include the IRremote library
#include  "IR.h"

#define DISPLAYS_ACROSS 4
#define DISPLAYS_DOWN 1
DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);

#define RECEIVER_PIN 12 // define the IR receiver pin
IRrecv receiver(RECEIVER_PIN); // create a receiver object of the IRrecv class
decode_results results; // create a results object of the decode_results class
unsigned char key_value = 0; // variable to store the key value

#define PIN_DMD_nOE       9    // D9 active low Output Enable, setting this low lights all the LEDs in the selected rows. Can pwm it at very high frequency for brightness control.
#define PIN_DMD_A         6    // D6
#define PIN_DMD_B         7    // D7
#define PIN_DMD_CLK       13   // D13_SCK  is SPI Clock if SPI is used
#define PIN_DMD_SCLK      8    // D8
#define PIN_DMD_R_DATA    11   // D11_MOSI is SPI Master Out if SPI is used


void ScanDMD()
{ 
  dmd.scanDisplayBySPI();
}

void setup()
{
   //Timer1.initialize( 5000 );           //period in microseconds to call ScanDMD. Anything longer than 5000 (5ms) and you can see flicker.
   //Timer1.attachInterrupt( ScanDMD );   //attach the Timer1 interrupt to ScanDMD which goes to dmd.scanDisplayBySPI()
   dmd.clearScreen( true );   //true is normal (all pixels off), false is negative (all pixels on)
   Serial.begin(9600); // begin serial communication with a baud rate of 9600
   receiver.enableIRIn(); // enable the receiver
   receiver.blink13(true); // enable blinking of the built-in LED when an IR signal is received
}

void loop()  
{
  dmd.selectFont(Arial_Black_16);
  //dmd.selectFont(Arial_14);
  // if (receiver.decode(&results)) 
  // { // decode the received signal and store it in results
  //   if (results.value == 0xFFFFFFFF) // if the value is equal to 0xFFFFFFFF
  //  { 
  //    results.value = key_value; // set the value to the key value
  //  }

  switch (results.value) 
   { 
     if (receiver.decode(&results)) 
     {
       if (results.value == 0xFFFFFFFF)
       {
         results.value = key_value;
         case 0xFF50AF: // if the value is equal to 0xFD00FF
         dmd.drawMarquee("POWER",14,(32DISPLAYS_ACROSS)-1,0);
         //Serial.println("POWER"); // print “POWER” in the Serial Monitor
         break;
         case 0xFF40BF:
         dmd.drawMarquee("VOL+"14,(32DISPLAYS_ACROSS)-1,0);
         //Serial.println("VOL+");
         break;
         case 0xFFF807:
         dmd.drawMarquee(">||"14,(32DISPLAYS_ACROSS)-1,0);
         //Serial.println(">||");
         break ;
         case 0xFF807F:
         dmd.drawMarquee("DOWN"14,(32DISPLAYS_ACROSS)-1,0);
         //Serial.println("DOWN");
         break ;
         case 0xFFC03F:
         dmd.drawMarquee("VOL-"14,(32DISPLAYS_ACROSS)-1,0);
         //Serial.println("VOL-");
         break ;
         case 0xFF00FF:
         dmd.drawMarquee("UP"14,(32DISPLAYS_ACROSS)-1,0);
         //Serial.println("UP");
         break ;
         case 0xFF08F7:
         dmd.drawMarquee("0"14,(32DISPLAYS_ACROSS)-1,0);
         //Serial.println("0");
         break ;
         case 0xFF02FD:
         dmd.drawMarquee("ST/REPT"14,(32DISPLAYS_ACROSS)-1,0);
         //Serial.println("ST/REPT");
         break ;
         case 0xFF8877:
         dmd.drawMarquee("1"14,(32DISPLAYS_ACROSS)-1,0);
         //Serial.println("1");
         break ;
         case 0xFF48B7:
         dmd.drawMarquee("2"14,(32DISPLAYS_ACROSS)-1,0);
         //Serial.println("2");
         break ;
         case 0xFFC837:
         dmd.drawMarquee("3"14,(32DISPLAYS_ACROSS)-1,0);
         //Serial.println("3");
         break ;
         case 0xFF28D7:
         dmd.drawMarquee("4"14,(32DISPLAYS_ACROSS)-1,0);
         //Serial.println("4");
         break ;
         case 0xFFA857:
         dmd.drawMarquee("5"14,(32DISPLAYS_ACROSS)-1,0);
         //Serial. println ( "5" ) ;
         break ;
         case  0xFF6897 :
         dmd.drawMarquee("6"14,(32DISPLAYS_ACROSS)-1,0);
         //Serial. println ( "6" ) ;
         break ;
         case  0xFFE817 :
         dmd.drawMarquee("7"14,(32DISPLAYS_ACROSS)-1,0);
         //Serial. println ( "7" ) ;
         break ;
         case  0xFF18E7 :
         dmd.drawMarquee("8"14,(32DISPLAYS_ACROSS)-1,0);
         //Serial. println ( "8" ) ;
         break ;
         case  0xFF9867 :
         dmd.drawMarquee("9"14,(32DISPLAYS_ACROSS)-1,0);
         //Serial. println ( "9" ) ;
         break ;
         key_value = results. value ; // stocke la valeur sous la forme key_value
         IrReceiver.resume () ; // réinitialise le récepteur pour le code suivant
        }
      }   
    }
 }
}