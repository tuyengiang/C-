#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<stddef.h>
class diem{
	public: int x,y;
	diem(){
		this->x=0;
		this->y=0;
	}
	diem(int a,int b){
	  this->x=a;
	  this->y=b;
	}
	~diem(){}
	void nhap();
	void in();
}
void diem::nhap(){
	cout<<"+ Nhap x: "; cin>>x;
	cout<<"+ Nhap y: "; cin>>y;
}
void diem::in(){
	cout<<"\t X= "<<x<<"\t Y= "<<y<<endl;
}
class doanthang:public diem{
	private: int x1,y1;
	public:
	doanthang():diem(){
		this->x1=0;
		this->y1=0;
	}
	doanthang(int x,int y,int x1,int y1):diem(x,y){
		this->x1=x1;
		this->y1=y1;
	}
	~doanthang(){	}
	friend istream & operator>>(istream &is,doanthang &p){
		diem::nhap();
		cout<<"+ Nhap x1: "; is>>p.x1;
		cout<<"+ Nhap y1: "; is>>p.y1;
		return is;
	}
	friend ostream & operator <<(ostream &os, doanthang &p){
		diem::in();
		os<<"=> Do dai cac doan: "<<p.x1"  "<<p.x1<<endl;
		os<<"=> Khoang cach: "
		<<sqrt((p.x1.x-p.y1.x)*(p.x1.x-p.y1.x))+sqrt((p.x1.y-p.y1.y)*(p.x1.y-p.y1.y))<<"\n";
		return os;
	}
	
}