#include<iostream.h>
#include<conio.h>
#include<string.h>
char s1[100],s2[100],gan,s3;
void nhap()
{
	cout<<"+ Nhap xau S1: "; cin.getline(s1,100);
	cout<<"+ Nhap xau S2: "; cin.getline(s2,100);
}
int bai()
{
	cout<<"=> Xau S1: "<<s1<<endl;
	cout<<"=> Xau S2: "<<s2<<endl;
	char *gan=strcat(s1,s2);
	cout<<"=> Xau moi: "<<gan<<endl;
	char *s3=strstr(s1,s2);
	cout<<"=> Vi tri Sau cung cua S2: "<<s3<<endl;
	return 1;
	
}

void xuat()
{
	nhap();
	cout<<"--------------------"<<endl;
	bai();
}
int main()
{
	xuat();
}
