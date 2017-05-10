#include"iostream"
#include"stdlib.h"
#include"ctime"
#include"Windows.h"
using namespace std;
//Cu?ng Ph?m 16520157 !
int main()
{
	int a=1,b=3,nguoi,may;
	char x;
	cuongpham:
	cout<<"-----------------MENU---------------------"<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"1.Play \3 \3 \3 "<<endl;
	cout<<endl;
	cout<<"2.Huong dan choi !"<<endl;
	cout<<endl;
	cout<<"3.Thoat \6!"<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"------------------(^-^)--------------------"<<endl;
	cin>>x;
	cout<<"\7";
	system("cls");
	if(x=='3')
	{
		cout<<"\3";
		return 0;
	}
	if(x=='2')
	{
		cout<<"Nhan so  hoac chu tuong uong tren ban phim de chon cac lenh tuong ung !"<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<"--------------------------end--------------------------------"<<endl;
		cout<<endl;
		cout<<"Nhan phim q de quay lai , phim x de thoat!"<<endl;
		cin>>x;
		cout<<"\3";
		system("cls");
		if(x=='q'||x=='Q')
		{
			goto cuongpham;
		}
		if(x=='x'||x=='X')
		{
			return 0;
		}
	}
	if(x=='1')
	{
		int n=100;
	  for(int i=1;i<=100;i++)
	  {
		  cout<<"\3 \3 \3 \3 \3 \3 \3 \3 LOADING ";
		  cout<<i<<"%";
		  cout<<"\3 \3 \3 \3 \3 \3 \3 \3";
		  Sleep(60);
		  system("cls");
	  }
	 cuongpham1:
	 cout<<"---------------  HELOO ---------------"<<endl;
	 cout<<"                 (^_^)            "<<endl;
     cout<<endl;
	 cout<<"__________ Xin chao ! Ban co muon choi voi toi khong !__________"<<endl;
     cout<<endl;
	 cout<<"1.Co ! \3 \3 \3 "<<endl;
	 cout<<endl;
	 cout<<"2.Khong \6 \6 \6!"<<endl;
	 cin>>x;
	 cout<<"\7";
	 system("cls");
	 if(x=='2')
	 {
		 cout<<"---------- I LOVE YOU !------------"<<endl;
		 cout<<endl;
		 cout<<endl;
		 cout<<endl;
		 cout<<endl;
		 cout<<endl;
		 cout<<endl;
		 cout<<"Nhan phim 1 de tiep tuc , phim bat ki de thoat !"<<endl;\
	     cin>>x;
		 cout<<"\7";
		 system("cls");
		 if(x=='1')
		 {
			 goto cuongpham1;
		 }
		 else
		 {
			 return 0;
		 }
	 }
	 if(x=='1')
	 {
		 cuongpham2:
		 srand(time(0));
		 may  =1+rand() % 3;
		 cout<<"_________________***(-_-)***_______________"<<endl;
		 cout<<endl;
		 cout<<endl;
		 cout<<"Ban chon gi ? \3 \3 \1  "<<endl;
		 cout<<endl;
		 cout<<"1.Chon  keo  \2 !"<<endl;
		 cout<<endl;
		 cout<<"2.Chon bua  \2 !"<<endl;
		 cout<<endl;
		 cout<<"3.Chon bao  \2 !"<<endl;
		 cin>>nguoi;
		 cout<<"\7";
		 system("cls");
		 int n=2;
		 for(int i=1;i<=n;i++)
		 {
		  cout<<"LOADING ";
		  cout<<"\3";
		  Sleep(1000);
		  cout<<"\3";
		  Sleep(1000);
		  cout<<"\3";
		  Sleep(1000);
		  system("cls");
		 }
		 if(nguoi==1)
		 {
			 cout<<"Ban chon keo  \2 ^^"<<endl;
			 cout<<endl;
		 }
		 if(nguoi==2)
		 {
			 cout<<"Ban chon bua \2 ^^"<<endl;
			 cout<<endl;
		 }
		 if(nguoi==3)
		 {
			 cout<<"Ban chon bao \2 ^^"<<endl;
			 cout<<endl;
		 }
		 if(may==1)
		 {
			 cout<<"Toi ra keo !!!! \1 "<<endl;
			 cout<<endl;
		 }
		 if(may ==2)
		 {
			 cout<<"Toi ra bua !!!! \1"<<endl;
			 cout<<endl;
		 }
		 if(may==3)
		 {
			 cout<<"toi  ra bao !!!! \1 "<<endl;
			 cout<<endl;
		 }
	     if(nguoi==may)
		 {
			 cout<<"Hoa roi ^^ \1 \1 \1  "<<endl;
			 cout<<endl;
		 }
		 if(nguoi==1&&may==2)
		 {
			 cout<<"Toi thang ^^ \1 \1 \1"<<endl;
			 cout<<endl;
		 }
		 if(nguoi==2&&may==1)
		 {
			 cout<<"Ban thang ^^ \1 \1 \1 "<<endl;
			 cout<<endl;
		 }
		 if(nguoi==1&&may==3)
		 {
			 cout<<"Ban thang ^^ \1 \1 \1 "<<endl;
			 cout<<endl;
		 }
		 if(nguoi==3&&may==1)
		 {
			 cout<<"Toi thang ^^ \1 \1 \1"<<endl;
			 cout<<endl;
		 }
		 if(nguoi==2&&may==3)
		 {
			 cout<<"Toi thang ^^ \1 \1 \1"<<endl;
			 cout<<endl;
		 }
		 if(nguoi==3&&may==2)
		 {
			 cout<<"Ban thang ^^ \1 \1 \1"<<endl;
			 cout<<endl;
		 }
         cout<<endl;
		 cout<<endl;
		 cout<<endl;
		 cout<<endl;
		 cout<<endl;
		 cout<<"---------------- (n-_-n) --------------------------"<<endl;
		 cout<<"Nhan phim n de tiep tuc , phim x de thoat ! \2 \2 \2"<<endl;
		 cin>>x;
		 cout<<"\7";
		 system("cls");
		 if(x=='n'||x=='N')
		 {
			 srand(time(0));
			 goto cuongpham2;
		 }
		 else 
		 {
			 cout<<"_____________GOOD LUCK _____________"<<endl;
			 system("pause");
			 return 0;
		 }
	 }
	 }
	system("pause");

}