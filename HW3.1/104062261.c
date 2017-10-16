#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int *Buffer;

long long max(long long a, long long b, long long c);
long long maxSubArraySum(long long start, long long end);
long long maxCrossingSubArraySum(long long start, long long mid, long long end);

int main(void) {
    FILE *input, *output;
    char s[20];
    long long size, i, Msum = 0;

    input = fopen("input.txt", "r");
    fgets(s, 20, input);
    size = atoi(s);
    Buffer = calloc(size, sizeof(int));
    for(i=0;i<size;i++) {
        fscanf(input, "%s", s);
        Buffer[i] = atoi(s);
    }
    fclose(input);

    Msum = maxSubArraySum(0, size-1);

    output = fopen("output.txt", "w");
    fprintf(output, "%lli\n", Msum);
    fclose(output);

    return 0;
}

long long max(long long a, long long b, long long c) {
    if( a>=b && a>=c ) return a;
    else if( b>=a && b>=c ) return b;
    else return c;
}

long long maxSubArraySum(long long start, long long end) {
    if(start == end) return Buffer[start];
    long long mid = (start + end) / 2;
    return max(maxSubArraySum(start, mid), maxSubArraySum(mid+1, end), maxCrossingSubArraySum(start, mid, end));
}

long long maxCrossingSubArraySum(long long start, long long mid, long long end) {
    long long Lsum, Rsum, sum, i;

    Lsum = INT_MIN;
    sum = 0;
    for(i=mid;i>=start;i--) {
        sum = sum + Buffer[i];
        if(sum > Lsum) {
            Lsum = sum;
        }
    }

    Rsum = INT_MIN;
    sum = 0;
    for(i=mid+1;i<=end;i++) {
        sum = sum + Buffer[i];
        if(sum > Rsum) {
            Rsum = sum;
        }
    }

    return Lsum + Rsum;
}
