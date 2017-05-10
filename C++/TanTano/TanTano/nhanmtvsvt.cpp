#include<iostream.h>
#include<conio.h>
#include<math.h>

class VT;
class MT;
class VT
{
	private:
	int n;
	double x[20];
	public:
	void nhapsl();
	friend void in(const VT &x);
	friend VT tich(const MT &a,const VT &x);
	
};
class MT
{
	private:
	int n;
	double a[20][20];
	public:
	friend VT tich(const MT &a,const VT &x);
	friend void in(const MT &a);
	void nhapsl();
	
};

void VT::nhapsl()
{
	cout<<"\nNhap vecto:";
	cin>>n;
	for (int i=1; i<=n; i++)
	{
		cout<<"\nPhan tu thu"<<i<<"=";
		cin>>x[i];
	}
}

void MT::nhapsl()
{
	cout<<"\nNhap ma tran:";
	cin>>n;
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++)
	{
		cout<<"A["<<i<<","<<j<<"]";
		cin>>a[i][j];
	}
}


VT tich(const MT &a,const VT &x)
{
	VT y;
	int n=a.n;
	if(n!=x.n)
	return x;
	y.n=n;
	for (int i=1; i<=n; i++)
	{
		y.x[i]=0;
		for (int j=1; j<=n; j++)
		y.x[i]=a.a[i][j]*x.x[j];
				
	}
	return y;
}

void in(const VT &x)
{
	for(int i=1; i<=x.n; i++)
	cout<<x.x[i]<<"  ";
	
}

void in(const MT &a)
{
	for (int i=1; i<=a.n; i++)
	{
		cout<<"\n";
		for(int j=1; j<=a.n; j++)
		cout<<a.a[i][j]<<"   ";
	}
}

void main()
{
	MT a;
	VT x, y, t;
	a.nhapsl();
	x.nhapsl();
	y=tich(a,x);
	cout<<"\nNhap Ma tran A:";
	in(a);
	cout<<"\nVecto x:";
	in(x);
	cout<<"\nVecto y=Ax:";
	in(y);
    t=tich(a,x);
	
}
