#include <stdio.h>
#include <string.h>

#define TAM 50

// Estrutura para armazenar os dados de uma cidade
struct CartaCidade {
    char codigo[10];
    char nome[TAM];
    char estado[TAM];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
};

void exibirCarta(struct CartaCidade carta) {
    printf("\n--- Carta da Cidade ---\n");
    printf("Código: %s\n", carta.codigo);
    printf("Nome: %s\n", carta.nome);
    printf("Estado: %s\n", carta.estado);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: R$ %.2f bilhões\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontosTuristicos);
}

int main() {
    struct CartaCidade cidade1, cidade2;
    int escolha;

    // Entrada de dados da cidade 1
    printf("Digite os dados da primeira cidade:\n");
    printf("Código: ");
    scanf("%s", cidade1.codigo);
    printf("Nome: ");
    scanf(" %[^\n]", cidade1.nome);
    printf("Estado: ");
    scanf(" %[^\n]", cidade1.estado);
    printf("População: ");
    scanf("%d", &cidade1.populacao);
    printf("Área (em km²): ");
    scanf("%f", &cidade1.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &cidade1.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &cidade1.pontosTuristicos);

    // Entrada de dados da cidade 2
    printf("\nDigite os dados da segunda cidade:\n");
    printf("Código: ");
    scanf("%s", cidade2.codigo);
    printf("Nome: ");
    scanf(" %[^\n]", cidade2.nome);
    printf("Estado: ");
    scanf(" %[^\n]", cidade2.estado);
    printf("População: ");
    scanf("%d", &cidade2.populacao);
    printf("Área (em km²): ");
    scanf("%f", &cidade2.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &cidade2.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &cidade2.pontosTuristicos);

    // Exibe as cartas cadastradas
    printf("\nCartas cadastradas:\n");
    exibirCarta(cidade1);
    exibirCarta(cidade2);

    // Menu interativo
    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional (população / área)\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha);

    // Comparação aninhada com base na escolha
    switch (escolha) {
        case 1:
            if (cidade1.populacao > cidade2.populacao) {
                printf("\n%s venceu! Tem maior população.\n", cidade1.nome);
            } else if (cidade2.populacao > cidade1.populacao) {
                printf("\n%s venceu! Tem maior população.\n", cidade2.nome);
            } else {
                printf("\nEmpate! Ambas têm a mesma população.\n");
            }
            break;
        case 2:
            if (cidade1.area > cidade2.area) {
                printf("\n%s venceu! Tem maior área territorial.\n", cidade1.nome);
            } else if (cidade2.area > cidade1.area) {
                printf("\n%s venceu! Tem maior área territorial.\n", cidade2.nome);
            } else {
                printf("\nEmpate! Ambas têm a mesma área.\n");
            }
            break;
        case 3:
            if (cidade1.pib > cidade2.pib) {
                printf("\n%s venceu! Tem maior PIB.\n", cidade1.nome);
            } else if (cidade2.pib > cidade1.pib) {
                printf("\n%s venceu! Tem maior PIB.\n", cidade2.nome);
            } else {
                printf("\nEmpate! Ambas têm o mesmo PIB.\n");
            }
            break;
        case 4:
            if (cidade1.pontosTuristicos > cidade2.pontosTuristicos) {
                printf("\n%s venceu! Tem mais pontos turísticos.\n", cidade1.nome);
            } else if (cidade2.pontosTuristicos > cidade1.pontosTuristicos) {
                printf("\n%s venceu! Tem mais pontos turísticos.\n", cidade2.nome);
            } else {
                printf("\nEmpate! Ambas têm o mesmo número de pontos turísticos.\n");
            }
            break;
        case 5: {
            float densidade1 = cidade1.populacao / cidade1.area;
            float densidade2 = cidade2.populacao / cidade2.area;

            if (densidade1 < densidade2) {
                printf("\n%s venceu! Tem menor densidade populacional.\n", cidade1.nome);
            } else if (densidade2 < densidade1) {
                printf("\n%s venceu! Tem menor densidade populacional.\n", cidade2.nome);
            } else {
                printf("\nEmpate! Ambas têm a mesma densidade populacional.\n");
            }
            break;
        }
        default:
            printf("\nOpção inválida! Tente novamente.\n");
    }

    return 0;
}