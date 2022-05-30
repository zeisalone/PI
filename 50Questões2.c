#include <stdlib.h>

typedef struct lligada {
int valor;
struct lligada *prox;
} *LInt;

int length (LInt l) {
  int r = 0;
  while(l!=0) {
    l = l->prox;
    r++;
  }
  return r;
}


void freeL (LInt l) {
  LInt aux = NULL;
  while(l!=0) {
    aux = l;
    l=l->prox;
    free(aux);
  }
}


void imprimeL (LInt l) {
  while(l!=0) {
    printf("%d\n",l->valor);
    l = l->prox;
  }
}


LInt reverseL (LInt l) {
  LInt r = NULL;
  LInt aux = NULL;
  while(l!=0) {
    aux = l;
    l = l->prox;
    aux->prox = r;
    r = aux;
  }
  return r;
}


