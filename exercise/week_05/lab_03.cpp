#include <iostream>
#include <string>
using namespace std;

int main() {
    string ten;
    int tuoi;
    float diemTB;

    // Nhap thông tin sinh viên
    cout << "Nhap ten sinh vien: ";
    cin.ignore();
    getline(cin, ten);
    cout << "Nhap tuoi: ";
    cin >> tuoi;
    cout << "Nhap diem trung binh: ";
    cin >> diemTB;

    // Xuat thông tin sinh viên
    cout << "Thong tin sinh vien:\n";
    cout << "Ten: " << ten << endl;
    cout << "Tuoi: " << tuoi << endl;
    cout << "Diem trung binh: " << diemTB << endl;

    return 0;
}

