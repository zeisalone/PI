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

int altura (ABin a){
    int r = 0;
    if(a!=NULL) {
        if(altura(a->esq) > altura(a->dir)) r = (1 + (altura (a->esq)));
        else r = (1 + (altura (a->dir)));
    }
    
	return r;
}

ABin cloneAB (ABin a) {
    ABin clone = NULL;
        if(a) {
            clone = malloc(sizeof(struct nodo));
            if(clone) {
                clone->valor = a->valor;
                clone->esq = cloneAB(a->esq);
                clone->dir = cloneAB(a->dir);
            }
        }
    return clone;
}

void mirror (ABin *a) {
    ABin temp;
    if(*a) {
        temp = (*a)->dir;
        (*a)->dir = (*a)->esq;
        (*a)->esq = temp;
        mirror(&((*a)->dir));
        mirror(&((*a)->esq));
    }
}

void inorder (ABin a, LInt * l) {
    if(a) {
        inorder(a->esq,l);
        while(*l)  l = &((*l)->prox);
        *l = malloc(sizeof(struct nodo));
        (*l)->valor = a->valor;
        inorder(a->dir,(&((*l))->prox));
    }
	else
        *l = NULL;
}

void preorder (ABin a, LInt * l) {
    if(a) {
        *l = malloc(sizeof(struct nodo));
        (*l)->valor = a->valor;
        preorder(a->esq,&((*l)->prox));
        while(*l) 
            l = &((*l)->prox);
            preorder(a->dir,l);
            
    }else *l = NULL;
}

void posorder (ABin a, LInt *l){
    if(a){
        posorder(a->esq, l);
        while(*l!=NULL)
            l = &((*l)->prox);
        posorder(a->dir, l);
        while(*l!=NULL)
            l = &((*l)->prox);
        *l = calloc(1, sizeof(struct nodo));
        (*l)->valor = a->valor;
    }else
        *l = NULL;
}

int depth (ABin a, int x){
    int r = -1;
    if(a!=NULL){
        if(a->valor == x)
            r = 1;
        else{
            int rEsq = depth(a->esq, x);
            int rDir = depth(a->dir, x);
            if(rEsq==-1 && rDir==-1)
                r = -1;
            else if(rEsq==-1)
                r = 1 + rDir;
            else if(rDir==-1)
                r = 1 + rEsq;
            else
                r = (rEsq < rDir) ? 1 + rEsq : 1 + rDir;
        }
    }

    return r;
}

int freeAB (ABin a) {
    int r = 0;
    if(a) {
        r+= freeAB(a->esq);
        r+= freeAB(a->dir);
        free(a);
        r++;
    }
    return r;
}

int pruneAB (ABin *a, int l) {
     int r = 0;
     if(*a) {
         r+=pruneAB(&((*a)->esq),l-1);
         r+=pruneAB(&((*a)->dir),l-1);
         if(l<=0) 
         {
             free(*a);
             *a=0;
             r++;
         }
     }
     return r;
 }

int iguaisAB (ABin a, ABin b) {
    int r = 0;
    if(a && b) 
    {
        r = ((a->valor==b->valor) && iguaisAB(a->esq,b->esq) && iguaisAB(a->dir,b->dir));
    }
    if(!a && !b) r = 1;
    return r;
}

LInt nivelL (ABin a, int n){
    LInt new = NULL, esq, dir;
    if(a!=NULL && n>=1){
        if(n==1){
            new = malloc(sizeof(struct lligada));
            new->valor = a->valor;
            new->prox = NULL;
        }else{
            esq = nivelL(a->esq, n-1);
            dir = nivelL(a->dir, n-1);
            if(esq!=NULL){
                new = esq;
                while(esq->prox!=NULL)
                    esq = esq->prox;
                esq->prox = dir;
            }else
                new = dir;
        }
    }

    return new; 
}

int nivelV (ABin a, int n, int v[]) {
    int r = 0; int e,d;
    if(a && n>=1) 
    {
        if(n==1) 
        {
            *v = a->valor;
            r++;
        }else{
            e = nivelV(a->esq, n-1, v);
            d = nivelV(a->dir, n-1, v+e);
            r+=e +d;
        }
    }
    return r;
}

