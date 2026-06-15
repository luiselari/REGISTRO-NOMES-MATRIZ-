#include <stdio.h>
#include <string.h>

#define MAX_REGISTROS 30
#define MAX_LETRAS    60

int main() {

    ////// incluir //////

    char registro_nomes[MAX_REGISTROS][MAX_LETRAS];
    int i;
    int encontrado;
    int total = 0;

    for (i = 0; i < MAX_REGISTROS; i++) {
        registro_nomes[i][0] = '\0';
    }

    char nome_novo[MAX_LETRAS];

    printf("Digite o nome: ");
    scanf(" %[^\n]", nome_novo);

    encontrado = 0;
    for (i = 0; i < MAX_REGISTROS; i++) {
        if (strcmp(registro_nomes[i], nome_novo) == 0) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado == 1) {
        printf("\n Este nome ja existe, por favor crie um nome unico\n");

    } else if (total >= MAX_REGISTROS) {
        printf("\n Memoria insuficiente!\n");

    } else {
        for (i = 0; i < MAX_REGISTROS; i++) {
            if (registro_nomes[i][0] == '\0') {
                strcpy(registro_nomes[i], nome_novo);
                total++;
                printf("\n Registro salvo!\n");
                printf("Aluno %d: %s\n", i + 1, registro_nomes[i]);
                break;
            }
        }
    }

    //////// Menu de comandos: /////////

    int menu;

    do {

       
        printf("\n ************** menu ************ \n");
        printf("\n 1 - Adicionar nomes \n");
        printf("\n 2 - Buscar registro \n");
        printf("\n 3 - Modificar nome\n");
        printf("\n 4 - Apagar registro de nome\n");
        printf("\n 5 - Exibir lista de registro de nomes\n");
        printf("\n 6 - Encerrar programa\n");  

        printf("\n ******* Digite o comando que deseja executar: ******* \n\n");

        scanf(" %d", &menu);

        switch (menu) {
            
            //////////////// Adicionar nomes novos ////////////
            case 1: {
                char nome_novo2[MAX_LETRAS];

                printf("\n Digite o nome: ");
                scanf(" %[^\n]", nome_novo2);

                encontrado = 0;
                for (i = 0; i < MAX_REGISTROS; i++) {
                    if (strcmp(registro_nomes[i], nome_novo2) == 0) {
                        encontrado = 1;
                        break;
                    }
                }

                if (encontrado == 1) {
                    printf("\n Este nome ja existe, por favor crie um nome unico\n");

                } else if (total >= MAX_REGISTROS) {
                    printf("\n Memoria insuficiente!\n");

                } else {
                    for (i = 0; i < MAX_REGISTROS; i++) {
                        if (registro_nomes[i][0] == '\0') {
                            strcpy(registro_nomes[i], nome_novo2);
                            total++;
                            printf("\n Registro salvo!\n");
                            printf("%d: %s\n", i + 1, registro_nomes[i]);
                            break;
                        }
                    }
                }

                break;
            }
            

            ///////////// buscar ///////////////////

            case 2: {
                char buscar_nome[MAX_LETRAS];

                printf("\n Digite o nome para buscar:\n");
                scanf(" %[^\n]", buscar_nome);

                encontrado = 0;
                for (i = 0; i < MAX_REGISTROS; i++) {
                    if (strcmp(registro_nomes[i], buscar_nome) == 0) {
                        printf("Encontrado no indice %d: %s\n", i, registro_nomes[i]);
                        encontrado = 1;
                        break;
                    }
                }

                if (encontrado == 0) {
                    printf("\n Nome nao encontrado nos registros.\n");
                }

                break;
            }

            ///////////// Modificar nome ///////////////

            case 3: {
                char modificar_nome[MAX_LETRAS];

                printf("\n Digite o nome para buscar:\n");
                scanf(" %[^\n]", modificar_nome);

                encontrado = 0;
                for (i = 0; i < MAX_REGISTROS; i++) {
                    if (strcmp(registro_nomes[i], modificar_nome) == 0) {
                        char nome_novo2[MAX_LETRAS];
                        printf("\n Digite o novo nome:\n");
                        scanf(" %[^\n]", nome_novo2);
                        strcpy(registro_nomes[i], nome_novo2);
                        printf("\n Nome modificado com sucesso!\n");
                        encontrado = 1;
                        break;
                    }
                }

                if (encontrado == 0) {
                    printf("\n Nome nao encontrado nos registros.\n");
                }

                break;
            }

            ///////////// Apagar registro de nome ///////////////

            case 4: {
                char apagar_nome[MAX_LETRAS];

                printf("\n Digite o nome para buscar:\n");
                scanf(" %[^\n]", apagar_nome);

                encontrado = 0;
                for (i = 0; i < MAX_REGISTROS; i++) {
                    if (strcmp(registro_nomes[i], apagar_nome) == 0) {
                        registro_nomes[i][0] = '\0';
                        total--;
                        printf("\n Registro de nome apagado com sucesso!\n");
                        encontrado = 1;
                        break;
                    }
                }

                if (encontrado == 0) {
                    printf("\n Nome nao encontrado nos registros.\n");
                }

                break;
            }

            ///////////// Exibir listra de registro de nomes ///////////////

            case 5:
                printf("\n Lista de registro de nomes:\n");
                for (i = 0; i < MAX_REGISTROS; i++) {
                    if (registro_nomes[i][0] != '\0') {
                        printf("\n %d: %s\n", i + 1, registro_nomes[i]);
                    }
                }
                break;

            default:
                printf("\n Comando invalido, por favor digite um comando valido.\n");

            
        }

    } while(menu != 6);


        return 0;
    }