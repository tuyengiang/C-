#include<iostream.h>
#include<iomanip.h>
#include<fstream.h>
struct sinhvien{
	char ma[15],ho[15],ten[15];
	float toan,ly,hoa,dtb;
};
void nhap(sinhvien *sv,int n)
{
	for(int i=0;i<n;i++)
	{
	 	cout<<i+1<<". Sv Thu "<<i+1<<" :"<<endl;
		cout<<"-------------"<<endl;
		cin.ignore(1);
		cout<<"\t > MA SV: ";
		cin.getline(sv[i].ma,15);
		cout<<"\t > HO SV: ";
		cin.getline(sv[i].ho,15);
		cout<<"\t > TEN SV: ";
		cin.getline(sv[i].ten,15);
		do{
			cout<<"\t > DIEM TOAN: ";
			cin>>sv[i].toan;
		}while(sv[i].toan>10||sv[i].toan<0);
		do{
			cout<<"\t > DIEM LY: ";
			cin>>sv[i].ly;
		}while(sv[i].ly>10||sv[i].ly<0);
		do{
			cout<<"\t > DIEM HOA: ";
			cin>>sv[i].hoa;
		}while(sv[i].hoa>10||sv[i].hoa<0);
		sv[i].dtb=(sv[i].toan+sv[i].ly+sv[i].hoa)/3;
	}
}
void ghitep(char svien[],int n)
{
	int sv1[n];
	ofstream tep("D:\\C++\\s.inp",ios::binary);
	if(!tep){
		cout<<"KHong mo duoc tep"<<tep<<endl;
		exit(1);
	}
   tep.write((char*)&sv1,sizeof(sinhvien)*n);
   tep.close();	
}
void xuat1(sinhvien sv){
		cout<<"|"<<sv.ma<<"\t|"<<sv.ho<<"\t|"<<sv.ten<<"\t|"<<sv.toan<<"\t\t|"<<sv.ly
		<<"\t\t|"<<sv.hoa<<"\t\t|"<<sv.dtb<<"\t\t|\n";
}
void xuat(sinhvien *sv,int n){
	cout<<"\n|---------------------------------------------------------------------------------------|\n";
	cout<<"|\t\t\t\t Ds Sinh Vien \t\t\t\t\t\t|\n";
	cout<<"|-------|-------|-------|---------------|---------------|---------------|---------------|\n";
	cout<<"|Ma Sv\t|Ho Sv\t|Ten Sv\t|Diem Toan\t|Diem Ly\t|Diem Hoa\t|Diem Tb\t|\n";
	cout<<"|-------|-------|-------|---------------|---------------|---------------|---------------|\n";
	for(int i=0;i<n;i++)
	{
		xuat1(sv[i]);
		cout<<"|-------|-------|-------|---------------|---------------|---------------|---------------|\n";
    } 
}
void doctep(char svien[],int n)
{
	int sv[n];
	ifstream tep("D:\\C++\\s.inp",ios::binary);
	if(!tep){
		cout<<"KHong mo duoc tep"<<tep<<endl;
		exit(1);
	}
	while(tep){
	  tep.read((char*)&sv,sizeof(sinhvien)*n);
      tep.close();	
	};
}
void sapxeptheoten(sinhvien *sv,int n){
	sinhvien tg;
	for(int i=0;i<n-1;i++)
	for(int j=i+1;j<n;j++)
	   if(strcmp(sv[i].ten,sv[j].ten)>0)
    {
    	tg=sv[i];
    	sv[i]=sv[j];
    	sv[j]=tg;
    }
   	cout<<"\n|---------------------------------------------------------------------------------------|\n";
	cout<<"|\t\t\t\t DS Sinh Vien Da Sap Xep \t\t\t\t|\n";
	cout<<"|-------|-------|-------|---------------|---------------|---------------|---------------|\n";
	cout<<"|Ma Sv\t|Ho Sv\t|Ten Sv\t|Diem Toan\t|Diem Ly\t|Diem Hoa\t|Diem Tb\t|\n";
	cout<<"|-------|-------|-------|---------------|---------------|---------------|---------------|\n";
	for(int i=0;i<n;i++)
	{
		xuat1(sv[i]);
		cout<<"|-------|-------|-------|---------------|---------------|---------------|---------------|\n";
    } 
}
main(){
	int n;
	struct sinhvien *sv;
	char svien[52];
	cout<<"Nhap so Sv can lap danh sach: ";
	cin>>n;
	sv=new sinhvien[n];
	cout<<endl;
	cout<<"\t\t\t -------NHAP TT SINH VIEN VAO DANH SACH------\t\t"<<endl;
	  nhap(sv,n);
	  ghitep(svien,n);
	  doctep(svien,n);
    cout<<endl;
   	cout<<"\t\t\t -------DANH SACH SINH VIEN------\t\t"<<endl;
   	  xuat(sv,n);
   cout<<endl;
   cout<<"\t\t\t -------SAP XEP THEO TEN ALPHABE------\t\t"<<endl;
      sapxeptheoten(sv,n);
   cout<<endl;
   cout<<"\t\t----- END -----\t\t"<<endl;
}