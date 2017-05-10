#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
#include<math.h>
#include<fstream.h>
struct hodan{
	char ma[15],ho[15],ten[15];
	long sodien,tiendien;
};
void ghitep(hodan *hd,char hdan[],int n)
{
	hodan hd1[n];
	ofstream fo("hodan.txt",ios::binary);
	if(!fo)
	{
		cout<<"Khong mo duoc tep"<<endl;
		exit(1);
	}
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<". Ho dan thu "<<i+1<<endl;
		cin.ignore(1);
		cout<<"   > Ma Cong to: "; cin.getline(hd[i].ma,15);
		cout<<"   > Ho ho dan: "; cin.getline(hd[i].ho,15);
		cout<<"   > Ten ho dan: "; cin.getline(hd[i].ten,15);
		cout<<"   > So dien: "; cin>>hd[i].sodien;
		hd[i].tiendien=0;
		if(hd[i].sodien<=50)
		{
			hd[i].tiendien=hd[i].sodien*1200;
		}
		else hd[i].tiendien=(hd[i].sodien-50)*1500+60000;
		if(hd[i].sodien>100)
		{
			hd[i].tiendien=(hd[i].sodien-100)*2000+75000+60000;
		}
	}
	fo.write((char*)hd1,sizeof(hodan)*n);
	fo.close();
}
void xuat1(hodan hd)
{
	cout<<setw(10)<<hd.ma<<setw(10)<<hd.ho<<setw(10)<<hd.ten<<setw(10)<<hd.sodien<<setw(10)<<hd.tiendien<<endl;
}
void xuat(hodan *hd,int n)
{
	cout<<setw(10)<<"Ma"<<setw(10)<<"Ho"<<setw(10)<<"Ten"<<setw(10)<<"So Dien"
	<<setw(10)<<"So Tien"<<endl;
	for(int i=0;i<n;i++)
	{
		xuat1(hd[i]);
		cout<<setw(10)<<"----"<<setw(10)<<"-----"<<setw(10)<<"-----"<<setw(10)<<"-----"
	    <<setw(10)<<"---------"<<endl;
		
	}
}
main()
{
	int n;
	char hdan[101];
	do{
		cout<<"+ Nhap n ho dan: "; cin>>n;
	}while(n<=0||n>=100);
	struct hodan *hd;
	hd=new hodan[101];
	cout<<"\t\t ====== Nhap TT Ho Dan ====== \t\t\n";
	  ghitep(hd,hdan,n);
	  cout<<endl;
    cout<<"\t\t ====== Danh Sach Ho Dan ====== \t\t\n";
      xuat(hd,n);
      cout<<endl;
	
}
