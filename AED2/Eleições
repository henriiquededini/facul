#include <stdio.h>
#include <stdlib.h>

float porcent(float v, float soma, int inv){
    float p = (soma*100)/(v-inv);
    return p;
}

void calculasegundo(int **votos, int v, int c, int primeiro, int segundo, int *soma){
    int aux1 = 0, i, j, cont = 0, inv = 0;
    float porcentagem1, porcentagem2;

    for(i=0; i<c; i++)
        soma[i] = 0;

    for(i=0; i<v; i++){
        cont = 0;
        for(j=0; j<3; j++){
            if(votos[i][j] == (primeiro+1) || votos[i][j] == (segundo+1)){
                soma[votos[i][j] - 1]++;
                cont++;
                break;
            }
        }
        if(cont == 0) inv++;
    }

    porcentagem1 = porcent(v, soma[primeiro], inv);
    porcentagem2 = porcent(v, soma[segundo], inv);

    if(porcentagem1 > porcentagem2)
        printf("\n%d %.2f", primeiro+1, porcentagem1);
    else if(porcentagem1 < porcentagem2)
        printf("\n%d %.2f", segundo+1, porcentagem2);
    else{
        if(primeiro < segundo)
            printf("\n%d %.2f", primeiro+1, porcentagem1);
        else
            printf("\n%d %.2f", segundo+1, porcentagem2);
    }

    free(votos);
}

void calculaprimeiro(int **votos, int v, int c){
    int i, j, total, x = 0, inv = 0;
    int soma[c];
    float porcentagem;

    for(i=0; i<c; i++)
        soma[i] = 0;

    for(i=0; i<v; i++){
        if(votos[i][0] > 0 && votos[i][0] <= c)
            soma[votos[i][0] - 1]++;
        else
            inv++;
    }

    total = soma[0];

    for(i=1; i<c; i++){
        if(total < soma[i]){
            total = soma[i];
            x = i;
        }
    }

    porcentagem = porcent(v, total, inv);

    if(inv == v){
        printf("0");
        return 0;
    }
    else if(porcentagem >= 50){
        printf("%d %.2f", x+1, porcentagem);
        free(votos);
    }
    else{
        int z = 1, aux;
        aux = soma[1];

        printf("%d %.2f", x+1, porcentagem);

        for(i=0; i<c; i++){
            if(i != x && soma[i] > aux){
                aux = soma[i];
                z = i;
            }
        }

        calculasegundo(votos, v, c, x, z, soma);
    }
}

int main()
{
    int v, c, i, j, aux;
    int** votos;

    scanf("%d %d", &v, &c);
    votos = (int**)malloc(v*sizeof(int*));

    for(i=0; i<v; i++){
        votos[i] = (int*)malloc(3*sizeof(int));
    }

    for(i=0; i<v; i++){
        for(j=0; j< 3; j++){
            scanf("%d", &aux);
            if(aux > 0 && aux <= c)
                votos[i][j] = aux;
            else{
                votos[i][j] = 0;
            }
        }
    }

    calculaprimeiro(votos, v, c);

    return 0;
}
