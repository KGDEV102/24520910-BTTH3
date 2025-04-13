#include "cNhanVienVP.h"
#include<string>
#include<iomanip>
#include<sstream>
cNhanVienVP::cNhanVienVP() {
	ma = "";
	hoTen = "";
	ngaySinh = "";	
	luong = 0;
}
void cNhanVienVP::Nhap() {
	cout << "Ma: ";
	cin >> ma;
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa bộ đệm 
	cout << "Ho ten: ";
	getline(cin, hoTen);
	cout << "Ngay sinh: ";
	cin >> ngaySinh;
	cout << "Luong: ";
	cin >> luong;
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Xóa bộ đệm 
}
void cNhanVienVP::Xuat() {
	if (hoTen.size() > 8) {
		cout << ma << "\t" << hoTen << "\t" << ngaySinh << "\t\t" << luong << endl;
	}
	else {
		cout << ma << "\t" << hoTen << "\t\t" << ngaySinh << "\t\t" << luong << endl;
	}
	
}
string cNhanVienVP:: getMa() {
	return ma;
}
string cNhanVienVP:: getHoTen() {
	return hoTen;
}
string cNhanVienVP:: getNgaySinh() {
	return ngaySinh;
}
double cNhanVienVP::getLuong() {
	return luong;
}
void cNhanVienVP:: setMa(string ma) {
	this->ma = ma;
}
void cNhanVienVP::setHoTen(string hoTen) {
	this->hoTen = hoTen;
}
void cNhanVienVP:: setNgaySinh(string ngaySinh) {
	this->ngaySinh = ngaySinh;
}
void cNhanVienVP::setLuong(double luong) {
	this->luong = luong;
}
int cNhanVienVP::getTuoi() {
	int ngay, thang, nam;

	// Tách ngày/tháng/năm từ chuỗi "dd/mm/yyyy"
	char delim; // để đọc dấu '/'
	stringstream ss(this->ngaySinh);
	if (!(ss >> ngay >> delim >> thang >> delim >> nam)) {
		cerr << "Lỗi: định dạng ngày sinh không hợp lệ!\n";
		return -1;
	}
	

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
