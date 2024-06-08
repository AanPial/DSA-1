#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    for (int i = 1; i < n; i++) { 
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int c[max + 1]; 
    int b[n];

    for (int i = 0; i <= max; i++) {
        c[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        c[arr[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        c[i] += c[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) { 
        b[c[arr[i]] - 1] = arr[i];
        c[arr[i]]--;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }

    return 0;
}
