#include"Diem.h"
#include"DaGiac.h"
int main() {
    int chon;
    DaGiac* dg = new DaGiac;
    do {
        cout << "----------CHUONG TRINH XU LY DaGiac----------\n";
        cout << "1. Nhap vao DaGiac \n";
        cout << "2. Xuat DaGiac \n";
        cout << "3. Tinh tien DaGiac \n";
        cout << "4. Phong to DaGiac \n";
        cout << "5. Quay DaGiac \n";
        cout << "0. Thoat CT \n";
        cout << "-------------------------------------------\n";
        cout << "Ban chon: ";
        cin >> chon;

        switch (chon) {
        case 1:
           
            dg->Nhap();
            break;
        case 2:
            dg->Xuat();
            cout << endl;
            break;
        case 3:
            double dx, dy;
            
            cout << "Nhap khoang cach ngang, doc can di chuyen DaGiac: \n";
            cin >> dx >> dy;
            dg->tinhTien(dx, dy);
            
            cout << "Cac diem cua DaGiac sau khi di chuyen: " << endl;
            dg->Xuat();
            break;
        case 4:
            int scale;
            cout << "Nhap vao gia tri de phong to DaGiac\n";
            cin >> scale;
            dg->phongTo(scale);
            cout << "Cac diem cua DaGiac sau khi phong to: " << endl;
            dg->Xuat();
            break;
        case 5:
            double alpha;
            cout << "Nhap vao goc quay: \n";
            cin >> alpha;
            dg->quay(alpha);
            cout << "Cac diem cua DaGiac sau khi quay: " << endl;
            dg->Xuat();
            break;
        case 0:
            cout << "Dang thoat...";
            break;
        default:
            cout << "Nhap khong dung. Vui long nhap lai!";
        }
    } while (chon != 0);
    delete dg;

}
