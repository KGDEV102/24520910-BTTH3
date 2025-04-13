#include "cCandidate.h"
#include<string>
void cCandidate::Nhap() {
    cout << "Ma: ";
    cin >> ma;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa bộ đệm trước khi nhập tên

    cout << "Ho ten: ";
    getline(cin, ten); // Đọc toàn bộ dòng, bao gồm cả dấu cách

    cout << "Ngay sinh: ";
    getline(cin, ngaySinh); // Đọc cả ngày sinh để tránh lỗi khi nhập theo format dd/mm/yyyy

    do {
        cout << "Toan: ";
        cin >> toan;
    } while (toan < 0 || toan > 10);

    do {
        cout << "Van: ";
        cin >> van;
    } while (van < 0 || van > 10);

    do {
        cout << "Anh: ";
        cin >> anh;
    } while (anh < 0 || anh > 10);

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Đảm bảo xóa bộ đệm sau khi nhập số
}

float cCandidate::tongDiem() {
	return (toan + van + anh);
}
void cCandidate::Xuat() {
    if (ten.size() > 8) {
        cout << ma << "\t" << ten << "\t" << ngaySinh << "\t\t" << toan << "\t" << van << "\t" << anh << "\t" << this->tongDiem() << endl;
    }
    else {
        cout << ma << "\t" << ten << "\t\t" << ngaySinh << "\t\t" << toan << "\t" << van << "\t" << anh << "\t" << this->tongDiem() << endl;
    }
    
}
