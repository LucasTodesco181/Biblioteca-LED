/**
 * Exemplo de como funciona a função acender();, ela fica ligada no tempo determinado nos parametros, no exemplo está 4000 milis
 * o que daria 4 segundos.
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
    LedA.acender(4000); // Função acender por 4000 milis, ou 4 segundos.
    jaExecutou = true; //COnfere o valor da variavel para true
  }

    LedA.update();


}

