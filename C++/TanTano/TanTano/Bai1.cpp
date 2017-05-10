#include<iostream.h>
#include<conio.h>

class phanso
{
	int tu, mau;
	public:
	void nhap();
	void in();
	phanso (int t=0, int m=1)
	{
		this->tu=t;
		this->mau=m;
	}
	
	~phanso()
	{
	}
	
	int sosanh(phanso a);	
	phanso toigian();
	phanso cong(phanso a);
	phanso tru(phanso a);
	phanso nhan(phanso a);
	phanso chia(phanso a);
	
	friend ostream& operator<<(ostream &os, const phanso &ps)
	{
		if(ps.tu==0)
  			os<<"\n0 "<<endl;
   		else
  			if(ps.tu==ps.mau)
   				os<<"\n1"<<endl;
			else
  				os<<ps.tu<<"/"<<ps.mau<<endl;
  		return os;
	}
	
	friend istream& operator>>(istream &is, phanso &ps);
	phanso operator+(phanso a);
	phanso operator-(phanso a);
	phanso operator*(phanso a);
	phanso operator/(phanso a);
};

class dayso
{
	int n;
	phanso *t;
	public:
	void nhapds();
	void inds();
	void sapxep();
};
void dayso::nhapds()
{
	cout<<"\nNhap so cac phan so la:";
	cin>>n;
	t=new phanso[n+1];
	for (int i=1; i<=n; i++)
	t[i].nhap();
}

int phanso::sosanh(phanso a)
{
	int t=(tu*a.mau)-(mau*a.tu);
	if (t<0) return 0;
	if (t>0) return 1;
	if (t==0) return 2;
}

void dayso::inds()
{
	cout<<"\nDay so vua nhap la:"<<endl;
	for (int i=1; i<=n; i++)
	{
	t[i].in();
	cout<<endl;
	}
}

void swap(phanso &a, phanso &b)
{
	phanso tg=a;
	a=b; 
	b=tg;
}

void dayso::sapxep()
{

	for (int i=1; i<n; i++)
	for (int j=i+1; j<=n; j++)
	if (t[i].sosanh(t[j])==1)
	swap(t[i],t[j]);
}

phanso phanso::operator+(phanso a)
{
	phanso c;
	c.tu=tu*a.mau+a.tu*mau;
	c.mau=tu*mau;
	return c;	
}

phanso phanso::operator-(phanso a)
{
	phanso c;
	c.tu=tu*a.mau-a.tu*mau;
	c.mau=tu*mau;
	return c;	
}


phanso phanso::operator*(phanso a)
{
	phanso c;
	c.tu=tu*a.tu;
	c.mau=mau*a.mau;
	return c;
}

phanso phanso::operator/(phanso a)
{
	phanso c;
	c.tu=tu*a.mau;
	c.mau=mau*a.tu;
	return c;
}


istream &operator>>(istream &is, phanso &ps)
{
	cout<<"Tu so:";
	is>>ps.tu;
	do 
	{
		cout<<"Mau so:";
		is>>ps.mau;
	}while(ps.mau==0);
	if(ps.mau<0) //doi dau
  	{
   		ps.tu=-ps.tu;
   		ps.mau=-ps.mau;
	}
	return is;
}


void phanso::nhap()
{
	
	cout<<"\nTu="; cin>>tu;
	do
	{
		cout<<"Mau="; cin>>mau;
	}
	while(mau==0);
	if(mau<0) //doi dau
  	{
 		tu=-tu;
   		mau=-mau;
  	}
}
	
int ucln(int tu, int mau)
	{
		 tu=abs(tu); 
         mau=abs(mau);
		while (tu!=mau)
		{
			if (tu>mau)
			tu-=mau;
			else mau-=tu;
		}
		return tu;
	}

phanso phanso::toigian()
{
	if(mau<0)
	{
		tu=-tu;
		mau=-mau;
	}
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
	b.toigian();
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

void phanso::in()
{
	cout<<tu<<"/"<<mau;	
}

void main()
{
	phanso t, a, n, i, k, m, l;
	dayso z;
	cout<<"\nNhap phan so thu nhat la:";
	t.nhap();
	cout<<"\nNhap phan so thu hai la:"<<endl;
	cin>>a;
	cout<<"\nPhan so vua nhap la:";
	cout<<"\nPhan so thu nhat:";
	t.in();
	cout<<"\nPhan so thu hai:"<<a;
	cout<<"\nPhan so sau khi toi gian:";
	cout<<"\nPhan so 1:";
	t.toigian();
	t.in();
	cout<<"\nPhan so 2:";
	a.toigian();
	a.in();
	cout<<"\nTong hai phan so la:";
	i=t+a;
	i.toigian();
	i.in();
	cout<<"\nHieu hai phan so la:";
	k=t.tru(a);
	k.toigian();
	k.in();
	cout<<"\nTich hai phan so la:";
	m=t.nhan(a);
	m.toigian();
	m.in();
	cout<<"\nThuong hai phan so la:";
	l=t.chia(a);
	l.toigian();
	l.in();	
	if (t.sosanh(a)==0)
	cout<<"\nSo 1 nho hon";
	if (t.sosanh(a)==1)
	cout<<"\nSo 2 nho hon";
	if (t.sosanh(a)==2)
	cout<<"\nHai so bang nhau!";
	cout<<endl;
	cout<<"-------------------------------";
	z.nhapds();
	z.inds();
	cout<<"Day so sau khi sap xep la:";
	z.sapxep();
	z.inds();

}

