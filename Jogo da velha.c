//Jogo da velha


//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <unistd.h>



//constantes
#define MAX 3


//protótipos funções
int menu(); // ok funcionando
void V_limpartabuleiro(char tabuleiro[][MAX]);// ok funcionando
void V_imprimirtabuleiro(char tabuleiro[][MAX]);// ok funcionando
int verifica(char tabuleiro[][MAX], int *placar); // ok funcionando
int inseri_coordenadas(char tabuleiro[][MAX], int jogador, int l, int c); // ok funcionando


// função principal
int main()
{

    //seta a linguagem do código
    setlocale(LC_ALL, "Portuguese");


    //declaração de variáveis
    int jogador = 0;
    char tabuleiro[MAX][MAX];
    int linha, coluna;
    int placar[3]={0,0,0};
    int o_jogo = 0;



    //limpa o buffer do tabuleiro
    V_limpartabuleiro(tabuleiro);

          //loop infinito
        while(1){

                    //limpa o buffer do CMD
                system("cls");

                //limpa o tabuleiro e jogadas ao iniciar menu novamente
                V_limpartabuleiro(tabuleiro);
                jogador = 0;


                printf("\t\t\t\t\t\t________SCORE_______\n");
                printf("\t\t\t\t\t\t|   Jogador 1 - %d  |\n", placar[0]);
                printf("\t\t\t\t\t\t|   Jogador 2 - %d  |\n", placar[1]);
                printf("\t\t\t\t\t\t|    Empates  - %d  |\n", placar[2]);
                printf("\t\t\t\t\t\t|__________________|\n");

                //Inicia o menu, tem que ser dentro do loop
            int menu_jogo = menu();

                    //menu jogo
                switch(menu_jogo){

                        //JOGADOR VS JOGADOR
                    case 1:
                        do{
                                    //limpa o buffer do CMD
                                system("cls");

                                //imprimi o tabuleiro
                            V_imprimirtabuleiro(tabuleiro);

                                //entrada de dados dos jogadores em um loop
                            do
                            {
                                        //PLAYER 1
                                    if(jogador%2==0){
                                    printf("\n\t\t\t\t=============Vez da 'O' JOGADOR 1=============\n");
                                    }

                                        //PLAYER 2
                                    else{
                                    printf("\n\t\t\t\t=============Vez da 'X' JOGADOR 2=============\n");
                                    }

                                        //ENTRADA DE DADOS
                                    printf("\n\t\t\t\tInforme a linha x coluna que deseja jogar EX(0_espaço_0): ");
                                    scanf("%d%d", &linha, &coluna);

                                    //opção para desenvolvedor
                                    if(linha == 10 && coluna == 10){
                                        break;
                                    }

                                        //VERIFICA SE O VALOR INSERIDO É VALIDO
                                    if(linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != ' '){
                                       printf("\n\t\t\t\tCoordenadas invalidas, tente novamente!\n");
                                    }
                                //Mantem no loop caso estejam erradas as entradas
                            }while (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != ' ');


                                    //inseri as coordenados do jogo e troca o jogar
                                jogador = inseri_coordenadas(tabuleiro, jogador, linha, coluna);

                                //CONDIÇÕES PARA O FIM DO JOGO
                                o_jogo = verifica(tabuleiro, placar);

                                //opção para desenvolvedor
                                if(linha == 10 && coluna == 10){
                                    o_jogo=1;
                                }


                        }while(!o_jogo);
                        break;

                        //JOGADOR VS MAQUINA
                    case 2:
                        do{
                                system("cls");

                                //imprimi o tabuleiro ESSENCIAL
                            V_imprimirtabuleiro(tabuleiro);

                                //entrada de dados dos jogadores
                            do
                            {
                                        //PLAYER
                                    if(jogador%2==0){
                                    printf("\n\t\t\t\t=============Vez da 'O' JOGADOR 1=============\n");

                                    printf("\n\t\t\t\tInforme a linha x coluna que deseja jogar EX(0_espaço_0) :  ");
                                    scanf("%d%d", &linha, &coluna);

                                            //opção para desenvolvedor
                                        if(linha == 10 && coluna == 10){
                                            break;
                                        }

                                            //avisa se coordenada estiver disponível
                                        if(linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != ' '){
                                           printf("\n\t\t\t\tCoordenadas invalidas, tente novamente!\n");
                                        }
                                    }

                                        //MAQUINA
                                    else{
                                        do{
                                            srand(time(NULL));
                                            //aqui sera gerado números aleatórios para linha e a coluna (valores entre 0 e 2)
                                            linha = rand() % 3; //rand = random
                                            coluna = rand() %3; //rand = random      (entenda que ele gera valores aleatórios)

                                            //Agora sera verificado se a posição escolhida já esta ocupada
                                            }while (tabuleiro[linha][coluna]== 'x' || tabuleiro[linha][coluna] == '0');
                                    }

                            }while (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != ' ');


                                //inseri as coordenados do jogo e troca o jogar
                                jogador = inseri_coordenadas(tabuleiro, jogador, linha, coluna);

                                //CONDIÇÕES PARA O FIM DO JOGO
                            o_jogo = verifica(tabuleiro, placar);

                                    //opção para desenvolvedor
                                    if(linha == 10 && coluna == 10){
                                        o_jogo=1;
                                    }

                        }while(!o_jogo);
                        break;

                        //SAINDO DO JOGO
                    case 0:
                        printf("\n\t\t\t\tSaindoo...\n");
                        exit(1);
                }

        }
}



