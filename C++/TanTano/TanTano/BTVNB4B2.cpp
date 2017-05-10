#include<iostream.h>
#include<string.h>
class nguoi
{
	protected:
	char hoten[50];
	public:
	nguoi();
    void nhap();
    void xuat();
};

class sinhvien :private nguoi
{
	private:
	float diemtb;
	public:
    int svduockhenthuong();
    void nhap();
    void xuat();
};

class giangvien :private nguoi
{
	private:
	int sobaibao;
	public:
    int gvduockhenthuong();
    void nhap();
    void xuat();
};

nguoi::nguoi()
{
	strcpy(hoten,"");
}

void nguoi::nhap()
{

	cout<<"\n\tNHAP HO TEN:";
		cin.ignore(1);
		cin.getline(hoten,50);
}

void nguoi::xuat()
{
	cout<<"\n\tHO TEN:"<<hoten;
}

int giangvien::gvduockhenthuong()
{
	if(sobaibao>=5)
	  return 2;
      return 3;
}

void giangvien::nhap()
{
	nguoi::nhap();
	cout<<"\n\tNHAP SO BAI BAO:";
	cin>>sobaibao;
}

void giangvien::xuat()
{
	nguoi::xuat();
}

int sinhvien::svduockhenthuong()
{
	if(diemtb>=8.0)
	  return 1;
      return 0;
}

void sinhvien::nhap()
{
	nguoi::nhap();
	cout<<"\n\tNHAP DIEM TRUNG BINH:";cin>>diemtb;
}

void sinhvien::xuat()
{
	nguoi::xuat();
}

int main()
{
	system("cls");
	giangvien *gv;
	gv=new giangvien[100];
	sinhvien *sv;
	sv=new sinhvien[100];
	char loai,chon;
	int n=0,m=0;
	do
	{
		cout<<"\n\tNHAP LOAI(G/S):";
		cin>>loai;
		if(loai=='g')
		   gv[n++].nhap();
		else
		  if(loai=='s')
		    sv[m++].nhap();
        cout<<"\n\tTIEP TUC(C/K):";
        cin>>chon;
        if(n+m==100||chon=='k')
          break;
	}
	while(1);
	for(int i=0;i<n;i++)
	   {
   		gv[i].xuat();
   		if(gv[i].gvduockhenthuong()==2)
   		   cout<<"\n\tDUOC KHEN THUONG";
   	    }
    for(int i=0;i<m;i++)
	   {
   		sv[i].xuat();
   		if(sv[i].svduockhenthuong()==1)
   		   cout<<"\n\tDUOC KHEN THUONG";
   	    }
    return 0;
}