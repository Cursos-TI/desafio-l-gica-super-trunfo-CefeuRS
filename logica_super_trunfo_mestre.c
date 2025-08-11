#include <stdio.h>
#include <string.h>

#define TAM 50

typedef struct {
    char codigo[4];             // ex: "A01"
    char nome[TAM];
    unsigned long int populacao; // unsigned long para evitar overflow
    float area;
    float pib;                  // em bilhões
    int pontos_turisticos;
} CartaCidade;

// Função para exibir os dados da carta, incluindo PIB per capita e densidade
void exibirCarta(CartaCidade c) {
    float pib_reais = c.pib * 1000000000.0f;
    float pib_per_capita = (c.populacao != 0) ? (pib_reais / c.populacao) : 0.0f;
    float densidade = (c.area != 0.0f) ? ((float)c.populacao / c.area) : 0.0f;

    printf("\nCódigo: %s\n", c.codigo);
    printf("Nome: %s\n", c.nome);
    printf("População: %lu\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Pontos turísticos: %d\n", c.pontos_turisticos);
    printf("PIB per capita: %.2f\n", pib_per_capita);
    printf("Densidade populacional: %.2f hab/km²\n", densidade);
}

// Função que retorna o nome do atributo para mostrar na interface
const char *nome_atributo(int opc) {
    switch (opc) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos turísticos";
        case 5: return "Densidade populacional";
        default: return "Desconhecido";
    }
}

// Função para calcular densidade populacional, tratando divisão por zero
float densidadePopulacional(CartaCidade c) {
    return (c.area != 0.0f) ? ((float)c.populacao / c.area) : 0.0f;
}

// Função para comparar um atributo entre duas cartas
// Retorna 1 se carta1 vence, 2 se carta2 vence, 0 empate
int compararAtributo(CartaCidade c1, CartaCidade c2, int atributo) {
    switch (atributo) {
        case 1: // População (maior vence)
            return (c1.populacao > c2.populacao) ? 1 : (c2.populacao > c1.populacao) ? 2 : 0;
        case 2: // Área (maior vence)
            return (c1.area > c2.area) ? 1 : (c2.area > c1.area) ? 2 : 0;
        case 3: // PIB (maior vence)
            return (c1.pib > c2.pib) ? 1 : (c2.pib > c1.pib) ? 2 : 0;
        case 4: // Pontos turísticos (maior vence)
            return (c1.pontos_turisticos > c2.pontos_turisticos) ? 1 : (c2.pontos_turisticos > c1.pontos_turisticos) ? 2 : 0;
        case 5: { // Densidade populacional (menor vence)
            float d1 = densidadePopulacional(c1);
            float d2 = densidadePopulacional(c2);
            return (d1 < d2) ? 1 : (d2 < d1) ? 2 : 0;
        }
        default:
            return 0;
    }
}

int main() {
    CartaCidade cidade1, cidade2;
    int atributo1, atributo2;
    int vitorias_c1 = 0, vitorias_c2 = 0;

    // Cadastro da carta 1
    printf("Digite o código da carta 1 (ex: A01): ");
    scanf("%3s", cidade1.codigo);
    getchar(); // Limpar buffer do Enter

    printf("Digite o nome da cidade 1: ");
    fgets(cidade1.nome, TAM, stdin);
    cidade1.nome[strcspn(cidade1.nome, "\n")] = '\0'; // Remove \n

    printf("Digite a população da cidade 1: ");
    scanf("%lu", &cidade1.populacao);
    getchar();

    printf("Digite a área da cidade 1 (km²): ");
    scanf("%f", &cidade1.area);
    getchar();

    printf("Digite o PIB da cidade 1 (em bilhões): ");
    scanf("%f", &cidade1.pib);
    getchar();

    printf("Digite o número de pontos turísticos da cidade 1: ");
    scanf("%d", &cidade1.pontos_turisticos);
    getchar();

    // Cadastro da carta 2
    printf("\nDigite o código da carta 2 (ex: B02): ");
    scanf("%3s", cidade2.codigo);
    getchar();

    printf("Digite o nome da cidade 2: ");
    fgets(cidade2.nome, TAM, stdin);
    cidade2.nome[strcspn(cidade2.nome, "\n")] = '\0';

    printf("Digite a população da cidade 2: ");
    scanf("%lu", &cidade2.populacao);
    getchar();

    printf("Digite a área da cidade 2 (km²): ");
    scanf("%f", &cidade2.area);
    getchar();

    printf("Digite o PIB da cidade 2 (em bilhões): ");
    scanf("%f", &cidade2.pib);
    getchar();

    printf("Digite o número de pontos turísticos da cidade 2: ");
    scanf("%d", &cidade2.pontos_turisticos);
    getchar();

    // Exibe as cartas
    printf("\n--- Carta 1 ---");
    exibirCarta(cidade1);
    printf("\n--- Carta 2 ---");
    exibirCarta(cidade2);

    // Menu para escolha do primeiro atributo (com validação)
    do {
        printf("\nEscolha o primeiro atributo para comparar:\n");
        printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos turísticos\n5 - Densidade populacional\n");
        printf("Digite sua escolha (1-5): ");
        scanf("%d", &atributo1);
        getchar();
        if (atributo1 < 1 || atributo1 > 5) {
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (atributo1 < 1 || atributo1 > 5);

    // Menu para escolha do segundo atributo (diferente do primeiro)
    do {
        printf("\nEscolha o segundo atributo para comparar (diferente do primeiro):\n");
        printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos turísticos\n5 - Densidade populacional\n");
        printf("Digite sua escolha (1-5): ");
        scanf("%d", &atributo2);
        getchar();
        if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
            printf("Opção inválida ou igual ao primeiro atributo! Tente novamente.\n");
        }
    } while (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1);

    // Comparações e contagem de vitórias
    int res1 = compararAtributo(cidade1, cidade2, atributo1);
    int res2 = compararAtributo(cidade1, cidade2, atributo2);

    if (res1 == 1) vitorias_c1++;
    else if (res1 == 2) vitorias_c2++;

    if (res2 == 1) vitorias_c1++;
    else if (res2 == 2) vitorias_c2++;

    // Exibe resultados individuais
    printf("\n--- Resultado por atributo ---\n");
    printf("%s: %s\n", nome_atributo(atributo1), (res1 == 1) ? "Carta 1 venceu" : (res1 == 2) ? "Carta 2 venceu" : "Empate");
    printf("%s: %s\n", nome_atributo(atributo2), (res2 == 1) ? "Carta 1 venceu" : (res2 == 2) ? "Carta 2 venceu" : "Empate");

    // Resultado final da rodada
    printf("\n--- Resultado da rodada ---\n");
    if (vitorias_c1 == 2) {
        printf("Carta 1 venceu a rodada!\n");
    } else if (vitorias_c2 == 2) {
        printf("Carta 2 venceu a rodada!\n");
    } else {
        printf("A rodada terminou empatada!\n");
    }

    return 0;
}