#include"cNhanVienVP.h"
#include<vector>
#include<limits>
#include<algorithm>
void Nhap(vector<cNhanVienVP>& arr) {
	int n;
	cout << "Nhap so luong nhan vien: ";
	cin >> n;
	
	arr.resize(n);
	for (int i = 0; i < n; i++) {
        cout << "Nhap vao nhan vien thu " << i + 1 <<": "<< endl;
		arr[i].Nhap();
	}
}
void Xuat(vector<cNhanVienVP> arr) {
    cout << "Ma: " << "\t" << "Ho ten: " << "\t" << "Ngay sinh: " << "\t\t" << "Luong: " << endl;
    for (int i = 0; i < arr.size(); i++) {
        cout << i + 1 << ": " << endl;
        arr[i].Xuat();
    }
}
void timMax( vector<cNhanVienVP> arr) {
    vector<cNhanVienVP> res;
    double max_luong = INT_MIN;

    for ( cNhanVienVP x : arr) {
        double luong = x.getLuong();
        if (luong > max_luong) {
            max_luong = luong;
            res.clear(); // xóa hết các phần tử cũ
            res.push_back(x);
        }
        else if (luong == max_luong) {
            res.push_back(x);
        }
    }

    // In kết quả
    cout << "Cac nhan vien co luong cao nhat (" << max_luong << "):\n";
    cout << "Ma: " << "\t" << "Ho ten: " << "\t" << "Ngay sinh: " << "\t" << "Luong: " << endl;
    for (cNhanVienVP nv : res) {
        
        nv.Xuat(); 
    }
}
void tongLuong(vector<cNhanVienVP> arr) {
    double sum = 0;
    for (cNhanVienVP x : arr) {
        sum += x.getLuong();
    }
    cout << "Tong luong ma cong ty phai tra cho nhan vien: " << sum << endl;
}
void timTuoiMax(vector<cNhanVienVP>arr) {
    vector<cNhanVienVP> res;
    int tuoi_max = INT_MIN;

    for (cNhanVienVP x : arr) {
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

    for (cNhanVienVP nv : res) {
        nv.Xuat();
    }
}
bool cmp(cNhanVienVP a, cNhanVienVP b) {
    return a.getLuong() < b.getLuong();
}
void sapXepTang(vector<cNhanVienVP>&arr) {
    sort(arr.begin(), arr.end(), cmp);

}
int main() {
    vector<cNhanVienVP>ds;
    Nhap(ds);
    Xuat(ds);
    timMax(ds);
    tongLuong(ds);
    timTuoiMax(ds);
    sapXepTang(ds);
    cout << "Danh sach nhan vien tang dan theo luong: \n";
    Xuat(ds);
    return 0;
}
