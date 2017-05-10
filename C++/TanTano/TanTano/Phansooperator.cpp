#include<iostream.h>
#include<conio.h>

class phanso
{
	int tu, mau;
	public:
	void nhap();
	void in();
	void khoitao(int t=0, int m=1)
	{
		this->tu=t;
		this->mau=m;
	}
	~phanso()
	{
	}
	phanso toigian();
	phanso cong(phanso a);
	phanso tru(phanso a);
	phanso nhan(phanso a);
	phanso chia(phanso a);
	phanso operator+(phanso a);
	phanso operator-(phanso a);
	phanso operator*(phanso a);
	phanso operator/(phanso a);

friend ostream & operator<<(ostream & os, phanso t)
{
	os<<t.tu<<"/"<<t.mau; 
	return os;
}
friend	istream & operator>>(istream & is, phanso &t)
{
		cout<<"\nNhap phan so:";
	is>>t.tu>>t.mau;
	return is;
}
	
};
phanso phanso::operator+(phanso a)
{
	phanso b;
	b.tu=tu*a.mau+a.tu*mau;
	b.mau=tu*mau;
	return b;
}

phanso phanso::operator-(phanso a)
{
	phanso b;
	b.tu=tu*a.mau-a.tu*mau;
	b.mau=tu*mau;
	return b;
}

phanso  phanso::operator*(phanso a)
{
	phanso b;
	b.tu=tu*a.tu;
	b.mau=mau*a.mau;
	return b;
	
}

phanso phanso::operator/(phanso a)
{
	phanso b;
	b.tu=tu*a.mau;
	b.mau=mau*a.tu;
	return b;
}


//Cach dung toan tu....phanso p,qu,v; u=operator+(p,q)....Hoac =p+q...



void phanso::nhap()
{
	
	cout<<"\nTu="; cin>>tu;
	cout<<"Mau="; cin>>mau;
}
	
int ucln(int tu, int mau)
	{
		while (tu!=mau)
		{
			if (tu>mau)
			tu-=mau;
			else mau-=tu;
		}
		return tu;
	}
void phanso::in()
{
	cout<<tu<<"/"<<mau;	
}

phanso phanso::toigian()
{
	int i=ucln(tu,mau);
tu=tu/i;
mau=mau/i;
}

phanso phanso::cong(phanso a)
{
	phanso b;
	b.tu=tu*a.mau+a.tu*mau;
	b.mau=mau*a.mau;
	return b;
}

phanso phanso::tru(phanso a)
{
	phanso b;
	b.tu=tu*a.mau-a.tu*mau;
	b.mau=mau*a.mau;
	return b;
}

phanso phanso::nhan(phanso a)
{
	phanso b;
	b.tu=tu*a.tu;
	b.mau=mau*a.mau;
	return b;
}

phanso phanso::chia(phanso a)
{
	phanso b;
	b.tu=tu*a.mau;
	b.mau=mau*a.tu;
	return b;
}



void main()
{
	phanso t, a, n, i, k, m, l;
	cout<<"\nNhap phan so thu nhat la:";
	cin>>t;
//	t.nhap();
	cout<<"\nNhap phan so thu hai la:";
	//cin>>a;
	a.nhap();
	cout<<"\nPhan so vua nhap la:";
	cout<<"\nPhan so thu nhat:";
	t.in();
	cout<<"\nPhan so thu hai:";
	a.in();
	cout<<"\nPhan so sau khi toi gian:";
	cout<<"\nPhan so 1:";
	t.toigian();
	t.in();
	cout<<"\nPhan so 2:";
	a.toigian();
	a.in();
	cout<<"\nTong hai phan so la:";
	//i=t.cong(a);
	i=t+a;
	i.toigian();
	i.in();
	cout<<"\nHieu hai phan so la:";
	k=t.tru(a);
	k.toigian();
	k.in();
	cout<<"\nTich hai phan so la:";
	//m=t.nhan(a);
	l=t*a;
	m.toigian();
	m.in();
	cout<<"\nThuong hai phan so la:";
	l=t.chia(a);
	l.toigian();
	l.in();	

}

