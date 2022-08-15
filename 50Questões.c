#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>


int norma(Posicao *p1){
    return abs(sqrt(((p1->x)*(p1->x))+((p1->y)*(p1->y))));
}

int compPrefixoSemRep (char s[]){
    int i, j, r=0;
    for(i=0; s[i]!='\0'; i++){
        for(j=0; s[j]!=s[i]; j++);

        if (j!=i) return r;
        else r++;
    }

    return r;
}

int elem(char c, char s[]) {
    int i;
    for(i=0;s[i]!='\0'; i++) {
        if(c==s[i]) return 1;
    }
    return 0;
}

// 1

void one() {
    int largest = INT_MIN;
    while(1) {
        int num;
        assert(scanf("%d",&num) == 1);
        if(num == 0) break;
        if(num > largest) largest = num;
    }
    printf("Maior: %d\n", largest);
}

// 2 

void two() {
    double soma = 0;
    int n = 0;
    while(1) {
        int num;
        assert(scanf("%d",&num) == 1);
        if(num == 0) break;
        soma += num;
        n++;
    }
    double media = soma / n;
    printf("Média: %.5f\n", media);
}

// 3 

void three() {
    int biggest = INT_MIN, second_biggest = INT_MIN, num;
    while(1) {
        assert(scanf("%d",&num) == 1);
        if(num == 0) break;
        if(num > biggest) {
            second_biggest = biggest;
            biggest = num;
        } else if (num > second_biggest) second_biggest = num;
    }
    printf("Segundo maior número: %d\n", second_biggest);
}

// 4

int bitsUm (unsigned int x){
    int r=0;
    while(x != 0){
        if(x%2 != 0) 
            r++;
    x /= 2;
    }

    return r;
}

// 5

int trailingZ (unsigned int n) {
    int s = 0, r = 0; 
    if (n == 0) return 32;
    else {     
        while (n / 2 != 0) { 
            if (n % 2 == 1) {
                s = 0;
                r = 0;
            }
            else {
                s = 1;
                r++;
            }   
            n /= 2;        
        }        
        if (sequencia == 1) return r;
        else return 0;        
    }    
}

// 6

int qDig (int n) {
    int r = 0;
    int i;
    for (i = 1; n >= i; i*=10) {
        r++;
    }
    return r;
}

// 7

char *mystrcat(char s1[], char s2[]) {
    
    int i, j;
    
    for (i = 0; s1[i]; i++);
    for (j = 0; s2[j]; j++) {
        s1[i] = s2[j];
        i++;
    }
    
    s1[i] = '\0';
    
    return s1;
}

// 8

char* mystrcpy(char* dest, char source[]) {
    char* result = dest;
    while((*dest = *source)) { 
        source++; 
        dest++; 
        
    }
    return result;
}

// 9

int mystrcmp(char s1[], char s2[]) {
    int i;
	for (i = 0; s1[i] || s2[i]; i++) {

		if (s1[i] > s2[i]) return 1;
		else if (s1[i] < s2[i]) return -1; 

	}
    return 0;
}

// 10 

char *mystrstr (char s1[], char s2[]) {
 char *ps1 = s1;
 char *ps2 = s2;
    
    if (*s1 == '\0' && *s2 == '\0' || *s1 != '\0' && *s2 == '\0') return s1;
    while (*s1) 
    {
        if (*s1 == *s2) {
            ps1 = s1;
            s1++;
            s2++;
        
        while (*s1 == *s2 && *s1 != '\0') {
            s1++;
            s2++;
                
        }
        if (*s2 == '\0') {
        s1 = ps1;
        return s1;
       }
        else s2 = ps2;
    }
    s1++;
    }
    return NULL;
}

// 11

void strrev (char s[]) {
    int i, j;
    char temp;
    for (i = 0; s[i]; i++);
    for (i -= 1, j = 0; j <= i / 2; j++) {
        temp = s[i - j];
        s[i - j] = s[j];
        s[j] = temp;
    }
    return;
}

//12

