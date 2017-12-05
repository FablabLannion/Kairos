/****************************
** programme : arc en ciel  *********
** Alain Renon                          ************
** créé le 28/04/20172017               ************
** modifié le 14/11/2017                ************
** écrit pour Wemos d1 mini             ************
****************************************************/



int nbLed = 8;

#include <Adafruit_NeoPixel.h>//bibliothèque de gestio des LEDs
#define PIN         D8 //broche data des LEDs


int tranche = 1;
byte R = 0;
byte V = 0;
byte Bl = 0;
int couleur = 0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(nbLed, PIN, NEO_GRB + NEO_KHZ800);

//********************************************************************
//*************         setup                   **********************
//********************************************************************
void setup()
{
  Serial.begin(9600);
 
  strip.begin();
  strip.show();//initialisation et extinction des LEDs

  
}// end setup


//********************************************************************
//*************         loop                   **********************
//********************************************************************

void loop()
{
   arcEnCiel();
}// end loop()



//***********************************************************************
//fonction arc-en-ciel
//statique: toutes les LEDs ont la même couleur
//durée sans insertion de delay() : 3,7 sec
//***********************************************************************
void arcEnCiel()
{
  for (int i = 0; i <= 1530; i++)
  {
    teinte(i);
    affiche(R, V, Bl);
    delay(10);
  }// end for
}// end fonction

//**************************************************************
//**   fonction affiche (LEDs de même couleur) *****************
//**************************************************************
void affiche(int R, int V, int Bl)
{
  for (int i = 0; i < nbLed; i++)
  {
    strip.setPixelColor(i, R, V, Bl);
    strip.show();
  }// end for
}// fin fonction affiche


//**************************************************************
//**   fonction teinte  ****************************************
//**************************************************************
void teinte(int couleur)
//teinte = mixage de couleurs, de 0 (rouge) à 1529 (rouge)
{
  byte pointCouleur = 0;
  byte tranche = (couleur / 255) + 1;
  byte pos = couleur % 255;
  if (tranche % 2)// tranche paire : la couleur de la LED discriminante augmente
  {
    pointCouleur = pos;
  }
  else // tranche impaire : la couleur de la LED discriminante diminue
  {
    pointCouleur = 255 - pos;
  }
  // end if
  switch (tranche) {
    case 1: {
        R = 255;
        V = pointCouleur;
        Bl = 0;
        break;
      }// end case
    case 2: {
        R = pointCouleur;
        V = 255;
        Bl = 0;
        break;
      }// end case
    case 3: {
        R = 0;
        V = 255;
        Bl = pointCouleur;
        break;
      }// end case
    case 4: {
        R = 0;
        V = pointCouleur;
        Bl = 255;
        break;
      }// end case
    case 5: {
        R = pointCouleur;
        V = 0;
        Bl = 255;
        break;
      }// end case
    case 6: {
        R = 255;
        V = 0;
        Bl = pointCouleur;
        break;
      }// end case
  }//end switch
}// end fonction teinte


//**************************************************************
//**   fin du programme          *******************************
//**************************************************************

