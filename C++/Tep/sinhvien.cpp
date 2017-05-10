#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<math.h>
#include<string.h>
#include<algorithm>
struct sinhvien{
	char ma[15],hoten[30],nt[20],diachi[30],sdt[15],khoa[50];
};
void doctep(sinhvien *sv, int &n)
{
	ifstream fi("sv.inp",ios::in);
	if(!fi)
	{
		cout<<"=> Khong mo duoc tep"<<fi<<endl;
		exit(1);
	}
	fi>>n;
	fi.seekg(sizeof(char)*1,ios::beg);
	for(int i=1;i<=n;i++)
	{
		fi.seekg(sizeof(char)*1,ios::cur);
		fi.getline(sv[i].ma,15);
		fi.getline(sv[i].hoten,30);
		fi.getline(sv[i].nt,20);
		fi.getline(sv[i].sdt,15);
		fi.getline(sv[i].diachi,30);
		fi.getline(sv[i].khoa,50);	
	}
	fi.close();
}

void sapxep(sinhvien *sv, int n)
{
	char *s, *s1;
	sinhvien tg;
	int i,j;
	for(int i=1;i<=n;i++)
	{
		s=strtok(sv[i].hoten," ");
		s=strtok(NULL," ");
		s=strtok(NULL," ");		
	}
	for(int i=1;i<=n-2;i++)
	for(int j=i+2;j<=n;j++)
	  if(strcmp(s,sv[j].hoten)>0);
	  {
  		sv[i]=tg;
  		sv[i]=sv[j];
  		tg=sv[j];
	   }
    for(int i=1;i<=n;i++)
    {
     cout<<"| "<<sv[i].ma<<"|"<<sv[i].hoten<<"| "<<sv[i].nt<<"| "
	 <<sv[i].sdt<<"| "<<sv[i].diachi<<"| "<<sv[i].khoa;	
    }
  		
}
 
main()
{
	int n;
    char name;
	struct sinhvien *sv;
	sv=new sinhvien[200];
	cout<<"+ So sinh vien can lap danh sach: ";
	doctep(sv,n);
	cout<<n;
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
	 cout<<"| "<<sv[i].ma<<"|"<<sv[i].hoten<<"| "<<sv[i].nt<<"| "
	 <<sv[i].sdt<<"| "<<sv[i].diachi<<"| "<<sv[i].khoa;
	 cout<<endl;
	}
	sapxep(sv,n);
}