int isVowel (char c){
    int r = 0;
    int i;
    char vogais[10] = "aeiouAEIOU";
    for(i=0; vogais[i]!='\0' && r==0; i++){
        if(vogais[i] == c)
            r = 1;
    }

    return r;
}

void strnoV (char s[]){
    int i, j;

    for(i=0, j=0; s[i]!='\0'; i++){
        if(!(isVowel(s[i])))
           s[j++] = s[i];
    }
    s[j] = '\0';
}

//13

void truncW (char t[], int n){
    int i, contador=n, j;
    
    for(i=0, j=0; t[i]!='\0'; i++){
        if(t[i]==' '){
            t[j++] = t[i];
            contador=n;
        }else{
            if(contador-- > 0)
                t[j++] = t[i];
        }
    }

    t[j] = '\0';
    
}

//14

char charMaisfreq (char s[]){
    int i, j , contaVezesMax = 0;
    char contaChar=0;

    for(i=0; s[i]!='\0'; i++){
        int contaVezes=0;
        for(j=0; s[j]!='\0'; j++){
            if(s[i]==s[j]) contaVezes++;
        }
        if(contaVezes > contaVezesMax){
                 contaVezesMax = contaVezes;
                contaChar = s[i];
            }
    }

    return contaChar;
}

//15

int iguaisConsecutivos (char s[]) {
    int i;
    int j;
    int contavezesmax = 0;
    for(i = 0; s[i]!='\0';i++){
        int contaVezes=0;
        for(j=i; s[j]!='\0' && s[i]==s[j]; j++)
            contaVezes++;  
        if (contavezesmax < contaVezes)
            contavezesmax = contaVezes;
    }
    return contavezesmax;
}

//16

int difConsecutivos (char s[]){
    int r=0, t, i;
    for(i=0; s[i]!='\0'; i++){
        t = compPrefixoSemRep(s+i);
        if (t > r) r=t;
    }

    return r;
}

//17

int maiorPrefixo (char s1 [], char s2 []) {
    int i; int contador = 0;int r = 0;
        for(i=0; s1[i]!='\0' && s2[i]!='\0' && r==0; i++) {
            if (s1[i] != s2[i]) r=1;
            else contador ++;
        }
        
    return contador;
}

//18

int maiorSufixo (char s1 [], char s2 []) {
 int i; int contador = 0; int r = 0;
 strrev(s1);
 strrev(s2);
 for(i=0;s1[i]!='\0' && s2[i]!='\0' && r==0;i++) {
     if(s1[i] != s2[i]) r=1;
     else contador++;
 }
    return contador;

}

//19

int sufPref (char s1[], char s2[]) {
    int i, j;

    for(i=0, j=0; s1[i]!='\0'; i++){
       if (s1[i]==s2[j]) j= j+1; else j=0;
    }    

    return j;
}

//20

int contaPal (char s[]){
    int i, j, contador=0, r;
    for(i=0; s[i]!='\0'; i++){
        if((s[i] != ' ' && s[i]!='\n') && s[i+1] == ' ' || (s[i] != ' ' && s[i]!='\n') && s[i+1] == '\0'){
            contador++;
        }       
    }
        
    return contador;
}

//21

int contaVogais (char s[]) {
   int i; int contador = 0;
   for(i=0; s[i]!='\0'; i++) {
   
       if(isVowel(s[i])) contador++;
   }
   return contador;
}

//22

int contida (char a[], char b[]) {
    int i; 
    for(i=0; a[i]!='\0'; i++){
        if(!(elem(a[i],b))) return 0;
    }
    return 1;
}

//23

int palindroma (char s[]){
    int i, j = strlen(s)-1, r=1;
    for(i=0; s[i]!='\0' && r==1; i++, j--){
        if(s[i]!=s[j])
            r = 0;
    }

    return r;
}

//24

int remRep (char texto[]) {
    int i,j; 
    for(i=0 , j=0; texto[i]!='\0';i++) {
        if(texto[i]!=texto[i+1])
            texto[j++]=texto[i];
    }
    
    texto[j] = '\0';
    return j;
}

