/**
 * Exemplo de como funciona a função piscar();, com if para que ela não entre em loop e fique ligada intermitente.
 */





#include <Arduino.h>
#include <LED.h>

Led LedA(45);
bool jaExecutou = false;

void setup() 
{
}

void loop() 
{

  if (!jaExecutou) 
  {
    LedA.piscar(2.0f, 6); // Função piscar na frequencia de 2 com 6 repetições.
    jaExecutou = true; //COnfere o valor da variavel para true
  }

    LedA.update();


}

