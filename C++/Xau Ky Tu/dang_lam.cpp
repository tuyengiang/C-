#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<stddef.h>
#include<iomanip.h>
class diem{
	private: int x,y;
  public:
   void nhap(){
   	cout<<"+ Nhap x: "; cin>>x;
   	cout<<"+ Nhap y: "; cin>>y;
   }
   void xuat()
   {
   	cout<<"=> toa do diem la: ( "<<x<<" , "<<y<<" )"<<endl;
   }
};
int main()
{
	diem pt;
	cout<<"Nhap doi tuong diem pt: \n";
	pt.nhap();
	pt.xuat();
	return 0;
}	