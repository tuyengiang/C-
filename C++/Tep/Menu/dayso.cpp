#include<iostream.h>
#include<iomanip.h>
#include<math.h>
#include<conio.h>
#include<fstream.h>

void menu()
{
	cout<<"---------Menu---------\n";
	cout<<"1. Xuat mang trong tep\n";
	cout<<"2. Dem so trung nhau trong mang\n";
	cout<<"3. Tim so long nhat trong mang a va b\n";
	cout<<"4. Tim max A co xuat hien trong B khong\n";
	cout<<"5. tinh A+B\n";
}
void doctep(int *a,int *b,int m,int n)
{
	ifstream fi("dayso.inp",ios::in);
	fi>>m>>n;
	for(int i=0;i<m;i++)
	{
	   fi>>a[i];
	}
	for(int j=0;j<n;j++)
	{
	   fi>>b[j];
	}
	fi.close();	
}
void xuat(int a[100],int b[100],int m,int n)
{
	cout<<"=> Sau khi doc tep: \n";
	doctep();
	cout<<m<<" "<<n<<endl;
		   for(int i=0;i<m;i++)
			{
	   			cout<<a[i]<<" ";
		    }
		    cout<<endl;
		   for(int j=0;j<n;j++)
			{
	          cout<<b[j]<<" ";
	        }
	        cout<<endl;
}
void demt()
{
	int dem=0;
	ofstream fo("dayso.out",ios::out);
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)
	{
		if(a[i]==b[j])
		  dem+=1;
	}
	fo<<dem<<endl;
	fo.close();
	
}
void maxab()
{
	int maxa=a[0],maxb=b[0];
	ofstream fo("dayso.out",ios::out);
	for(int i=0;i<m;i++)
	{
		if(a[i]>maxa)
		   maxa=a[i];
	}
	for(int j=0;j<n;j++)
	{
		if(b[j]>maxb)
		   maxb=b[j];
	}
	fo<<maxa<<" "<<maxb<<endl;
	fo.close();
}
void tim()
{
	int max1=a[0],vt=0;
	ofstream fo("dayso.out",ios::out);
	for(int i=0;i<m;i++)
	{
		if(max1<a[i])
		  max1=a[i];
	}
	for(int j=0;j<n;j++)
	{
		if(max1==b[j]){
			vt=j;
			fo<<j<<endl;
		}
	}
}
void tong()
{
	int s1=0,s2=0,s=0;
	ofstream fo("dayso.out",ios::out);
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		s1+=a[i];
	    s2+=b[j];
	    s=s1+s2;
	}
	
}

main()
{
    int a[100],b[100],m,n;
    int chon,c;
	cout<<"*** Chu y: - Tep (dayso.inp) and (days.out) luu cung thu muc.\n";
	cout<<"           - Va bai lam thao tren tep\n";
	cout<<"           - Muon thay doi tinh toan thi thay doi o tep (dayso.inp)\n";
    menu();
    cout<<endl;
	chon=c;
	cout<<"=> Moi ban nhap: "; cin>>c;
	switch(chon)
	{
		case 1: cout<<"Xuat tep"<<endl;
		   cout<<xuat(a,b,m,n);
	        break;
        case 2: cout<<"Dem so trung nhau trong mang\n";
           demt();
           break;
        case 3: cout<<"Tim max A va B\n";
           maxab(); break;
        case 4: cout<<"Tim Max A va vi tri cuat hien trong B \n";
           tim(); break;
        case 5: cout<<"Tinh tong A+B\n";
           tong(); break;
	};
}

