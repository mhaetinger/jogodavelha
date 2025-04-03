//NOME DA DUPLAS - Mateus Haetinger e Luis Fabiano da Silva Oliveira

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

    //define o tamanho usado na matriz
#define MAX 9

    //protótipos de funções
int menu();
void preencher_fixos(int sudoku[][MAX]);
void imprimirSudoku(int sudoku[][MAX]);
void checkQuadrantes(int sudoku[][MAX], int linha, int coluna, int operador);



    //função principal do programa:
int main()
{

        //Linguagem
    setlocale(LC_ALL, "portuguese");

        //Declaração de variaveis
    int sudoku [MAX][MAX];
    int operador, linha, coluna;


        //começa o loop utilizando o menu
    while(1){
        system("cls");

             //Inicia o menu, tem que ser dentro do loop
        int menu_jogo = menu();

        switch(menu_jogo){

            case 1:

                    //preenche o sudoku
                preencher_fixos(sudoku);
                system("cls");

                    //entra em um loop para assim inicar o jogo
                do{
                    //ele por padrão sempre vai imprimir o sudoku atualizado  através dessa função
                imprimirSudoku(sudoku);
                printf("\n");

                    //opção caso o usuario queira para o jogo
                printf("\nDigite 0 para sair!\n");

                    //faz uma verificação para ver se o numero é valido
                do{
                    printf("\nDigite um numero de 1 à 9 que deseja inserir: ");
                    scanf("%d", &operador);
                }while((operador >9) || ( operador <1) && (operador != 0));


                if(operador==00){
                    break;
                }

                    //faz uma verificação para ver se o numero da linha é valido
                do{
                printf("\nDigite a linha que deseja inserir(numero lateral válido): ");
                scanf("%d", &linha);
                }while((linha >9) || ( linha <1));

                //faz uma verificação para ver se o numero da coluna é valido
                do{
                printf("Digite a coluna que deseja inserir(numero acima válido): ");
                scanf("%d", &coluna);
                 }while((coluna >9) || ( coluna <1));

                 //função para checar se a inserção está correta e se é possivel
                checkQuadrantes(sudoku, linha-1, coluna-1, operador);
                }while(operador!=0);

        }
    }
}

//função utilizada para o menu do jogo
int menu() {
    int menu_jogo;

        //entra em um loop para iniciar o menu
    while (1) {
        printf("\n----ESCOLHA QUAL OPCAO DESEJAR----\n");
        printf("\n1 - Iniciar jogo");
        printf("\n2 - Sair");

        printf("\n\nEscolha uma opcao:\n");
        scanf("%d", &menu_jogo);

        if (menu_jogo == 1) {
            return menu_jogo;
        }
        else if(menu_jogo == 2){
            printf("\nSaindoo..");
            exit (0);
        }
        else {
            printf("\nOpção inválida. Tente novamente.\n");
        }
    }
}

//função para inicializar os numeros fixos do sudoku
void preencher_fixos(int sudoku[][MAX]){

    //numeros fixos do sudoku
  int sudoku_fixo[MAX][MAX] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };



    // Copie os valores da matriz temporaria sudoku_fixo para a matriz original
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            sudoku[i][j] = sudoku_fixo[i][j];
        }
    }
}

//função para imprimir tabela sudoku formatada na tela
void imprimirSudoku(int sudoku[MAX][MAX]) {


    // Cabeçalho das colunas
    printf("   1 2 3   4 5 6   7 8 9\n");

        //percorre as linhas
    for (int i = 0; i < MAX; i++) {

            // Números das linhas, imprimi no inicio de cada "for"
        printf("%d  ", i + 1);

            //percorre as colunas
        for (int j = 0; j < MAX; j++) {

                //Substitui os zeros por pontos
            if (sudoku[i][j] == 0) {
                printf(". ");
            }
                //se não imprimi os numeros
            else {
                printf("%d ", sudoku[i][j]);
            }

            //Linhas verticais depois de cada quadrante
            if (j == 2 || j == 5) {
                printf("| ");
            }
        }

            //da um "enter" antes de entrar na proxima linha
        printf("\n");

        // Linhas horizontais depois de cada quadrante, e depois da uma nova linha
        if (i == 2 || i == 5) {
            printf("   ------+-----+------\n");
        }
    }
}

//função para checar se não a outro numero igual na linha, coluna ou quadrante
void checkQuadrantes(int sudoku[][MAX], int linha, int coluna, int operador){


    int i, j;

    // Verifica a linha
    for (i = 0; i < MAX; i++) {
        if (sudoku[linha][i] == operador) {
            printf("\nErro na linha %d, coluna %d: número %d já existe na mesma linha.\n", linha + 1, i + 1, operador);
            return;
        }
    }

    // Verifica a coluna
    for (i = 0; i < MAX; i++) {
        if (sudoku[i][coluna] == operador) {
            printf("\nErro na linha %d, coluna %d: número %d já existe na mesma coluna.\n", i + 1, coluna + 1, operador);
            return;
        }
    }

    /* Calcula o início do quadrante
    no caso calcula qual seria o canto esquerdo de cada quadrante*/
    int linhaInicio = linha - (linha % 3);
    int colunaInicio = coluna - (coluna % 3);

    // Verifica o quadrante
    for (i = linhaInicio; i < linhaInicio + 3; i++) {
        for (j = colunaInicio; j < colunaInicio + 3; j++) {
            if (sudoku[i][j] == operador) {
                printf("\nErro de quadrante, linha %d, coluna %d: número %d já existe no quadrante.\n",  i + 1, j + 1, operador);
                return;
            }
        }
    }

    // Se passou por todas as verificações, o número pode ser inserido na célula
    sudoku[linha][coluna] = operador;
    printf("\nNúmero %d inserido com sucesso na linha %d, coluna %d.\n", operador, linha + 1, coluna + 1);
}

