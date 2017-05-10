#include<iostream.h>
#include<conio.h>
#include<string.h>
char s[100];int dodai;
void nhap()
{
	cout<<"+ Nhap Xau ky tu: ";
	cin.getline(s,100);
}
int bailam()
{
    cout<<"+ Xau S la: "<<s<<endl;
	dodai=strlen(s);
	cout<<"+ Xau dao nguoc cua S: "<<dodai<<endl;
	return 1;	
}
void xuat()
{
	nhap();
	bailam();
}
int main()
{
	xuat();
}