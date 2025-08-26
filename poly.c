#include <stdio.h>
#define MAX_TERMS 100

typedef struct {
    int coeff;
    int exp;
} Term;

int readPolynomial(Term poly[]) {
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    printf("Enter terms as coefficient and exponent :\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &poly[i].coeff, &poly[i].exp);
    }
    return n;
}

void printPolynomial(Term poly[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%dx^%d", poly[i].coeff, poly[i].exp);
        if (i != n - 1) printf(" + ");
    }
    printf("\n");
}
int addPolynomial(Term poly1[], int n1, Term poly2[], int n2, Term sum[]) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (poly1[i].exp > poly2[j].exp)
            sum[k++] = poly1[i++];
        else if (poly1[i].exp < poly2[j].exp)
            sum[k++] = poly2[j++];
        else {
            sum[k] = poly1[i];
            sum[k++].coeff = poly1[i].coeff + poly2[j].coeff;
            i++; j++;
        }
    }
    while (i < n1) sum[k++] = poly1[i++];
    while (j < n2) sum[k++] = poly2[j++];
    return k;
}
int main() {
    Term poly1[MAX_TERMS], poly2[MAX_TERMS], sum[MAX_TERMS];
    int n1, n2, nSum;

    printf("Read first polynomial:\n");
    n1 = readPolynomial(poly1);

    printf("Read second polynomial:\n");
    n2 = readPolynomial(poly2);

    nSum = addPolynomial(poly1, n1, poly2, n2, sum);

    printf("Sum polynomial: ");
    printPolynomial(sum, nSum);

    return 0;
}

