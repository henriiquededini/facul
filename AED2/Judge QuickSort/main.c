#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[15];
    int idade;
    int pos;
}pessoa;

void swap(pessoa* lista, int a, int b){
        pessoa aux;

        aux = lista[b];
        lista[b] = lista[a];
        lista[a] = aux;
}

int partition(pessoa* lista, int p, int r){
    int pivo = lista[r].idade;
    int i = p-1, j;

    for(j = p; j < r; j++){
        if(lista[j].idade <= pivo){
            i++;
            swap(lista, i, j);
        }
    }
    swap(lista, i+1, r);
    return (i+1);
}

void quicksort(pessoa* lista, int a, int b){
    if(a<b){
        int q, meio = (b+a)/2, media = 0;

        if(lista[a].idade < lista[meio].idade){
            if(lista[meio].idade < lista[b].idade)
                media = meio;
            else{
                if(lista[a].idade < lista[b].idade)
                    media = b;
                else
                    media = a;
            }
        }
        else{
            if(lista[b].idade < lista[meio].idade)
                media = meio;
            else{
                if(lista[b].idade < lista[a].idade)
                    media = b;
                else
                    media = a;
            }
        }

        swap(lista, media, b);

        q = partition(lista, a, b);
        quicksort(lista, a, q-1);
        quicksort(lista, q+1, b);
    }
}

int main()
{
    int n, i, inicio, fim, cont = 0, estavel = 0;
    pessoa* lista;

    scanf("%d", &n);

    lista = (pessoa*)malloc(n*sizeof(pessoa));

    for(i=0; i<n; i++){
        scanf("%s", lista[i].nome);
        scanf("%d", &lista[i].idade);
        lista[i].pos = i;
    }

    quicksort(lista, 0, n-1);

    scanf("%d %d", &inicio, &fim);

    for(i = 0; i < n; i++){
        if(lista[i].idade == lista[i+1].idade && lista[i].pos > lista[i+1].pos)
            estavel++;
    }

    if(estavel == 0)
        printf("yes\n");
    else
        printf("no\n");

    i = inicio-1;
    while(cont < fim){
        printf("%s ", lista[i].nome);
        printf("%d\n", lista[i].idade);
        i++;
        cont++;
    }

    free(lista);

    return 0;
}
