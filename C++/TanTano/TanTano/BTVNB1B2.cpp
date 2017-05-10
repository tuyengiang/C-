/*Bai 2 Tran Ngoc Tan
xay dung lop so phuc gom cac thanh phan
dl: phan thuc, phan ao
pt: nhap, in, tinh sqrt(p*sqr(t)+p*sqr(a)... 
nhan chia hai so phuc
ham main:
nhap 2 so phuc
tinh va in tong hieu hai so phuc
in mang sau khi xep
*/


#include<iostream.h>
#include<math.h>

class sophuc
{
	private:
	float thuc;
	float ao;
	public:
    void nhap();
	void in();
	void inphuc();
	float tinh();
	sophuc(int t=0, int m=0)
	{
		this->thuc=t;
		this->ao=m;
	}
	~sophuc()
	{}
	
	
	sophuc tong(sophuc a);
	sophuc hieu(sophuc b);	
	sophuc tich(sophuc c);
	sophuc thuong(sophuc d);
	sophuc operator+(sophuc t)
	{
	sophuc c;
	c.thuc=thuc+t.thuc;
	c.ao=ao+t.ao;
	return c;		
	}
	sophuc operator-(sophuc t);
	sophuc operator*(sophuc t);
	sophuc operator/(sophuc t);
	friend ostream& operator<<(ostream &os, const sophuc& sp)
	{
		os<< sp.thuc<<" + "<<sp.ao<<"i";
		return os;
	}
	
	friend istream& operator>>(istream& is,sophuc& sp);
	
};

istream& operator>>(istream& is,sophuc& sp)
{
	cout<<"Tu so:";
	is>>sp.thuc;
	cout<<"Mau so:";
	is>>sp.ao;
	return is;
}
void sophuc::nhap()
{
	cout<<"\nThuc="; cin>>thuc;
	cout<<"Ao="; cin>>ao;
}

void sophuc::in()
{
	cout<<thuc<<"+"<<ao<<"i";
}

float sophuc::tinh()
{
	return (sqrt(pow(thuc, 2)+pow(ao,2)));
}

sophuc sophuc::tong(sophuc a)
{
	sophuc c;
	c.thuc=thuc+a.thuc;
	c.ao=ao+a.ao;
	return c;
}
sophuc sophuc::operator-(sophuc t)
{
	sophuc c;
	c.thuc=thuc-t.thuc;
	c.ao=ao-t.ao;
	return c;		
}

sophuc sophuc::operator*(sophuc t)
{
	sophuc c;
	c.thuc=(thuc*t.thuc)-(ao*t.ao);
	c.ao=(thuc*t.ao)+(t.thuc*ao);
	return c;	
}

sophuc sophuc::operator/(sophuc t)
{
	sophuc n;
	n.thuc=(thuc*t.thuc+ao*t.ao)/( t.thuc*t.thuc+t.ao*t.ao);
	n.ao=(t.thuc*ao-thuc*t.ao)/(t.thuc*t.thuc+t.ao*t.ao);	
	return n;		
}

sophuc sophuc::hieu(sophuc a)
{
	sophuc c;
	c.thuc=thuc-a.thuc;
	c.ao=ao-a.ao;
	return c;
}

sophuc sophuc::tich(sophuc a)
{
	sophuc c;
	c.thuc=(thuc*a.thuc)-(ao*a.ao);
	c.ao=(thuc*a.ao)+(a.thuc*ao);
	return c;
}

sophuc sophuc::thuong(sophuc d)
{
	sophuc t;
	t.thuc=(thuc*d.thuc+ao*d.ao)/( d.thuc*d.thuc+d.ao*d.ao);
	t.ao=(d.thuc*ao-thuc*d.ao)/(d.thuc*d.thuc+d.ao*d.ao);	
	return t;	
}

void main()
{
	sophuc t,a, n;
	cout<<"\nNhap so phuc la:";
	cout<<"\nSo phuc 1:"<<endl;
	cin>>t;
	cout<<"\nSo phuc 2 la:";
	a.nhap();
	cout<<"\nSo phuc vua nhap la:";
	cout<<"\nSo phuc 1:"<<t;
	cout<<"\nSo phuc 2:";
	a.in();
	cout<<"\nTich la:"<<t.tinh();
	cout<<"\nTong hai so phuc la:";
	n=t+a;;
	n.in();
	cout<<"\nHieu hai so phuc la:";
	n=t.hieu(a);
	n.in();
	cout<<"\nTich hai so phuc la:";
	n=t*a;
	n.in();
	cout<<"\nThuong hai so phuc la:";
	n=t.thuong(a);
	n.in();
	
}
