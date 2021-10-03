#include <stdio.h>

int main() {
    int N, M, P;
    int x, i, j;
    int A, B, k;
    int K, L;
    scanf("%d %d %d", &N, &M, &P);
    while (((N < 0) || (N > 400)) || ((M < 0) || (M > ((N - 1)*N)/2)) || ((P < 0) || (P > 100000)))
        scanf("%d %d %d", &N, &M, &P);
    int MA[N][N];
    for (i = 0; i < N; i++) {
        for (j = 1; j <= N; j++) {
            MA[i][j] = 0;
        }
    }
    for (x = 0; x < M; x++) {
        scanf("%d %d", &A, &B);
        while((A <= 0) || (B > N) || (A > N) || (B <= 0))
            scanf("%d %d", &A, &B);
        MA[A-1][B-1] = 1;
        MA[B-1][A-1] = 1;
    }
    //Floyd-Warshall
    for (k = 0; k < N; k++) {
        for (i = 0; i < N; i++) {
            if (MA[i][k] == 1) {
                for (j = 0; j < N; j++) {
                    if ((j != k) && (MA[i][j] == 0))
                        MA[i][j] = MA[k][j];
                    if ((j != k) && (MA[k][j] == 0))
                        MA[k][j] = MA[i][j];
                }
            }
        }
    } 
    for (x = 0; x < P; x++) {
        scanf("%d %d", &K, &L);
        if (MA[K-1][L-1] == 1) 
            printf("Lets que lets\n");
        else
            printf("Deu ruim\n");
    }
    return 0;
}

