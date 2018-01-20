#include <stdio.h>

#define MAXPILHA 20 //tamanho maximo da pilha

struct pilha {
    int topo;
    int item [MAXPILHA];
};

//funcao para inicializar a pilha
void iniciaPilha(struct pilha *p) {
    p->topo = -1;
}

//funcao para esvaziar pilha
int esvaziaPilha(struct pilha *p) {
    while(p->topo > -1) {
        p->item[p->topo] = -1; //usamos -1 para evitar trabalhar com valores nulos
        p->topo = p->topo - 1; //diminui a posicao do topo
    }
    return 0;
    
}

//funcao para retornar a posicao do topo da pilha
int topo(struct pilha *p) {
    return p->topo;
    
}

//funcao para verificar se a pilha está vazia
int pilhaVazia(struct pilha *p) {
   if (p->topo == -1) 
    return 1; //verdadeiro é 1
   else
    return 0; //falso é 0

}

//funcao para verificar se a pilha está cheia
int pilhaCheia(struct pilha *p) {
    if (p->topo + 1 == MAXPILHA) 
    return 1; //verdadeiro é 1
   else
    return 0; //falso é 0
    
}

//funcao para empilhar um elemento na pilha
int empilha(int d, struct pilha *p) {
    if(pilhaCheia(p) == 0) {
        p->topo = p->topo + 1;
        p->item[p->topo] = d;
        
    }
    return 0;
}

//funcao para desempilhar o primeiro elemento da fila
int desempilha(int d, struct pilha *p) {
    if(pilhaVazia(p) == 0) {
        int retorno = p->item[p->topo];
        p->item[p->topo] = -1; //usamos -1 para evitar trabalhar com valores nulos
        p->topo = p->topo - 1;
    }
    return 0;
    
}



int main()
{
    struct pilha *variavel_pilha; //cria uma variavel do tipo "pilha"
    iniciaPilha(variavel_pilha); //inicializa a pilha
    empilha(9,variavel_pilha); //empilha o numero 9
    printf("%d\n",variavel_pilha->item[topo(variavel_pilha)]);

    return 0;
}



