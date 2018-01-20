#include <stdio.h>

#define MAXFILA 20 //tamanho maximo da fila

struct fila {
    int inicio,fim;
    int item [MAXFILA];
};

//funcao para inicializar a fila
void iniciaFila(struct fila *f) {
    f->inicio = MAXFILA-1; //esta fila circular se move no sentido da figura do slide!
    f->fim = MAXFILA-1;
}

//funcao para verificar se a fila está vazia
int filaVazia(struct fila *f) {
   if (f->inicio == f->fim) 
    return 1; //verdadeiro é 1
   else
    return 0; //falso é 0

}

//funcao para verificar se a fila está cheia
int filaCheia(struct fila *f) {
   if(f->fim==MAXFILA-1)
    return(f->inicio==0);
   else
    return(f->inicio==((f->fim)+1));
    
}

//funcao para remover um elemento da fila
int desenfileira(struct fila *f) {
    if(filaVazia(f) == 0) {
        //desloca o indicador de inicio
        if(f->inicio == MAXFILA-1)
            f->inicio = 0;
        else
            f->inicio = f->inicio + 1;
        return f->item[f->inicio]; 
    }
    
    
}

//funcao para enfileirar um elemento na fila
void enfileira(int d, struct fila *f) {
    if(filaCheia(f) == 0) {
        //desloca o indicador de fim
        if(f->fim == MAXFILA-1)
            f->fim = 0;
        else
            f->fim = f->fim + 1;
        f->item[f->fim] = d; //insere o elemento no fim da fila
    }
    return;
}

int main()
{
    struct fila *variavel_fila; //cria uma variavel do tipo "fila"
    iniciaFila(variavel_fila); //inicializa a fila
    enfileira(9,variavel_fila); //enfileira o numero 9
    //desenfileira e imprime o numero 9
    printf("%d\n",desenfileira(variavel_fila));

    return 0;
}



