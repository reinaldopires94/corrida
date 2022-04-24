/**
 * @file listaAtletas.c
 * @author Reinaldo Pires  
 * @brief
 * 
 * @date 2022-04-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaAtletas.h"

listaatletas *newlistaatletas()

{     // locar a memoria e inicializacao das variveis
    listaatletas *l = malloc(sizeof(listaatletas));
    l->total = 0;
    l->first = NULL;
    l->last = NULL;
    return l;
}

void freeList(listaatletas *l)
{
    // Apagar elementos da lista 
    Atleta *tmp, *atleta = l->first;
    while (atleta)
    {

        free(atleta->esc);
        free(atleta->nome);
        free(atleta->sexo);
        free(atleta->tempo);
        tmp = atleta->next;
        free(atleta);
        atleta = tmp;
    }
    //liberar memoria 
    free(l);
}
// add o Atleta
void addAtleta(listaatletas *l, int pos, char *esc, int posEsc, int dorsal, char *nome, char *sexo, char *tempo)
{
    Atleta *atleta = malloc(sizeof(Atleta));
    atleta->pos = pos;
    atleta->esc = malloc(strlen(esc) + 1);
    memset(atleta->esc, '\0', strlen(esc) + 1);
    strcpy(atleta->esc, esc);
    atleta->posEsc = posEsc;
    atleta->nome = malloc(strlen(nome) + 1);
    memset(atleta->nome, '\0', strlen(nome) + 1);
    strcpy(atleta->nome, nome);
    atleta->sexo = malloc(strlen(sexo) + 1);
    memset(atleta->sexo, '\0', strlen(sexo) + 1);
    strcpy(atleta->sexo, sexo);
    atleta->dorsal = dorsal;
    atleta->tempo = (malloc(strlen(tempo) + 1));
    memset(atleta->tempo, '\0', strlen(tempo) + 1);
    strcpy(atleta->tempo, tempo);

    
    if (!l->first)
    { // l->first==NULL
        atleta->next = NULL;
        atleta->prev = NULL;
        l->first = atleta;
        l->last = atleta;
        l->total++;
        return;
    }

    Atleta *busca = l->first;
    while (busca)
    {

        // condição se é repetido
        if (busca->dorsal == dorsal)
        {
            free(atleta);
            return;
        }
        // ver se é a posição
        if (busca->dorsal > dorsal)
            break;
        busca = busca->next;
    }

    // Inserir no fim
    if (busca == NULL)
    {
        atleta->next = NULL;
        atleta->prev = l->last;
        l->last->next = atleta;
        l->last = atleta;
        l->total++;
        return;
    }

    // Inserir no inicio da lista
    if (busca == l->first)
    {
        atleta->prev = NULL;
        atleta->next = l->first;
        l->first->prev = atleta;
        l->first = atleta;
        l->total++;
        return;
    }

    
    atleta->next = busca;
    atleta->prev = busca->prev;
    busca->prev = atleta;
    atleta->prev->next = atleta;
    l->total++;
}
// print apos o input do dorsal 
void printListaAtleta(listaatletas *l, int dorsalinput)
{
    // if caso o user coloque um numero < 0 (Ex. -3, -4)
    Atleta *atleta = l->first;
    if (dorsalinput < 0)
    {
        printf("ERRO! Número de dorsal inválido\n");
        return;
    }
    // if para o user sair do app
    if (dorsalinput == 0)
    {
        printf("A sair. Obrigado\n");
        return;
    }

    while (atleta)
    {
        // saida no ecra apos o user colocar o dorsal correto 
        if (dorsalinput == atleta->dorsal)
        {
            printf("---------------------");
            printf("\nAtleta: %s", atleta->nome);
            printf("\nSexo: %s", atleta->sexo);
            printf("\nEscalão: %s", atleta->esc);
            printf("\nPos. Geral: %d", atleta->pos);
            printf("\nPos. Escalão: %d", atleta->posEsc);
            printf("\nTempo Prova: %s", atleta->tempo);
            printf("---------------------\n");
            return;
        }
        if (atleta->dorsal > dorsalinput)
        {
            printf("Erro! Atleta não existe\n");
            return;
        }

        atleta = atleta->next;
    }
}