int dumpAbin (ABin a, int v[], int N) {
    int r = 0;
    int esq, dir;
    if(a && N>0){
         esq = dumpAbin(a->esq, v, N);
         if(esq < N) {
             v[esq] = a->valor;
             dir = dumpAbin(a->dir,v+esq+1,N-1-esq);
             r += 1 + esq +dir;
         }else r = esq;
    }
       
        
    return r;
}

ABin somasAcA (ABin a) {
   ABin acc = NULL;
        if(a) {
            ABin e = somasAcA(a->esq);
            ABin d = somasAcA(a->dir);
            acc = malloc(sizeof(struct nodo));
            acc->esq = e;
            acc->dir = d;
            if(a->esq && a->dir)
            {
                acc->valor = a->valor + e->valor + d->valor;
            }
            else if(a->esq) 
            {
                acc->valor = a->valor + e->valor;
            }
            else if(a->dir)
            {
                acc->valor = a->valor + d->valor;
            }
            else
            {
                acc->valor = a->valor;
            }
            
        }
    return acc;
}

int contaFolhas (ABin a) {
    int c = 0; 
    if(a)
        if(a->esq==NULL && a-> dir==NULL) {
            c++;
        }
        else{
            c = contaFolhas(a->esq) + contaFolhas(a->dir);
        } 
    return c;
}

ABin cloneMirror (ABin a) {
    ABin clone = NULL;
    if(a) {
        clone = malloc(sizeof(struct nodo));
        clone->valor = a->valor;
        clone->esq = cloneMirror(a->dir);
        clone->dir = cloneMirror(a->esq);
    }
    return clone;
}

int addOrd (ABin *a, int x) {
  int  r = 1;
    while(*a && (*a)->valor!=x)
    {
        if((*a)->valor > x) a = &((*a)->esq);
        else a = &((*a)->dir);
    }
    if(*a == NULL){
        r = 0;
        *a = malloc(sizeof(struct nodo));
        (*a)->valor = x;
        (*a)->dir = (*a)->esq = NULL;
    }
    return r;
}

int lookupAB (ABin a, int x) {
    int r = 0;
    while(a && a->valor != x) 
    {
        if(a->valor > x) a = a->esq;
        else a = a->dir;
    }
    if(a!=NULL)
    r = 1;
    return r;
}

int depthOrd (ABin a, int x) {
    int nivel = 1;
    while(a && a->valor != x) 
    {
        if(a->valor > x) 
        {
            a = a->esq; nivel++;
        }
        else
        {
            a = a->dir; nivel++;
        } 
    }
    if(a == NULL){
        nivel = -1;
    }
    return nivel;
}

int maiorAB (ABin arv){
    while(arv->dir!=NULL)
        arv = arv->dir;

    return arv->valor;

}

void removeMaiorA (ABin *a) {
    if(*a != NULL) {
        while((*a)->dir != NULL)
        a = &((*a)->dir);
        ABin temp = *a;
        *a = (*a)->esq;
        free(temp);
    }
}

int quantosMaiores (ABin a, int x) {
    int r = 0;
        if(a) 
        {
            if(a->valor <= x) r += quantosMaiores(a->dir,x);
            else 
            {
                r += 1 + quantosMaiores(a->dir,x) + quantosMaiores(a->esq,x);
            }
        }
    return r;
}

/* void aux(ABin p,ABin *a) 
{
    while(*a) 
    {
        if((*a)->valor > p->valor) 
        a = &((*a)->esq);
        else if((*a)->valor < p->valor) 
        a = &((*a)->dir);
    }
    *a=p;
}
*/

void listToBTree (LInt l, ABin *a) {
    ABin p; 
    while(l)
    {
        p = malloc(sizeof(struct nodo));
        p->valor = l->valor;
        p->esq = NULL;
        p->dir = NULL;
        aux(p,a);
        l=l->prox;
    }
}
/*
int aux (int valor, int bool, ABin a) {
    return a==NULL || (a && (bool) ? a->valor < valor && aux(valor,bool,a->esq) && aux(valor,bool,a->dir) : a->valor > valor && aux(valor,bool,a->esq) && aux(valor,bool,a->dir));
}
*/

int deProcura (ABin a) { 
    return a == NULL || (a && aux(a->valor,1,a->esq) && aux(a->valor,0,a->dir) && deProcura(a->esq) && deProcura(a->dir));
}
