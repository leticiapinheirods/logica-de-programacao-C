#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

int num_tab, op_menu, n1;
_Bool sub = false;
_Bool divi = false;

void menu(){
    printf("****************************\n");
    printf("*         TABUADA          *\n");
    printf("****************************\n");
    printf("*                          *\n");
    printf("*  1 - ADIÇÃO              *\n");
    printf("*  2 - SUBTRAÇÃO           *\n");
    printf("*  3 - MULTIPLICAÇÃO       *\n");
    printf("*  4 - DIVISÃO             *\n");
    printf("*  5 - SAIR                *\n");
    printf("*                          *\n");
    printf("****************************\n");
    printf("Escolha uma opção: ");
}

void adicao_subtracao(n1){
    for(int n2 = 1; n2<11; n2++){
        int n3 = n1 + n2;
        if(sub == true){
            printf("%i - %i = %i\n", n3, n1, n2);
        }else{
            printf("%i + %i = %i\n", n1, n2, n3);
        }
    }
}

void multipli_divisao(n1){
    for(int n2 = 1; n2<11; n2++){
        int n3 = n1 * n2;
        if(divi == true){
            printf("%i / %i = %i\n", n3, n1, n2);
        }else{
            printf("%i * %i = %i\n", n1, n2, n3);
        }
    }
}

void main(){

    do{
        system("clear");
        menu();
        scanf("%i", &op_menu);

        if(op_menu>0 && op_menu<5){
            printf("Digite o numero para a tabuada: ");
            scanf("%i", &num_tab);

            while(num_tab < 0){
                printf("Numero para tabuada invalido. Digita um numero inteiro: ");
                scanf("%i", &num_tab);
            }
        }

        system("clear");

        switch(op_menu){
            case 1: {
                printf("A tabuada de adicao para o numero %i e:\n", num_tab);
                adicao_subtracao(num_tab);
                sleep(5);
                break;
            }

            case 2: {
                sub = true;
                printf("A tabuada de subtracao para o numero %i e:\n", num_tab);
                adicao_subtracao(num_tab);
                sleep(5);
                break;
            }

            case 3: {
                printf("A tabuada de multiplicao para o numero %i e:\n", num_tab);
                multipli_divisao(num_tab);
                sleep(5);
                break;
            }

            case 4: {
                divi = true;
                printf("A tabuada de multiplicao para o numero %i e:\n", num_tab);
                multipli_divisao(num_tab);
                sleep(5);
                break;
            }

            default:{
                if (op_menu<1 || op_menu>5){
                    printf("Opção inválida!\n");
                    sleep(2);
                }
            }
        }

    }while(op_menu!=5);

    printf("Sistema finalizado");
}