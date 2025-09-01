#include <stdio.h>
#include <string.h>

// Estrutura da carta
struct Carta {
    char estado[3];
    char codigo[5];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
};

// Função para calcular dados derivados
void calcularDados(struct Carta *carta) {
    carta->densidade = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

// Função para exibir uma carta
void mostrarCarta(struct Carta c) {
    printf("\nCidade: %s (%s)", c.cidade, c.estado);
    printf("\nPopulacao: %d", c.populacao);
    printf("\nArea: %.2f", c.area);
    printf("\nPIB: %.2f", c.pib);
    printf("\nPontos Turisticos: %d", c.pontosTuristicos);
    printf("\nDensidade Populacional: %.2f", c.densidade);
    printf("\nPIB per capita: %.2f\n", c.pibPerCapita);
}

// Função de comparação de atributo
float compararAtributo(struct Carta c1, struct Carta c2, int atributo) {
    float valor1, valor2;

    switch (atributo) {
        case 1: valor1 = c1.populacao; valor2 = c2.populacao; break;
        case 2: valor1 = c1.area; valor2 = c2.area; break;
        case 3: valor1 = c1.pib; valor2 = c2.pib; break;
        case 4: valor1 = c1.pontosTuristicos; valor2 = c2.pontosTuristicos; break;
        case 5: valor1 = c1.densidade; valor2 = c2.densidade; break;
        case 6: valor1 = c1.pibPerCapita; valor2 = c2.pibPerCapita; break;
        default: valor1 = valor2 = 0; break;
    }

    printf("\nComparacao do atributo %d:", atributo);
    printf("\n%s: %.2f", c1.cidade, valor1);
    printf("\n%s: %.2f\n", c2.cidade, valor2);

    // Regra da densidade: menor vence
    if (atributo == 5) {
        if (valor1 < valor2) return 1;
        else if (valor2 < valor1) return 2;
        else return 0;
    }
    // Regra geral: maior vence
    else {
        if (valor1 > valor2) return 1;
        else if (valor2 > valor1) return 2;
        else return 0;
    }
}

int main() {
    struct Carta carta1, carta2;
    int escolha1, escolha2;
    float resultado1, resultado2;
    int pontos1 = 0, pontos2 = 0;

    // Cadastro da primeira carta
    printf("Cadastro da primeira carta:\n");
    printf("Estado: "); scanf("%s", carta1.estado);
    printf("Codigo: "); scanf("%s", carta1.codigo);
    printf("Cidade: "); scanf(" %[^\n]", carta1.cidade);
    printf("Populacao: "); scanf("%d", &carta1.populacao);
    printf("Area: "); scanf("%f", &carta1.area);
    printf("PIB: "); scanf("%f", &carta1.pib);
    printf("Pontos turisticos: "); scanf("%d", &carta1.pontosTuristicos);
    calcularDados(&carta1);

    // Cadastro da segunda carta
    printf("\nCadastro da segunda carta:\n");
    printf("Estado: "); scanf("%s", carta2.estado);
    printf("Codigo: "); scanf("%s", carta2.codigo);
    printf("Cidade: "); scanf(" %[^\n]", carta2.cidade);
    printf("Populacao: "); scanf("%d", &carta2.populacao);
    printf("Area: "); scanf("%f", &carta2.area);
    printf("PIB: "); scanf("%f", &carta2.pib);
    printf("Pontos turisticos: "); scanf("%d", &carta2.pontosTuristicos);
    calcularDados(&carta2);

    // Exibir cartas
    printf("\n===== CARTA 1 =====");
    mostrarCarta(carta1);
    printf("\n===== CARTA 2 =====");
    mostrarCarta(carta2);

    // Menu para escolha do primeiro atributo
    printf("\nEscolha o primeiro atributo para comparacao:\n");
    printf("1 - Populacao\n2 - Area\n3 - PIB\n4 - Pontos Turisticos\n5 - Densidade Populacional\n6 - PIB per capita\n");
    scanf("%d", &escolha1);

    // Menu para escolha do segundo atributo (sem repetir o primeiro)
    do {
        printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
        printf("1 - Populacao\n2 - Area\n3 - PIB\n4 - Pontos Turisticos\n5 - Densidade Populacional\n6 - PIB per capita\n");
        scanf("%d", &escolha2);
    } while (escolha2 == escolha1);

    // Comparar primeiro atributo
    resultado1 = compararAtributo(carta1, carta2, escolha1);
    if (resultado1 == 1) pontos1++;
    else if (resultado1 == 2) pontos2++;

    // Comparar segundo atributo
    resultado2 = compararAtributo(carta1, carta2, escolha2);
    if (resultado2 == 1) pontos1++;
    else if (resultado2 == 2) pontos2++;

    // Resultado final
    printf("\n===== RESULTADO FINAL =====\n");
    printf("%s: %d pontos\n", carta1.cidade, pontos1);
    printf("%s: %d pontos\n", carta2.cidade, pontos2);

    if (pontos1 > pontos2) {
        printf("Vencedora: Carta 1 (%s)\n", carta1.cidade);
    } else if (pontos2 > pontos1) {
        printf("Vencedora: Carta 2 (%s)\n", carta2.cidade);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
