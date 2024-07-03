/*************************************
 * Program : Project 26. Interfacing Arduino dg P10 LED
 * Output  : Modul Dot Matrix P10
 * 125 Proyek Arduino Inkubatek
 * www.tokotronik.com
 * ***********************************/
#include <SPI.h>        
#include <DMD.h>        
#include <TimerOne.h>   
#include "SystemFont5x7.h"
 
#define DISPLAYS_ACROSS 1
#define DISPLAYS_DOWN 1
DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);
 
void ScanDMD()
{ 
  dmd.scanDisplayBySPI();
}
 
 
void setup(void)
{
 Timer1.initialize( 5000 );           
 Timer1.attachInterrupt( ScanDMD );
 dmd.clearScreen( true );
} 
 
void loop(void)
{
  dmd.clearScreen( true );   
  dmd.selectFont(SystemFont5x7);  
  dmd.drawString(4,0,"99+", 4, GRAPHICS_NORMAL );
  dmd.drawString(4,8,"ARDU", 4, GRAPHICS_NORMAL );
  delay(5000);   
}
