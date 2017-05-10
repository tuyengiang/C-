#include<iostream.h>
#include<conio.h>
#include<string.h>
char s[100],k; int dem,kt=0;
void nhap()
{
	cout<<"+ Nhap Xau ky tu: ";
	cin.getline(s,100);
}
int bai()
{
    cout<<"+ Xau S la: "<<s<<endl;
	int dem=strlen(s);
	for(int i=0;i<dem;i++)
	{
		if(s[i]=='k')
		kt=kt+1;
	}
	cout<<"+ Ky tu k trong S: "<<kt<<endl;
	return 1;	
}
void xuat()
{
	nhap();
	cout<<"---------------------"<<endl;
	bai();
}
int main()
{
	xuat();
}