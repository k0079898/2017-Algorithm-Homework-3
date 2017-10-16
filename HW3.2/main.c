#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

int main() {
    FILE *input, *output;
    char s[20];
    int *Buffer;
    long long size, i, j, k, sum, Msum = INT_MIN;
    clock_t t1, t2;

    input = fopen("input.txt", "r");
    fgets(s, 20, input);
    size = atoi(s);
    Buffer = calloc(size, sizeof(int));
    for(i=0;i<size;i++) {
        fscanf(input, "%s", s);
        Buffer[i] = atoi(s);
    }
    fclose(input);

    Msum = Buffer[0];
    t1 = clock();
    for(i=0;i<size;i++) {
        for(j=i;j<size;j++) {
            sum = 0;
            for(k=i;k<=j;k++) {
                sum = sum + Buffer[k];
            }
            if(sum >= Msum) Msum = sum;
        }
    }
    t2 = clock();
    printf("%lf", (t2-t1)/(double)(CLOCKS_PER_SEC));

    output = fopen("output.txt", "w");
    fprintf(output, "%lli\n", Msum);
    fclose(output);

    return 0;
}
