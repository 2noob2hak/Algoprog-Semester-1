#include <stdio.h>

int main(void) {
    int T,N,M,Q; // N=friends, M=rooms, Q=friends will visit the rooms
    // handling input
    scanf("%d", &T);

    for (int t=0; t<T; t++) 
    {
        scanf("%d %d %d", &N, &M, &Q);
        int rooms_arr[N][M];
        for (int i=0; i<N; i++) 
        {
            for (int j=0; j<M; j++) 
            {
                scanf("%d", &rooms_arr[i][j]);
            }
        }
    
        // compute
        int visitors[Q];
        for (int k=0; k<Q; k++) 
        {
            scanf("%d", &visitors[k]);
        }

        int lights[M];
        for (int l=0; l<M; l++)
            lights[l] = 0;

        for (int m=0; m<Q; m++) 
        {
            int f=visitors[m] - 1;
            for (int n=0; n<M; n++) 
            {
                if (rooms_arr[f][n] == 1)
                    lights[n] = 1 - lights[n];
            }
        }

        // handling output
        printf("Case #%d:\n", t + 1);
        for (int o = 0; o < M; o++) 
        {
            if (lights[o] == 1)
                printf("YES\n");
            else 
                printf("NO\n");
        }
    }
    return 0;
}