//25

int limpaEspacos (char texto[]) {
    int i,j;
    for(i=0, j=0; texto[i]!='\0'; i++) {
        if(texto[i]!=' ' || texto[i+1]!=' ')
        texto[j++] = texto[i];
    }
    texto[j] ='\0';
    return j;
}

//26

void insere (int s[], int N, int x){
   int i,j; int a = 0;
    for(i=0; i<N && a==0; i++) {
        if(x<= s[i]) {
            s[N+1] = s[N];
            for(j=N; j>i;j--) {
                s[j] = s[j-1];
            }
            s[i] = x;
            a = 1;
        }
    } 
}

//28

int crescente (int a[], int i, int j){
    int n; 
    int r=1;
       for(n=i; n<j && r==1 ;n++) {
        if(a[n] > a[n+1])
            r = 0;
           
       }    
       return r;
}

//29

int retiraNeg (int v[], int N){
    int i, j;
        for(i=0,j=0;i<N;i++) {
        if(v[i] > 0)
            v[j++] = v[i];
        }
      return j;
}

//30

int menosFreq (int v[], int N){
    int i, j, min=N+1, valor=v[0];

    for(i=1, j=1; i<N; i++){
        if(v[i]!=v[i-1]){
            if(j < min){
                min = j;
                valor = v[i-1];
            }
            j = 1;
        }else
            j++;
    }

    if(j < min){
        min = j;
        valor = v[i-1];
    }

    return valor;
}

//31

int maisFreq (int v[], int N){
       int i,j;
       int max = 1;
       int a = v[0];
       for(i = 1, j = 1; i < N; i++) {
           if(v[i]!=v[i-1]){
           if(j > max) {
               max = j;
               a = v[i-1];
           }
           j = 1;
       }
       else j++;
       }
   if (j > max) {
       max = j;
       a = v[i-1];
   }
           
     
    return a;
}

//32

int maxCresc (int v[], int N) {
       int r =1; int i,j;
       for(i = 1, j = 1; i<N; i++) {
           if(v[i-1]>v[i]) j = 1;
           else j++;
           if(j > r) r = j;
       }
       return r;
}

//33

int elimRep (int v[], int N) {
       int n,i,j;
        for(i=0; i<N; i++) {
            j=i+1;
                while(j<N) {
                    if(v[i]==v[j]) {
                        for(n=j;n<N;n++)
                        v[n] = v[n+1];
                        N--;
                    }else
                    j++;
                }
        }
       
       return N;
}

//34

int elimRepOrd (int v[], int n){
    int e = 0, l;
    for(l=1; l<n; l++){
        if(v[l]!=v[e]){
            e++;
            v[e] = v[l];
        }
    }

    if(n>0) e++;

    return e;
}

//35

int comunsOrd (int a[], int na, int b[], int nb){
       int i = 0; int j = 0; int c = 0;
            while(i<na && j <nb) {
                if (a[i] > b[j] )
                    j++;
                else if (a[i] < b[j])
                    i++;
                else{
                     c++;
                     i++;
                     j++;
                }  
            }
            
       return c;
}

//36

int comuns (int a[], int na, int b[], int nb){
      int i; int j;
      int c = 0;
      int p = 0;
        for(i = 0; i < na; i++) {
               for(j = 0; j < nb && p == 0; j++){
                    if (a[i] == b[j]) {
                        c++; p = 1;
                    } 
                        
              }
              p = 0;
        }
      return c;
}

//37

int minInd (int v[], int n) {
   int i ;
   int indice=0;
    for(i=1; i<n; i++){
        if(v[i]<v[indice])
            indice = i;
    }
   return indice;
}

//38

int somasAcaux(int v[],int acc) {
    int r = 0;
    while(acc >= 0){
        r += v[acc];
        acc--;
    }
    return r;
}


void somasAc (int v[], int Ac [], int N){
    int acc = 0; int i;
    for(i = 0; i<N; i++, acc++) {
        Ac[i] = somasAcaux(v,acc);
    }
}

