#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>

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
