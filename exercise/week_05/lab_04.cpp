#include <iostream>
using namespace std;

int main() {
    int mat[100][100], rows, cols;

    // Nhap ma tran
    cout << "Nhap so hang: ";
    cin >> rows;
    cout << "Nhap so cot: ";
    cin >> cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Nhap phan tu [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }

    // Xuat ma tran
    cout << "Ma tran la:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

