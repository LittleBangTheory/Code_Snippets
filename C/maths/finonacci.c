#include <stdio.h>
int fibonacci(int);


int main() {
    int n;
    printf("Entrez un entier\n");
    scanf("%d", &n);
    printf("%d\n", fibonacci(n));

    return 0;
}

int fibonacci(int n) {
    int a = 0;
    int b = 1;
    int result;
    if (n == 0) {
        result = 0;
    } else if (n == 1) {
        result = 1;
    }

    for (int i=2; i<=n; i++) {
        result = a + b;
        a = b;
        b = result;
    }
    
    return result;
}
