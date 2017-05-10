#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<iomanip.h>
#include<stddef.h>
class ngaysinh{
	public: int ngay,thang,nam;
	ngaysinh(){
		this->ngay=0;
		this->thang=0;
		this->nam=0;
	}
	ngaysinh(int a,int b,int c){
		this->ngay=a;
		this->thang=b;
		this->nam=c;
	}
	~ngaysinh(){}
	void nhap();
	void in();
};
void ngaysinh::nhap(){
	cout<<"  > Nhap ngay sinh: "; cin>>ngay;
	cout<<"  > Nhap thang sinh: "; cin>>thang;
	cout<<"  > Nhap nam sinh: "; cin>>nam;
}
void ngaysinh::in(){
	cout<<setw(15)<<"    Birthday: "<<ngay<<" / "<<thang<<" / "<<nam<<endl;
}
class sinhvien:public ngaysinh{
	public:
	  char hoten[30],que[100];
    sinhvien(){
  		strcpy(hoten,""); strcpy(que,"");
  	}
  	sinhvien(char ht[30], char q[100]){
	  	strcpy(hoten,ht); strcpy(que,q);
	  }
	  ~sinhvien(){}
    friend ostream & operator <<(ostream & os, sinhvien &sv){
  		cout<<setw(15)<<"Ho Ten"<<setw(15)<<"Que Quan"<<endl;
  		cout<<setw(15)<<sv.hoten<<setw(15)<<sv.que<<endl;
  		return os;
  	}
  	friend istream & operator >>(istream & is, sinhvien &sv){
	  	cout<<"  > Nhap Ten: "; is.getline(sv.hoten,30);
	  	cout<<"  > Nhap Que: "; is.getline(sv.que,100);
	  	return is;
	  }
	  void nhap();
	  void in();
	  float kiemtra();
};
void sinhvien::nhap(){
	ngaysinh::nhap();
}
void sinhvien::in(){
	ngaysinh::in();
}
float sinhvien::kiemtra(){
	cout<<2017-nam;
}
int main(){
	sinhvien s;
	cout<<"+ Nhap thong tin: \n";
	  cin>>s;
	  s.nhap();
    cout<<"\n+ Thong tin: \n";
      cout<<s;
      s.in();
    cout<<"\n+ Tuoi cua ban: "; s.kiemtra();
    cout<<endl;
    return 0;
}