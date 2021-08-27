void swapM (int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swap (int v[], int i, int j){
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void inverteArray (int v[], int N){
    int i;
    
    for (i = 0; i < N / 2; i++) {
        
        swapM (&v[i], &v[N - i - 1]);
        
    } 
}

void dumpV (int v[], int N){
    int i;
    for (i=0; i<N; i++) printf ("%d ", v[i]);
    putchar ('\n');
}

int soma (int v[], int N){
   int i; int soma = 0;
    for(i = 0; i < N; i++) {
        soma = soma + v[i]; 
    }
    return soma;
}

int maximum (int v[], int N, int *m){
int r;
    if(N < 0) r = -1;
    else{
        int i;
        for(i=0, *m=v[i]; i<N; i++){
            if(v[i] > *m)
                *m = v[i];
        }
        r = 0;
    }
    return r;
    return 1;
}
