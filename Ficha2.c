float multInt1 (int n, float m){
    int p = n; float c = 0.0;
        for(; p != 0; p--) {
            c = c + m;
        }
            return c;

}

float multInt2 (int n, float m){
    int impar = 0.0;
    while (n != 1) {
       if(n%2 == 1) 
        impar = impar + m;
        n = n/2;
        m = m*2;
            
            
    }
    impar = impar + m;
    return impar;
}

float multInt3 (int n, float m, int *count){
     float r = 0.0; *count = 0;
    while (n != 1) {
         if(n%2 == 1) {
         r = r + m; (*count)++;
         }
         n = n/2;
         m = m*2;

    }
     r = r + m;
    return r;
}
int mdc1 (int a, int b){
    int r = 1; int i;
    if(b > a)
    mdc1(b,a);
    else {  
        for (i = 1; b <= i; i++) {
            if(a % i == 0 && b % i == 0)
            r = i;
            return r;
        }
    }
    
}
int mdc2(int a, int b){
    int r;
    while(a!=0 && b!=0){
        if (a > b) a -= b;
        else if (a< b) b -= a;
        else return a;
    }
    if(a==0) r = b;
    else r = a;
    return r;
}

int mdc3 (int a, int b, int *count){
      int r; (*count) = 0;
    while(a!=0 && b!=0){
        if (a > b) {
            a -= b; (*count)++; 
            
        }
        else if (a < b) { 
             b -= a; 
            (*count)++;  
        } 
        else {
            (*count)++;
            return a ;
            
        }
    }
    if(a==0) r = b;
    else r = a;
    return r;
}
int mdc4 (int a, int b, int *count){
       while (!(a == 0 || b == 0)) {
        if (a > b) {
             a = a % b;    
             (*count)++;
        }
        else {
            b = b % a; 
            (*count)++;
        }
            
    }

    if (a == 0)
        return b;
    else
        return a;
}
int fib (int n) {
    
    if (n == 1 || n == 2)
        return 1;

    else
        return fib(n - 1) + fib(n - 2);

}

int fastfib (int n){
int v1, v2, r; int i;
v1 = 1;
v2 = 1;

    if (n == 1 || n == 2)
        return 1;

    for(; i < n - 2; i++) {
        r = v1 + v2;
        v1 = v2;
        v2 = r;
    }

    return r;

}
