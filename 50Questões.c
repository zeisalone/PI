

int bitsUm (unsigned int x){
    int r=0;
    while(x != 0){
        if(x%2 != 0) 
            r++;
    x /= 2;
    }

    return r;
}
