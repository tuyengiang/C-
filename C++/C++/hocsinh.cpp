#include<iostream.h>
#include<iomanip.h>
#include<fstream.h>
struct hocsinh{
	char mahs[15],tenhs[15],hk[10];
	float tb;
};
void nhap(hocsinh *hs,int n){
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<"Hoc Sinh Thu "<<i+1<<endl;
		cin.ignore(1);
		cout<<"\t > Ma Hs: ";
		cin.getline(hs[i].mahs,15);
		cout<<"\t > Ten Hs: ";
		cin.getline(hs[i].tenhs,15);
		do{
		   cout<<"\t > DTB: ";
		   cin>>hs[i].tb;	
		 }while(hs[i].tb<=0);
	    cout<<"\t > Hanh kiem: ";
	    cin.getline(hs[i].hk,10);
	}
}
void ghitep(char hsinh[],int n)
  {
  	hocsinh hs1[n];
  	ofstream tep("D:\\C++\\hocsinh.inp",ios::binary);
  	if(!tep)
	  {
  		cout<<"=> Khong mo duoc tep"<<tep<<endl;
  		exit(1);
  	}
  	tep.write((char*)&hs1,sizeof(hocsinh)*n);
  	tep.close();
  }
void xuat1(hocsinh hs){
	cout<<setw(10)<<hs.mahs<<setw(10)<<hs.tenhs<<setw(10)<<hs.tb<<setw(10)<<hs.hk<<setw(10)
	<<"\n";
}
void xuat(hocsinh *hs, int n){
	cout<<setw(10)<<"MA HS"<<setw(10)<<"TEN HS"<<setw(10)<<"DIEM TB"<<setw(10)<<"HANH KIEM"<<setw(10)
	<<endl;
	for(int i=0;i<n;i++)
	{
		xuat1(hs[i]);
	}
}
void doctep(char hsinh[],int n)
{
	int hs[n];
	ifstream tep("D:\\C++\\hocsinh.inp",ios::binary);
	if(!tep)
	{
		cout<<"=> Khong mo duoc tep"<<tep<<endl;
		exit(1);
	}
	tep.read((char*)&hs,sizeof(hocsinh)*n);
	tep.close();
}
main(){
	int n;
	struct hocsinh *hs;
	char hsinh[100];
	cout<<"Nhap so hoc sinh can lap danh sach: ";
	cin>>n;
	hs=new hocsinh[n];
	cout<<endl;
	cout<<"\t\t ------ NHAP TT HOC SINH ------ \t\t\n";
	  nhap(hs,n);
	  ghitep(hsinh,n);
	  ghitep(hsinh,n);
   cout<<endl;
}