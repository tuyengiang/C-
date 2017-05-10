/*
Xay dung class diem bao gom thuoc tinh x,y. xay dung phuong thuc nhap,indl cho lop diem
xay lop doan thang ke thua tu lop diem,thuoc tinh x1,y1. xay dung phuong thuc tinh khoang cach
tai dinh nghia ton tu nhap xuat(in ra do dai daon thang) cho lop doan thang.
kai pao doi tuong p thuoc lop doan thang. nhap in dl cho lop doi tuong p tren.*/

#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<stddef.h>
class diem{
	public: float x,y;
};
class doanthang:public diem{
	diem x1,y1;
	public:
	doanthang(){
		this->x1.x=0;
		this->x1.y=0;
		this->y1.x=0;
		this->y1.y=0;
	}
	doanthang(float a,float b){
		this->x1.x=a;
		this->x1.y=b;
		this->y1.x=a;
		this->y1.y=b;
	}
	~doanthang(){ }
	friend istream & operator>>(istream &is,doanthang &p){
		cout<<"    + Nhap X1x: "; is>>p.x1.x;
		cout<<"    + Nhap X1y: "; is>>p.x1.y;
		cout<<"    + Nhap Y1x: "; is>>p.y1.x;
		cout<<"    + Nhap Y1y: "; is>>p.y1.y;
		return is;
	}
	friend ostream & operator <<(ostream &os, doanthang &p){
		os<<"=> Do dai cac doan: "<<p.x1.x<<"  "<<p.x1.y<<"  "<<p.y1.x<<"  "<<p.y1.y<<"\n";
		os<<"=> Khoang cach: "
		<<sqrt((p.x1.x-p.y1.x)*(p.x1.x-p.y1.x))+sqrt((p.x1.y-p.y1.y)*(p.x1.y-p.y1.y))<<"\n";
		return os;
	}
};
int main(){
	doanthang p,q;
	cout<<"+ Nhap du lieu: \n";
    cin>>p;
    cout<<"+ Du lieu ban vua nhap: \n";
    cout<<p;
    return 0;
	
}