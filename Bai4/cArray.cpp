#include "cArray.h"
#include<random>
#include<climits> // để dùng INT_MIN, INT_MAX

cArray::cArray() {
	cout << "Nhap vao n: ";
	cin >> n;
    random_device rd;//nguồn tạo seed ngẫu nhiên 
    mt19937 gen(rd()); // tạo dãy số ngẫu nhiên
    uniform_int_distribution<int> dist(INT_MIN, INT_MAX);

    for (int i = 0; i < n; ++i) {
        arr.push_back(dist(gen));
    }
}
void cArray::Xuat() {
    cout << "Day so ngau nhien la: \n";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}
void cArray::Dem() {
    int cnt = 0;
    int x;
    cout << "Nhap vao gia tri x can dem: ";
    cin >> x;
    for (int temp : arr) {
        if (temp == x) ++cnt;
    }
    if (cnt) {
        cout << "So " << x << " xuat hien " << cnt << " lan trong mang \n";
    }
    else {
        cout << "So " << x << " khong xuat hien trong mang \n";
    } 
}
bool cArray::kiemTraTangDan() {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) return false;
    }
    return true;
}
int cArray::timSoLeMin() {
    int res = INT_MAX;
    for (int x : arr) {
        if (x % 2 != 0) {
            if (x < res) res = x;
        }
    }
    if (res == INT_MAX) {
        cout << "Khong co so le trong mang\n";
        return 0;
    }
    return res;
}
bool kiemTraNT(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}
int cArray::timSoNTMax() {
    int res = INT_MIN;
    for (int x : arr) {
        if (kiemTraNT(x)) {
            if (x > res) res = x;
        }
    }
    if (res == INT_MIN) {
        cout << "Khong co so nguyen to trong mang.\n";
        return 0;
    }
    return res;
}
void quickSort1(vector<int>& v, int l, int r) {
    if (l >= r) return;
    int pivot = v[(l + r) / 2];
    int i = l, j = r;
    while (i <= j) {
        while (v[i] < pivot) ++i;
        while (v[j] > pivot) --j;
        if (i <= j) {
            swap(v[i], v[j]);
            ++i;
            --j;
        }
    }
    if (l < j) quickSort1(v, l, j);
    if (i < r) quickSort1(v, i, r);
}

void quickSort2(vector<int>& v, int l, int r) {
    if (l >= r) return;
    int pivot = v[(l + r) / 2];
    int i = l, j = r;
    while (i <= j) {
        while (v[i] > pivot) ++i;
        while (v[j] < pivot) --j;
        if (i <= j) {
            swap(v[i], v[j]);
            ++i;
            --j;
        }
    }
    if (l < j) quickSort2(v, l, j);
    if (i < r) quickSort2(v, i, r);
}

void cArray :: sapXepTang() {
    quickSort1(arr, 0, arr.size() - 1);
    cout << "Mang sau khi sap xep tang dan: ";
    for (int x : arr) {
        cout << x<<" ";
    }
    cout << endl;
}
void cArray::sapXepGiam() {
    quickSort2(arr, 0, arr.size() - 1);
    cout << "Mang sau khi sap xep giam dan: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}
