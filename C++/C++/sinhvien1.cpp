#include<iostream.h>
#include<iomanip.h>
#include<fstream.h>
struct sinhvien{
	char ma[15],ho[15],ten[15];
	float toan,ly,hoa,dtb;
};
int menu(){
	int m;
	cout<<"\t\t ***** MENU ***** \t\t"<<endl;
	cout<<"1. Nhap TT sinh vien \n";
	cout<<"2. Xuat TT sinh vien \n";
	cout<<"3. Ghi ten sinh vien vao tep \n";
	cout<<"4. Sap xep danh sah sinh vien theo alphabe \n";
	cout<<"=> Moi ban chon: ";
    cin>>m;
}
void xuly()
{
	int m,n,sv[50];
 	
	switch(m)
 	{
 	case 1:
 	cout<<"\t\t----------------------\t\t0"<<endl;
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
	 	   break;
	
	 };
}
main()
 {
 	int m=menu();
 	switch(m){
	 	xuly(sv,n);
	 }
 	
 	
 }