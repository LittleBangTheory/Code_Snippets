#include <stdio.h>

int factorielle(int);
int factorielleBis(int);

int main() {
    int n;
    printf("Entrez un entier\n");
    scanf("%d", &n);
    printf("%d\n", factorielle(n));

    return 0;
}

int factorielle(int n) {
    int result = 1;
    for (int i=1; i<=n; i++) {
        result = result * i;
    }

    return result;
}


int factorielleBis(int m) {
    int result = 1;
    int i = 1;

    while (result <= m) {
        i++;
        result = result * i;
    }

    return i;
}   