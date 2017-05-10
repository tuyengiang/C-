/*Tran Ngoc Tan
Bai 5
Xay dung lop sinh vien gom cac thanh phan
DL: Ho ten, ngay sinh, gioi tinh, lop (k44/41.01), diem toan, li, hoa, dtb
PT: Nhap, in, tinh diem trung binh
Ham main
Nhap danh sach sinh vien
sap xep theo diem trung binh giam dan
in danh sach sinh vien khi sap xep
*/

#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<iomanip.h>

struct ngaysinh
{
	int ngay, thang, nam;
};

class sinhvien
{
	char hoten[30], lop[20], gt[10];
	float toan, li, hoa;
	ngaysinh ns;
	public:

	sinhvien(char *hoten="", char *lop="", char *gt="")
	{
		strcpy(hoten,"Tran Ngoc Tan");
		strcpy(lop,"Tin8A3");
		strcpy(gt,"Nam");
		toan=10;li=10;hoa=10;
		ns.ngay=14;
		ns.thang=7;
		ns.nam=1996;
	}
	~sinhvien(){}
	
	void nhap();
	void in();
	float tb()
	{
		return (toan+li+hoa)/3;
	}
	friend ostream& operator<<(ostream& os,sinhvien &sv);
	friend istream& operator>>(istream& is, sinhvien& sv)
	{
	cout<<"\n\tHo va ten:";
	is.getline(sv.hoten,30);
	strcpy(sv.lop,"k44/41.01");
	cout<<"\tGioi tinh:";
	is>>sv.gt;	
    cout<<"\tNhap ngay sinh:";
	is>>sv.ns.ngay>>sv.ns.thang>>sv.ns.nam;
	cout<<"\tToan:";
	is>>sv.toan;
	cout<<"\tLi";
	is>>sv.li;
	cout<<"\tHoa";
	is>>sv.hoa;		
	}
	
};


ostream& operator<<(ostream& os,sinhvien &sv)
{
	os<<endl<<setw(15)<<"Ho ten"<<setw(7)<<"GT"<<setw(15)<<"Lop"<<setw(7)<<"Toan"<<setw(7)<<"Li"<<setw(7)<<"Hoa"<<setw(7)<<"DTB"<<setw(10)<<"NSinh";
	os<<endl<<setw(15)<<sv.hoten<<setw(7)<<sv.gt<<setw(15)<<sv.lop<<setw(7)<<sv.toan<<setw(7)<<sv.li<<setw(7)<<sv.hoa<<setw(7)<<sv.tb()<<setw(7)<<sv.ns.ngay<<"/"<<sv.ns.thang<<"/"<<sv.ns.nam;			
	return os;
}
	
	
class dssv
{
	sinhvien *sv;
	int n;
	public:
	void nhapds();
	void xuatds();
	void sapxepds(); 
};

void sinhvien::nhap()
{
	cin.ignore(1);
	cout<<"\n\tHo va ten:";
	cin.getline(hoten,30);
	strcpy(lop,"k44/41.01");
	cout<<"\tGioi tinh:";
	cin>>gt;	
    cout<<"\tNhap ngay sinh:";
	cin>>ns.ngay>>ns.thang>>ns.nam;
	cout<<"\tToan:";
	cin>>toan;
	cout<<"\tLi";
	cin>>li;
	cout<<"\tHoa";
	cin>>hoa;
}

void sinhvien::in()
{
	cout<<endl<<setw(15)<<"Ho ten"<<setw(7)<<"GT"<<setw(15)<<"Lop"<<setw(7)<<"Toan"<<setw(7)<<"Li"<<setw(7)<<"Hoa"<<setw(7)<<"DTB"<<setw(10)<<"NSinh";
	cout<<endl<<setw(15)<<hoten<<setw(7)<<gt<<setw(15)<<lop<<setw(7)<<toan<<setw(7)<<li<<setw(7)<<hoa<<setw(7)<<tb()<<setw(7)<<ns.ngay<<"/"<<ns.thang<<"/"<<ns.nam;
}

void dssv::nhapds()
{
	cout<<endl<<"\no0o--------------------------------o0o";
	cout<<"\nNhap so sinh vien la:";
	cin>>n;
	cin.ignore(1);
	sv= new sinhvien[n];
	for (int i=1; i<=n; i++)
	sv[i].nhap();	
}

void dssv::xuatds()
{
	for (int i=1;i<=n;i++)
	sv[i].in();
}

void swap(sinhvien &a, sinhvien &b)
{
	sinhvien tg=a;
	a=b;
	b=tg;
}

void dssv::sapxepds()
{
	for (int i=1; i<n; i++)
	for (int j=i+1; j<=n; j++)
	if (sv[i].tb()<sv[j].tb())
	swap(sv[i], sv[j]);
}

void main()
{
	sinhvien a;
	dssv t;
	int n;
	cout<<"\nNhap sinh vien la:";
	cin>>a;
	cout<<"\nSinh vien vua nhap la:\n"<<a;
	t.nhapds();
	t.xuatds();
	cout<<"\nDanh sach sau khi sap xep la:";
	t.sapxepds();
	t.xuatds();

}
