#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
#include<fstream.h>
#include<math.h>
#include<algorithm>
struct sinhvien{
	char ma[15],ten[50],lop[20];
	float toan,ly,hoa,dtb;
};
int menu()
{
	cout<<"|---|-----------Menu---------------|\n";
	cout<<"| 1 | Xuat DS sinh vien tu tep.    |\n";
	cout<<"|---|------------------------------|\n";
	cout<<"| 2 | Sap xep danh sach sinh vien. |\n";
	cout<<"|---|------------------------------|\n";
	cout<<"| 3 | Sv co diem Tb >8.            |\n";
	cout<<"|---|------------------------------|\n";
	cout<<"| 4 | Sv hoc lop tin 9a5.          |\n";
	cout<<"|---|------------------------------|\n";
	int chon;
	cout<<endl;
	cout<<">>> Moi ban chon: "; cin>>chon;
	return chon;
}
void doctep(sinhvien *sv, int &n)
{
	ifstream fi("sinhvien.inp",ios::in);
	if(!fi)
	{
		cout<<"=> Khong co tep nao duoc mo"<<endl; exit(1);
	}
	fi>>n;
	fi.seekg(sizeof(char)*1,ios::beg);
	for(int i=0;i<n;i++)
	{
		fi.seekg(sizeof(char)*1,ios::cur);
		fi.getline(sv[i].ma,15);
		fi.getline(sv[i].ten,50);
		fi.getline(sv[i].lop,20);
		fi.seekg(sizeof(char)*1,ios::cur);
		fi>>sv[i].toan; 
		fi>>sv[i].ly; 
		fi>>sv[i].hoa;
		sv[i].dtb=(sv[i].toan+sv[i].ly+sv[i].hoa)/3;		
	}
}
void sapxep(sinhvien *sv, int n)
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
    cout<<setw(10)<<"Ma sv"<<setw(15)<<"Ho Ten"<<setw(15)<<"Hoc Lop"<<setw(10)<<"Diem Toan"
    <<setw(10)<<"Diem Ly"<<setw(10)<<"Diem Hoa"<<setw(10)<<"Diem Tb"<<endl;
    for(int i=0;i<n;i++)
    {
     cout<<setw(10)<<sv[i].ma<<setw(15)<<sv[i].ten<<setw(15)<<sv[i].lop<<setw(10)<<sv[i].toan
     <<setw(10)<<sv[i].ly<<setw(10)<<sv[i].hoa<<setw(10)<<sv[i].dtb<<"\n";
    }
  	  
}
void tim(sinhvien *sv,int n)
{
	cout<<setw(10)<<"Ma sv"<<setw(15)<<"Ho Ten"<<setw(15)<<"Hoc Lop"<<setw(10)<<"Diem Toan"
    <<setw(10)<<"Diem Ly"<<setw(10)<<"Diem Hoa"<<setw(10)<<"Diem Tb"<<endl;
	for(int i=0;i<n;i++)
	{
	  if(sv[i].dtb>8.0)
	  {
	    cout<<setw(10)<<sv[i].ma<<setw(15)<<sv[i].ten<<setw(15)<<sv[i].lop<<setw(10)<<sv[i].toan
        <<setw(10)<<sv[i].ly<<setw(10)<<sv[i].hoa<<setw(10)<<sv[i].dtb<<"\n";
	  }
	}
}
void tim2(sinhvien *sv,int n)
{
	cout<<setw(10)<<"Ma sv"<<setw(15)<<"Ho Ten"<<setw(15)<<"Hoc Lop"<<setw(10)<<"Diem Toan"
    <<setw(10)<<"Diem Ly"<<setw(10)<<"Diem Hoa"<<setw(10)<<"Diem Tb"<<endl;
	for(int i=0;i<n;i++)
	{
		if(strcmpi(sv[i].lop,"Tin9a5")==0)
		{
		  cout<<setw(10)<<sv[i].ma<<setw(15)<<sv[i].ten<<setw(15)<<sv[i].lop<<setw(10)<<sv[i].toan
          <<setw(10)<<sv[i].ly<<setw(10)<<sv[i].hoa<<setw(10)<<sv[i].dtb<<"\n";	
		}
	}
}
main()
{
	int n,chon;
	struct sinhvien *sv;
	sv=new sinhvien[100];
	do{
		chon=menu();
		switch(chon)
		{
		 case 1: 
	         doctep(sv,n);
			 cout<<"+ Danh sac sinh vien co: "<<n<<endl;
			 cout<<"\t\t----- Ds Sinh Vien-----\t\t\n";
			 for(int i=0;i<n;i++)
			 {
 				cout<<setw(10)<<sv[i].ma<<setw(15)<<sv[i].ten<<setw(15)<<sv[i].lop<<setw(10)<<sv[i].toan
                <<setw(10)<<sv[i].ly<<setw(10)<<sv[i].hoa<<setw(10)<<sv[i].dtb<<"\n";	
 			 }
 			 break;
 		 case 2:
		     sapxep(sv,n);
			 break;
		 case 3: 
		     tim(sv,n);
			 break;
	     case 4:
		     tim2(sv,n);
			 break; 
		}
	}while(n!=5);
	
}
