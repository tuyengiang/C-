#include <iostream.h>
#include <iomanip.h>
#include <stdlib.h>
#include<string.h>
#include <conio.h>

class danhsach
{
	private:
		char ma[5],ten[30],lp[5],ngay[10];
		int kl,dg,tt;
	public:
	
	danhsach ()
	{
		strcpy(ma,"TNT");
		strcpy(ten,"Tan");
		strcpy(lp,"Nhap");
		strcpy(ngay,"14");
		kl=14;
		dg=7;
		tt=kl*dg;
	}
	
	~danhsach(){}
	
	void nhap();
	void in();
	void sapxep(danhsach *a,int n);
	int kt(danhsach a);
	int tinhtien()
	{
		return kl*dg;
	}
	friend ostream &operator<<(ostream& os,  danhsach ds)
	{
			os<<"\n"<<setw(5)<<ds.ma<<setw(20)<<ds.ten<<setw(15)<<ds.ngay<<setw(10)<<ds.lp<<setw(10)<<ds.kl<<setw(10)<<ds.dg<<setw(10)<<ds.tinhtien();

	}
	friend istream &operator>>(istream& is, danhsach &ds);

};

void danhsach::nhap()
{
	int a;
	cin.ignore(1);
	cout<<"\n\tMa:";
	cin.getline(ma,5);
	cout<<"\n\tTen:";
	cin.getline(ten,30);
	do
	{
		cout<<"\n\tLoai phieu:\n\t\t 1:Xuat n\n\t\t2:Nhap \n\t\t";
		cin>>a;
		if (a==1)
			strcpy(lp,"xuat");
		else
			strcpy(lp,"nhap");
	}
	while (a<0 || a>2);
	cout<<"\n\t nhap vao ngay nhap: ";
	cin>>ngay;
	cout<<"\n\t nhap vao khoi  luong mat hang: ";
	cin>>kl;
	cout<<"\n\t nhap vao don gia: ";
	cin>>dg;
}
istream& operator>>(istream &is, danhsach &ds)
{
	int a;
	cin.ignore(1);
	cout<<"\n\tMa: ";
	is.getline(ds.ma,5);
	cout<<"\n\tTen: ";
	is.getline(ds.ten,30);
	do
	{
		cout<<"\n\tLoai phieu: \n\t\t 1:Xuat \n\t\t 2:Nhap \n\t\t";
		cin>>a;
		if (a==1)
			strcpy(ds.lp,"Xuat");
		else
			strcpy(ds.lp,"Nhap");
	}
	while (a<0 || a>2);
	cout<<"\n\tNgay nhap:";
	is>>ds.ngay;
	cout<<"\n\tKhoi luong:";
	is>>ds.kl;
	cout<<"\n\tDon gia: ";
	is>>ds.dg;	
	return is;
}


void danhsach::in()
{
	cout<<"\n"<<setw(5)<<ma<<setw(20)<<ten<<setw(15)<<ngay<<setw(10)<<lp<<setw(10)<<kl<<setw(10)<<dg<<setw(10)<<tinhtien();
}


void sapxep(danhsach *a,int n)
{
	danhsach tg;
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++)
			if (a[i].tinhtien()<a[j].tinhtien())
			{
				tg=a[i];
				a[i]=a[j];
				a[j]=tg;
			}
}

int danhsach::kt(danhsach a)
{
	if (strcmpi(a.lp,"xuat")==0)
		return 1;
	else
		return 0;	
}

int main()
{
	int n,k=0,t,tong=0;
	danhsach *ds;
	ds= new danhsach[100];
	do
	{
	
		cout<<"\nDanh sach mat hang: \n\t 1. Nhap mat hang \n\t 2. In ra du lieu: \n\t 3. Sap xep cac mat hang theo tong tien: \n\t";
		cout<<" 4. In ra so tien va tong tien: \n\t 5. In ra cac mat hang xuat: \n\t 6. In ra cac mat hang nhap: \n\t 7. Thoat: \n";
		cin>>t;
		if (t<1 || t>7)
		{
			cout<<"\n yeu cau nhap lai!!!!";
			cin>>t;
		}
		switch (t)
		{
			case 1:
				
				cout<<"\nSo mat hang can nhap:";
				cin>>n;
				n=n+k;
				for (int i=k;i<n;i++)
				{
					cout<<"\n***********************";
					cout<<"\nMat hang thu:"<<i+1;
					ds[i].nhap();
					k++;
				}
				cout<<"\n press any key.";
		
				break;
			case 2:
			
				cout<<"\n"<<setw(5)<<"Ma"<<setw(20)<<"Ten"<<setw(15)<<"Ngay"<<setw(10)<<"Loai"<<setw(10)<<"KL"<<setw(10)<<"DG"<<setw(10)<<"TT";
				for (int i=0;i<n;i++)
					ds[i].in();
				
				cout<<"\n press any key.";
				break;
			case 3:
			
				sapxep(ds,n);
				cout<<"\n Da sap xep xong. \n press any key.";
				
				break;
			case 4:
			
				cout<<"\n So tien cua tung mat hang la: ";
				for (int i=0;i<n;i++)
				{
					cout<<"\n\tMat hang thu "<<i+1<<": "<<ds[i].tinhtien();
					tong=tong+ds[i].tinhtien();
				}
				cout<<"\n******************\nTong tien da ban la: "<<tong;
				cout<<"\n press any key.";
			
				break;
			case 5:
				
				cout<<"\n"<<setw(5)<<"Ma"<<setw(20)<<"Ten"<<setw(15)<<"Ngay"<<setw(10)<<"Loai"<<setw(10)<<"KL"<<setw(10)<<"DG"<<setw(10)<<"TT";
				for (int i=0;i<n;i++)
					if (ds[n].kt(ds[i])==1)
					{
						ds[i].in();
					}
				cout<<"\n press any key.";
				
				break;
			case 6:
			
				cout<<"\n"<<setw(5)<<"Ma"<<setw(20)<<"Ten"<<setw(15)<<"Ngay"<<setw(10)<<"Loai"<<setw(10)<<"KL"<<setw(10)<<"DG"<<setw(10)<<"TT";
				for (int i=0;i<n;i++)
					if (ds[n].kt(ds[i])==0)
					{
						ds[i].in();
					}
				cout<<"\n press any key.";
				
				break;				
			case 7:
				exit(1);
				break;
		}
	}
	while (t>0 && t<8);
	return 0;
}
