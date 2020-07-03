#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
using namespace std;


struct HoTen{
    char ho[5];
    char dem[5];
    char ten[5];

};
struct DiemMH{
    float toan;
    float van;
    float anh;
    float TrungBinh;

};
struct SinhVien{
    int ma;
    struct HoTen HoVaTen;
    string GioiTinh;
    int Tuoi;
    struct DiemMH diem;
};
void NhapDiem(struct DiemMH *diem){
    cout<<"diem toan : ";
    cin>>diem->toan;
    if(diem->toan >10 || diem->toan < 0 ){
        cout<<"diem khong hop le! ";
        cout<<"\nmoi nhap lai : ";
        cin>>diem->toan;
    }   
    cout<<"diem van : ";
    cin>>diem->van;
    if(diem->van >10 || diem->van < 0 ){
        cout<<"diem khong hop le! ";
         cout<<"\nmoi nhap lai : ";
        cin>>diem->van;
    }  
    cout<<"diem anh : ";
    cin>>diem->anh;
    if(diem->anh >10 || diem->anh < 0 ){
        cout<<"diem khong hop le! ";
        cout<<"\nmoi nhap lai : ";
        cin>>diem->toan;
    }  
    diem->TrungBinh = (diem->toan + diem->anh + diem->van)/3;
}
void NhapHoTen(struct HoTen *tenSV){
    cin.ignore();
    cout<<"ho : ";
    cin>>tenSV->ho;
    cout<<"dem : ";
    cin>>tenSV->dem;
    cout<<"ten : ";
    cin>>tenSV->ten;
}
struct SinhVien NhapSV(){
    struct SinhVien sv;
    cout<<"ma : ";
    cin>>sv.ma;
    NhapHoTen(&sv.HoVaTen);
   cout<<"tuoi : ";
   cin>>sv.Tuoi;
   cout<<"gioi tinh : ";
   cin>>sv.GioiTinh;
   NhapDiem(&sv.diem);
   return sv;
};
void HienThiTTSinhVien(struct SinhVien sv){
    cout<<sv.ma<<"\t"<<sv.HoVaTen.ho<<"\t"<<sv.HoVaTen.dem<<"\t"<<sv.HoVaTen.ten<<"\t"<<sv.Tuoi<<"\t"<<sv.GioiTinh<<"\t"<<sv.diem.toan<<"\t"<<sv.diem.van<<"\t"<<sv.diem.anh<<"\t"<<sv.diem.TrungBinh<<endl;
}
void HienThiTenCot(){
    cout<<"ma"<<"\t";
    cout<<"ho"<<"\t";
    cout<<"dem"<<"\t";
    cout<<"ten"<<"\t";
    cout<<"tuoi"<<"\t";
    cout<<"GT"<<"\t";
    cout<<"toan"<<"\t";
    cout<<"van"<<"\t";
    cout<<"anh"<<"\t";
    cout<<"DTB"<<"\n";
}
void TimTheoTen(struct SinhVien *ds, int slsv){
    char ten[10];
    cout<<"nhap ten sinh vien can tim : ";
    cin>>ten;
    HienThiTenCot();
    int timSV = 0;
    for(int i = 0; i < slsv; i++){
        if(int (strcmp(ten, ds[i].HoVaTen.ten)) == 0){
            HienThiTTSinhVien(ds[i]);
            timSV = 1 ;
        }
    }
    if(timSV == 0){
        cout<<endl<<endl;
        cout<<"khong co sinh vien nay!";
    }
}
void SapXepSinhVienTheoTen(struct SinhVien* ds, int slsv){
    
    for(int i = 0 ; i < slsv-1 ; i ++ ){
        if(strcmp(ds[i].HoVaTen.ten, ds[i+1].HoVaTen.ten) > 0 ){
            struct SinhVien sv = ds[i] ;
            ds[i] = ds[i+1];
            ds[i+1] = sv;
        }
    }
}
void SapXepTheoDiem(struct SinhVien *ds, int slsv){
    HienThiTenCot();
    for(int i= 0; i < slsv-1; i++){
        for(int j = slsv -1 ; j > i; j--){
        if(ds[j].diem.TrungBinh < ds[j-1].diem.TrungBinh){
            struct SinhVien sv = ds[j];
            ds[j] = ds[j-1];
            ds[j-1] = ds[j];
        }
        }
    }
}
void GhiFile(struct SinhVien *ds, int slsv){
    ofstream QuanLiSinhVien("quanlisinhvien1.txt");
     QuanLiSinhVien<<"ma"<<"\t";
     QuanLiSinhVien<<"ho"<<"\t";
     QuanLiSinhVien<<"dem"<<"\t";
     QuanLiSinhVien<<"ten"<<"\t";
     QuanLiSinhVien<<"tuoi"<<"\t";
     QuanLiSinhVien<<"GT"<<"\t";
     QuanLiSinhVien<<"toan"<<"\t";
     QuanLiSinhVien<<"van"<<"\t";
     QuanLiSinhVien<<"anh"<<"\t";
     QuanLiSinhVien<<"DTB"<<"\n";
    for(int i = 0; i < slsv ; i++){
        struct SinhVien sv = ds[i];
        QuanLiSinhVien<<sv.ma;
        QuanLiSinhVien<<"\t";
        QuanLiSinhVien<<sv.HoVaTen.ho;
        QuanLiSinhVien<<"\t";
        QuanLiSinhVien<<sv.HoVaTen.dem;
        QuanLiSinhVien<<"\t";
        QuanLiSinhVien<<sv.HoVaTen.ten;
        QuanLiSinhVien<<"\t";
        QuanLiSinhVien<<sv.Tuoi;
        QuanLiSinhVien<<"\t";
        QuanLiSinhVien<<sv.GioiTinh;
        QuanLiSinhVien<<"\t";
        QuanLiSinhVien<<sv.diem.toan;
        QuanLiSinhVien<<"\t"<<sv.diem.van;
        QuanLiSinhVien<<"\t"<<sv.diem.anh;
        QuanLiSinhVien<<"\t";
        QuanLiSinhVien<<sv.diem.TrungBinh;
        QuanLiSinhVien<<"\n";
    }
    QuanLiSinhVien.close();

}
void XepLoaiDanhSachSinhVien(struct SinhVien *ds, int slsv){
    cout<<"ten"<<"\t"<<"Xep Loai"<<endl;
    for(int i = 0; i<slsv; i++){
        struct SinhVien sv =ds[i];
        if(ds[i].diem.TrungBinh >= 8 ){
            cout<<ds[i].HoVaTen.ten<<"\t";
            cout<<"SINH VIEN GIOI ! "<<endl;
        }
        else if (ds[i].diem.TrungBinh < 8 && ds[i].diem.TrungBinh >= 5 )
        {
            cout<<ds[i].HoVaTen.ten<<"\t";
            cout<<"SINH VIEN KHA !"<<endl;
        }
        else
        {
            cout<<ds[i].HoVaTen.ten<<"\t";
            cout<<"ROT MON !"<<endl;
        }
    }
}
int main(){
    struct SinhVien dssv[200];
    int luachon;
    int slsv = 0;
    do {
        cout<<"\n";
        cout<<"-------------MENU----------"<<endl;
        cout<<"7: Xep loai sinh vien"<<endl;
        cout<<"6: Ghi danh sach sinh vien ra File ten quanlisinhvien 1.txt "<<endl;
        cout<<"5: sap xep theo diem trung binh tu be den to"<<endl;
        cout<<"4: sap xep sinh vien theo ten "<<endl;
        cout<<"3: tim sinh vien bang ten "<<endl;
        cout<<"2: them sinh vien "<<endl;
        cout<<"1: hien thi sinh vien "<<endl;
        cout<<"0: de thoat chuong trinh "<<endl;
        cout<<"LUU Y! "<<endl;
        cout<<"ho, dem, ten chi ghi 1 chu khong qua 5 tu! "<<endl;
        cout<<"nhap vao so ban chon : ";
        cin>>luachon;

        struct SinhVien sv;
        switch(luachon){
            case 0 :
                break;
            case 1 : 
                HienThiTenCot();
                for(int i = 0; i < slsv ; i++){
                HienThiTTSinhVien(dssv[i]);
                 }
                break;

            case 2: 
                sv = NhapSV();
                dssv[slsv++] = sv; 
                break;
            case 3:
                TimTheoTen(dssv, slsv);
                break;
            case 4:
                SapXepSinhVienTheoTen(dssv, slsv);
                HienThiTenCot();
                for ( int i = 0; i <slsv; i++){
                    HienThiTTSinhVien(dssv[i]);
                }
                break;
            case 5:
                SapXepTheoDiem(dssv, slsv);
                for(int i = 0 ;i < slsv; i++){
                    HienThiTTSinhVien(dssv[i]);
                }
                break;
            case 6: 
                GhiFile(dssv,slsv);
                break;
            case 7:
                XepLoaiDanhSachSinhVien(dssv,slsv);
                break;
            default :
                cout<<"lua chon khong hop le!";
                break;
        }
    }while(luachon);
    return 0;

}
