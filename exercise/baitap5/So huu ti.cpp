#include <iostream>
using namespace std;

int main() {
    int tu1, mau1, tu2, mau2, tuKQ, mauKQ;

    // Nhap hai so huu ti
    cout << "Nhap tu so va mau so cua so huu ti thu nhat (a/b): ";
    cin >> tu1 >> mau1;
    cout << "Nhap tu so va mau so cua so huu ti thu hai (c/d): ";
    cin >> tu2 >> mau2;

    // Tính tong
    tuKQ = tu1 * mau2 + tu2 * mau1;
    mauKQ = mau1 * mau2;
    cout << "Tong hai so huu ti: " << tuKQ << "/" << mauKQ << endl;

    // Tính tích
    tuKQ = tu1 * tu2;
    mauKQ = mau1 * mau2;
    cout << "Tich hai so huu ti: " << tuKQ << "/" << mauKQ << endl;

    // Tính thuong
    tuKQ = tu1 * mau2;
    mauKQ = mau1 * tu2;
    cout << "Thuong hai so huu ti: " << tuKQ << "/" << mauKQ << endl;

    return 0;
}

