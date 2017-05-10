#include<iostream.h>
#include<stddef.h>
#include<conio.h>
#include<iomanip.h>
class complex{
	private: float a,b;
	public:
	complex(){
		this->a=0;
		this->b=0;
	}
	complex(float t, float m){
		this->a=t;
		this->b=m;
	}
	~complex(){}
	void nhap(){
		cout<<"+ Nhap phan thuc: "; cin>>a;
		cout<<"+ Nhap phan ao: "; cin>>b;
	}
	void in(){
		cout<<a<<" + "<<b<<"i"<<endl;
	}
	complex tong(complex c1){
		complex c;
		c.a=a+c1.a;
		c.b=b+c1.b;
		return c;
	}
	complex hieu(complex c1){
		complex c;
		c.a=a-c1.a;
		c.b=b-c1.b;
		return c;
	}
	complex tich(complex c1){
		complex c;
		c.a=(a*c1.a)-(b*c1.b);
		c.b=(a*c1.b)-(c1.a*b);
		return c;	
	}
};
int main(){
	complex c1,c2;
	cout<<"+ Nhap so phuc: \n";
	cout<<"  > Nhao so phuc 1: \n"; c1.nhap();
	cout<<"  > Nhao so phuc 2: \n"; c2.nhap();
	cout<<"+ Tong 2 so phuc: \n";
	c1.in(); cout<<" + "; c2.in(); cout<<"= "; c1.tong(c2).in();
	cout<<"+ Hieu 2 so phuc: \n";
	c1.in(); cout<<" - "; c2.in(); cout<<"= "; c1.hieu(c2).in();
	cout<<"+ Tich 2 so phuc: \n";
	c1.in(); cout<<" * "; c2.in(); cout<<"= "; c1.tich(c2).in();
	return 0;
	
}