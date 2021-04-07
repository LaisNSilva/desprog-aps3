#include <stdio.h>
#include <math.h>

#include "dna.h"


void load_string(FILE *file, int *p, char *s, int t) {
    if (fscanf(file, "%d", p) != 1) {
        fprintf(stderr, "erro ao ler string do teste %d\n", t);
    }

    char c;
    do {
        c = getc(file);
    } while (c != '\n');

    fgets(s, *p + 1, file);
}


int mlcs_w(char a[], int n, char b[], int m, int length[MAX_SIZE + 1][MAX_SIZE + 1]) {
    if (n==0 || m==0){
        length[n][m]=0;
        return 0;
    }

    //mlcs_w(a, n-1, b, m, length);
    //mlcs_w(a, n, b, m-1, length);
    //mlcs_w(a, n-1, b, m-1, length);

    if(length[n][m]!=-1){
        length[n][m];
    }

    if(a[n-1] == b[m-1]){
        
        length[n][m] =  1+ mlcs_w(a, n-1, b, m-1, length);
        //mlcs_w(a, n-1, b, m-1, length);
    }
    else{
        
        if(length[n-1][m] > length[n][m-1]){
            
            length[n][m] = mlcs_w(a, n-1, b, m, length);
            
        }
        else {
            
            length[n][m]= mlcs_w(a, n, b, m+1, length);
            
        }
        
       
        
    
    }
    return length[n][m];
    
}


int mlcs(char a[], int n, char b[], int m) {
    
    int length[MAX_SIZE+1][MAX_SIZE+1];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            length[i][j] = -1;
    mlcs_w(a, n, b, m, length);

    return length[n][m];
    
}



int dlcs(char a[], int n, char b[], int m) {
    // int length[n+1][m+1];

    // // se o n-ésimo caractere do primeiro vetor é igual ao m-ésimo caractere do segundo vetor;

    // for(int r = 0; r < n; r++){
    //     length[r][0] = 0;
    // }
    // for(int c = 0; c < m; c++){
    //     length[0][c] = 0;
    // }

    // for (int row = 1; row <= n; row++){
    //     for (int col = 1; col <= m; col++){

    //         if(a[row-1] == b[col-1]){
    //             length[row][col] = length[row-1][col-1] +1;
    //         }
    //         else{
    //             if(length[row-1][col] >= length[row][col-1]){
    //                 length[row][col] = length[row-1][col];
    //             }
    //             else{
    //                 length[row][col] = length[row][col-1];
    //             }
    //         }
    //     }

    //     }

    return 2;
}
