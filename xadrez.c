#include <stdio.h>

// Função recursiva para o movimento da Torre
void moverTorre(int casas) {
    if (casas <= 0) return; // Condição de parada
    printf("Direita\n");
    moverTorre(casas - 1); // Chamada recursiva
}

// Função recursiva para o movimento do Bispo
void moverBispo(int casasVertical, int casasHorizontal) {
    if (casasVertical <= 0) return; // Condição de parada
    for (int i = 0; i < casasHorizontal; i++) {
        printf("Cima, Direita\n"); // Movimento diagonal
    }
    moverBispo(casasVertical - 1, casasHorizontal); // Chamada recursiva
}

// Função recursiva para o movimento da Rainha
void moverRainha(int casas) {
    if (casas <= 0) return; // Condição de parada
    printf("Esquerda\n");
    moverRainha(casas - 1); // Chamada recursiva
}

// Função para o movimento do Cavalo
void moverCavalo() {
    const int movimentoVertical = 2; // casas para cima
    const int movimentoHorizontal = 1; // casa para a direita

    // Loop aninhado para o movimento do Cavalo
    for (int i = 0; i < movimentoVertical; i++) {
        for (int j = 0; j < movimentoHorizontal; j++) {
            if (j == 0 && i == 1) {
                printf("Direita\n"); // Movimento para a direita
            }
        }
        printf("Cima\n"); // Movimento para cima
    }
}

int main() {
    // Definindo o número de casas a serem movidas
    const int casasTorre = 5;
    const int casasBispo = 5; // Número de casas na diagonal
    const int casasRainha = 8;

    // Movimento da Torre
    printf("Movimento da Torre:\n");
    moverTorre(casasTorre);
    
    // Separando o movimento do Bispo
    printf("\nMovimento do Bispo:\n");
    moverBispo(casasBispo, casasBispo); // Movimento diagonal

    // Separando o movimento da Rainha
    printf("\nMovimento da Rainha:\n");
    moverRainha(casasRainha);

    // Separando o movimento do Cavalo
    printf("\nMovimento do Cavalo:\n");
    moverCavalo();

    return 0;
}
