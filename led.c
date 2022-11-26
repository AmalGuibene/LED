#include "gpio.h"
#include "led.h"

// La fonction InputOutputConfig active l'horloge et configure les entr�es/sorties n�cessaires.
void InputOutputConfig(void)
{
  
  /* Mise en marche des horloge g�rant les ports D (led) et A (bouton) */
     GPIO_Clock_Enable(GPIOD);       //Led
     GPIO_Clock_Enable(GPIOA);       // Button
    
  /* Configuration de LED3, LED4, LED5, LED6 en sortie de type "pushpull" (mode classique) */
     GPIO_Config(GPIOD, PIN12 || PIN13 || PIN14 || PIN15, OUTPUT, OUTPUT_PUSH_PULL, LOW_SPEED);
     
  /* Configuration du bouton "User" en entr�e de type "pushpull" (mode classique) */
     GPIO_Config(GPIOA, PIN0, INPUT,  OUTPUT, OUTPUT_PUSH_PUL, LOW_SPEED);  
      
}

//doit allumer la led L si le bouton B est cliqu�, au deuxi�me clic du bouton B, la led L doit s'�teindre.
//La fonction ButtonToggleLed peut �tre r�impl�ment�e dans la couche sup�rieure  ==>  main.c.
void ButtonToggleLed(void)
{   
    /* Boucle infini */
    for (;;) 
    {
        /* Lecture de l'�tat du bouton, si appuy� on entre dans le if */
        if (GPIO__Read_Pin(GPIOA, PIN0))
        {
            if (GPIO__Read_Pin(GPIOD, PIN12))
               GPIO_Write_Pin(GPIOD, PIN12, RESET); 
            else 
               GPIO_Write_Pin(GPIOD, PIN12, SET); 
        }
    }
}
