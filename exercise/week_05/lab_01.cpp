#include <iostream>
using namespace std;

int main() {
    int arr[100], n;

    // Nhap mang
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Xuat mang
    cout << "Cac phan tu trong mang la: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

