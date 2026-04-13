#include "LED.h"



Led::Led(uint8_t pin) :
pino(pin),
estado(LOW),
apagarNoTempo(false),
apagarNoMomento(false),
estadoPiscar(false),
tempoEspera(0),
tempoAnteriroPiscar(0),
repeticoes(0)
{
    pino = pin;
    estado = LOW;
    pinMode(pino, OUTPUT);
}


void Led::acender()
{
    estado = HIGH;
    estadoPiscar = false;
}

void Led::acender(uint32_t tempoLigado)
{
    estado = HIGH;
    apagarNoTempo = true;
    apagarNoMomento = millis() + tempoLigado;
    estadoPiscar = false;
}

void Led:: apagar()
{
    estado = LOW;
    apagarNoTempo = false;
    estadoPiscar = false;
}

void Led::alternar()
{
    estado = !estado;
    apagarNoTempo = false;
    estadoPiscar = false;
}
void Led::setEstado(bool estado)
{
    this -> estado = estado;
    apagarNoTempo = false;
    estadoPiscar = false;
}

uint8_t Led::getPino()
{
    return pino;
}

void Led::update()
{
    if(apagarNoTempo)  funcaoApagarNoTempo();
    if(estadoPiscar)  funcaoPiscar();

    digitalWrite(pino, estado);
}

void Led::piscar()
{
    estadoPiscar = true;
    tempoEspera = 500;
    tempoAnteriroPiscar = millis();
    estado = HIGH;
    apagarNoTempo = false;
    repeticoes = -1;
}

void Led::piscar(float freq)
{
    if(freq == 0)
    {
        return;
    }

    estadoPiscar = true;
    tempoEspera = (1000.0f / (2.0f * freq));
    tempoAnteriroPiscar = millis();
    estado = HIGH;
    apagarNoTempo = false;
    repeticoes = -1;
}

void Led::piscar(float freq, uint16_t repeticoes)
{
    if(freq == 0)
    {
        return;
    }


    estadoPiscar = true;
    tempoEspera = (1000.0f / (2.0f * freq));
    tempoAnteriroPiscar = millis();
    estado = HIGH;
   this->repeticoes = repeticoes * 2;
   apagarNoTempo = false;

}

void Led::funcaoApagarNoTempo()
{
     if(millis() >= apagarNoMomento)
        {
            estado = LOW;
            apagarNoTempo = false;
       }
}

void Led::funcaoPiscar()
{
    if(millis() - tempoAnteriroPiscar >= tempoEspera)
        {
            estado = !estado;
            tempoAnteriroPiscar = millis();
            if(repeticoes > 0)
            {
                repeticoes --;
                if(repeticoes == 0)
                {
                    estadoPiscar = false;
                    estado = LOW;
                }
            }
        }
}
