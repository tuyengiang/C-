#include<iostream.h>
#include<math.h>
#include<stddef.h>
#include<conio.h>
#include<iomanip.h>
class sinhvien{
	public:
	  char ten[30],que[30];
    sinhvien(){
  		strcpy(ten,""); strcpy(que,"");
  	}
  	sinhvien(char t[30],char q[30]){
	  	strcpy(ten,t); strcpy(que,q);
	  }
    ~sinhvien(){ }
    void nhap();
    void xuat();
};
void sinhvien::nhap(){
	cout<<"  > Nhap ten: "; cin.getline(ten,30);
	cout<<"  > Nhap que: "; cin.getline(que,30);
}
void sinhvien::xuat(){
	cout<<setw(15)<<"Ho Ten"<<setw(15)<<"Que Quan"<<endl;
	cout<<setw(15)<<ten<<setw(15)<<que<<endl;
}
class diem:sinhvien{
	public: int toan,ly,hoa;
	diem(){
		this->toan=0;
		this->ly=0;
		this->hoa=0;
	}
	diem(int t,int l,int h){
		this->toan=t;
		this->ly=l;
		this->hoa=h;
	}
	~ diem(){}
	friend ostream & operator <<(ostream & os, diem & d){
		os<<setw(15)<<"Diem Toan"<<setw(15)<<"Diem Ly"<<setw(15)<<"Diem Hoa"<<endl;
		os<<setw(15)<<d.toan<<setw(15)<<d.ly<<setw(15)<<d.hoa<<endl;
		return os;
	}
	friend istream & operator >>(istream & is, diem & d){
		cout<<"  > Nhap toan: "; is>>d.toan;
		cout<<"  > Nhap ly: "; is>>d.ly;
		cout<<"  > Nhap hoa: "; is>>d.hoa;
		return is;
	}
	void nhap();
	void xuat();
};
void diem::nhap(){
	sinhvien::nhap();
}
void diem::xuat(){
	int tb=0;
	sinhvien::xuat();
	tb=(toan+hoa+ly)/3;
	cout<<"  => Diem tb= "<<tb<<endl;
}
int main(){
	diem d;
	cout<<"+ Nhap thong tin cho sinh vien: \n";
      d.nhap();
	  cin>>d;
    cout<<"\t\t -------- TT sinh vien vua nhap -------- \t\t\n";
      d.xuat();
      cout<<d;
      
}