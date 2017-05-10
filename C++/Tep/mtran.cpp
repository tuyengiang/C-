#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
#include<math.h>
#include<fstream.h>
int a[10][10],m,i,j;
float s,k;
void doctep()
{
	ifstream fi("matran.inp",ios::in);
	if(!fi)
	{
		cout<<"=> Khong mo duoc tep"<<endl;
		exit(1);
	}
	fi>>m;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			fi>>a[i][j];
		}
		cout<<endl;
	}
	fi.close();
}
void ghitep()
{
	int snt[10][10],c,d;
	ofstream fo("matran.out",ios::out);
	if(!fo)
	{
		cout<<"=> Khong mo duoc tep"<<endl;
		exit(1);
	}
	// so nguyen to
	for(int i=0;i<m;i++)
	for(int j=0;j<m;j++)
	{
		if(a[i][j]%i==0 && a[i][j]%j==0)
		 {
 			snt[d][c]=a[i][j];
 			d++;c++;
 		}
	}
	int max=snt[0][0];
	for(int i=0;i<d;i++)
	for(int j=0;j<c;j++)
	{
		if(snt[d][c]>max)
	     max=snt[d][c];
	}
	fo<<max<<endl;
	// tong duong cheo chinh
   s=0;
   for(i=0;i<m;i++){
   	 s+=float(a[i][i]);
   }
   fo<<s<<endl;
   // tong duong cheo phu
    k= 0;
   for(i=0; i<m;i++){
   	 for(j=0; j<m;j++){
 	   	if(i+j==m)
			k=k+a[i][j];
 	   }
   	}
   fo<<k<< endl;
   fo.close();
   
}
main()
{
	doctep();
	cout<<m<<endl;
    for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<setw(10)<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	ghitep();
	cout<<endl;
}
