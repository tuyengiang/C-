#include<iostream.h>
#include<iomanip.h>
#include<windows.h>
#include<math.h>
#include<conio.h>
#include<algorithm>
struct sinhvien{
	char hoten[50],quequan[50],ngaysinh[20];
	float toan,ly,hoa,dtb;
};
void nhap (sinhvien *sv,int n)
{
	for(int i=1;i<=n;i++)
	{
		cout<<i<<". Sinh vien "<<i<<endl;
		cin.ignore(1);
		cout<<"   > Ho Ten: "; cin.getline(sv[i].hoten,50);
		cout<<"   > Que Quan: "; cin.getline(sv[i].quequan,50);
		cout<<"   > Ngay Sinh: "; cin.getline(sv[i].ngaysinh,20);
		do{
		   cout<<"   > Diem Toan: "; cin>>sv[i].toan;
		}while(sv[i].toan<0 && sv[i].toan>10);
		do{
		   cout<<"   > Diem Ly: "; cin>>sv[i].ly;
		}while(sv[i].ly<0 && sv[i].ly>10);
		do{
		   cout<<"   > Diem Hoa: "; cin>>sv[i].hoa;
		}while(sv[i].hoa<0 && sv[i].hoa>10);
		sv[i].dtb=(sv[i].toan+sv[i].ly+sv[i].hoa)/3;		
	}
}
void xuat1(sinhvien sv)
{
	cout<<setw(10)<<sv.hoten<<setw(15)<<sv.quequan<<setw(15)<<sv.ngaysinh<<setw(10)<<sv.toan<<setw(10)
	<<sv.ly<<setw(10)<<sv.hoa<<setw(10)<<sv.dtb<<"\n";
}
void xuat(sinhvien *sv,int n)
{
	cout<<setw(10)<<"Ho Ten"<<setw(15)<<"Que Quan"<<setw(15)<<"Ngay Sinh"<<setw(10)<<"Diem Toan"
	<<setw(10)<<"Diem Ly"<<setw(10)<<"Diem Hoa"<<setw(10)<<"Diem Tb"<<endl;
	for(int i=1;i<=n;i++)
	{
		xuat1(sv[i]);
	}
}
void kiemtra(sinhvien *sv,int n)
{
	cout<<setw(10)<<"Ho Ten"<<setw(15)<<"Que Quan"<<setw(15)<<"Ngay Sinh"<<setw(10)<<"Diem Toan"
	<<setw(10)<<"Diem Ly"<<setw(10)<<"Diem Hoa"<<setw(10)<<"Diem Tb"<<endl;
	for(int i=1;i<=n;i++)
	{
		if(sv[i].dtb>=8 && sv[i].toan>5 && sv[i].ly>5 && sv[i].hoa>5)
		  xuat1(sv[i]);
	}
}
void sapxep(sinhvien *sv,int n)
{
	sinhvien tg;
  for(int i=1;i<=n-1;i++)
  for(int j=i+1;j<=n;j++)
  if(strcmp(sv[i].hoten,sv[j].hoten)>0)
  {
  	sv[i]=tg;
  	sv[i]=sv[j];
  	tg=sv[j];
  }	
  cout<<setw(10)<<"Ho Ten"<<setw(15)<<"Que Quan"<<setw(15)<<"Ngay Sinh"<<setw(10)<<"Diem Toan"
	<<setw(10)<<"Diem Ly"<<setw(10)<<"Diem Hoa"<<setw(10)<<"Diem Tb"<<endl;
  for(int i=1;i<=n;i++)
  {
  	xuat1(sv[i]);
  }
  
}
/*
void tinh(sinhvien *sv, int n)
{
	int a=0;
	for(int i=1;i<=n;i++)
	{
		if()
	}
}*/
main()
{
	int n;
	do{
		cout<<"+ Nhap so sv can lap Ds: "; cin>>n;
	}while(n<=0);
	struct sinhvien *sv;
	sv=new sinhvien[1000];
	cout<<"\t\t ----- Nhap TT Sv:\ -----\n";
	  nhap(sv,n);
    cout<<"\t\t ----- Ds Sinh Vien ----- \n";
      xuat(sv,n);
    cout<<"\t\t ----- Ds Sv DTB>8 Va Cac Mon >5 ----- \t\t\n";
      kiemtra(sv,n);
    cout<<"\t\t ----- Sap Xep Theo Bang Chu Cai ----- \t\t\n";
      sapxep(sv,n);
}