/**
 * Exemplo de como funciona a função piscar(); , aonde liga e desliga LED.
 */





#include <Arduino.h>
#include <LED.h>

Led LedA(45);

void setup() 
{
  LedA.piscar();// Função piscar sem parametros, liga e desliga o LED.
}

void loop() 
{

 

    LedA.update();


}

