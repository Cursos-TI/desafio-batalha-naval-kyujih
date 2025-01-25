#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int matriz[7][7] = { // Tamanho do campo
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {3,0,0,3,0,0,0},
        {3,0,0,0,3,0,0},
        {3,0,0,0,0,3,0},
        {3,0,0,0,0,0,3},
        {3,0,0,0,0,0,0},
    };

char letras[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

int display[7][7] = { 0 }; // Esse é o visual, e vai mudando conforme for acertando

void quadro_naval(){ // Função que mostra o display

    int tamanho = 7; 
    
    printf("  ");// Letras na parte superior do jogo
    for (int i = 0; i < tamanho; i++) {
        printf("  %c", letras[i]);
    }

    printf("\n");// Espaço da letra para os numeros

    for (int i = 0; i< tamanho; i++){// Numeros junto com o display
        
        printf("%d ", i+1);
        for (int j = 0; j< tamanho; j++){
            printf("  %d", display[i][j]);
        }
        printf("\n");
    }

    
}

bool checar_local(char chute[2]) { //checa se o a possição escolhida é valida e altera no display
    system("cls");
    char letra_num = chute[0];
    int numero = chute[1] - '0' -1;// O (- '0') é para "ignorar" o código ASCII e tentar pegar os números de 1 a 7

    if (numero < 0 || numero >7) {
        printf("\nNúmero invalido, tente novamente.\n");
        return false;
    }

    switch (letra_num) //Troca a letra escolhida no chute para um numero
    {
    case 'A':
        letra_num = 1 - 1;
        break;
    
    case 'B':
        letra_num = 2 - 1;
        break;

    case 'C':
        letra_num = 3 - 1;
        break;
    
    case 'D':
        letra_num = 4 - 1;
        break;
    
    case 'E':
        letra_num = 5 - 1;
        break;
    
    case 'F':
        letra_num = 6 - 1;
        break;
    
    case 'G':
        letra_num = 7 - 1;
        break;
    
    default:
        printf("\nLetra invalida, tente novamente.\n");
        break;
    }

    if (matriz[numero][letra_num] == 0)
    {
        printf("\nVocê atirou na água\n");
        display[numero][letra_num] = 1;
        matriz[numero][letra_num] = 1;
    } else if (matriz[numero][letra_num] == 3){
        printf("\nVocê acertou um navio\n");
        display[numero][letra_num] = 3;
    } else {
        printf("Você já tentou essa casa.\n");
    }
    
    quadro_naval();

}


bool compararCampos(int matriz1[][7], int matriz2[][7], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (matriz1[i][j] != matriz2[i][j]) {
                return true; // Matrizes são diferentes
            }
        }
    }
    return false; // Matrizes são iguais
}

int main(){
    char resposta[2] = "A1";

    printf("Escolha uma letra e um número para atacar Ex: A1\n");
    quadro_naval();

    do{
    scanf("%s", &resposta);
    checar_local(resposta);
    } while (compararCampos(matriz,display,7));
    printf("Você acertou todos os navios");


}