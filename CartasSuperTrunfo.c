#include <stdio.h>

// 1. Definindo a estrutura da carta usando typedef para melhor legibilidade
typedef struct {
    char nome;
    unsigned long int populacao;
    float area;
    float idh;
    float densidade_populacional;
    float super_poder;
} Carta;
