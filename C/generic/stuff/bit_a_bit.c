#include <stdio.h>

int main() {
    int i = 2, j = 3, k = 4;
    
    printf("%d, %d, %d\n", i & j, i | 1, k | j); /* Affiche i et bit à bit j, i et bit à bit 1, k bit à bit j */
    if ((i & k) || (i & j)) 
    printf("ok");
    return (0);
}