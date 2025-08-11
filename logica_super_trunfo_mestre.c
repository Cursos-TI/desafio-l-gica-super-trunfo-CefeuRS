#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[3];
    int codigo;
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} CartaCidade;

void exibirCarta(CartaCidade c) {
    printf("\n=== Carta ===\n");
    printf("Estado: %s\n", c.estado);
    printf("Código: %d\n", c.codigo);
    printf("Nome: %s\n", c.nome);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Pontos turísticos: %d\n", c.pontos_turisticos);
}

float densidadePopulacional(CartaCidade c) {
    return (c.area != 0) ? (c.populacao / c.area) : 0;
}

int compararAtributo(int escolha, CartaCidade c1, CartaCidade c2) {
    switch (escolha) {
        case 1: return (c1.populacao > c2.populacao) ? 1 : (c1.populacao < c2.populacao) ? 2 : 0;
        case 2: return (c1.area > c2.area) ? 1 : (c1.area < c2.area) ? 2 : 0;
        case 3: return (c1.pib > c2.pib) ? 1 : (c1.pib < c2.pib) ? 2 : 0;
        case 4: return (c1.pontos_turisticos > c2.pontos_turisticos) ? 1 : (c1.pontos_turisticos < c2.pontos_turisticos) ? 2 : 0;
        case 5: {
            float d1 = densidadePopulacional(c1);
            float d2 = densidadePopulacional(c2);
            return (d1 < d2) ? 1 : (d1 > d2) ? 2 : 0;
        }
        default:
            printf("Erro: Opção de comparação inesperada.\n");
            return 0;
    }
}

int main() {
    CartaCidade cidade1, cidade2;
    int escolha1, escolha2;
    int vitorias_carta1 = 0, vitorias_carta2 = 0;

    printf("Digite o estado da cidade 1: ");
    scanf("%2s", cidade1.estado);
    printf("Digite o código da carta 1: ");
    scanf("%d", &cidade1.codigo);
    getchar();
    printf("Digite o nome da cidade 1: ");
    fgets(cidade1.nome, sizeof(cidade1.nome), stdin);
    cidade1.nome[strcspn(cidade1.nome, "\n")] = '\0';
    printf("Digite a população da cidade 1: ");
    scanf("%d", &cidade1.populacao);
    printf("Digite a área da cidade 1 (em km²): ");
    scanf("%f", &cidade1.area);
    printf("Digite o PIB da cidade 1 (em bilhões): ");
    scanf("%f", &cidade1.pib);
    printf("Digite o número de pontos turísticos da cidade 1: ");
    scanf("%d", &cidade1.pontos_turisticos);

    printf("\nDigite o estado da cidade 2: ");
    scanf("%2s", cidade2.estado);
    printf("Digite o código da carta 2: ");
    scanf("%d", &cidade2.codigo);
    getchar();
    printf("Digite o nome da cidade 2: ");
    fgets(cidade2.nome, sizeof(cidade2.nome), stdin);
    cidade2.nome[strcspn(cidade2.nome, "\n")] = '\0';
    printf("Digite a população da cidade 2: ");
    scanf("%d", &cidade2.populacao);
    printf("Digite a área da cidade 2 (em km²): ");
    scanf("%f", &cidade2.area);
    printf("Digite o PIB da cidade 2 (em bilhões): ");
    scanf("%f", &cidade2.pib);
    printf("Digite o número de pontos turísticos da cidade 2: ");
    scanf("%d", &cidade2.pontos_turisticos);

    printf("\n=== Escolha dois atributos diferentes para comparar ===\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos turísticos\n5 - Densidade populacional (menor vence)\n");

    do {
        printf("Escolha o primeiro atributo: ");
        scanf("%d", &escolha1);
    } while (escolha1 < 1 || escolha1 > 5);

    do {
        printf("Escolha o segundo atributo (diferente do primeiro): ");
        scanf("%d", &escolha2);
    } while (escolha2 < 1 || escolha2 > 5 || escolha2 == escolha1);

    exibirCarta(cidade1);
    exibirCarta(cidade2);

    int resultado1 = compararAtributo(escolha1, cidade1, cidade2);
    int resultado2 = compararAtributo(escolha2, cidade1, cidade2);

    vitorias_carta1 += (resultado1 == 1) ? 1 : 0;
    vitorias_carta2 += (resultado1 == 2) ? 1 : 0;
    vitorias_carta1 += (resultado2 == 1) ? 1 : 0;
    vitorias_carta2 += (resultado2 == 2) ? 1 : 0;

    printf("\n===== Resultado da Comparação =====\n");
    if (vitorias_carta1 > vitorias_carta2) {
        printf("Vencedora: %s\n", cidade1.nome);
    } else if (vitorias_carta2 > vitorias_carta1) {
        printf("Vencedora: %s\n", cidade2.nome);
    } else {
        printf("Empate na rodada!\n");
    }

    return 0;
}