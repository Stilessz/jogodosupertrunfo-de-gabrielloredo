#include <stdio.h>

struct Carta {
    int codigo;
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
};

void calcularDados(struct Carta *c) {
    c->densidade = c->populacao / c->area;
    c->pibPerCapita = c->pib / c->populacao;
}

float pegarValor(struct Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontosTuristicos;
        case 5: return c.densidade;
        case 6: return c.pibPerCapita;
        default: return 0;
    }
}

int main() {
    // Carta 1 - Rio de Janeiro
    struct Carta carta1 = {
        1, "Rio de Janeiro", 6748000, 1182.3, 413.0, 12
    };
    calcularDados(&carta1);

    // Carta 2 - Ceará
    struct Carta carta2 = {
        2, "Ceará", 9241000, 148894.4, 168.3, 9
    };
    calcularDados(&carta2);

    int opcao, atributo, modo;
    int jogando = 1;

    while (jogando) {
        printf("\n===== MENU =====\n");
        printf("1 - Jogar (comparar cartas)\n");
        printf("2 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nEscolha o modo:\n1 - Ataque (maior vence)\n2 - Defesa (menor vence)\n");
                scanf("%d", &modo);

                printf("\nEscolha o atributo para comparar:\n");
                printf("1 - Populacao\n2 - Area\n3 - PIB\n4 - Pontos Turisticos\n5 - Densidade Populacional\n6 - PIB per capita\n");
                scanf("%d", &atributo);

                // Pegar valores
                float v1 = pegarValor(carta1, atributo);
                float v2 = pegarValor(carta2, atributo);

                printf("\nComparacao:\n");
                printf("Carta 1 - %s: %.2f\n", carta1.cidade, v1);
                printf("Carta 2 - %s: %.2f\n", carta2.cidade, v2);

                if (modo == 1) { // Ataque (maior vence)
                    if (v1 > v2)
                        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
                    else if (v2 > v1)
                        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
                    else
                        printf("Resultado: Empate!\n");
                } else { // Defesa (menor vence)
                    if (v1 < v2)
                        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
                    else if (v2 < v1)
                        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
                    else
                        printf("Resultado: Empate!\n");
                }
                break;

            case 2:
                jogando = 0;
                printf("Saindo do jogo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }
    }

    return 0;
}