//função utilizada para o menu do jogo
int menu() {
    int menu_jogo;

        //entra em um loop para iniciar o menu
    while (1) {
        printf("\n\t\t\t\t----ESCOLHA QUAL OPCAO DESEJAR----\n");
        printf("\n\t\t\t\t1 - Iniciar jogo Player vs Player");
        printf("\n\t\t\t\t2 - Iniciar jogo Player vs Computador");
        printf("\n\t\t\t\t0 - Sair");

        printf("\n\n\t\t\t\tEscolha uma opcao:  ");
        scanf("%d", &menu_jogo);

        if (menu_jogo == 1 || menu_jogo == 2 || menu_jogo == 0) {
            return menu_jogo;
        }
        else {
            printf("\n\t\t\tOpção inválida. Tente novamente.\n");
        }
    }
}

//função de verificação de jogada
int verifica(char tabuleiro[][MAX], int *placar){

    int linha, coluna, game=0, flag=0;

    // Condições de vítoria

    //Diagonal principal (jogador)
    if (tabuleiro[0][0] == '0' && tabuleiro[1][1] == '0' && tabuleiro[2][2] == '0')
    {
        printf("\n\t\t\t\tO tabuleiro acabou! O jogador 1 ganhou por diagonal principal.\n");
        V_imprimirtabuleiro(tabuleiro);
        sleep(5);
        placar[0]+=1;
        return game = 1;
    }
    //Diagonal principal (computador)
    if (tabuleiro[0][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][2] == 'X')
    {
        printf("\n\t\t\t\tO tabuleiro acabou! O jogador 2 ganhou por diagonal principal.\n");
        V_imprimirtabuleiro(tabuleiro);
        sleep(5);
        placar[1]+=1;
        return game = 1;
    }

    // Vitória em diagonal secundária (jogador)
    if (tabuleiro[0][2] == '0' && tabuleiro[1][1] == '0' && tabuleiro[2][0] == '0')
    {
        printf("\n\t\t\t\tO tabuleiro acabou! O jogador 1 ganhou por diagonal secundária.\n");
        V_imprimirtabuleiro(tabuleiro);
        sleep(5);
        placar[0]+=1;
        return game = 1;
    }
    // Vitória em diagonal secundária (computador)
    if (tabuleiro[0][2] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][0] == 'X')
    {
        printf("\n\t\t\t\tO tabuleiro acabou! O jogador 2 ganhou por diagonal secundária.\n");
        V_imprimirtabuleiro(tabuleiro);
        sleep(5);
        placar[1]+=1;
        return game = 1;

    }
    //Vitória em Linha (jogador)
    if (tabuleiro[0][0] == '0' && tabuleiro [0][1] == '0' && tabuleiro [0][2] == '0' ||
            tabuleiro[1][0] == '0' && tabuleiro [1][1] == '0' && tabuleiro [1][2] == '0' ||
            tabuleiro[2][0] == '0' && tabuleiro [2][1] == '0' && tabuleiro [2][2] == '0')
    {
        printf("\n\t\t\t\tO tabuleiro acabou! O jogador 1 ganhou por linha\n");
        V_imprimirtabuleiro(tabuleiro);
        sleep(5);
        placar[0]+=1;
        return game = 1;
    }
    //Vitória em Linha (computador)
    if ((tabuleiro[0][0] == 'X' && tabuleiro [0][1] == 'X' && tabuleiro [0][2] == 'X') ||
            (tabuleiro[1][0] == 'X' && tabuleiro [1][1] == 'X' && tabuleiro [1][2] == 'X') ||
            (tabuleiro[2][0] == 'X' && tabuleiro [1][1] == 'X' && tabuleiro [2][2] == 'X'))

    {
        printf("\n\t\t\t\tO tabuleiro acabou! O jogador 2 ganhou por linha\n");
        V_imprimirtabuleiro(tabuleiro);
        sleep(5);
        placar[1]+=1;
        return game = 1;
    }

    // Vitória em Coluna(jogador)
    if (tabuleiro[0][0] == '0' && tabuleiro [1][0] == '0' && tabuleiro [2][0] == '0' ||
            tabuleiro[0][1] == '0' && tabuleiro [1][1] == '0' && tabuleiro [2][1] == '0' ||
            tabuleiro[0][2] == '0' && tabuleiro [1][2] == '0' && tabuleiro [2][2] == '0')
    {
        printf("\n\t\t\t\tO tabuleiro acabou! O jogador 1 ganhou por coluna\n");
        V_imprimirtabuleiro(tabuleiro);
        sleep(5);
        placar[0]+=1;
        return game = 1;
    }
    // Vitória em Coluna(computador)
    if (tabuleiro[0][0] == 'X' && tabuleiro [1][0] == 'X' && tabuleiro [2][0] == 'X' ||
            tabuleiro[0][1] == 'X' && tabuleiro [1][1] == 'X' && tabuleiro [2][1] == 'X' ||
            tabuleiro[0][2] == 'X' && tabuleiro [1][2] == 'X' && tabuleiro [2][2] == 'X')
    {
        printf("\n\t\t\t\tO tabuleiro acabou! O jogador 2 ganhou por coluna\n");
        V_imprimirtabuleiro(tabuleiro);
        sleep(5);
        placar[1]+=1;
        return game = 1;
    }


    //verifica se todas posições estão preenchidas
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(tabuleiro[i][j] != ' '){
                flag+=1;
            }
        }
    }

    /*caso tenha passado por todos os IFs
    esse verifica se todas posições estão
    preenchidas, caso esteja significa empate*/
    if (flag == 9){
        printf("\n\t\t\t\tO tabuleiro acabou! EMPATE\n");
        V_imprimirtabuleiro(tabuleiro);
        sleep(5);
        placar[3]+=1;
        return game = 1;
    }



    //mantêm o 0 para o jogo continuar caso ninguem tenha ganho
    return game;



}

//função de inserir no tabuleiro
int inseri_coordenadas(char tabuleiro[][MAX], int jogador, int l, int c){
    // inseri nas cordenadas apontadas
    if (jogador %2 == 0) //player 1
    {
     tabuleiro[l][c] = '0';
    }

    else //player 2
    {
    tabuleiro[l][c] = 'X';
    }

     //troca o jogador
     jogador++;

     return jogador;

}

//impressão do tabuleiro OK FUNCIONANDO
void V_imprimirtabuleiro(char tabuleiro[][MAX])
{
    printf("\t\t\t\t\t\t   0   1   2\n\n");

    printf("\t\t\t\t\t\t0  %c | %c | %c\n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("\t\t\t\t\t\t  ---+---+---\n");
    printf("\t\t\t\t\t\t1  %c | %c | %c\n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("\t\t\t\t\t\t  ---+---+---\n");
    printf("\t\t\t\t\t\t2  %c | %c | %c\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
}

//limpeza do tabuleiro
void V_limpartabuleiro(char tabuleiro[][MAX])
{
    for (int linha = 0; linha < MAX; linha++)
    {
        for (int coluna = 0; coluna < MAX; coluna++)
            tabuleiro[linha][coluna] = ' ';
    }
}

