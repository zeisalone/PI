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


void insertOrd(LInt *l, int x) {
  while (*l && (*l)->valor < x)
    l = &((*l)->prox);
  LInt new = malloc(sizeof(struct lligada));
  new->valor = x;
  new->prox = *l;
  *l = new;
}


int removeOneOrd (LInt *l, int x) {
  while(*l && (*l)->valor < x) 
    l = &((*l)->prox);
    if(!*l || (*l)->valor != x)
      return 1;
  else {
    *l = (*l)->prox;
    return 0;
  }
}


void merge(LInt *r, LInt a,LInt b) {
  while(a!=NULL || b != NULL){
    if( (a != NULL && b != NULL && a->valor < b->valor) || b == NULL){
			*r = a;
			a = a->prox;
		} else {
			*r = b;
			b = b->prox;
		}
		r = &( (*r)->prox);
	}
	*r = NULL;
}

