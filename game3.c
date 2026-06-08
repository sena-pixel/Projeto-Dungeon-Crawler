#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void mostrarmapa(char mapa[10][10], int linha_jogador, int coluna_jogador, char direcao) {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (i == linha_jogador && j == coluna_jogador) {
                printf("%c ", direcao);
            } else {
                printf("%c ", mapa[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int opcao;
    int linha_jogador = 5;
    int coluna_jogador = 4;
    char direcao = 'A'; 
    char comando;
    int arma = 0;
    int fase = 0; 
    int tem_chave = 0;
    int tem_pocao = 0;
    int vida_chefe = 30;
    int vidas = 3;

    char vila[10][10] = {
        {'*','*','*','*','*','*','*','*','*','*'},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        {'*',' ','N',' ',' ',' ',' ',' ',' ','*'},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        {'*',' ',' ',' ',' ',' ',' ',' ','L','*'},
        {'*','*','*','*','*','*','*','*','*','*'}
    };

    char andar1[15][15] = {
{'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
{'*',' ','@',' ',' ',' ',' ','D',' ',' ',' ',' ',' ',' ','*'},
{'*',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
{'*',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ','*'},
{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
{'*',' ',' ',' ',' ','O',' ',' ',' ',' ',' ',' ',' ',' ','*'},
{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
{'*',' ','@',' ',' ',' ',' ','D',' ',' ',' ',' ',' ',' ','*'},
{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','L','*'},
{'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'}
};

char boss[25][25] = {
{'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'},
{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','D',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
{'*',' ','@',' ','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*',' ',' ',' ','@',' ','*'},
{'*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*'},
{'*',' ',' ',' ','*',' ','#','#','#','#','#','#','#','#','#','#',' ',' ','*',' ',' ',' ',' ',' ','*'},
{'*',' ',' ',' ','*',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','*',' ',' ',' ',' ',' ','*'},
{'*',' ',' ',' ','*',' ','#',' ','Y',' ',' ',' ',' ',' ',' ','#',' ',' ','*',' ',' ',' ',' ',' ','*'},
{'*',' ',' ',' ','*',' ','#',' ',' ',' ',' ','O',' ',' ',' ','#',' ',' ','*',' ',' ',' ',' ',' ','*'},
{'*',' ',' ',' ','*',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','*',' ',' ',' ',' ',' ','*'},
{'*',' ',' ',' ','*',' ','#','#','#','#','D','#','#','#','#','#',' ',' ','*',' ',' ',' ',' ',' ','*'},
{'*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*'},
{'*',' ',' ',' ','*','*','*','*','*','*','*',' ','*','*','*','*','*','*','*',' ',' ',' ',' ',' ','*'},
{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','Z',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
{'*',' ',' ',' ','*','*','*','*','*','*','*',' ','*','*','*','*','*','*','*',' ',' ',' ',' ',' ','*'},
{'*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*'},
{'*',' ',' ',' ','*',' ','#','#','#','#','D','#','#','#','#','#',' ',' ','*',' ',' ',' ',' ',' ','*'},
{'*',' ',' ',' ','*',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','*',' ',' ',' ',' ',' ','*'},
{'*',' ',' ',' ','*',' ','#',' ',' ',' ',' ','O',' ',' ',' ','#',' ',' ','*',' ',' ',' ',' ',' ','*'},
{'*',' ',' ',' ','*',' ','#',' ','Y',' ',' ',' ',' ',' ',' ','#',' ',' ','*',' ',' ',' ',' ',' ','*'},
{'*',' ',' ',' ','*',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ','*',' ',' ',' ',' ',' ','*'},
{'*',' ',' ',' ','*',' ','#','#','#','#','#','#','#','#','#','#',' ',' ','*',' ',' ',' ',' ',' ','*'},
{'*',' ',' ',' ','*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*'},
{'*',' ','@',' ','*','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*','*','*',' ',' ',' ','@',' ','*'},
{'*',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','L',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','*'},
{'*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*','*'}
};

    do {
        system("cls");
        printf("\n======= MENU =======\n");
        printf("1 - Jogar\n");
        printf("2 - Tutorial\n");
        printf("3 - Sair\n");
        printf("Escolha: ");
        if (scanf("%d", &opcao) != 1) {
            opcao = 0;
            fflush(stdin);
        }

        switch (opcao) {
            case 1:
                linha_jogador = 5;
                coluna_jogador = 4;
                direcao = 'A';
                fase = 0;
                vidas = 3;
                tem_chave = 0;
                tem_pocao = 0;
                vida_chefe = 30;

                do {
                    system("cls");
                    char (*mapaatual)[10];

                    if (fase == 0) {
                        mapaatual = vila;
                    } else if (fase == 1) {
                        mapaatual = andar1;
                    } else {
                        mapaatual = boss;
                    }

                    mostrarmapa(mapaatual, linha_jogador, coluna_jogador, direcao);

                    printf("\nChave: %s\n", tem_chave ? "SIM" : "NAO");
                    printf("Pocao: %s\n", tem_pocao ? "SIM" : "NAO");
                    printf("Vida: %d\n", vidas);
                    printf("Arma: ");
                    if (arma == 1) printf("Espada\n");
                    else if (arma == 2) printf("Arco\n");
                    else if (arma == 3) printf("Cajado\n");
                    else printf("Nenhuma\n");

                    if (fase == 2) {
                        printf("Vida do Chefe: %d\n", vida_chefe);
                    }

                    printf("\n[W A S D] Mover | [I] Interagir | [O] Atacar | [P] Pocao | [Q] Sair\n");
                    comando = _getch();

                    int proxima_linha = linha_jogador;
                    int proxima_coluna = coluna_jogador;

                    if (comando == 'w' || comando == 'W') {
                        proxima_linha--;
                        direcao = 'A';
                    } else if (comando == 'a' || comando == 'A') {
                        proxima_coluna--;
                        direcao = '<';
                    } else if (comando == 's' || comando == 'S') {
                        proxima_linha++;
                        direcao = 'V';
                    } else if (comando == 'd' || comando == 'D') {
                        proxima_coluna++;
                        direcao = '>';
                    }

                    if (comando == 'w' || comando == 'W' || comando == 'a' || comando == 'A' || comando == 's' || comando == 'S' || comando == 'd' || comando == 'D') {
                        char destino = mapaatual[proxima_linha][proxima_coluna];
                        if (destino != '*' && destino != 'D' && destino != 'k' && destino != 'N' && destino != 'B') {
                            linha_jogador = proxima_linha;
                            coluna_jogador = proxima_coluna;
                        }
                    }

                    if (fase == 1 && mapaatual[linha_jogador][coluna_jogador] == 'M') {
                        vidas--;
                        printf("\nVoce colidiu com um monstro e perdeu 1 vida!\n");
                        linha_jogador = 1;
                        coluna_jogador = 1;
                        _getch();
                        if (vidas <= 0) break;
                    }

                    if (fase == 1 && mapaatual[linha_jogador][coluna_jogador] == '@') {
                        tem_chave = 1;
                        mapaatual[linha_jogador][coluna_jogador] = ' ';
                        printf("\nVoce pegou a chave!\n");
                        _getch();
                    }

                    if (linha_jogador == 8 && coluna_jogador == 8 && mapaatual[linha_jogador][coluna_jogador] == 'L') {
                        if (fase == 0) {
                            printf("\nEntrando na masmorra...\n");
                            fase = 1;
                            linha_jogador = 1;
                            coluna_jogador = 1;
                        } else if (fase == 1) {
                            printf("\nEntrando na sala do chefe...\n");
                            fase = 2;
                            linha_jogador = 8;
                            coluna_jogador = 4;
                        }
                        _getch();
                    }

                    if (comando == 'i' || comando == 'I') {
                        int alvo_linha = linha_jogador;
                        int alvo_coluna = coluna_jogador;

                        if (direcao == 'A') alvo_linha--;
                        else if (direcao == 'V') alvo_linha++;
                        else if (direcao == '<') alvo_coluna--;
                        else if (direcao == '>') alvo_coluna++;

                        char alvo = mapaatual[alvo_linha][alvo_coluna];

                        if (fase == 0 && alvo == 'N') {
                            printf("\n=== ESCOLHA A ARMA ===\n");
                            printf("1 - Espada\n2 - Arco\n3 - Cajado\nEscolha: ");
                            scanf("%d", &arma);
                            fflush(stdin);
                            if (arma == 1) printf("Voce escolheu a Espada!\n");
                            else if (arma == 2) printf("Voce escolheu o Arco!\n");
                            else if (arma == 3) printf("Voce escolheu o Cajado!\n");
                            _getch();
                        } else if (fase == 1 && alvo == 'D') {
                            if (tem_chave) {
                                tem_chave = 0;
                                mapaatual[alvo_linha][alvo_coluna] = ' ';
                                printf("\nPorta aberta com sucesso!\n");
                            } else {
                                printf("\nVoce precisa de uma chave (@) para abrir esta porta!\n");
                            }
                            _getch();
                        } else if (fase == 1 && alvo == 'k') {
                            mapaatual[alvo_linha][alvo_coluna] = ' ';
                            tem_pocao = 1;
                            printf("\nVoce destruiu a caixa e encontrou uma pocao!\n");
                            _getch();
                        }
                    }

                    if (comando == 'o' || comando == 'O') {
                        if (arma == 0) {
                            printf("\nVoce esta desarmado! Fale com o NPC na Vila.\n");
                            _getch();
                        } else {
                            int alvo_linha = linha_jogador;
                            int alvo_coluna = coluna_jogador;

                            if (direcao == 'A') alvo_linha--;
                            else if (direcao == 'V') alvo_linha++;
                            else if (direcao == '<') alvo_coluna--;
                            else if (direcao == '>') alvo_coluna++;

                            if (fase == 1 && mapaatual[alvo_linha][alvo_coluna] == 'M') {
                                mapaatual[alvo_linha][alvo_coluna] = ' ';
                                printf("\nInimigo derrotado! A escada para o Boss apareceu.\n");
                                _getch();
                            } else if (fase == 2 && mapaatual[alvo_linha][alvo_coluna] == 'B') {
                                vida_chefe -= 10;
                                printf("\nVoce acertou o chefe! Ele sofreu 10 de dano.\n");
                                _getch();
                                if (vida_chefe <= 0) {
                                    mapaatual[alvo_linha][alvo_coluna] = ' ';
                                    printf("\n=================================");
                                    printf("\nPARABENS! VOCE DERROTOU O CHEFE!");
                                    printf("\n=================================\n");
                                    _getch();
                                    break;
                                }
                            } else {
                                printf("\nVoce atacou o vento...\n");
                                _getch();
                            }
                        }
                    }

                    if ((comando == 'p' || comando == 'P') && tem_pocao == 1) {
                        vidas = 3;
                        tem_pocao = 0;
                        printf("\nVida totalmente restaurada!\n");
                        _getch();
                    }

                    if (fase == 2 && vida_chefe > 0) {
                        vidas--;
                        printf("\nO ambiente hostil do Boss drena suas forças! Você perdeu 1 vida.\n");
                        _getch();
                    }

                    if (vidas <= 0) {
                        printf("\n=== GAME OVER ===\n");
                        printf("Voce perdeu todas as suas vidas.\n");
                        _getch();
                        break;
                    }

                } while (comando != 'q' && comando != 'Q');
                break;

            case 2:
                system("cls");
                printf("\n======= CONTROLES =======\n");
                printf("W - Mover para Cima (A)\n");
                printf("A - Mover para Esquerda (<)\n");
                printf("S - Mover para Baixo (V)\n");
                printf("D - Mover para Direita (>)\n");
                printf("I - Interagir com objetos a sua frente\n");
                printf("O - Atacar inimigos na sua frente\n");
                printf("P - Usar pocao de cura\n");
                printf("Q - Sair da partida atual\n");
                printf("=========================\n");
                printf("Pressione qualquer tecla para voltar...");
                _getch();
                break;

            case 3:
                printf("\nSaindo do jogo... Ate a próxima aventura!\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                _getch();
                break;
        }
    } while (opcao != 3);

    return 0;
}