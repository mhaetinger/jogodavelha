# Projeto Final: Jogo da Velha e Sudoku

## Descrição

Este projeto é uma implementação de dois jogos clássicos: **Jogo da Velha** e **Sudoku**. O código foi desenvolvido como parte do trabalho final para a disciplina de **Resolução de Problemas**, utilizando a linguagem **C**. Ambos os jogos são executados no console e oferecem uma interface interativa para o usuário.

### Funcionalidades

#### **Jogo da Velha**:
- **Modo Player vs Player**: Dois jogadores podem se enfrentar no jogo da velha, jogando com os símbolos 'O' e 'X'.
- **Modo Player vs Computador**: Um jogador compete contra o computador, onde o computador faz suas jogadas aleatoriamente.
- **Placar**: O jogo mantém um placar para os jogadores, exibindo vitórias e empates.
- **Verificação de Vitória**: O sistema verifica automaticamente se algum jogador ganhou ou se houve empate.

#### **Sudoku**:
- **Tabuleiro Fixo**: O jogo começa com um Sudoku parcialmente preenchido, onde o jogador pode preencher as casas vazias.
- **Validação**: O sistema valida automaticamente a jogada do jogador, garantindo que o número inserido não viole as regras do Sudoku (sem repetições na linha, coluna ou quadrante).
- **Interface**: O Sudoku é exibido no terminal com uma interface amigável, e os jogadores podem interagir com ele para tentar resolver o puzzle.

## Como Rodar

### **Jogo da Velha**:

1. Compile o código utilizando o seguinte comando:
   ```bash
   gcc -o jogo_da_velha jogo_da_velha.c
