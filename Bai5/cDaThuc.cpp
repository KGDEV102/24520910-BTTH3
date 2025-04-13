#include "cDaThuc.h"
cDaThuc::cDaThuc() {
	n = 0;
}
void cDaThuc::Nhap() {
	cout << "Nhap vao bac da thuc: ";
	cin >> n;
	arr.resize(n+1);
	cout << "Nhap vao cac he so: " << endl;
	for (int i = 0; i <=n; i++) {
		cout << "Nhap vao he so thu " << i + 1 << ":";
		cin >> arr[i];
	}
}
void cDaThuc::Xuat() {
    bool firstTerm = true; //check phần tử đầu tiên 
    int degree = n;

    for (int i = 0; i < arr.size(); ++i, --degree) {
        int coeff = arr[i];
        if (coeff == 0) continue;

        // Dấu +/-
        if (!firstTerm) {
            if (coeff > 0) cout << "+";
        }

        // Hệ số
        if (abs(coeff) != 1 || degree == 0) {
            cout << coeff;
        }
        else if (coeff == -1) {
            cout << "-";
        }

        // Biến x
        if (degree > 0) {
            cout << "x";
            if (degree > 1) cout << "^" << degree;
        }

        firstTerm = false;
    }

    // Trường hợp mọi hệ số đều là 0
    if (firstTerm) {
        cout << "0";
    }

    cout << endl;
}

void cDaThuc::tinhcDaThuc() {
	cout << "Nhap vao gia tri x: ";
	cin >> x;
	int index = 0;
	double res = 0;
	for (int temp : arr) {
		res += temp * pow(x, n - index);
		++index;
	}
	cout << "Gia tri cua da thuc voi x = " << x << ": " << res << endl;
}
cDaThuc cDaThuc::operator+(const cDaThuc& other) {
	cDaThuc result;

	int maxDegree = max(this->n, other.n);
	int sizeA = this->arr.size();
	int sizeB = other.arr.size();
	int diff = abs(sizeA - sizeB);

	// Đệm hệ số 0 vào đầu vector nhỏ hơn (vì lưu từ bậc cao -> thấp)
	vector<int> a = this->arr;
	vector<int> b = other.arr;

	if (sizeA < sizeB) a.insert(a.begin(), diff, 0);
	if (sizeB < sizeA) b.insert(b.begin(), diff, 0);

	for (int i = 0; i < max(sizeA, sizeB); ++i) {
		result.arr.push_back(a[i] + b[i]);
	}

	result.n = maxDegree;
	return result;
}
cDaThuc cDaThuc::operator-(const cDaThuc& other) {
	cDaThuc result;

	int maxDegree = max(this->n, other.n);
	int sizeA = this->arr.size();
	int sizeB = other.arr.size();
	int diff = abs(sizeA - sizeB);

	vector<int> a = this->arr;
	vector<int> b = other.arr;

	if (sizeA < sizeB) a.insert(a.begin(), diff, 0);
	if (sizeB < sizeA) b.insert(b.begin(), diff, 0);

	for (int i = 0; i < max(sizeA, sizeB); ++i) {
		result.arr.push_back(a[i] - b[i]);
	}

	result.n = maxDegree;
	return result;
}
