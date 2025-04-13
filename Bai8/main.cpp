#include"cNhanVienSX.h"
#include<vector>
#include<limits>
#include<algorithm>
void Nhap(vector<cNhanVienSX>& arr) {
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cout << "Nhap vao nhan vien thu " << i + 1 << ": " << endl;
        arr[i].Nhap();
    }
}
void Xuat(vector<cNhanVienSX> arr) {
    cout << "Ma: " << "\t" << "Ho ten: " << "\t" << "Ngay sinh: " << "\t" << "Luong: " << endl;
    for (int i = 0; i < arr.size(); i++) {
        cout << i + 1 << ": " << endl;
        arr[i].Xuat();
    }
}

void timMin(vector<cNhanVienSX> arr) {
    vector<cNhanVienSX> res;
    double min_luong = INT_MAX;

    for (cNhanVienSX x : arr) {
        double luong = x.tinhLuong();
        if (luong < min_luong) {
            min_luong = luong;
            res.clear(); // xóa hết các phần tử cũ
            res.push_back(x);
        }
        else if (luong == min_luong) {
            res.push_back(x);
        }
    }

    // In kết quả
    cout << "Cac nhan vien co luong thap nhat (" << min_luong << "):\n";
    cout << "Ma: " << "\t" << "Ho ten: " << "\t" << "Ngay sinh: " << "\t" << "Luong: " << endl;
    for (cNhanVienSX nv : res) {

        nv.Xuat();
    }
}
void tongLuong(vector<cNhanVienSX> arr) {
    double sum = 0;
    for (cNhanVienSX x : arr) {
        sum += x.tinhLuong();
    }
    cout << "Tong luong ma cong ty phai tra cho nhan vien: " << sum << endl;
}
void timTuoiMax(vector<cNhanVienSX>arr) {
    vector<cNhanVienSX> res;
    int tuoi_max = INT_MIN;

    for (cNhanVienSX x : arr) {
        int tuoi = x.getTuoi(); // tránh gọi nhiều lần
        if (tuoi > tuoi_max) {
            tuoi_max = tuoi;
            res.clear();
            res.push_back(x);
        }
        else if (tuoi == tuoi_max) {
            res.push_back(x);
        }
    }

    cout << "Cac nhan vien co tuoi cao nhat (" << tuoi_max << "):\n";
    cout << "Ma: " << "\t" << "Ho ten: " << "\t" << "Ngay sinh: " << "\t" << "Luong: " << endl;

    for (cNhanVienSX nv : res) {
        nv.Xuat();
    }
}
bool cmp(cNhanVienSX a, cNhanVienSX b) {
    return a.tinhLuong() < b.tinhLuong();
}
void sapXepTang(vector<cNhanVienSX>&arr) {
    sort(arr.begin(), arr.end(), cmp);
}
void main() {
    vector<cNhanVienSX>ds;
    Nhap(ds);
    Xuat(ds);
    timMin(ds);
    tongLuong(ds);
    timTuoiMax(ds);
    sapXepTang(ds);
    cout << "Danh sach nhan vien tang dan theo luong: \n";
    Xuat(ds);
}
