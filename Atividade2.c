#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento{

struct Elemento* proximo;
int *dado;

}Elemento;

typedef struct Fila{

struct Elemento* head;
struct Elemento* tail;

}Fila;

Fila* criaFila();
Elemento* criaElemento(int);
Elemento* ultimoDaFila(Fila*);
Elemento* removeElemento(Fila*);
int removeMenor(Fila*);
void pqInsert(Fila*,int);
Elemento* pqMinRemove(Fila*);
void mostrarFila(Fila*);


int main(){
    Fila* fila = criaFila();
    pqInsert(fila,80);
    pqInsert(fila,20);
    pqInsert(fila,30);
    pqInsert(fila,40);

    mostrarFila(fila);
    printf("\n");

    removeMenor(fila);

    mostrarFila(fila);
    printf("\n");

    removeMenor(fila);

    mostrarFila(fila);
    printf("\n");



}

//=============================================

Elemento* criaElemento(int dado){

Elemento* elemento = (Elemento*) malloc(sizeof(Elemento));


    if(elemento == NULL){
        printf("Erro na alocacao do elemento");
        return;
    }else{
        elemento->proximo = NULL;
        elemento->dado = dado;
    }
return elemento;
}

//=============================================

Fila* criaFila(){

    Fila* fila = (Fila*) malloc(sizeof(Fila*));

    if(fila == NULL){
        printf("Erro na alocacao da fila");
        return;
    }else{
        fila->head = NULL;
        fila->tail = NULL;

    }
    return fila;
}

//=============================================

void pqInsert(Fila* fila,int dado){
    Elemento* novo_elemento = criaElemento(dado);


    if(novo_elemento == NULL){
        printf("Erro na alocacao");
        return;
    }

    novo_elemento->proximo = NULL;
    if(fila->head == NULL){
        fila->head = novo_elemento;
    }else{
       fila->tail->proximo = novo_elemento;
    }
    fila->tail=novo_elemento;

}

//=============================================

Elemento* removeElemento(Fila* fila){
Elemento* aux = fila->head;
Elemento* dado = (Elemento*) malloc(sizeof(Elemento*));
    if(aux != NULL){
        fila->head = aux->proximo;
        aux->proximo = NULL;
        dado = aux->dado;
        free(aux);
    }else{
        printf("Lista Vazia");
        return;
    }

    return dado;
}

//=============================================

Elemento* ultimoDaFila(Fila* fila){

    return fila->tail;
}

//=============================================

int removeMenor(Fila* fila){

Elemento* excluiMenor = (Elemento*) malloc(sizeof(Elemento*));
Elemento* menor = pqMinRemove(fila);
Elemento* ultimo = ultimoDaFila(fila);
Elemento* proximoFila = NULL;
Elemento* aux = fila->head;

    do{
        proximoFila = removeElemento(fila);
            if(proximoFila == menor){
                excluiMenor = menor;
            }else{
                pqInsert(fila,proximoFila);
            }
    }while(fila->tail != ultimo);


}

//=============================================


Elemento* pqMinRemove(Fila* fila){

Elemento* aux = fila->head;
Elemento* menor = (Elemento*) malloc(sizeof(Elemento*));

while(aux != NULL){
    if(aux->dado<menor){
        menor=aux->dado;
    }
    aux = aux->proximo;
}

return menor;
}




//=============================================

void mostrarFila(Fila* fila){
    Elemento* aux = fila->head;

    while(aux != NULL){
        printf("%i,", aux->dado);
        aux = aux->proximo;
    }
}

//=============================================



