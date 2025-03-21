#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

char matriz[3][3], s='X', jx[50], jo[50];
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
    printf("*VITÓRIAS JOGADOR(A) %s: %d       *\n", jx, vx);
    printf("*VITÓRIAS JOGADOR(A) %s: %d       *\n", jo, vo);
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

void inicializar_matriz() {
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            matriz[i][j] = ' ';
        }
    }
}

char coordenadas(){
    
    //impedir que o jogador insira vazio
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
    
    //e se o jogador quiser trocar de simbolo no meio do jogo?
    //impedir que o jogador insira vazio
    if(jx[0] == '\0' && jo[0] == '\0'){
        
        printf("Insira o nome do jogador(a) X: ");
        scanf("%s", jx);
    
        printf("Insira o nome do jogador(a) O: ");
        scanf("%s", jo);
    }
    
    do{
        system("clear");

        if (s == 'X'){
            s = 'O';
            printf("Vez do jogador(a) %s", jo);
        } else{
            s = 'X';
            printf("Vez do jogador(a) %s", jx);
        }
        
        jogo();
        
        coordenadas();
        
        while(matriz[i-1][j-1]){
            printf("Coordenada não disponível. Insira outra\n");
            
            coordenadas();
        }
        
        matriz[i-1][j-1] = s;

        jogada++;
        
        if(jogada > 4){
            if(verificar_vitoria()){
                char vencedor = verificar_vitoria();
                
                system("clear");
                jogo();

                if (vencedor == 'X'){
                    printf("Vitória do jogador(a) %s!\n", jx);
                    sleep(2);
                    vx++;
                    break;
                } else if (vencedor == 'O'){
                    printf("Vitória do jogador(a) %s!\n", jo);
                    sleep(2);
                    vo++;
                    break;
                } else{
                    printf("Deu velha!\n");
                    sleep(2);
                    empates++;
                    break;
                }
                
            }
        }

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
                inicializar_matriz();
                break;
            case 2:
                if(jx[0] == '\0' && jo[0] == '\0'){
                    printf("Necessário iniciar o jogo primeiro\n");
                    sleep(2);
                    break;
                }
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