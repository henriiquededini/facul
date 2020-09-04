#include <stdio.h>
#include <stdlib.h>

void swap(int* vet, int i, int j){
    int aux;

    aux = vet[i];
    vet[i] = vet[j];
    vet[j] = aux;
}

void maxheapfy(int* vet, int i, int n){
    int l = (2*i) + 1;
    int r = (2*i) + 2;
    int max;

    if(l <= n && vet[l] > vet[i]) max = l;
    else max = i;
    if(r <= n && vet[r] > vet[max]) max = r;
    if(max != i){
        swap(vet, i, max);
        maxheapfy(vet, max, n);
    }
}

void buildmaxheap(int* vet, int n){
    int i;

    for(i=(n/2)-1; i>=0; i--)
        maxheapfy(vet, i, n);
}

int heapextractmax(int* vet, int n){
    if(n >= 1){
        int max = vet[0];
        swap(vet, 0, n);
        n--;
        maxheapfy(vet, 0, n);
        return max;
    }
}

void heapsort(int* vet, int n){
    int aux[n];
    int i = n-1, x = n, j;
    buildmaxheap(vet, n);

    for(j=0; j<n; j++)
        printf("%d ", vet[j]);

    printf("\n");
    while(i>=0){
        aux[i] = heapextractmax(vet, i);
        i--;
    }

    for(j=0; j<n; j++)
        printf("%d ", vet[j]);
}

int main()
{
    int n, i;
    int* vet;

    scanf("%d", &n);

    vet = (int*)malloc(n*sizeof(int));

    for(i=0; i< n; i++){
        scanf("%d", &vet[i]);
    }

    heapsort(vet, n);

    free(vet);

    return 0;
}