//39

int triSup (int N, int m [N][N]) {
    int c; int i; int j; 
        for(i = 0; i < N; i++) {
            c = i;
                for(j = 0; j < N && c!=0 ; c--, j++ )
                    if (m[i][j] !=0)
                        return 0;
        }
            
    return 1;
}

//40

void transposta (int N, float m [N][N]) {
    int i; int j; 
    for(i = 0; i < N; i++ ) {
        for(j = 0; j < i; j++) {
            if(i != j) {
                float temp = m[i][j];
                    m[i][j] = m[j][i];
                    m[j][i] = temp;
                
            }
        }
    }
}

//41

void addTo(int N, int M, int a [N][M], int b[N][M]) {
   int i; int j; 
        for (i=0; i < N ;i++) {
            for (j=0; j < M ;j++)
                a[i][j] = a[i][j] + b[i][j];
        }
}

//42

int unionSet (int N, int v1[N], int v2[N], int r[N]){
    int c=0, i;

    for(i=0; i<N; i++) {
        if (v1[i]<v2[i]) r[i] = v2[i]; 
        else r[i] = v1[i];
    }
        
    return c;
}

//43

int intersectSet (int N, int v1[N], int v2[N], int r[N]){
    int c=0, i;

    for(i=0; i<N; i++)
        if (v1[i] == v2[i])  r[i] = v1[i];
        else r[i] = 0;

    return c;
}

//44

int intersectMSet (int N, int v1[N], int v2[N], int r[N]){
       int c = 0;
       int i = 0;
       for(;i < N; i++)
       r[i] = (v1[i]<v2[i]) ? v1[i] : v2[i];
       return c;
}

//45

int unionMSet (int N, int v1[N], int v2[N], int r[N]) {
    int c = 0, i;
    for(i = 0; i < N; i++)
        r[i] = (v1[i]<v2[i]) ? v2[i] : v1[i];
    
    return c;
}

//46

int cardinalMSet (int N, int v[N]){
   int c=0; int i=0;
   for(;i < N;i++)
   	if(v[i]!=0) 
   	    c += v[i];
   	  
   return c;
}

//47

Posicao posFinal (Posicao inicial, Movimento mov[], int N){
    int i;
    for(i=0; i < N ;i++) {
        switch(mov[i]){
        case Norte: 
        inicial.y++;
        break;
        case Sul:
        inicial.y--;
        break;
        case Oeste:
        inicial.x--;
        break;
        case Este:
        inicial.x++;
        break;
        }   
    }
    return inicial;
}

//48

int caminho (Posicao inicial, Posicao final, Movimento mov[], int N){
    int i;
    for(i=0; i<N; i++){
        if(inicial.x < final.x){
            inicial.x++;
            mov[i] = Este;
        }else if(inicial.x > final.x){
            inicial.x--;
            mov[i] = Oeste;
        }else if(inicial.y < final.y){
            inicial.y++;
            mov[i] = Norte;
        }else if(inicial.y > final.y){
            inicial.y--;
            mov[i] = Sul;
        }else
            return i;
    }
     if(inicial.x != final.x || inicial.y != final.y)
        i = -1;
    return i;
}

//49

int maiscentral (Posicao pos[], int N){
    int i; int r = 0;
    double min = sqrt(pow((pos[0].x),2)+pow((pos[0].y),2));
    double x = 0.0;
    for(i=0; i<N; i++)
    {
        x = sqrt(pow((pos[i].x),2) + pow((pos[i].y),2));
            if(x<min) {
                r = i;
                min = x;
            }
    }
    return r;
} 

//50

int distanciaIgualA1(Posicao *p1, Posicao *p2){
    return ((abs(p1->x-p2->x)+abs(p1->y-p2->y))==1);
}

int vizinhos (Posicao p, Posicao pos[], int N){
    int cont = 0, i;
    for(i=0; i<N; i++){
        if(distanciaIgualA1(&p, &pos[i]))
            cont++;
    }

    return cont;
}
