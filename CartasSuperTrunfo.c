#include <stdio.h>

 //  Definindo a estrutura da carta usando typedef para melhor legibilidade

 typedef struct {
    char nome;
    unsigned long int populacao;
    float area;
    float idh;
    float densidade_populacional;
    float super_poder;
} Carta;

 //  Função para calcular o Super Poder de uma carta
 //    Esta função encapsula a lógica de cálculo, incluindo o tratamento de erros.
void calcular_super_poder(Carta *carta) {
    float densidade_invertida = 0.0;
    
    // Tratamento de cenário de divisão por zero:
    // A divisão por zero em C leva a comportamento indefinido.
    // Esta verificação preventiva garante que a operação é segura e o programa é robusto.
    if (carta->densidade_populacional > 0) {
        // Casting explícito para float:
        // A expressão 1.0 / densidade_populacional garante que a divisão seja de ponto flutuante,
        // preservando a precisão do valor. Se um dos operandos for float, a operação inteira se torna float.
        densidade_invertida = 1.0 / carta->densidade_populacional;
    }

    // Soma de todos os atributos, conforme a fórmula do jogo.
    carta->super_poder = carta->populacao + carta->area + carta->idh + densidade_invertida;
}

