#include<iostream.h>
#include<math.h>
#include<conio.h>
int main()
{
	int a[201],b[201],m,n;
	int max,min,i,j;
	int c[402],k;
	cout<<"***** Nhap mang a[i] ****** \n";
	cout<<"* Nhap m: "; cin>>m;
	cout<<"----------------------\n";
	cout<<"> Nhap phan tu: \n";
	for(int i=0;i<m;i++)
	{
		cout<<"  > a["<<i<<"]= "; cin>>a[i];
	}
	cout<<"----------------------\n";
	max=a[1];
	min=a[0];
	for(int i=0;i<m;i++)
	{
		if(max<a[i])
		  max=a[i];
        else min=a[i];
	}
	cout<<"=> Max a[i]= "<<max<<endl;
	cout<<"    > Vi tri max= ";
	for(int i=0;i<m;i++)
	{
		if(max==a[i])
		  cout<<i<<endl;
	}
	cout<<"=> Min a[i]= "<<min<<endl;
	cout<<"    > Vi tri min= ";
	for(int i=0;i<m;i++)
	{
		if(min==a[i])
		  cout<<i<<endl<<endl;
	}
	cout<<"***** Nhap mang b[i] ****** \n";
	cout<<"* Nhap n: "; cin>>n;
	cout<<"----------------------\n";
	cout<<"> Nhap phan tu: \n";
	for(int i=0;i<n;i++)
	{
		cout<<"  > b["<<i<<"]= "; cin>>b[i];
	}
	cout<<"----------------------\n";
	max=b[1];
	min=b[0];
	for(int i=0;i<n;i++)
	{
		if(max<b[i])
		  max=b[i];
        else min=b[i];
	}
	cout<<"=> Max b[i]= "<<max<<endl;
	cout<<"    > Vi tri max= ";
	for(int i=0;i<n;i++)
	{
		if(max==b[i])
		  cout<<i<<endl;
	}
	cout<<"=> Min b[i]= "<<min<<endl;
	cout<<"    > Vi tri min= ";
	for(int i=0;i<n;i++)
	{
		if(min==b[i])
		  cout<<i<<endl<<endl;
	}
	cout<<"***** Tron 2 mang ****** \n";
	for(int i=1;i<=m;i++)
	{
		c[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		c[i+n]=b[i];
	}
	k=m+n;
	cout<<"=> Day so da tron: ";
	for(int i=1;i<=k;i++)
	{
		cout<<c[i]<<" ";
	}
	
}