#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<stddef.h>
#include<iomanip.h>
class diem{
	private: float x,y;
	public:
	   void nhap(){
   		cout<<"  > Nhap x: "; cin>>x;
   		cout<<"  > Nhap y: "; cin>>y;
   	}
   	void xuat(){
	   	cout<<"=> Diem ban vua nhap: "<<"\tX= "<<x<<"\tY= "<<y<<endl;
	   }
};
class tamgiac{
	private: float a,b,c;
	public:
	   void nhap(){
   		cout<<"  > Nhap a: "; cin>>a;
   		cout<<"  > Nhap b: "; cin>>b;
   		cout<<"  > Nhap c: "; cin>>c;	
   	}
   	void xuat(){
	   	cout<<"=> 3 canh tam giac: "<<"\tA= "<<a<<"\tB= "<<b<<"\tC= "<<c<<endl;
	   }
    void kiemtra()
    {
    	if(a+b>c && a+c>b && b+c>a)
    	{
	    	cout<<"=> 3 canh vua nhap tao thanh 1 tam giac \n";
	    }
	    else{
    		cout<<"=> 3 canh vua nhap khong tao thanh 1 tam giac \n";
    	}
    }
};
int main(){
	diem d; tamgiac tg;
	cout<<"+ Nhap diem: \n";
	   d.nhap();
       d.xuat();
    cout<<endl;
    cout<<"+ Nhap 3 canh tam giac: \n";
       tg.nhap();
       tg.xuat();
       tg.kiemtra();
    return 0;
}