/**
 * Exemplo de como funciona a função piscar(); , apenas colocando o parametro 
 * de frequência nela.
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
    LedA.piscar(3); // Função piscar em uma frequencia de 3
    jaExecutou = true; //COnfere o valor da variavel para true
  }

    LedA.update();


}

