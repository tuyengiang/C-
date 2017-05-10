#include<iostream.h>
#include<iomanip.h>
#include<fstream.h>
#include<string.h>
struct canbo{
	char ma[10],ho[15],ten[15];
	long luong;
};
void nhap(canbo *cb,int n){
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<". Can bo thu "<<i+1<<endl;
		cin.ignore(1);
		cout<<"\t > Ma CB: ";
		cin.getline(cb[i].ma,15);
		cout<<"\t > Ho CB: ";
		cin.getline(cb[i].ho,15);
		cout<<"\t > Ten CB: ";
		cin.getline(cb[i].ten,15);
		do{
		cout<<"\t > Luong Thu Nhap: ";
		cin>>cb[i].luong;
		}while(cb[i].luong<=0);
	}
}
void ghitep(canbo *cb,int n)
{
	ofstream tep("D:\\C++\\canbo.inp");
	if(!tep){
		cout<<"=> Khong the mo tep "<<tep<<endl;
		exit(1);
	}
	tep<<"\t\t ----- DANH SACH CAN BO -----\t\t"<<endl;
	tep<<setw(10)<<"MA CB"<<setw(10)<<"HO CB"<<setw(10)<<"TEN CB"<<setw(10)<<"LUONG"<<endl;
	for(int i=0;i<n;i++)
	{
		tep<<setw(10)<<cb[i].ma<<setw(10)<<cb[i].ho<<setw(10)<<cb[i].ten<<setw(10)<<cb[i].luong<<"\n";
	}
	tep.close();
}
main()
{
	int n;
	struct canbo *cb;
	cout<<"Nhap so can bo can lap danh sach: ";
	cin>>n;
	cb=new canbo[n];
	cout<<"\t\t ----- NHAP TT CAN BO ----- \t\t"<<endl;
	  nhap(cb,n);
	  ghitep(cb,n);
	  
}