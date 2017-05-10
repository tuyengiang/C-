#include <iostream>
#include <string.h>
#include <iomanip.h>
#include <fstream.h>
#include <ctime>
#include <conio.h>
#define max 100

//Cau truc thong tin sinh vien trong nhom
struct DATE
{
	int dd,mm,yyyy;
};
struct USER
{
	int admin;
	char user[32], pass[32], ten[30];
	DATE SN, NTG;
	float DTB;

}MAIN[max];

int i;

//DIEM SO THANH VIEN TRONG NHOM RA TEP
int SUM(int n)
{
	int sum=0;
	//dau vao la so luong nhap vao nhom
	//dau ra la tong thanh vien trong nhom
	
	
	
	ifstream fi("user.sum");
	if(!fi){cout<<"SUMIN 404\n";exit(1);}
	fi>>sum;
	fi.close();
	
	sum+=n;
	ofstream f("user.sum");
	if(!f){cout<<"SUMOUT 404\n";exit(1);}
	f<<sum;
	f.close();
	return sum;
	
}

//KIEM TRA USER 
bool CHECKUSER(char a[],USER *b,int leng)
{
	if(strlen(a)<3) return true;
	else for(i=0;i<leng+1;i++)
	{
		if(strcmp(a,b[i].user)==0) return true; else return false;
	}
}

//SAO CHEP CHO USER
void CAPPHAT(USER *a,USER *b,int n)
{
	for(i=0;i<n;i++)	b[i]=a[i];
}
//Doc thong tin tu tep
void DOC(int n)
{
	fstream f("user.inp",ios::in|ios::binary);
	if(!f){cout<<"DOC 404\n";exit(1);}
	f.read((char*)&MAIN,sizeof(USER)*n);
	f.close();
}



//Ghi thong tin
void GHIADM(int n)
{
	
	cout<<"\n--------------------NHAP VAO THONG TIN NGUOI DUNG--------------------\n";
	USER b[n];
	for(i=0;i<n;i++)
	{
		
		cout<<"\nNGUOI DUNG "<<i+1;
		
		cout<<"\n	>ADMIN (1:Yes,0:No): ";do cin>>b[i].admin; while(b[i].admin<0||b[i].admin>1);
		
		cin.ignore();
		u:;	
		cout<<"	>USER NAME: "; cin.getline(b[i].user,32);
		//CHECK USER
		if(CHECKUSER(b[i].user,MAIN,i)==true){cout<<"\n\n		USER bi trung hoac < 3 ki tu!\n\n"; goto u;}
		
		p:; 
		cout<<"	>PASSWORD: ";cin.getline(b[i].pass,32);
		//CHECK PASS
		if(strlen(b[i].pass)<6) {cout<<"\n\n		Password phai tu 6 ki tu!\n\n";goto p;}
		
		name:;
		cout<<"	>HO VA TEN: ";cin.getline(b[i].ten,30);
		
		cout<<"	>NGAY THANG NAM SINH: \n";
		cout<<"		>NGAY: "; do cin>>b[i].SN.dd; while(b[i].SN.dd<1||b[i].SN.dd>31);
		cout<<"		>THANG: "; do cin>>b[i].SN.mm; while(b[i].SN.mm<1||b[i].SN.mm>12);
		cout<<"		>NAM: "; do cin>>b[i].SN.yyyy; while(b[i].SN.yyyy<1900||b[i].SN.yyyy>2000);
		//NGAY THAM GIA
		time_t baygio = time(0);
   		tm *ltm = localtime(&baygio);
  		b[i].NTG.yyyy=1900 + ltm->tm_year;
  		b[i].NTG.mm= 1 + ltm->tm_mon;
  		b[i].NTG.dd=ltm->tm_mday;

		cout<<"	>DIEM TRUNG BINH: ";do cin>>b[i].DTB; while(b[i].DTB<0||b[i].DTB>10);	
	}
	
	cout<<"\n----------------------------------------------------------------------\n";
	fstream f("user.inp",ios::out|ios::app|ios::binary);
	if(!f){cout<<"GHIADM 404\n";exit(1);}
	f.write((char*)&b,sizeof(USER)*n);
	f.close();
	int sum=SUM(n);
	DOC(sum);
	
}

