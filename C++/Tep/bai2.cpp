#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<algorithm>
#include<fstream.h>
void doctep(int a[],int &n)
{
	ifstream fi("in2.txt",ios::in);
	if(!fi)
	{
		cout<<"Khong co tep duoc mo"<<endl;
		exit(1);
	}
	fi>>n;
	for(int i=1;i<=n;i++)
	{
		fi>>a[i];
	}
	fi.close();
}
void swap(int &x, int &y)
{
	int temp=x;
	x=y;
	y=temp;
}
void blubbesor(int a[],int &n)
{
	for(int i=1;i<=n-1;i++)
	for(int j=n-1;j>i;j--)
	{
		if(a[j]>a[j-1])
		{
			swap(a[j],a[j-1]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
}
void scp(int a[],int n)
{
	int b;
	for(int i=1;i<=n;i++)
	{
		b=sqrt(a[i]);
		if(b*b==a[i])
		   cout<<a[i]<<" ";
	}
}
void timhs(int a[], int &n)
{
	for(int i=1;i<n-1;i++)
	{
		if(a[i]%i==0)
			cout<<a[i]<<" ";
	}
}
void timstc(int a[], int &n)
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]%10==6||a[i]%10==4)
			cout<<a[i]<<" ";
	}
}
void ghitep(int a[],int &n)
{
	ofstream fo("in2.out",ios::out);
	if(!fo){
		cout<<"Khong mo duoc tep"<<endl; exit(1);
	}
	blubbesor(a,n);
	for(int i=1;i<=n;i++)
	{
	   fo<<a[i]<<" ";
	}
	cout<<endl;
	scp(a,n);
	fo.close();
}
main()
{
	int a[51],n;
	doctep(a,n);
	cout<<"+ n= "<<n<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<"=> Sap xep sui bot (blubbe sor)= ";
	   blubbesor(a,n); cout<<endl;
	cout<<"=> So chinh phuong: ";
	   scp(a,n); cout<<endl;
	cout<<"=> Hop so: ";
	   timhs(a,n); cout<<endl;
    cout<<"=> So tan cung 4 & 6: ";
       timstc(a,n); cout<<endl;
    ghitep(a,n);
       
}