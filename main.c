
/**
 *
 * @author Reinaldo
 * @brief Projeto Corrida
 * @date 2022-04-20
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaAtletas.h"

int main(int argc, char const *argv[])
{
    // obrigatorio 2 argumentos para entrar no app (Ex. ->  ./corrida results-atec.txt)
    if (argc != 2)                                   
    {
        return EXIT_FAILURE;
    }

    // ponteiro do ficheiro (tipo file) em modo de leitura
    FILE *file = fopen(argv[1], "r");
    // Mensagem de ERRO caso o USER, insira um ficheiro que existe.
    if (file == NULL)
    {
        puts("ERRO! ficheiro não encontrado");
        return EXIT_FAILURE;
    }
    
    listaatletas *corrida = newlistaatletas();
    int pos;
    char *esc;
    int posEsc;
    int dorsal;
    char *nome;
    char *sexo;
    char *tempo;
    char *token;
    char linha[1024];
    memset(linha, '\0', 1024);
    
    // ciclo while para o ponteiro 
    int contador = 0;
    while (fgets(linha, 1024 - 1, file))
    {
        if (contador == 0)
        {
            contador++;
            memset(linha, '\0', 1024);
            continue;
        }
        token = strtok(linha, "\t");
        pos = atoi(token); // atoi -> transforma int em string
        esc = strtok(NULL, "\t");
        token = strtok(NULL, "\t");
        posEsc = atoi(token);
        token = strtok(NULL, "\t");
        dorsal = atoi(token);
        nome = strtok(NULL, "\t");
        sexo = strtok(NULL, "\t");
        tempo = strtok(NULL, "\t");

        addAtleta(corrida, pos, esc, posEsc, dorsal, nome, sexo, tempo);

        memset(linha, '\0', 1024);
    }
    // fechar o ficheiro
    fclose(file);
    int dorsalinput;
    // ciclo do/while e interface para apresentação do app
    do
    {
        printf("Insira Nº dorsal -> ");
        scanf("%i", &dorsalinput);
        
        printListaAtleta(corrida,dorsalinput);
        
        
    } while (dorsalinput!=0);
    
        // Libertação de memoria
        freeList(corrida);
    return EXIT_SUCCESS;
}