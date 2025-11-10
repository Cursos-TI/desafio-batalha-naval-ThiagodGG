#include <stdio.h>

#define TAM 10    
#define TAM_HAB 5  
#define HABILIDADE 5
#define AGUA 0
#define NAVIO 3

//Inicialização do tabuleiro
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = AGUA;
}

// função para imprimir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\n----- TABULEIRO DE BATALHA NAVAL -----\n\n");
    printf("   ");
    for (int j = 0; j < TAM; j++) printf("%2d ", j);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == AGUA) printf(" 0 ");        // Água
            else if (tabuleiro[i][j] == NAVIO) printf(" 3 ");  // Navio
            else if (tabuleiro[i][j] == HABILIDADE) printf(" 5 "); // Área de efeito
        }
        printf("\n");
    }
    printf("\nLegenda: 0 = Água | 3 = Navio | 5 = Área de Habilidade\n");
}

//Matriz em forma de CONE
void gerarCone(int cone[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++){
        for (int j = 0; j < TAM_HAB; j++){
            if (j >= (TAM_HAB / 2) - i && j <= (TAM_HAB / 2) + i)
                cone[i][j] = 1;
            else
                cone[i][j]=0;
            }
        }
    }

//Matriz em forma de CRUZ
void gerarCruz (int cruz[TAM_HAB][TAM_HAB]){
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++){
        for (int j = 0; j < TAM_HAB; j++){
            if (i == centro || j == centro)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }
}

//Matriz em forma de OCTAEDRO
void gerarOctaedro(int octaedro[TAM_HAB][TAM_HAB]){
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++){
        for(int j = 0; j < TAM_HAB; j++){
            if (abs(i - centro) + abs(j - centro) <= centro)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }
}

//Matriz de habilidade
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna) {
    int deslocamento = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linha = origemLinha + (i - deslocamento);
            int coluna = origemColuna + (j - deslocamento);

            // Garante que o efeito não ultrapasse os limites do tabuleiro
            if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                if (habilidade[i][j] == 1 && tabuleiro[linha][coluna] == AGUA)
                    tabuleiro[linha][coluna] = HABILIDADE;
            }
        }
    }
}


int main() {
   
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    //Posiciona navios
    tabuleiro[2][3] = NAVIO;
    tabuleiro[2][4] = NAVIO;
    tabuleiro[2][5] = NAVIO;
    tabuleiro[6][6] = NAVIO;
    tabuleiro[7][6] = NAVIO;

    //Matriz de habilidades
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    //Formas das habilidades
    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    //Habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 4, 4);      
    aplicarHabilidade(tabuleiro, cruz, 7, 2);      
    aplicarHabilidade(tabuleiro, octaedro, 5, 8);

    //Resultado final
    exibirTabuleiro(tabuleiro);

    //Exibiçao dos resultados
    printf("\n----- MATRIZES DE HABILIDADES -----\n");
    
    printf("\nCone:\n");
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++)
            printf("%d ", cone[i][j]);
        printf("\n");
    }

    printf("\nCruz:\n");
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++)
            printf("%d ", cruz[i][j]);
        printf("\n");
    }

    printf("\nOctaedro:\n");
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++)
            printf("%d ", octaedro[i][j]);
        printf("\n");
    }

    return 0;
}
