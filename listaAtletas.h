
/**
 * @file listaAtletas.h
 * @author Reinaldo Pires  
 * @brief 
 * 
 * @date 2022-04-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef LISTAATLETAS_H
#define LISTAATLETAS_C

typedef struct _atleta
{
   int pos;
   char *esc;
   int posEsc;
   int dorsal;
   char *nome;
   char *sexo;
   char *tempo;
   struct _atleta* next;
   struct _atleta* prev;
   
}Atleta;
 typedef struct _l 
 {
    int total; 
    Atleta*first;
    Atleta*last;
    
 }listaatletas;

 listaatletas* newlistaatletas();


 void freeList(listaatletas *l);

 void addAtleta(listaatletas *l, int pos, char *esc, int posEsc, int dorsal, char *nome, char *sexo, char *tempo);

 void printListaAtleta(listaatletas *l,int dorsalinput);

 


#endif







