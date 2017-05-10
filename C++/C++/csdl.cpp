#include<iostream.h>
#include<iomanip.h>
#include<fstream.h>
struct sinhvien{
	char ma[15],ho[15],ten[15];
	float csdl,ktlt,ktmt;
};
void nhap(sinhvien *sv,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<". Sv "<<i+1<<endl;
		cout<<"------"<<endl;
		cin.ignore(1);
		cout<<"\t > Ma Sv: ";
		cin.getline(sv[i].ma,15);
		cout<<"\t > Ho Sv: ";
		cin.getline(sv[i].ho,15);
		cout<<"\t > Ten Sv: ";
		cin.getline(sv[i].ten,15);
		cout<<"\t > Diem CSDL: ";
		cin>>sv[i].csdl;
		cout<<"\t > Diem KTLT: ";
		cin>>sv[i].ktlt;
		cout<<"\t > Diem KTMT: ";
		cin>>sv[i].ktmt;
	}
}
void ghitep(char svien[],int n)
{
	int sv1[n];
	ofstream tep("D:\\C++\\sinhvien.inp",ios::binary);
	if(!tep)
	{
		cout<<"=> Khong mo duoc tep "<<tep<<endl;
		exit(1);
	}
	tep.write((char *)&sv1,sizeof(sinhvien)*n);
	tep.close();
}
void in1sv(sinhvien sv)
{
	cout<<setw(10)<<sv.ma<<setw(10)<<sv.ho<<setw(10)<<sv.ten<<setw(10)<<sv.csdl<<setw(10)<<sv.ktlt<<setw(10)
	<<sv.ktmt<<setw(10)<<"\n";
}
void inall(sinhvien *sv,int n)
{
	cout<<"setw(10)Ma Sv \tHo Sv \tTen Sv \tDiem CSDL \tDiem KTLT \tDiem KTMT \t\n";
	for(int i=0;i<n;i++)
	{
		in1sv(sv[i]);
	}
}
void doctep(char svien[],int n)
{
	int sv[n];
	ifstream tep("D:\\C++\\sinhvien.inp",ios::binary);
	
	if(!tep)
	{
		cout<<"=> Khong mo duoc tep "<<tep<<endl;
		exit(1);
	}
	tep.read((char *)&sv,sizeof(sinhvien)*n);
	tep.close();
	
}
void sapxep(sinhvien *sv,int n)
{
	sinhvien tg;
	for(int i=0;i<n-1;i++)
	for(int j=i+1;j<n;j++)
	  if(strcmp(sv[i].ten,sv[j].ten)>0)
	  {
  		tg=sv[i];
  		sv[i]=sv[j];
  		sv[j]=tg;
  	}
  	cout<<"\t Ma Sv \t Ho Sv \t Ten Sv \t Diem CSDL \t Diem KTLT \t Diem KTMT \t\n";
  	for(int i=0;i<n;i++)
  	{
	  	in1sv(sv[i]);
	  }
  	
}
main()
{
	int n;
	char svien[100];
	struct sinhvien *sv;
	cout<<"Nhap so sinh vien can lap danh sach: ";
	cin>>n;
	cout<<"---------------------------------------\n";
	cout<<endl;
	sv=new sinhvien[n];
	cout<<"\t\t\t -------- Nhap TT Sinh Vien -------- \t\t\t\n";
	  nhap(sv,n);
	  ghitep(svien,n);
	  doctep(svien,n);
    cout<<endl;
    cout<<"\t\t\t -------- Danh Sach Sinh Vien -------- \t\t\t\n";
      inall(sv,n);
    cout<<endl;
    cout<<"\t\t\t -------- Sap Xep Sinh Vien Theo Ten -------- \t\t\t\n";
      sapxep(sv,n);
    cout<<endl;
}