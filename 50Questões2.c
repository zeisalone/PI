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

void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
   while(l!=NULL) {
       if(l->valor < x) {
           *mx = l;
            mx = &((*mx)->prox);
       }else{
           *Mx = l;
           Mx = &((*Mx)->prox);
       }
        l = l->prox;    
   }
    *mx = NULL; *Mx = NULL;
}

LInt parteAmeio (LInt *l){
    int meio = length(*l)/2;
    int i;
    if(meio == 0) 
    	return NULL;
    
    LInt y = (*l);
    LInt prev = NULL;
    for(i = 0; i < meio; i++) {
        prev = (*l);
        (*l) = (*l)->prox;
    }
    prev->prox = NULL;
    return y;
}

int removeAll(LInt *l, int x) {
    int rem = 0;
    LInt prev = NULL;
    while(*l) {
        if((*l)->valor == x) {
            if(!prev) (*l) = (*l)->prox;
            else prev->prox = (*l)->prox;
            rem++;
        }
        else {
            prev = (*l);
            l = &((*l)->prox);
        }
    }
    return rem;
}

int removeDups (LInt *l){
    int cont = 0;
    LInt temp, ret;
    while(*l!=NULL){
        ret = *l;
        l = &((*l)->prox);
        while(*l!=NULL){
            if((*l)->valor == ret->valor){
                temp = *l;
                *l = (*l)->prox;
                free(temp);
                cont++;
            }else
                l = &((*l)->prox);
        }
        l = &ret;
        l = &((*l)->prox);
    }
    return cont;
}

int removeMaiorL (LInt *l){
    int max = (*l)->valor;
    LInt maior = *l, anterior, maiorAnt = NULL, lista=*l;
        while(lista != NULL) {
            if(max < lista->valor){
                maiorAnt = anterior;
                max = lista->valor;
                maior = lista; 
            }
            anterior = lista;
            lista = lista->prox;
        }
        if(maiorAnt != NULL) maiorAnt->prox = maior->prox;
        else *l = (*l)->prox;
        free(maior);
        
    return max;
}

void init (LInt *l){
    LInt temp;
    while(*l!=NULL){
        if((*l)->prox != NULL)
            l = &((*l)->prox);
        else{
            temp = *l;
            *l = (*l)->prox;
            free(temp);
        }
    }
}

void appendL (LInt *l, int x){
    while(*l!=NULL) 
        l = &((*l)->prox);
        *l = malloc(sizeof(struct lligada));
        (*l)->valor = x; (*l)->prox = NULL;
    ;
}

void concatL (LInt *a, LInt b){
    while(*a!=NULL)
        a = &((*a)->prox);
    *a = b;
}

LInt cloneL (LInt l){
    LInt nova; LInt *point = (&nova);
    while(l!=NULL){
        *point = malloc(sizeof(struct lligada));
        (*point)->valor = l->valor;
        point = &((*point)->prox);
        l = l->prox;
    }
    *point = NULL;
    return nova; 
}

LInt cloneRev (LInt l){
    LInt novamerda = cloneL(l);
    novamerda = reverse(novamerda);
    return novamerda;
}

int maximo (LInt l){
    LInt max = l->valor;
        while(l!=NULL) {
            if(l->valor > max) {
                max = l->valor;
               }
               l = l->prox;
        }
    return max;
}

int take (int n, LInt *l){
    int i = n; int c = 0;
    while(i!=0 && *l!=NULL){
        l= &((*l)->prox);
        c++;
        i--;
    }
    if(i==0) {
        LInt temp;
            while(*l!=NULL){
                temp = *l;
                *l = (*l)->prox;
                free(temp);
            }
    }
    return c;
}

int drop (int n, LInt *l){
    int i = n; int r = 0;
    while(i!=0 && *l!=NULL) {
        LInt temp = *l;
        *l = (*l)->prox;
        free(temp);
        i--;
        r++;
    }
    return r;
}

LInt NForward (LInt l, int N){
    while(N!=0){
        l=l->prox;
        N--;
    }
    return l;
}

int listToArray (LInt l, int v[], int N){
    int i = 0;
    for(; l!=NULL && i < N; i++) {
        v[i] = l->valor;
        l = l->prox;
    }
    return i;
}

LInt arrayToList (int v[], int N){
    LInt l; LInt *pointer = &l;
    int i = 0;
    for(;i<N;i++) {
        *pointer = malloc(sizeof(struct lligada));
        (*pointer)->valor = v[i];
        pointer = &((*pointer)->prox);
    }
    *pointer = NULL;
    return l;
}

LInt somasAcL (LInt l){
    int acc = 0;
    LInt nova, *sitio = &nova;
    while(l!=NULL){
        *sitio = malloc(sizeof(struct lligada));
        assert(*sitio!=NULL);
        acc += l->valor;
        (*sitio)->valor = acc;
        l = l->prox;
        sitio = &((*sitio)->prox);
    }
    *sitio = NULL;
    return nova;
}

void remreps (LInt l){
    LInt proximo;
    while(l) 
    {
        proximo = l->prox;
        while(proximo && l->valor == proximo->valor) 
        {
            LInt temp = proximo->prox;
            free(proximo);
            proximo = temp;
        }
        l->prox = proximo;
        l = l->prox;
    }  
}

LInt rotateL (LInt l){
    LInt n = l;
    if(l != NULL && l->prox != NULL){
        LInt start = l;
        l = l->prox;
        n = l;
        start->prox = NULL;
        while(l->prox != NULL)
            l = l->prox;
        l->prox = start;
    }
    return n;
}
LInt parte (LInt l){
   LInt n = NULL;LInt *p = &n;
   while(l && l->prox) 
   {
     if(n==NULL) n = *p = l->prox;  
   else{
       *p = l->prox;
       l = l->prox = l->prox->prox;
       (*p)->prox = NULL;
       p = &((*p)->prox);
   } 
   }
    return n;
}
