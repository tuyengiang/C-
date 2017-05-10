// xay dung lo phan to co tu so va mau do. xay dung ct nhap va in du lieu. khai bao hai doi tuong p1,p2 thuoc
// lop phan so
#include<iostream.h>
#include<iomanip.h>
#include<stddef.h>
#include<conio.h>
#include<math.h>
class phanso{
	private:
     	int x,y;
	public:	
	void nhap()
	{
		cout<<"+ Nhap phan so: \n";
		cout<<"   > Nhap tu so: "; cin>>x;
		cout<<"   > Nhap mau so: "; cin>>y;
	}
	void indl()
	{
		cout<<"+ Hai phan so da nhap: \n";
		cout<<"=> Phan so= "<<x<<"/"<<y<<endl;
	}
	float giatri()
	{
		return float(x)/y;
	}
};
int main()
{
	phanso p1,p2;
	cout<<"--- Nhap phan so ---"<<endl;
	p1.nhap();
	p2.nhap();
	if(p1.giatri()>p2.giatri())
	    p1.indl();
    else
	    p2.indl();
	return 0;
	
}