#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

char matriz[3][3], s='X';
int nj = 1, op, i, j;

void matriz_jogo(){
    printf("        *           *        \n");
    printf("  %c    *    %c     *   %c   \n", matriz[0][0], matriz[0][1], matriz[0][2]);
    printf("        *           *        \n");
    printf("* * * * * * * * * * * * * * *\n");
    printf("        *           *        \n");
    printf("  %c    *    %c     *   %c   \n", matriz[1][0], matriz[1][1], matriz[1][2]);
    printf("        *           *        \n");
    printf("* * * * * * * * * * * * * * *\n");
    printf("        *           *        \n");
    printf("  %c    *    %c     *   %c   \n", matriz[2][0], matriz[2][1], matriz[2][2]);
    printf("        *           *        \n");
}

void menu(){
    printf("*         GAME VELHA          *\n");
    printf("*******************************\n");
    printf("* 1 - JOGAR                   *\n");
    printf("* 2 - ESTATISTICA             *\n");
    printf("* 3 - SAIR                    *\n");
    printf("*******************************\n");
    printf("Selecione uma opção: ");
}

char coordenadas(char s){
    do{
        printf("Qual linha você quer posicionar %c (insira um numero de 1 a 3)? ", s);
        scanf("%d", &i);
    }while(i < 1 || i > 3);

    do{
        printf("Qual coluna você quer posicionar %c (insira um numero de 1 a 3)? ", s);
        scanf("%d", &j);
    }while(j < 1 || j > 3);
    
    return matriz[i-1][j-1];
}

//por que aqui se passar os parametros s, i, j da erro?
void jogar(){
    do{
        system("clear");

        if (s == 'X'){
            s = 'O';
        } else{
            s = 'X';
        }
        
        coordenadas(s);
        
        while(matriz[i-1][j-1]){
            printf("Coordenada não disponível. Insira outra\n");
            
            coordenadas(s);
        }

        matriz[i-1][j-1] = s;

        matriz_jogo();

        nj++;

        sleep(2);

    }while(nj < 10);
    
    printf("Fim do jogo!");
}


int main(){
    do{
        menu();
        scanf("%d", &op);
        system("clear");

        switch(op){
            case 1:
                jogar();
                break;
            default:
                printf("Opção não disponível. Insira uma das opções do menu\n");
        }
    }while(op!=3);

    printf("Programa finalizado");
    return 0;
}