#include<iostream.h>
#include<conio.h>
#include<string.h>
char s[100],s1;
void nhap()
{
	cout<<"+ Nhap Xau ky tu: ";
	cin.getline(s,100);
}
int bai()
{
    cout<<"+ Xau S la: "<<s<<endl;
	char *s1=strrev(s);
	cout<<"+ Xau dao nguoc cua S: "<<s1<<endl;
	return 1;	
}
void xuat()
{
	nhap();
	bai();
}
int main()
{
	xuat();
}