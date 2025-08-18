#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }
}

// Função para verificar se uma posição está livre
int posicaoLivre(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int tamanho, int direcao) {
    for (int i = 0; i < tamanho; i++) {
        int l = linha + (direcao == 0 ? 0 : (direcao == 1 ? i : (direcao == 2 ? i : -i)));
        int c = coluna + (direcao == 0 ? i : (direcao == 1 ? 0 : (direcao == 2 ? -i : i)));
        if (l < 0 || l >= TAMANHO_TABULEIRO || c < 0 || c >= TAMANHO_TABULEIRO || tabuleiro[l][c] != 0) {
            return 0; // Posição não está livre
        }
    }
    return 1; // Posição está livre
}

// Função para posicionar um navio horizontalmente
int posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (posicaoLivre(tabuleiro, linha, coluna, TAMANHO_NAVIO, 0)) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha][coluna + i] = 3; // 3 representa parte do navio
        }
        return 1; // Sucesso
    }
    return 0; // Falha
}

// Função para posicionar um navio verticalmente
int posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (posicaoLivre(tabuleiro, linha, coluna, TAMANHO_NAVIO, 1)) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i][coluna] = 3; // 3 representa parte do navio
        }
        return 1; // Sucesso
    }
    return 0; // Falha
}

// Função para posicionar um navio diagonalmente (crescente)
int posicionarNavioDiagonalCrescente(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (posicaoLivre(tabuleiro, linha, coluna, TAMANHO_NAVIO, 2)) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i][coluna + i] = 3; // 3 representa parte do navio
        }
        return 1; // Sucesso
    }
    return 0; // Falha
}

// Função para posicionar um navio diagonalmente (decrescente)
int posicionarNavioDiagonalDecrescente(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (posicaoLivre(tabuleiro, linha, coluna, TAMANHO_NAVIO, 3)) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i][coluna - i] = 3; // 3 representa parte do navio
        }
        return 1; // Sucesso
    }
    return 0; // Falha
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]); // Exibe cada posição do tabuleiro
        }
        printf("\n"); // Nova linha após cada linha do tabuleiro
    }
}

// Função para criar a matriz de habilidade em forma de cone
void criarHabilidadeCone(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (j >= (TAMANHO_HABILIDADE / 2) - i && j <= (TAMANHO_HABILIDADE / 2) + i) {
                habilidade[i][j] = 1; // 1 representa área afetada
            } else {
                habilidade[i][j] = 0; // 0 representa área não afetada
            }
        }
    }
}

// Função para criar a matriz de habilidade em forma de cruz
void criarHabilidadeCruz(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == TAMANHO_HABILIDADE / 2 || j == TAMANHO_HABILIDADE / 2) {
                habilidade[i][j] = 1; // 1 representa área afetada
            } else {
                habilidade[i][j] = 0; // 0 representa área não afetada
            }
        }
    }
}

// Função para criar a matriz de habilidade em forma de octaedro
void criarHabilidadeOctaedro(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i + j >= TAMANHO_HABILIDADE / 2 && i + (TAMANHO_HABILIDADE - 1 - j) >= TAMANHO_HABILIDADE / 2 &&
                (TAMANHO_HABILIDADE - 1 - i) + j >= TAMANHO_HABILIDADE / 2 && (TAMANHO_HABILIDADE - 1 - i) + (TAMANHO_HABILIDADE - 1 - j) >= TAMANHO_HABILIDADE / 2) {
                habilidade[i][j] = 1; // 1 representa área afetada
            } else {
                habilidade[i][j] = 0; // 0 representa área não afetada
            }
        }
    }
}

// Função para aplicar a habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int linhaOrigem, int colunaOrigem) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int l = linhaOrigem + i - (TAMANHO_HABILIDADE / 2);
            int c = colunaOrigem + j - (TAMANHO_HABILIDADE / 2);
            if (l >= 0 && l < TAMANHO_TABULEIRO && c >= 0 && c < TAMANHO_TABULEIRO && habilidade[i][j] == 1) {
                tabuleiro[l][c] = 5; // 5 representa área afetada pela habilidade
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int habilidadeCone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidadeCruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidadeOctaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Define as coordenadas iniciais dos navios
    int linhaNavioHorizontal = 2; // Linha do navio horizontal
    int colunaNavioHorizontal = 1; // Coluna do navio horizontal
    int linhaNavioVertical = 5; // Linha do navio vertical
    int colunaNavioVertical = 3; // Coluna do navio vertical
    int linhaNavioDiagonalCrescente = 0; // Linha do navio diagonal crescente
    int colunaNavioDiagonalCrescente = 0; // Coluna do navio diagonal crescente
    int linhaNavioDiagonalDecrescente = 0; // Linha do navio diagonal decrescente
    int colunaNavioDiagonalDecrescente = 9; // Coluna do navio diagonal decrescente

    // Posiciona os navios no tabuleiro
    if (!posicionarNavioHorizontal(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal)) {
        printf("Navio horizontal não pode ser posicionado.\n");
    }
    if (!posicionarNavioVertical(tabuleiro, linhaNavioVertical, colunaNavioVertical)) {
        printf("Navio vertical não pode ser posicionado.\n");
    }
    if (!posicionarNavioDiagonalCrescente(tabuleiro, linhaNavioDiagonalCrescente, colunaNavioDiagonalCrescente)) {
        printf("Navio diagonal crescente não pode ser posicionado.\n");
    }
    if (!posicionarNavioDiagonalDecrescente(tabuleiro, linhaNavioDiagonalDecrescente, colunaNavioDiagonalDecrescente)) {
        printf("Navio diagonal decrescente não pode ser posicionado.\n");
    }

    // Cria as matrizes de habilidade
    criarHabilidadeCone(habilidadeCone);
    criarHabilidadeCruz(habilidadeCruz);
    criarHabilidadeOctaedro(habilidadeOctaedro);

    // Aplica as habilidades ao tabuleiro
    aplicarHabilidade(tabuleiro, habilidadeCone, 1, 2); // Aplica cone na posição (1, 2)
    aplicarHabilidade(tabuleiro, habilidadeCruz, 4, 4); // Aplica cruz na posição (4, 4)
    aplicarHabilidade(tabuleiro, habilidadeOctaedro, 3, 3); // Aplica octaedro na posição (3, 3)

    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}
