#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    unsigned long populacao;
    double area;
    double idh;
    double densidade_populacional;
    double super_poder;
} Carta;

void limpar_input(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void calcular_super_poder(Carta *carta) {
    if (carta->area > 0.0) {
        carta->densidade_populacional = (double)carta->populacao / carta->area;
    } else {
        carta->densidade_populacional = 0.0;
    }

    double densidade_invertida = (carta->densidade_populacional > 0.0)
                                 ? 1.0 / carta->densidade_populacional
                                 : 0.0;

    /* fórmula de exemplo — adapte conforme a regra do jogo */
    carta->super_poder = (double)carta->populacao + carta->area + carta->idh + densidade_invertida;
}

void ler_carta(Carta *carta) {
    printf("Nome do Pais: ");
    if (fgets(carta->nome, sizeof carta->nome, stdin) != NULL) {
        size_t ln = strlen(carta->nome);
        if (ln > 0 && carta->nome[ln - 1] == '\n') carta->nome[ln - 1] = '\0';
    }

    printf("Populacao (unsigned long): ");
    while (scanf("%lu", &carta->populacao) != 1) {
        printf("Valor invalido. Digite novamente: ");
        limpar_input();
    }

    printf("Area (double): ");
    while (scanf("%lf", &carta->area) != 1) {
        printf("Valor invalido. Digite novamente: ");
        limpar_input();
    }

    printf("IDH (double): ");
    while (scanf("%lf", &carta->idh) != 1) {
        printf("Valor invalido. Digite novamente: ");
        limpar_input();
    }

    limpar_input(); /* remove o '\n' restante para que o próximo fgets funcione */
}

int main(void) {
    Carta carta1, carta2;

    printf("--- Super Trunfo: Carta 1 ---\n");
    ler_carta(&carta1);
    calcular_super_poder(&carta1);

    printf("\n--- Super Trunfo: Carta 2 ---\n");
    ler_carta(&carta2);
    calcular_super_poder(&carta2);

    printf("\nResultado:\n");
    printf("Carta 1: %s -> super_poder = %.2f\n", carta1.nome, carta1.super_poder);
    printf("Carta 2: %s -> super_poder = %.2f\n", carta2.nome, carta2.super_poder);

    if (carta1.super_poder > carta2.super_poder)
        printf("Vencedor: Carta 1 (%s)\n", carta1.nome);
    else if (carta2.super_poder > carta1.super_poder)
        printf("Vencedor: Carta 2 (%s)\n", carta2.nome);
    else
        printf("Empate!\n");

    return 0;
}
