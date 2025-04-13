#include "cNhanVienSX.h"
#include "cNhanVienSX.h"
#include<string>
#include<iomanip>
#include<sstream>
cNhanVienSX::cNhanVienSX() {
	ma = "";
	hoTen = "";
	ngaySinh = "";
	soSP = 0;
	donGia = 0;
}
void cNhanVienSX::Nhap() {
	cout << "Ma: ";
	cin >> ma;
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa b? d?m 
	cout << "Ho ten: ";
	getline(cin, hoTen);
	cout << "Ngay sinh: ";
	cin >> ngaySinh;
	cout << "So san pham da gia cong: ";
	cin >> soSP;
	cout << "Don gia mot san pham: ";
	cin >> donGia;
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa b? d?m 
}
double cNhanVienSX::tinhLuong() {
	return soSP * donGia;
}
void cNhanVienSX::Xuat() {
	if (hoTen.size() > 8) {
		cout << ma << "\t" << hoTen << "\t" << ngaySinh << "\t" << tinhLuong() << endl;
	}
	else {
		cout << ma << "\t" << hoTen << "\t\t" << ngaySinh << "\t" << tinhLuong() << endl;
	}
}
string cNhanVienSX::getMa() {
	return ma;
}
string cNhanVienSX::getHoTen() {
	return hoTen;
}
string cNhanVienSX::getNgaySinh() {
	return ngaySinh;
}
int cNhanVienSX::getSoSP() {
	return soSP;
}
double cNhanVienSX::getDonGia() {
	return donGia;
}
void cNhanVienSX::setMa(string ma) {
	this->ma = ma;
}
void cNhanVienSX::setHoTen(string hoTen) {
	this->hoTen = hoTen;
}
void cNhanVienSX::setNgaySinh(string ngaySinh) {
	this->ngaySinh = ngaySinh;
}
void cNhanVienSX::setSoSP(int soSP) {
	this->soSP = soSP;
}
void cNhanVienSX::setDonGia(double donGia) {
	this->donGia = donGia;
}
int cNhanVienSX::getTuoi() {
	int ngay, thang, nam;

	// Tách ngày/tháng/năm từ chuỗi "dd/mm/yyyy"
	char delim; // để đọc dấu '/'
	stringstream ss(this->ngaySinh);
	if (!(ss >> ngay >> delim >> thang >> delim >> nam)) {
		cerr << "Lỗi: định dạng ngày sinh không hợp lệ!\n";
		return -1;
	}
	ss >> ngay >> delim >> thang >> delim >> nam;

	// Lấy thời gian hiện tại
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now); // Dùng localtime_s thay vì localtime

	int namHienTai = 1900 + ltm.tm_year;
	int thangHienTai = 1 + ltm.tm_mon;
	int ngayHienTai = ltm.tm_mday;


	int tuoi = namHienTai - nam;

	// Trừ 1 nếu chưa tới sinh nhật năm nay
	if (thangHienTai < thang || (thangHienTai == thang && ngayHienTai < ngay)) {
		tuoi--;
	}

	return tuoi;
}
