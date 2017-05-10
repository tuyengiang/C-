#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<iomanip.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

const int lai=0.05;
// --------------xay dung class nguoi---------------

class nguoi
{
	private: 
		char ht[30];//ho ten
		char dc[30];//dia chi
		int tuoi;//tuoi
	public:
		nguoi(int x=0)
		{
			strcpy(ht,"***");
			strcpy(dc,"***");
			tuoi=x;
		}
		~nguoi()
		{
			
		}
		friend istream& operator>>(istream& is, nguoi &ng);//nhap nguoi
		friend ostream& operator<<(ostream& os,nguoi &ng);//in nguoi
};

istream& operator>>(istream& is,nguoi &ng)
{
	is.ignore(1);
	cout<<"\n\t nhap vao ten: ";is.getline(ng.ht,30);//nhap ho ten
	cout<<"\n\t nhap vao dia chi: ";is.getline(ng.dc,30);//nhap dia chi
	cout<<"\n\t nhap vao so tuoi: ";is>>ng.tuoi;//nhap tuoi
	return is;
}

ostream& operator<<(ostream& os,nguoi &ng)
{
	os<<setw(20)<<ng.ht<<setw(20)<<ng.dc<<setw(10)<<ng.tuoi;	
	return os;
}

//-------------------xay dung class khach hang----------------------

class KH:private nguoi
{
	private:
		int ms;//ma so khach hang
		nguoi ng;
	public:
		KH (int x=0)
		{
			ms=x;
		}
		~KH ()
		{
			
		}
		friend istream& operator>>(istream& is,KH &kh);
		friend ostream& operator<<(ostream& os,KH &kh);
};

istream& operator>>(istream& is,KH &kh)
{
	cout<<"\n\t nhap vao ma so khach hang: ";
	is>>kh.ms;
	is>>kh.ng;//nhap nguoi
	return is;
}

ostream& operator<<(ostream& os,KH &kh)
{
	os<<setw(5)<<kh.ms;
	os<<kh.ng;//in nguoi
	return os;
}

//---------------------------xay dung class khach hang vay---------------

class KHV:private KH
{
	private:
		int sotien;//so tien vay
		int tg;//thoi gian vay
		KH kh;
	public:
		KHV (int x=0)
		{
			sotien =x;
			tg=x;
		}
		~KHV()
		{
			
		}
		friend istream& operator>>(istream& is,KHV &khv);
		friend ostream& operator<<(ostream& os,KHV &khv);
};

istream& operator>>(istream& is,KHV &khv)
{
	is>>khv.kh;
	cout<<"\n\t nhap vao so tien vay(trieu dong): ";
	is>>khv.sotien;
	cout<<"\n\t nhap vao thoi gian vay(thang): ";
	is>>khv.tg;
	return is;
}

ostream& operator<<(ostream& os,KHV &khv)
{
	cout<<"\n";
	os<<khv.kh;
	os<<setw(10)<<khv.sotien<<setw(10)<<khv.tg;
	return os;
}

//---------------------xay dung class doanh nghiep---------------------

class doanhnghiep
{
	private:
		char ten[30];//ten doanh nghiep
		char msdk[30];//ma so dang ky kinh doanh
		char msthue[30];//ma so thue
	public:
		doanhnghiep()
		{
			strcpy(ten,"***");
			strcpy(msdk,"***");
			strcpy(msthue,"****");
		}
		~doanhnghiep()
		{
			
		}
		friend istream& operator>>(istream& is, doanhnghiep &dn);
		friend ostream& operator<<(ostream& os,doanhnghiep &dn);
};

istream& operator>>(istream& is,doanhnghiep &dn)
{
	is.ignore(1);
	cout<<"\n\t nhap vao ten doanh nghiep: ";
	is.getline(dn.ten,30);
	cout<<"\n\t nhap vao ma so dang ky kinh doanh: ";
	is.getline(dn.msdk,30);
	cout<<"\n\t nhap vao ma so thue: ";
	is.getline(dn.msthue,30);
	return is;
}

ostream& operator<<(ostream& os,doanhnghiep &dn)
{
	os<<setw(20)<<dn.ten<<setw(15)<<dn.msdk<<setw(15)<<dn.msthue;
	return os;
}

//--------------------------xay dung class khach hang doanh nghiep--------------

class KHDN:private KHV, private doanhnghiep
{
	private:
		KHV khv;
		doanhnghiep dn;
	public:
		friend istream& operator>>(istream &is,KHDN &khdn);
		friend ostream& operator<<(ostream &os,KHDN &khdn);
};

istream& operator>>(istream &is,KHDN &khdn)
{
	is>>khdn.khv;
	is>>khdn.dn;
	return is;
}

ostream& operator<<(ostream &os,KHDN &khdn)
{
	os<<khdn.khv;
	os<<khdn.dn;
	return os;
}

//------------------------main------------------------

int main()
{
	int n;
	KHDN *ds;
	ds =new KHDN[100];
	cout<<"\n nhap vao so khach hang vay: ";
	cin>>n;
	if (n>100 || n<1)
		do
		{
			cout<<"\n nhap lai so khach hang: ";
			cin>>n;
		}
		while (n>100 || n<1);
	for (int i=0;i<n;i++)
	{
		system("cls");
		cin>>ds[i];
	}
	system("cls");
	cout<<"**************************************** danh sach *************************************";
	cout<<"\n"<<setw(5)<<"ms"<<setw(20)<<"ho ten"<<setw(20)<<"dia chi"<<setw(10)<<"tuoi"<<setw(10)<<"tien"<<setw(10)<<"time"<<setw(20)<<"ten dn"<<setw(15)<<"msdkkd"<<setw(15)<<"msthue";
	for (int i=0;i<n;i++)
	{
		cout<<ds[i];
	}
	cout<<"\n";
	return 0;
}