void GHIUSER()
{

	cout<<"\n--------------------DANG KI THONG TIN NGUOI DUNG--------------------\n";
	USER b[1];
	for(i=0;i<1;i++)
	{
		b[i].admin=0;
		cin.ignore();
		u:;	
		cout<<"	>USER NAME: "; cin.getline(b[i].user,32);
		//CHECK USER
		if(CHECKUSER(b[i].user,MAIN,i)==true){cout<<"\n\n		USER bi trung hoac < 3 ki tu!\n\n"; goto u;}
		
		p:; 
		cout<<"	>PASSWORD: ";cin.getline(b[i].pass,32);
		//CHECK PASS
		if(strlen(b[i].pass)<6) {cout<<"\n\n		Password phai tu 6 ki tu!\n\n";goto p;}
		
		name:;
		cout<<"	>HO VA TEN: ";cin.getline(b[i].ten,30);
		
		cout<<"	>NGAY THANG NAM SINH: \n";
		cout<<"		>NGAY: "; do cin>>b[i].SN.dd; while(b[i].SN.dd<1||b[i].SN.dd>31);
		cout<<"		>THANG: "; do cin>>b[i].SN.mm; while(b[i].SN.mm<1||b[i].SN.mm>12);
		cout<<"		>NAM: "; do cin>>b[i].SN.yyyy; while(b[i].SN.yyyy<1900||b[i].SN.yyyy>2000);
		//NGAY THAM GIA
		time_t baygio = time(0);
   		tm *ltm = localtime(&baygio);
  		b[i].NTG.yyyy=1900 + ltm->tm_year;
  		b[i].NTG.mm= 1 + ltm->tm_mon;
  		b[i].NTG.dd=ltm->tm_mday;

		cout<<"	>DIEM TRUNG BINH: ";do cin>>b[i].DTB; while(b[i].DTB<0||b[i].DTB>10);
	}
	cout<<"\n----------------------------------------------------------------------\n";
	fstream f("user.inp",ios::out|ios::app|ios::binary);
	if(!f){cout<<"GHIUSER 404\n";exit(1);}
	f.write((char*)&b,sizeof(USER));
	f.close();
	int sum=SUM(1);
	DOC(sum);
	
}


void IN(USER *a, int n,int vt)
{
	if(vt==-1)
	{
	cout<<"\n\n\nSTT"<<setw(5)<<"ADM"<<setw(20)<<"HO VA TEN"<<setw(20)<<"NGAY SINH"<<setw(20)<<"NGAY THAM GIA"<<setw(21)<<"DIEM TRUNG BINH"<<setw(15)<<"USER NAME"<<setw(15)<<"PASSWORD\n";
	for(i=0;i<n;i++)
	cout<<i+1<<setw(5)<<a[i].admin<<setw(22)<<a[i].ten<<setw(13)<< a[i].SN.dd<<"/"<<a[i].SN.mm<<"/"<<a[i].SN.yyyy<<setw(13)<<a[i].NTG.dd<<"/"<<a[i].NTG.mm<<"/"<<a[i].NTG.yyyy<<setw(21)<<a[i].DTB<<setw(15)<<a[i].user<<setw(15)<<a[i].pass<<"\n\n\n";
	}
	if(n==-1)
	{
	cout<<"\n\n\nSTT"<<setw(5)<<"ADM"<<setw(20)<<"HO VA TEN"<<setw(20)<<"NGAY SINH"<<setw(20)<<"NGAY THAM GIA"<<setw(21)<<"DIEM TRUNG BINH\n";
	cout<<1<<setw(5)<<a[vt].admin<<setw(22)<<a[vt].ten<<setw(13)<< a[vt].SN.dd<<"/"<<a[vt].SN.mm<<"/"<<a[vt].SN.yyyy<<setw(13)<<a[vt].NTG.dd<<"/"<<a[vt].NTG.mm<<"/"<<a[vt].NTG.yyyy<<setw(21)<<a[vt].DTB<<"\n\n\n";
	}
}

//RENEW TEP
void RENEW(int n)
{
	ofstream fs("user.sum");
	if(!fs){cout<<"RENEW SUM 404\n";exit(1);}
	fs<<n;
	fs.close();
		
	fstream f("user.inp",ios::out|ios::binary);
	if(!f){cout<<"RENEW MAIN 404\n";exit(1);}
	f.write((char*)&MAIN,sizeof(USER)*n);
	f.close();
}

