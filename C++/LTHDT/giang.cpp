#include<iostream.h>
#include<conio.h>
#include<stddef.h>
#include<iomanip.h>
class sinhvien{
	public:
	 char ten[30],lop[10];
	 sinhvien(){
 		strcpy(ten,""); strcpy(lop,"");
 	}
 	sinhvien(char t[30], char l[10]){
	 	strcpy(ten,t); strcpy(lop,l);
	 }
	 ~sinhvien(){}
	 void nhap();
	 void in();
};
void sinhvien::nhap(){
	cin.ignore(1);
	cout<<"  + Nhap Ten: "; cin.getline(ten,30);
	cout<<"  + Nhap Lop: "; cin.getline(lop,10);
}
void sinhvien::in(){
    cout<<ten<<" "<<lop;
}
class nguoi:public sinhvien{
	float toan,ly,hoa,dtb;
	public:
	nguoi(){
		toan=0;ly=0;hoa=0;
	}
	nguoi(float t,float l, float h){
		toan=t;ly=l;hoa=h;
	}
	~nguoi(){}
	friend ostream & operator <<(ostream & os, nguoi b){
	    b.in();
		os<<setw(10)<<b.toan<<setw(10)<<b.ly<<setw(10)<<b.hoa<<setw(10)<<b.dtb<<endl;
		return os;	
	}
	friend istream & operator >>(istream & is,nguoi b){
		b.nhap();
		cout<<"  + Nhap diem toan: "; is>>b.toan;
		cout<<"  + Nhap diem ly: "; is>>b.ly;
		cout<<"  + Nhap diem hoa: "; is>>b.hoa;
		b.dtb=(b.toan+b.ly+b.hoa)/3;
		return is;
	}
    
};
int main(){
	int n;
	nguoi b[100];
	cout<<"+ Nhap so sinh vien can lap ds: "; cin>>n;
	for(int i=0;i<n;i++){
		cout<<" + Sinh vien "<<i+1<<endl;
		cin>>b[i];
	}
	cout<<setw(10)<<"Ten Sv"<<setw(10)<<"Lop Sv"<<setw(10)<<"Diem Toan"
	<<setw(10)<<"Diem Ly"<<setw(10)<<"Diem Hoa"<<setw(10)<<"Diem Tb"<<endl;
	for(int i=0;i<n;i++){
	   cout<<b[i];
	}
	return 0;
}