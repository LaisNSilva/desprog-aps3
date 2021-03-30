#include <stdio.h>

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
    // Base da recursão
    if (n==0 || m==0){
        length[n][m]=0;
        return 0;
    }

    mlcs_w(a, n-1, b, m-1, length);
    // se o n-ésimo caractere do primeiro vetor é igual ao m-ésimo caractere do segundo vetor;
    if(a[n-1] == b[m-1]){
        length[n][m]= length[n-1][m-1] +1;
    }
    // caso contrário
    else{
        if(length[n-1][m] > length[n][m-1]){
            length[n][m]= length[n-1][m];
        }
        else{
            length[n][m]=length[n][m-1];
        }
    }



    return 0;
}


int mlcs(char a[], int n, char b[], int m) {
    // inicializa matiz
    int length[MAX_SIZE+1][MAX_SIZE+1];

    // Deve chamar a função mlcs_w
    mlcs_w(a, n, b, m, length);

    // O QUE QUE TEM QUE RETORNAR?? 
    // PREENCHE UMA MATRIZ MAS RETORNA SÓ UM NUMERO???
    // BOTEI PARA RETORNAR O MAXIMO DA MATRIZ NESSE CÓDIGO ABAIXO
    // MAS SÓ DEVOLVE "2"
    int r=0;
    for (int i=0; i<n; i++){
        for(int e=0; e<m; e++){
            if (length[i][e] >r){
                r = length[i][e];
            }

        }
    }
    return r;
}


int dlcs(char a[], int n, char b[], int m) {
    return 2;
}
