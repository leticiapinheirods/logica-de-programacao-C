#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

char matriz[3][3], s='X';
int i, j, jogada=1, op, partidas = 0, empates = 0, vx = 0, vo = 0;

void jogo(){
    printf("\n");
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

void estatisticas(){
    printf("*         ESTATISTICAS        *\n");
    printf("*******************************\n");
    printf("*TOTAL DE PARTIDAS: %d        *\n", partidas);
    printf("*VITÓRIAS JOGADOR X: %d       *\n", vx);
    printf("*VITÓRIAS JOGADOR Y: %d       *\n", vo);
    printf("*EMPATES: %d                  *\n", empates);
    printf("*******************************\n");
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

char coordenadas(){
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

int verificar_vitoria(){
    for (int i = 0; i < 3; i++) {
        if (matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2]){
            return matriz[i][0];
        } else if(matriz[0][i] == matriz[1][i] && matriz[1][i] == matriz[2][i]){
            return matriz[0][i];
        }
    }

    if (matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2]){
        return matriz[0][0];
    }
         
    if (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0]){
        return matriz[0][2];
    } 
}

void jogar(){
    do{
        system("clear");

        if (s == 'X'){
            s = 'O';
        } else{
            s = 'X';
        }
        
        coordenadas();
        
        while(matriz[i-1][j-1]){
            printf("Coordenada não disponível. Insira outra\n");
            
            coordenadas();
        }
        
        matriz[i-1][j-1] = s;

        jogo();

        jogada++;
        
        if(jogada > 4){
            if(verificar_vitoria()){
                char vencedor = verificar_vitoria();

                if (vencedor == 'X'){
                    printf("Vitória do Jogador X!\n");
                    sleep(2);
                    vx++;
                    break;
                } else if (vencedor == 'O'){
                    printf("Vitória do Jogador O!\n");
                    sleep(2);
                    vo++;
                    break;
                } else{
                    printf("O jogo empatou\n");
                    sleep(2);
                    empates++;
                    break;
                }
            }
        
        }

        sleep(2);

    }while(jogada < 10);
    
    partidas++;

    printf("Fim do jogo!\n");
}

void main(){
    do{
        system("clear");
        menu();
        scanf("%d", &op);
        system("clear");

        switch(op){
            case 1:
                jogar();
                break;
            case 2:
                estatisticas();
                sleep(2);
                break;
            case 3:
                break;
            default:
                printf("Opção não disponível. Insira uma das opções do menu\n");
        }
    }while(op!=3);

    printf("Programa finalizado");
}