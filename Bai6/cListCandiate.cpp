#include "cListCandidate.h"
void cListCandidate::Nhap() {
	cout << "Nhap so luong thi sinh: ";
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cout << "Nhap thong tin thi sinh " << i + 1 << endl;
		arr[i].Nhap();
	}
}
void cListCandidate::Xuat() {
	cout << "Nhung thi sinh co tong diem lon hon 15: " << endl;
	cout << "Ma" << "\t" << "Ho ten:" << "\t\t" << "Ngay sinh:" << "\t\t" << "Toan:" << "\t" << "Van:" << "\t" << "Anh:" << "\t" <<"Tong diem"<< endl;
	for (int i = 0; i < n; i++) {
		if (arr[i].tongDiem() > 15) {
			arr[i].Xuat();
		}
	}
}
void cListCandidate::candidateMax() {
	if (arr.empty()) {
		cout << "Danh sach trong!" << endl;
		return;
	}
	vector<cCandidate> res;
	float diemMax = arr[0].tongDiem();
	for (int i = 1; i < n; i++) {
		if (arr[i].tongDiem() > diemMax) {
			diemMax = arr[i].tongDiem();
		}
	}
	for (cCandidate x : arr) {
		if (x.tongDiem() == diemMax) {
			res.push_back(x);
		}
	}
	cout << "Nhung thi sinh co tong diem cao nhat: " << endl;
	cout << "Ma" << "\t" << "Ho ten:" << "\t\t" << "Ngay sinh:" << "\t\t" << "Toan:" << "\t" << "Van:" << "\t" << "Anh:" << "\t" <<"Tong diem"<< endl;
	for (int i = 0; i < res.size(); i++) {
		cout << i + 1 << ". " << endl;
		res[i].Xuat();
	}
}
void cListCandidate::sapXepGiam() {
	if (arr.empty()) {
		cout << "Danh sach trong!" << endl;
		return;
	}
	for (int i = 0; i < n; i++) {
		int max = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j].tongDiem() > arr[max].tongDiem()) {
				max = j;
			}
		}
		swap(arr[i], arr[max]);
	}
	cout << "Danh sach thi sinh co tong diem giam dan: " << endl;
	cout << "Ma" << "\t" << "Ho ten:" << "\t\t" << "Ngay sinh:" << "\t\t" << "Toan:" << "\t" << "Van:" << "\t" << "Anh:" << "\t" << endl;
	for (int i = 0; i < n; i++) {
		cout << i + 1 << ": " << endl;
		arr[i].Xuat();
	}
}
