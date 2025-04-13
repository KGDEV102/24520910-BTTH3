#include "DaGiac.h"
DaGiac::DaGiac() {
	n = 0;
}
DaGiac::DaGiac(int m, vector<Diem> d) {
	n = m;
	dg = d;
}
DaGiac::DaGiac(const DaGiac& d) {
	n = d.n;
	dg = d.dg;
}
DaGiac::~DaGiac(){
	return;
}

void DaGiac::Nhap() {
	cout << "Nhap vao so diem cua da giac: ";
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cout << "Nhap vao diem thu " << i + 1 << ": " << endl;
		Diem temp;
		temp.Nhap();
		dg.push_back(temp);
	}
}
void DaGiac::Xuat() {
	cout << "Da giac gom " << n << " diem: ";
	for (Diem temp : dg) {
		cout << "("; temp.Xuat(); cout << ")";
	}
	cout << endl;
}
void DaGiac::tinhTien(double dx, double dy) {
	for (Diem &temp : dg) {
		temp.tinhTien(dx, dy);
	}
}
void DaGiac::phongTo(double scale) {
	for (Diem &temp : dg) {
		temp.phongTo(scale);
	}
}
void DaGiac::quay(double alpha) {
	for (Diem &temp : dg) {
		temp.quay(alpha);
	}
}
