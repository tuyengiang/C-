#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<iomanip.h>
struct sinhvien{
	char ma[15],ho[15],ten[15],nt[20];
};
struct diemso{
	float toan,tin,ta,ktlt,dtb,tong;
	int ttoan,ttin,tta,tktlt;
};
void nhap(sinhvien *sv,diemso *ds,int n){
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<". Sinh vien thu "<<i+1<<endl;
		cin.ignore(1);
		cout<<"   > Ma Sv: "; cin.getline(sv[i].ma,15);
		cout<<"   > Ho Sv: "; cin.getline(sv[i].ho,15);
		cout<<"   > Ten Sv: "; cin.getline(sv[i].ten,15);
		cout<<"   > Ngay Sinh: "; cin.getline(sv[i].nt,15);
		cout<<"   + Nhap Diem Va tin chi mon hoc: \n";
		cout<<"     > Diem Toan: "; cin>>ds[i].toan;
	    cout<<"        + Tin chi: "; cin>>ds[i].ttoan;
	    cout<<"     > Diem Tin co so: "; cin>>ds[i].tin;
        cout<<"        + Tin chi: "; cin>>ds[i].ttin;
       	cout<<"     > Diem T.A: "; cin>>ds[i].ta;
	    cout<<"        + Tin chi: "; cin>>ds[i].tta;
    	cout<<"     > Diem KTLT: "; cin>>ds[i].ktlt;
	    cout<<"        + Tin chi: "; cin>>ds[i].tktlt;
	    ds[i].tong=ds[i].ttoan+ds[i].ttin+ds[i].tta+ds[i].tktlt;
	    ds[i].dtb=((ds[i].toan*ds[i].ttoan)+(ds[i].tin*ds[i].ttin)+(ds[i].ta*ds[i].tta)
        +(ds[i].ktlt*ds[i].tktlt))/ds[i].tong;
	}
}
void xuat1(sinhvien sv, diemso ds)
{
	cout<<setw(10)<<sv.ma<<setw(10)<<sv.ho<<setw(10)<<sv.ten<<setw(15)<<sv.nt
	<<setw(10)<<ds.toan<<setw(10)<<ds.tin<<setw(10)<<ds.ta<<setw(10)<<ds.ktlt<<setw(10)<<ds.dtb<<endl;
}
void xuat(sinhvien *sv, diemso *ds, int n)
{
	cout<<setw(10)<<"Ma Sv"<<setw(10)<<"Ho Sv"<<setw(10)<<"Ten Sv"<<setw(15)<<"Ngay Sinh"
	<<setw(10)<<"Diem Toan"<<setw(10)<<"Diem Tin"<<setw(10)<<"Diem Ta"<<setw(10)<<"Diem KTLT"
	<<setw(10)<<"Diem Tb"<<endl;
	for(int i=0;i<n;i++)
	{
		xuat1(sv[i],ds[i]);
	}
}
void ktra(sinhvien *sv, diemso *ds, int n)
{
	for(int i=0;i<n;i++)
	{
		if(ds[i].dtb<2)
		  xuat1(sv[i],ds[i]);
        else
          cout<<"\t => khong co sv nao <=\t"<<endl;
	}
}
main()
{
	int n;
	do{
		cout<<"+ Nhap so sv can lap Ds: "; cin>>n;
	}while(n>=200);
	struct sinhvien *sv;
	struct diemso *ds;
	sv=new sinhvien[200];
	ds=new diemso[100];
	cout<<"----- Nhap TT Sinh Vien -----\n";
	  nhap(sv,ds,n);
    cout<<endl;
    cout<<"----- DS Sinh Vien -----\n";
      xuat(sv,ds,n);
    cout<<endl;
    cout<<"----- Ds Sinh Vien Bi Loai -----\n";
      ktra(sv,ds,n);
    cout<<endl;
}