//DANG NHAP
int vt;
int DANGNHAP()
{
	int n=SUM(0),e;
	USER *c;
	c=new USER[1];
	
	cout<<"\n----------------------------- DANG NHAP ------------------------------\n";
	do
	{
	u:;
	for(i=0;i<1;i++)
	{
		cin.ignore();	
		cout<<"> TEN DANG NHAP: ";cin.getline(c[0].user,32);
	
		cout<<"> PASSWORD: ";cin.getline(c[0].pass,32);
	}
	
	//CHECKUSER
	bool check=true;
	
	for(i=0;i<n;i++)
	{
		if(strcmp(c[0].user,MAIN[i].user)==0 && strcmp(c[0].pass,MAIN[i].pass)==0) {cout<<"DANG NHAP THANH CONG!\n"; vt=i;check=true;break;}
		else check=false;
	}
	
	if(check==false)
	{
		cout<<"SAI TEN DANG NHAP HOAC MAT KHAU!\n"<<c[0].user<<endl<<c[0].pass<<"\n";
		cout<<"	> QUAY LAI(1: Co/0 Khong): ";do cin>>e; while(e<0||e>1); if(e!=0){vt=-1; break;} else goto u;
	}	
	} while (true);
	cout<<"\n----------------------------------------------------------------------\n";

	delete [] c;	

}

//XOA TAI KHOAN
void XOA(int vt)
{
	int k,x=SUM(0);
	if(vt!=0)
	{
	
		for (k=vt+1;k<x;k++) MAIN[k-1]=MAIN[k];
		x--;
	}
	else cout<<"> KHONG THE XOA TAI KHOAN admin !\n";
	RENEW(x);
}
int 
main()
{

	DOC(SUM(0));

	cout<<"\n----------------------------------------------------------------------\n";
	cout<<"\n               CHAO MUNG DEN VOI TRINH QUAN LI THANH VIEN\n";
	cout<<"\n                           DEV: HUNGG\n";
	cout<<"\n----------------------------------------------------------------------\n";
	
	
	menu1:;
	cout<<"\n----------------------------------------------------------------------\n";
	cout<<"> MENU 1: \n	TRANG THAI: CHUA DANG NHAP\n	1. DANG NHAP\n	2. DANG KI\n	3. THONG TIN UNG DUNG\n	0. THOAT\n	> CHON: ";

	int key;cin>>key;
	cout<<"\n----------------------------------------------------------------------\n";	
	switch(key)
	{
		case 1: DANGNHAP();break;
		
		case 2: GHIUSER(); cout<<"\nDANG KI THANH CONG!\n"; goto menu1;
		
		case 3: 
			cout<<"\n----------------------------------------------------------------------\n";
			cout<<"\n                       THONG TIN UNG DUNG\n";
			cout<<"\n	>PHIEN BAN: 1\n	>NGAY TAO: 17/5/2016\n	>NGUOI TAO: NGUYEN MANH HUNG\n	>LIEN HE: 0165 831 2821 | 0164 769 5197\n";
			cout<<"\n----------------------------------------------------------------------\n";
			goto menu1;
		default:
		 cout<<"\nHUNG DEP TRAI KHONG? ( A.CO B.A )";
		 getch();
		 exit(1);
	}
	if(vt==-1) goto menu1;
	if(MAIN[vt].admin==1) goto menuaadm; 
	if(MAIN[vt].admin==0) goto menuuser;

	
	menuaadm:;
	cout<<"\n----------------------------------------------------------------------\n";	
	cout<<"> MENU ADM: \n	TRANG THAI: "<<MAIN[vt].ten<<" <ADMINISTRATOR>\n	1. XEM THONG TIN TAT CA\n	2. XEM THONG TIN CA NHAN\n	3. THEM THANH VIEN\n	4. DANG XUAT\n	5. THOAT\n	> CHON: ";
	cin>>key;
	cout<<"\n----------------------------------------------------------------------\n";
		switch(key)
	{
		case 1: IN(MAIN,SUM(0),-1); goto menuaadm;
		
		case 2: IN(MAIN,-1,vt); goto menuaadm;
		
		case 3: 
			cout<<"\n	>SO THANH VIEN THEM VAO: ";int n; cin>>n; GHIADM(n); goto menuaadm;
		case 4: goto menu1;
		
		default:
		 cout<<"\nHUNG DEP TRAI KHONG? ( A.CO B.A )";
		 getch();
		 exit(1);
			
	}
	
	menuuser:;
	cout<<"\n----------------------------------------------------------------------\n";	
	cout<<"> MENU USER: \n	TRANG THAI: "<<MAIN[vt].ten<<" <USER>\n	1. XEM THONG TIN CA NHAN\n	2. DANG XUAT\n	3. HUY TAI KHOAN\n	> CHON: ";
	cin>>key;
	cout<<"\n----------------------------------------------------------------------\n";
		switch(key)
	{
		case 1: IN(MAIN,-1,vt); goto menuuser;
	
		case 2:	 goto menu1;
		
		case 3: XOA(vt); cout<<"THANH CONG !";goto menu1;
		
		default:
		 cout<<"\nHUNG DEP TRAI KHONG? ( A.CO B.A )";
		 getch();
		 exit(1);
			
	}
	
	
	getch();
}