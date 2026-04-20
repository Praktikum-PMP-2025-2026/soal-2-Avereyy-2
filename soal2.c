#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int a[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    // prefix sum
    int prefix[N];
    prefix[0] = a[0];
    for (int i = 1; i < N; i++) {
        prefix[i] = prefix[i - 1] + a[i];
    }

    int min_diff = 1000000000;
    int best_i = 0, best_j = 0;

    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {

            int s1 = prefix[i];
            int s2 = prefix[j] - prefix[i];
            int s3 = prefix[N - 1] - prefix[j];

            int max = s1;
            if (s2 > max) max = s2;
            if (s3 > max) max = s3;

            int min = s1;
            if (s2 < min) min = s2;
            if (s3 < min) min = s3;

            int diff = max - min;

            if (diff < min_diff) {
                min_diff = diff;
                best_i = i;
                best_j = j;
            }
        }
    }

    // output: panjang dua potongan pertama
    printf("MIN_DIFF %d\n", min_diff);
    printf("CUT %d %d\n", best_i + 1, best_j - best_i);

    return 0;
}
