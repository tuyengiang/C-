#include<iostream.h>
#include<conio.h>
#include<string.h>
char s[100],s1;
void nhap()
{
	cout<<"+ Nhap xau S: "; cin.getline(s,100);
}
int bai()
{
	cout<<"=> Xau S: "<<s<<endl;
	char *s1=strtok(s," ");
	cout<<"=> KQ Xau: "<<s1<<endl;	
	return 1;
}
void xuat()
{
	nhap();
	cout<<"--------------------------\n";
	bai();
}
int main()
{
	xuat();
}