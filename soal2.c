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
    int best_first = 1, best_second = 1;

    for (int first = 1; first <= N - 2; first++) {
        for (int second = 1; second <= N - first - 1; second++) {
            int end_first = first - 1;
            int end_second = first + second - 1;

            int sum_first = prefix[end_first];
            int sum_second = prefix[end_second] - prefix[end_first];
            int sum_third = prefix[N - 1] - prefix[end_second];

            int diff = sum_first + sum_second - sum_third;
            if (diff < 0) diff = -diff;

            if (diff < min_diff || (diff == min_diff && (first < best_first || (first == best_first && second < best_second)))) {
                min_diff = diff;
                best_first = first;
                best_second = second;
            }
        }
    }

    // output: panjang dua potongan pertama
    printf("MIN_DIFF %d\n", min_diff);
    printf("CUT %d %d\n", best_first, best_second);

    return 0;
}
