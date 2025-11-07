#include <stdio.h>

#define TAM 10       // Tamanho do tabuleiro 10x10 bidimensional
#define TAM_NAVIO 3  // Tamanho fixo dos navios (3 posições)
#define AGUA 0
#define NAVIO 3

int main() {
   
    int tabuleiro [TAM][TAM]; //Matriz do tabuleiro
    int i, j;

    // Inniciando o tabuleiro com a água = 0
    for (i = 0; i < TAM; i++){
        for (j = 0; j < TAM; j++){
            tabuleiro[i][j] = AGUA;
        }
    }

    //Coordenadas dos navios
    int linNavioHorz = 2;
    int colNavioHorz = 4;
    int linNavioVert = 5;
    int colNavioVert = 7;

    // --- Validação dos limites do tabuleiro ---
    // Verifica se o navio horizontal cabe no tabuleiro
    if (colNavioHorz + TAM_NAVIO > TAM) {
        printf("Erro: o navio horizontal ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // Navio Horizontal
    for (i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linNavioHorz][colNavioHorz + i] = NAVIO;
    }

    for (i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linNavioVert + i][colNavioVert] == NAVIO) {
            printf("Erro: os navios se sobrepõem no tabuleiro!\n");
            return 1;
        }
    }

    // Navio Vertical
     for (i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linNavioVert + i][colNavioVert] = NAVIO;
    }

    // Tabuleiro 
    printf("\n=== TABULEIRO DE BATALHA NAVAL ===\n\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda: 0 = Água | 3 = Navio\n");
    printf("\n");

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
