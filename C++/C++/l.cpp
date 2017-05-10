#include<iostream.h>
#include<iomanip.h>
#include<fstream.h>
#include<string.h>
struct sinhvien{
	char ma[15],ho[15],ten[15];
	float toan,ly,hoa,dtb;
};
int menu(){
	int m;
	cout<<"\n|-----------------------------------------|\n";
	cout<<"|\t\t  MENU \t\t\t  |\n";
	cout<<"|-----------------------------------------|\n";
	cout<<"| 1. Nhap TT sinh vien                    |\n";	
	cout<<"| 2. Xuat TT sinh vien                    |\n";
	cout<<"| 3. Ghi vao tep                          |\n";
	cout<<"| 4. Sap xep                              |\n";
	cout<<"|-----------------------------------------|\n";
	cout<<"=> Xin nhap lua chon: ";
	cin>>m;
	return m;
}
void nhap(sinhvien *sv, int n){
	cout<<"* Nhap sv can lap danh sach: ";
 	cin>>n;
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
	    cout<<"=> An enter tiep tuc\n";
	    
}
void xuat(sinhvien *sv,int n){
	cout<<"\n|-----------------------------------------|\n";
	cout<<"|\t\t Ds Sinh Vien \t\t\t  |\n";
	cout<<"|-----------------------------------------|\n";
	cout<<"|Ma Sv\t|Ho Sv\t|Ten Sv\t|Diem Toan\t|Diem Ly\t|Diem Hoa\t|Diem Tb\t|\n";
	cout<<"\n|-----------------------------------------|\n";
	for(int i=0;i<n;i++)
	{
		cout<<"|"<<sv[i].ma<<"\t|"<<sv[i].ho<<"\t|"<<sv[i].ten<<"\t|"<<sv[i].toan<<"\t|"<<sv[i].ly
		<<"\t|"<<sv[i].hoa<<"\t|"<<sv[i].dtb<<"\t|\n";
	}
	
}
main()
 {
 	int n;
 	struct sinhvien *sv;
 	sv=new sinhvien[n];
    int m=menu();
 	switch(m){
	 	case 1:
	 	  nhap(sv,n);
	 	  break;
	    case 2:
	      xuat(sv,n);
	      break;
	 }
 	
 	
 }
	