#include<iostream.h>
#include<string.h>

template <class T>
void swap(T &a, T & b)
{
	T tg=a;
	a=b;
	b=tg;
}

template <class T>
void sort(T *a, int n)
{
	for (int i=0; i<n-1; i++)
		for (int j=i+1; j<n; j++)
			if (a[i]>a[j])
				swap(a[i],a[j]);
}

template <class T>
void nhap(T *a, int &n)
{
	cout<<"Nhap so phan tu cua day la:";
	cin>>n;
	for (int i=0; i<n; i++)
	{
		cout<<"Phan tu thu"<<i<<" =:";
		cin>>a[i];
	}
}

template <class T>
void in(T *a, int n)
{
	for (int i=0; i<n; i++)
		cout<<a[i]<<"  ";	
}

void main()
{
	double a[100];
	char b[100];
	int n;
	int m;
	cout<<"Nhap mang thuc la:"<<endl;
	nhap(a,n);
	cout<<"Day vua nhap la:"<<endl;
	in(a,n);
	cout<<"Nhap mang ki tu la:"<<endl;
	nhap(b,m);
	cout<<"Day ki tu vua nhap la:"<<endl;
	in(b,m);
	cout<<"\nMang so thuc sau khi sap xep la:"<<endl;
	sort(a,n);
	in(a,n);
	cout<<"\nMang ki tu sua khi sap xep la:"<<endl;
	sort(b,m);
	in(b,m);
}


