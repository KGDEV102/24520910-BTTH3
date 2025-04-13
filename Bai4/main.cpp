#include"cArray.h"
void main() {
	cArray arr;
	arr.Xuat();
	arr.Dem();
	if (arr.kiemTraTangDan()) {
		cout << "Mang tren la mang tang dan\n";
	}
	else {
		cout << "Mang tren khong tang dan\n";
	}
	if (arr.timSoLeMin()) {
		cout << "So le nho nhat trong mang la: " << arr.timSoLeMin() << endl;
	}
	if (arr.timSoNTMax()) {
		cout << "So nguyen to lon nhat trong mang la: " << arr.timSoNTMax();
	}
	arr.sapXepTang();
	arr.sapXepGiam();
	
}
