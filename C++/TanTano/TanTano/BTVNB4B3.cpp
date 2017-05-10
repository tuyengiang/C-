#include<iostream.h>
const double lcb=3000000;
class nguoi
{
	public:
	char hoten[50];
	char maso[5];
    void nhap();
    void xuat();
};
void nguoi::nhap()
{
	cout<<"\n\tNHAP HO TEN:";
	cin.ignore(1);
	cin.getline(hoten,50);
	cout<<"\n\tNHAP MA SO:";
	cin.ignore(1);
	cin>>maso;
}
void nguoi::xuat()
{
	cout<<"\n\tHO TEN:"<<hoten;
	cout<<"\n\tMA SO:"<<maso;
}
class bienche:private nguoi
{
	private:
	float hesoluong;
	float tienphucap;
	public:
    void nhap();
    void xuat();
};
void bienche::nhap()
{
	nguoi::nhap();
	cout<<"\n\tNHAP HE SO LUONG:";cin>>hesoluong;
	cout<<"\n\tNHAP HE SO PHU CAP:";cin>>tienphucap;
}
void bienche::xuat()
{
	nguoi::xuat();
	cout<<"\n\tHE SO LUONG:"<<hesoluong;
	cout<<"\n\tHE SO PHU CAP:"<<tienphucap;
	cout<<"\n\tLUONG:"<<lcb*hesoluong+tienphucap;
}
class hopdong:private nguoi
{
	private:
	float tiencong;
	float ngaycong;
	float hesovuotgio;
	public:
    void nhap();
    void xuat();
};
void hopdong::nhap()
{
	nguoi::nhap();
	cout<<"\n\tNHAP TIEN CONG:";cin>>tiencong;
	cout<<"\n\tNHAP NGAY CONG:";cin>>ngaycong;	
}
void hopdong::xuat()
{
	nguoi::xuat();
	cout<<"\n\tNGAY CONG:"<<ngaycong;
	cout<<"\n\tTIEN CONG:"<<tiencong;
	cout<<"\n\tLUONG:"<<tiencong*ngaycong*hesovuotgio;
}
int main()
{
	bienche *bc;
	bc=new bienche[100];
	hopdong *hd;
	hd=new hopdong[100];
	char loai,chon;
	int n=0,m=0;
	do
	{
		cout<<"\n\tNHAP LOAI(B/H):";
		cin>>loai;
		if(loai=='h')
		   hd[n++].nhap();
		else
		  if(loai=='b')
		    bc[m++].nhap();
        cout<<"\n\tTIEP TUC(C/K):";
        cin>>chon;
        if(n+m==100||chon=='k')
          break;
	}
	while(1);
	for(int i=0;i<n;i++)
   		hd[i].xuat();
    for(int i=0;i<m;i++)
   		bc[i].xuat();
    return 0;
}