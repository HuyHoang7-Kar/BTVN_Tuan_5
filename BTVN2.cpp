#include <stdio.h>
#include <math.h>
int nt(int n) {
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
int ntBlum(int n) {
    if (nt(n) && n % 4 == 3) {
        return 1;
    }
    return 0;
}
int CheckBlum(int n) {
    for (int p = 2; p <= sqrt(n); p++) {
        if (n % p == 0) {
            int q = n / p;
            if (ntBlum(p) && ntBlum(q) && p != q) {
                return 1;
            }
        }
    }
    return 0;
}
void PrintBlumNumbers(int n) {
    printf("Day blum nho hon %d là: ", n);
    for (int i = 0; i < n; i++) {
        if (CheckBlum(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}
void FindBlum(int n, int m) {
    int a[n];  
    int size = 0;
    int found = 0;
    for (int i = 2; i <= n; i++) {
        if (CheckBlum(i)) {
            a[size++] = i;
        }
    }
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            int sum = a[i] + a[j];

            if (CheckBlum(sum)) {
                printf("Cap so co tong la so Blum: %d + %d = %d\n", a[i], a[j], sum);
            }
            else printf("Khong co cap so nao");
        }
    }

    for (int i = 0; i < size; i++) {
        if (m == a[i]) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("So %d co trong day so Blum\n", m);
    } else {
        printf("So %d khong co trong day so Blum\n", m);
    }
}
int main() {
    int n, m;
    printf("Nhap n và m: ");
    scanf("%d %d", &n, &m);
	PrintBlumNumbers(n);
    FindBlum(n, m);

    return 0;
}

