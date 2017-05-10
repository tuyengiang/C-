//Tran Ngoc Tan
//Bai 3. Xay dung lop vecto gom cac thanhphan
//-DL: So phan tu, mang cac phan tu
//-PT: Nhap, in, tong 2 vecto, tich vo huong
//Ham main
//-Nhap 2 vecto
//-Tinh va in tong a+b

#include<iostream.h>
#include<conio.h>

class vecto
{
	int x, y, n;
	vecto *t;
	public:
	vecto(int hoanh=0, int tung=0)
	{
		this->x=hoanh;
		this->y=tung;
	}
	~vecto(){}
	void nhap();
	void in();
	vecto tong(vecto a);
	float tich(vecto b);
};



void vecto::nhap()
{
	cout<<"\nNhap vecto:"<<endl;
	cout<<"x=";
	cin>>x;
	cout<<"y=";
	cin>>y;
}

void vecto::in()
{
	cout<<"(x,y)=("<<x<<","<<y<<")";
}

vecto vecto::tong(vecto a)
{
	vecto b;
	b.x=x+a.x;
	b.y=y+a.y;
	return b;
}

float vecto::tich(vecto a)
{
	return (x*a.x+y*a.y);
}

void main()
{
	vecto t,a,n;
	cout<<"Nhap vecto 1 la:";
	t.nhap();
	cout<<"Nhap vecto 2 la:";
	a.nhap();
	n=t.tong(a);
	cout<<"Tong hai vec to la:";
	n.in();
	cout<<"\nTich vo huong hai vecto la:"<<t.tich(a);
	cout<<endl;
}
