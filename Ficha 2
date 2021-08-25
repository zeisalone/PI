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
