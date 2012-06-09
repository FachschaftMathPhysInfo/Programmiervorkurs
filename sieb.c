#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2)
        return 1;
    uint64_t n = atoi(argv[1]);
    if (n <= 0)
        return 1;
    
    uint64_t *candidates = malloc(n * sizeof(uint64_t));
    if (candidates == NULL) {
        fprintf(stderr, "OOM\n");
        return 1;
    }

    for (uint64_t i = 0; i < n; i++) {
        candidates[i] = i;
    }

    for (uint64_t i = 2; i < n; i++) {
        uint64_t j = i * i;
        while (j < n) {
            candidates[j] = 0;
            j += i;
        }
    }

    for (uint64_t i = 0; i < n; i++) {
        if (candidates[i] != 0) {
            printf("%d\n", candidates[i]);
        }
    }
    free(candidates);
}
