#include <stdio.h>

int main() {
    // Declaração das variáveis
    char estado1[50], estado2[50];
    char codigo1[10], codigo2[10];
    char cidade1[50], cidade2[50];
    int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontos1, pontos2;

    // Cadastro carta 1
    printf("Digite o estado da cidade 1: ");
    scanf(" %[^\n]", estado1);
    printf("Digite o código da carta 1: ");
    scanf(" %s", codigo1);
    printf("Digite o nome da cidade 1: ");
    scanf(" %[^\n]", cidade1);
    printf("Digite a população da cidade 1: ");
    scanf("%d", &populacao1);
    printf("Digite a área da cidade 1 (em km²): ");
    scanf("%f", &area1);
    printf("Digite o PIB da cidade 1 (em bilhões): ");
    scanf("%f", &pib1);
    printf("Digite o número de pontos turísticos da cidade 1: ");
    scanf("%d", &pontos1);

    // Cadastro carta 2
    printf("\nDigite o estado da cidade 2: ");
    scanf(" %[^\n]", estado2);
    printf("Digite o código da carta 2: ");
    scanf(" %s", codigo2);
    printf("Digite o nome da cidade 2: ");
    scanf(" %[^\n]", cidade2);
    printf("Digite a população da cidade 2: ");
    scanf("%d", &populacao2);
    printf("Digite a área da cidade 2 (em km²): ");
    scanf("%f", &area2);
    printf("Digite o PIB da cidade 2 (em bilhões): ");
    scanf("%f", &pib2);
    printf("Digite o número de pontos turísticos da cidade 2: ");
    scanf("%d", &pontos2);

    // Comparação (exemplo: população)
    printf("\n===== Resultado da Comparação =====\n");
    if (populacao1 > populacao2) {
        printf("Vencedora: %s (População maior)\n", cidade1);
    } else if (populacao2 > populacao1) {
        printf("Vencedora: %s (População maior)\n", cidade2);
    } else {
        printf("Empate na população entre %s e %s\n", cidade1, cidade2);
    }

    return 0;
}