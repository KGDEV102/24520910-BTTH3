#include"cCandidate.h"
#include"cListCandidate.h"
void main() {
	cListCandidate ds;
	ds.Nhap();
	ds.Xuat();
	cout << endl << endl;
	ds.candidateMax();
	cout << endl << endl;
	ds.sapXepGiam();
}
