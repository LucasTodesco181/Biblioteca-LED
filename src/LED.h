#ifndef LED_h
#define LED_h

#include <Arduino.h>
    /**
    * @class Led
    * @brief  Classe para controle não bloqueante de um LED.
    * 
    * Permite ligar, desligar, ligar por um tempo,
    * piscar continuamente e piscar por quantidade definida.
    * 
    * 
    * @note O método update() deve ser chamado continuamente dentro do loop()
    */
class Led 
{
    private:
    uint8_t pino;
    bool estado;
    bool apagarNoTempo;
    uint32_t apagarNoMomento;
    bool estadoPiscar;

    uint32_t tempoEspera;
    uint32_t tempoAnteriroPiscar;
    uint16_t repeticoes;

    /**
     * @brief Processa o desligamento temporizado.
     */
    void funcaoApagarNoTempo();

    /**
     * @brief Processa a lógica do piscar do LED.
     */
    void funcaoPiscar();

  
    public:

    /**
     * @brief Constrói um objeto LED.
     * @param pin Numero do pino digital onde o LED está.
     */
    Led(uint8_t pin); 

    /**
     * @brief Liga o LED continuamente.
     */
    void acender();

    /**
     * @brief Liga o LED por um tempo determinado.
     * @param tempoLigado Tempo, em milissegundos, que o LED ficará ligado.
     */
    void acender(uint32_t tempoLigado);

    /**
     * @brief Desliga o LED e cancela o modos automáticos.
     */
    void apagar();

    /**
     * @brief Acende e apaga o LED continuamente.
     */
    void piscar();

    /**
     * @brief Ascende e apaga o LED com uma frequência determinada.
     * @param freq frequência que o LED irá piscar.
     */
    void piscar(float freq);

    /**
     * @brief Ascende e apaga o led com uma frequência determinada com um número de repetições determinado.
     * @param freq Frequência que o LED irá piscar
     * @param repeticoes Quantidade de repetições que o LED irá piscar.
     */
    void piscar(float freq, uint16_t repeticoes);

    /**
     * @brief Aleterna o estado do LED (ligado/desligado).
     */
    void alternar();

    /**
     * @brief Altera o estado do pino do LED.
     * @param estado Define o esatado do LED (ligado/desligado).
     */
    void setEstado(bool estado);

    /**
     * @brief Retorna o número do pino do LED para o usuário.
     */
    uint8_t getPino();

    /**
     * @brief Atualiza a lógica interna da classe e escreve o pino.
     * 
     * @note Deve ser chamado repetidamente dentro da função loop().
     */
    void update();

};


#endif