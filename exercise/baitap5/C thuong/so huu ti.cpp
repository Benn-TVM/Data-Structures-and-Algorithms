#include <stdio.h>

int main() {
    int tu1, mau1, tu2, mau2, tuKQ, mauKQ;

    // Nh?p hai s? h?u t?
    printf("Nhap tu so va mau so cua so huu ti thu nhat (a/b): ");
    scanf("%d %d", &tu1, &mau1);
    printf("Nhap tu so va mau so cua so huu ti thu hai (c/d): ");
    scanf("%d %d", &tu2, &mau2);

    // Tính t?ng
    tuKQ = tu1 * mau2 + tu2 * mau1;
    mauKQ = mau1 * mau2;
    printf("Tong hai so huu ti: %d/%d\n", tuKQ, mauKQ);

    // Tính tích
    tuKQ = tu1 * tu2;
    mauKQ = mau1 * mau2;
    printf("Tich hai so huu ti: %d/%d\n", tuKQ, mauKQ);

    // Tính thuong
    tuKQ = tu1 * mau2;
    mauKQ = mau1 * tu2;
    printf("Thuong hai so huu ti: %d/%d\n", tuKQ, mauKQ);

    return 0;
}

