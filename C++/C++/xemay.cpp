#include<iostream.h>
#include<fstream.h>
#include<iomanip.h>
struct xemay{
	char maxe[15],tenxe[30],hang[15],mauxe[15];
	float giaban;
};
void nhap (xemay *x,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<". Xe may thu "<<i+1<<endl;
		cin.ignore(1);
          cout<<"\t > Ma Xe: ";
          cin.getline(x[i].maxe,15);	
		cout<<"\t > Ten Xe: ";
		cin.getline(x[i].tenxe,30);
		cout<<"\t > Hang Xe: ";
		cin.getline(x[i].hang,15);
		cout<<"\t > Mau xe: ";
		cin.getline(x[i].mauxe,15);
		do{
		   cout<<"\t > Gia Ban: ";
	  	   cin>>x[i].giaban;
		  }while(x[i].giaban<0);
	}
	cin>>x[i].maxe>>"\t";
}
void ghitep (char xe[], int n)
{
	xemay x1[n];
	ofstream tep("D:\\C++\\xemay.inp",ios::binary);
	if(!tep)
	{
		cout<<"=> Khong mo duoc tep"<<tep<<endl;
		exit(1);
	}
	tep.write((char*)&x1,sizeof(xemay)*n);
	tep.close();
}
void xuat1(xemay x){
	cout<<setw(10)<<x.maxe<<setw(10)<<x.tenxe<<setw(10)<<x.hang<<setw(10)<<x.mauxe<<setw(10)
	<<x.giaban<<setw(10)<<"\n";
}
void xuat (xemay *x,int n){
	cout<<setw(10)<<"MA XE"<<setw(10)<<"TEN XE"<<setw(10)<<"HANG XE"<<setw(10)<<"MAU XE"<<setw(10)
	<<"GIA BAN"<<setw(10)<<endl;
	for(int i=0;i<n;i++)
	{
		xuat1(x[i]);
	}
}
void doctep(char xe[], int n)
{
	xemay x[n];
	ifstream tep("D:\\C++\\xemay.inp",ios::binary);
	if(!tep)
	{
		cout<<"=> Khong mo duoc tep"<<tep<<endl;
		exit(1);
	}
	tep.read((char*)&x,sizeof(xemay)*n);
	tep.close();
}
void sapxep(xemay *x, int n){
	xemay tg;
	for(int i=0;i<n-1;i++)
	for(int j=i+1;j<n;j++)
	   if(x[i].giaban<x[j].giaban)
    {
    	tg=x[i];
    	x[i]=x[j];
    	x[j]=tg;
    }
    cout<<setw(10)<<"MA XE"<<setw(10)<<"TEN XE"<<setw(10)<<"HANG XE"<<setw(10)<<"MAU XE"<<setw(10)
	<<"GIA BAN"<<setw(10)<<endl;
	for(int i=0;i<n;i++)
	{
		xuat1(x[i]);
	}
}
void tim(xemay *x,int n)
{
	for(int i=0;i<n;i++)
	 {
	 if(strcmp(x[i].hang,"honda")==0&&strcmp(x[i].mauxe,"vang")==0)
	 if(strcmp(x[i].tenxe,"yamaha")==0&&x[i].giaban<=20000000)
	          xuat1(x[i]);
 		
 	 }
}
main()
{
	int n;
	struct xemay *x;
	char xe[10];
	cout<<"Nhap so xe can lap danh sach: ";
	cin>>n;
	x=new xemay[n];
	cout<<"----------------------------------"<<endl;
	cout<<endl;
	cout<<"\t\t ------ NHAP TT XE MAY ------\t\t"<<endl;
	  nhap(x,n);
	  ghitep(xe,n);
	  doctep(xe,n);
    cout<<endl;
    cout<<"\t\t ------DANH SACH XE MAY ------ \t\t"<<endl;
      xuat(x,n);
    cout<<"\t\t ------ DANH SACH XE THEO GIA BAN ------ \t\t"<<endl;
      sapxep(x,n);
    cout<<endl;
    cout<<"\t\t ------ DANH SACH XE DUOC TIM KIEM ------ \t\t"<<endl;
      tim(x,n);
    cout<<endl;
    
    
}