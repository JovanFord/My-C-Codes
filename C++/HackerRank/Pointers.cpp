#include <stdio.h>
#include <cstdlib>
void update(int *a,int *b) {
    int c = *a + *b;
    int d = abs(*a - *b);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}