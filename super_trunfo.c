#include <stdio.h>

int main() {
    // Definição das variáveis para a carta 1
    char estado1;
    char codigo1[4];
    char nomeCidade1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidadePopulacional1;

    // Entrada de dados para a carta 1
    printf("Digite o estado (A-H) da carta 1: ");
    scanf(" %c", &estado1);
    printf("Digite o código da carta 1 (ex: A01): ");
    scanf("%s", codigo1);
    printf("Digite o nome da cidade da carta 1: ");
    scanf(" %[^\n]", nomeCidade1);
    printf("Digite a população da cidade da carta 1: ");
    scanf("%lu", &populacao1);
    printf("Digite a área da cidade da carta 1 (em km²): ");
    scanf("%f", &area1);
    printf("Digite o PIB da cidade da carta 1 (em bilhões de reais): ");
    scanf("%f", &pib1);
    printf("Digite o número de pontos turísticos da carta 1: ");
    scanf("%d", &pontosTuristicos1);

    // Cálculo da densidade populacional para a carta 1
    densidadePopulacional1 = populacao1 / area1;

    // Definição das variáveis para a carta 2
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidadePopulacional2;

    // Entrada de dados para a carta 2
    printf("\nDigite o estado (A-H) da carta 2: ");
    scanf(" %c", &estado2);
    printf("Digite o código da carta 2 (ex: A01): ");
    scanf("%s", codigo2);
    printf("Digite o nome da cidade da carta 2: ");
    scanf(" %[^\n]", nomeCidade2);
    printf("Digite a população da cidade da carta 2: ");
    scanf("%lu", &populacao2);
    printf("Digite a área da cidade da carta 2 (em km²): ");
    scanf("%f", &area2);
    printf("Digite o PIB da cidade da carta 2 (em bilhões de reais): ");
    scanf("%f", &pib2);
    printf("Digite o número de pontos turísticos da carta 2: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculo da densidade populacional para a carta 2
    densidadePopulacional2 = populacao2 / area2;

    // Variáveis para armazenar as escolhas dos atributos
    int atributo1, atributo2;

    // Menu para escolher o primeiro atributo
    printf("\nEscolha o primeiro atributo para comparação:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Número de Pontos Turísticos\n");
    printf("5. Densidade Populacional\n");
    printf("Digite sua opção: ");
    scanf("%d", &atributo1);

    // Menu para escolher o segundo atributo
    printf("\nEscolha o segundo atributo para comparação (não pode ser o mesmo que o primeiro):\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Número de Pontos Turísticos\n");
    printf("5. Densidade Populacional\n");
    printf("Digite sua opção: ");
    scanf("%d", &atributo2);

    // Verifica se o usuário escolheu o mesmo atributo
    while (atributo1 == atributo2) {
        printf("Você não pode escolher o mesmo atributo. Escolha novamente o segundo atributo:\n");
        printf("1. População\n");
        printf("2. Área\n");
        printf("3. PIB\n");
        printf("4. Número de Pontos Turísticos\n");
        printf("5. Densidade Populacional\n");
        printf("Digite sua opção: ");
        scanf("%d", &atributo2);
    }

    // Variáveis para armazenar os valores dos atributos escolhidos
    float valor1_carta1, valor1_carta2, valor2_carta1, valor2_carta2;

    // Comparação dos atributos escolhidos
    switch (atributo1) {
        case 1: // População
            valor1_carta1 = populacao1;
            valor1_carta2 = populacao2;
            break;
        case 2: // Área
            valor1_carta1 = area1;
            valor1_carta2 = area2;
            break;
        case 3: // PIB
            valor1_carta1 = pib1;
            valor1_carta2 = pib2;
            break;
        case 4: // Pontos Turísticos
            valor1_carta1 = pontosTuristicos1;
            valor1_carta2 = pontosTuristicos2;
            break;
        case 5: // Densidade Populacional
            valor1_carta1 = densidadePopulacional1;
            valor1_carta2 = densidadePopulacional2;
            break;
        default:
            printf("Opção inválida!\n");
            return 1; // Encerra o programa em caso de erro
    }

    switch (atributo2) {
        case 1: // População
            valor2_carta1 = populacao1;
            valor2_carta2 = populacao2;
            break;
        case 2: // Área
            valor2_carta1 = area1;
            valor2_carta2 = area2;
            break;
        case 3: // PIB
            valor2_carta1 = pib1;
            valor2_carta2 = pib2;
            break;
        case 4: // Pontos Turísticos
            valor2_carta1 = pontosTuristicos1;
            valor2_carta2 = pontosTuristicos2;
            break;
        case 5: // Densidade Populacional
            valor2_carta1 = densidadePopulacional1;
            valor2_carta2 = densidadePopulacional2;
            break;
        default:
            printf("Opção inválida!\n");
            return 1; // Encerra o programa em caso de erro
    }

    // Comparação dos atributos e cálculo das somas
    float soma_carta1 = valor1_carta1 + valor2_carta1;
    float soma_carta2 = valor1_carta2 + valor2_carta2;

    // Exibição dos resultados
    printf("\nComparação de cartas:\n");
    printf("Carta 1 - %s (%c):\n", nomeCidade1, estado1);
    printf("Atributo 1: %.2f\n", valor1_carta1);
    printf("Atributo 2: %.2f\n", valor2_carta1);
    printf("Soma: %.2f\n", soma_carta1);

    printf("\nCarta 2 - %s (%c):\n", nomeCidade2, estado2);
    printf("Atributo 1: %.2f\n", valor1_carta2);
    printf("Atributo 2: %.2f\n", valor2_carta2);
    printf("Soma: %.2f\n", soma_carta2);

    // Determinando o vencedor
    if (soma_carta1 > soma_carta2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
    } else if (soma_carta2 > soma_carta1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}



