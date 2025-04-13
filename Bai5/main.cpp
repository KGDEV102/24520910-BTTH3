#include"cDaThuc.h"
void main() {
	cDaThuc dt1, dt2, res1, res2;
	cout << "Nhap vao da thuc 1: ";
	dt1.Nhap();
	dt1.Xuat();
	cout << "Nhap vao da thuc 2: ";
	dt2.Nhap();
	dt2.Xuat();
	dt1.tinhcDaThuc();
	dt2.tinhcDaThuc();
}
