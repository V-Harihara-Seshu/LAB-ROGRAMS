#include <stdio.h>
#include <string.h>

void sm(char txt[],char patt[]){
    int m = strlen(txt);
    int n = strlen(patt);
    int i,j;
    for(i=0; i <= m-n; i++){
        for(j = 0; j < n; j++){
            if(patt[j]!=txt[j+i]){
                break;
            }
        }
        if(j==n){
            printf("\n at index %d",i);
        }
    }
}

int main(){
    char x[] = "husehuseshuiihu";
    char patt[] = "hu";
    sm(x,patt);
    return 0;
}
