/**
 * Exemplo de como piscar o botao clicando no botao do pino 0
 */





#include <Arduino.h>
#include <LED.h>

Led LedA(45);
uint8_t pinBot = 0;
bool jaExecutou = false;
bool botaoAnterior = 1;

void setup() 
{
  pinMode(pinBot, INPUT_PULLUP);
}

void loop() 
{
  bool botaoAtual = digitalRead(pinBot);
  
  if (!jaExecutou)
   {
    if(!botaoAtual && botaoAnterior)
    {
    LedA.piscar(3, 6); // Funcao piscar 3 vezes
    }

    LedA.update();
  }

}

