#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento{
    struct Elemento *proximo;
    int dado; //Depende do tipo de dados que se deseja trabalhar
} Elemento;



typedef struct Fila{

    struct Elemento* head;
    struct Elemento* tail;
    int size;

}Fila;

Fila* criaFila();
Elemento* criaElemento(int);
void insereElemento(Fila*,int);
int removeElemento(Fila*);
Elemento* encontraCarro(Fila*,int);
Elemento* primeiroDaFila(Fila*);
Elemento* ultimoDaFila(Fila*);
Elemento* removeCarro(Fila*,int);
void mostrarFila(Fila*);
void liberarFila(Fila*);

int main(){

    Fila* fila = criaFila();
    insereElemento(fila,10);
    insereElemento(fila,20);
    insereElemento(fila,30);
    insereElemento(fila,40);
    insereElemento(fila,50);

    mostrarFila(fila);

    removeCarro(fila,50);
    printf("\n");

    mostrarFila(fila);

}

//=============================================

Elemento* criaElemento(int dado){
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    novo->proximo = NULL;
    novo->dado = dado;
    return novo;
}

//=============================================

Fila* criaFila(){
  Fila* lista = (Fila*) malloc(sizeof(Fila));
  lista->head = NULL;
  lista->tail = NULL;
  lista->size = 0;

  return lista;
}

//=============================================

void insereElemento(Fila* fila,int dado){
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
    fila->size++;
}

//=============================================

int removeElemento(Fila* fila){
    Elemento* aux = fila->head;
    int dado;
    if(aux != NULL){
        fila->head = aux->proximo;
        aux->proximo = NULL;
        dado = aux->dado;
        free(aux);
    }else{
        printf("Lista Vazia");
        return -1;
    }
    fila->size--;

    return dado;
}

//=============================================

Elemento* encontraCarro(Fila* fila, int carro){
    Elemento* aux = fila->head;
    Elemento* carroEscolhido = (Elemento*) malloc(sizeof(Elemento*));
    int cont = 0;
    while(aux!=NULL){
        if(aux->dado == carro){
             carroEscolhido->dado = aux->dado;
             printf("\nVaga %i: Carro encontrado;", cont);
        }
        aux = aux->proximo;
        cont++;
    }
    return carroEscolhido;
}

//=============================================

Elemento* primeiroDaFila(Fila* fila){

    return fila->head;
}
Elemento* ultimoDaFila(Fila* fila){

    return fila->tail;
}

//=============================================

Elemento* removeCarro(Fila* fila,int carro){

    Elemento* foraEstacionamento = (Elemento*) malloc(sizeof(Elemento*));
    Elemento* carroEscolhido = encontraCarro(fila,carro);
    Elemento* foraEst;
    Elemento* primeiro = primeiroDaFila(fila);
    Elemento* ultimo = ultimoDaFila(fila);
    int proximoFila;
    Elemento* aux = fila->head;

    do{
        if(carroEscolhido->dado != primeiro->dado){
            proximoFila = removeElemento(fila);
        }else{
            int i = removeElemento(fila);
            foraEst = criaElemento(i);
            return foraEst;
        }
        if(proximoFila == carroEscolhido->dado){
            foraEstacionamento = carroEscolhido;
        }else{
            insereElemento(fila,proximoFila);
        }
    }while(fila->head != primeiro);

    return foraEstacionamento;

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

void liberarFila(Fila* fila){
    Elemento* aux = fila->head;

    while(aux != NULL){
        free(aux);
        aux = aux->proximo;
        printf("Fila liberada");
    }
}
