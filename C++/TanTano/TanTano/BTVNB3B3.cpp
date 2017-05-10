#include<iostream.h>
template <class T>
T Min(T a, T b, T c)
{
	T tg=(a>b)?b:a;
	return (tg>c)?c:tg;
}

template <class T>
void nhap(T &a, T &b, T &c)
{
	cout<<"Nhap so thu nhat:";
	cin>>a;
	cout<<"Nhap so thu hai:";
	cin>>b;
	cout<<"Nhap so thu ba:";
	cin>>c;
}

template<class T>
void in(T a, T b, T c)
{
	cout<<"A="<<a<<endl;
	cout<<"B="<<b<<endl;
	cout<<"C="<<c<<endl;
}

void main()
{
	int a, b, c;
	float d, e, f;
	cout<<"Nhap 3 so nguyen"<<endl;
	nhap(a,b,c);
	cout<<"\n3 so vua nguyen la:"<<endl;
	in(a,b,c);
	cout<<"Nhap 3 so thuc"<<endl;
	nhap(d,e,f);
	cout<<"\n3 so thuc vua nhap la:"<<endl;
	in(d,e,f);
	cout<<"\nMin 3 so nguyen la:"<<Min(a,b,c);
	cout<<"\nMin 3 so thuc la:"<<Min(d,e,f);	
}
