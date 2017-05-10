#include<iostream.h>
#include<iomanip.h>
#include<string.h>
#include<stdlib.h>

class connguoi
{
	public:
	char hoten[30];
	char diachi[50];
	int tuoi;
	void nhap();
	void in();
};

void connguoi::nhap()
{
	cout<<"\n\t"<<"Ho ten:";
	cin.getline(hoten,30);
	cout<<"\t"<<"Dia chi:";
	cin.getline(diachi,50);
	cout<<"\t"<<"Tuoi:";
	cin>>tuoi;
}

void connguoi::in()
{
cout<<endl<<setw(15)<<"Ho ten"<<setw(15)<<"Dia chi"<<setw(10)<<"Tuoi";
cout<<endl<<setw(15)<<hoten<<setw(15)<<diachi<<setw(10)<<tuoi<<endl;
}

class namgioi:public connguoi
{
	public:
	char ban[20], vo[20], cha[20];
	void nhap();
	void in();
};

void namgioi::nhap()
{
	int t;
	connguoi::nhap();
	cout<<"Co ban? 1=Nam |  2=Nu";
	do
	{
	cin>>t;
	if(t<1 ||t>2) 
	cout<<"Nhap lai!";
	}
	while(t<1 || t>2);	
	switch (t)
	{
		case 1: strcpy(ban,"Nam"); break;
		case 2: strcpy(ban,"Nu"); break;
	}
	
	cout<<"Co vo khong? 1=co |  2=Khong";
	do
	{
	cin>>t;
	if(t<1 ||t>2) 
	cout<<"Nhap lai";
	}
	while(t<1 || t>2);	
	switch (t)
	{
		case 1: strcpy(vo,"Co vo"); break;
		case 2: strcpy(vo,"Khong co vo"); break;
		default : strcpy(vo,NULL);
	}		
	
	cout<<"Co la bo khong? 1=Co |  2=Khong";
	do
	{
	cin>>t;
	if(t<1 ||t>2) 
	cout<<"Nhap lai!";
	}
	while(t<1 || t>2);	
	switch (t)
	{
		case 1: strcpy(cha,"La bo"); break;
		case 2: strcpy(cha,"Khong la bo"); break;
		default : strcpy(cha,NULL);
	}		
}

void namgioi::in()
{

	connguoi::in();
	cout<<setw(15)<<"Ban"<<setw(15)<<"Vo"<<setw(10)<<"Cha";
	cout<<endl<<setw(15)<<ban<<setw(15)<<vo<<setw(10)<<cha<<endl;
}


class nugioi: public connguoi
{
	public:
	char ban[20],chong[20],me[20];
	void nhap();
	void in();
};

void nugioi::nhap()
{
	int t;
	connguoi::nhap();
	cout<<"Co ban? 1=Nam |  2=Nu";
	do
	{
	cin>>t;
	if(t<1 ||t>2) 
	cout<<"Nhap lai!";
	}
	while(t<1 || t>2);	
	switch (t)
	{
		case 1: strcpy(ban,"Nam"); break;
		case 2: strcpy(ban,"Nu"); break;
	}
	
	cout<<"Co chong khong? 1=co |  2=Khong";
	do
	{
	cin>>t;
	if(t<1 ||t>2) 
	cout<<"Nhap lai";
	}
	while(t<1 || t>2);	
	switch (t)
	{
		case 1: strcpy(chong,"Co chong"); break;
		case 2: strcpy(chong,"Khong co chong"); break;
		default : strcpy(chong,NULL);
	}		
	
	cout<<"Co la bo khong? 1=Co |  2=Khong";
	do
	{
	cin>>t;
	if(t<1 ||t>2) 
	cout<<"Nhap lai!";
	}
	while(t<1 || t>2);	
	switch (t)
	{
		case 1: strcpy(me,"La me"); break;
		case 2: strcpy(me,"Khong la me"); break;
		default : strcpy(me,NULL);
	}		
	void sapxep();
}


void nugioi::in()
{
	connguoi::in();
	cout<<setw(15)<<"Ban"<<setw(15)<<"Vo"<<setw(10)<<"Cha";
	cout<<endl<<setw(15)<<ban<<setw(15)<<chong<<setw(10)<<me<<endl;
}



class sinhvien:public nugioi, public namgioi
{
	float tin, toan;
	public:
	void nhap();
	void in();
	float trungbinh()
	{
		return (tin+toan)/2;
	}
	
	void sapxepchung(sinhvien *sv, int n)
	{
		for (int i=0; i<n-1; i++)
			for (int j=i+1; j<n; j++)
				if( sv[i].trungbinh()<sv[i].trungbinh() && sv[i].nugioi::ban==sv[j].nugioi::ban)
				{
					sinhvien tg;
					tg=sv[i];
					sv[i]=sv[j];
					sv[j]=tg;
				}			
	}
};


void sinhvien::nhap()
{
	nugioi::nhap();
	cout<<"Diem Tin";
	cin>>tin;
	cout<<"Diem Toan:";
	cin>>toan;

}

void sinhvien::in()
{
	nugioi::in();
	cout<<setw(15)<<"Diem Tin"<<setw(15)<<"Diem Toan"<<setw(10)<<"Trung binh";
	cout<<endl<<setw(15)<<tin<<setw(15)<<toan<<setw(10)<<trungbinh();
}




int main()
{
	connguoi cn[100];
	namgioi n[100];
	nugioi l[100];
	sinhvien sv[100];
	int t, i=0, j=0, k=0, h=0;	
do{
	cout<<"\n\t 1. Nhap thong tin con nguoi!";
	cout<<"\n\t 2. In thong tin con nguoi!";
	cout<<"\n\t 3. Nhap thong tin nam gioi!";
	cout<<"\n\t 4. In thong tin nam gioi!";
	cout<<"\n\t 5. Nhap thong tin nu gioi!";
	cout<<"\n\t 6. In thong thin nu gioi!";
	cout<<"\n\t 7. Nhap thong tin sinh vien!";
	cout<<"\n\t 8. In thong tin sinh vien!";
	cout<<"\n\t 9. Thoat!";
	cout<<"\n\t 10.Sap xep sinh vien co cung ban";
	cin>>t;
	if(t<1 || t>11)
			cout<<"Nhap lai!";	
	switch (t)
	{		
		case 1: 
		
		system("cls");
		int o;
		cout<<"\n\tNhap so nguoi can them!";
		cin>>o;
		o=o+i;
		for(int x=i; x<o; x++)
		{
			cout<<"\n***********************";
			cout<<"\n\tNhap thong tin nguoi"<<x+1;
			cin.ignore(1);
			cn[x].nhap();
			i++;
		}
		system("pause");
		break;
		
		case 2:
		system("cls");
		cout<<"\n\tThong tin con nguoi!";
		for(int i=0; i<o; i++)
		cn[i].in();
		system("pause");
		break;
		
	
		
		
case 3:
		system("cls");
		int p;
		cout<<"\n\tNhap so nguoi can them!";
		cin>>p;
		p=p+j;
		
		for(int i=j; i<p; i++)
		{
			cout<<"\n***********************";
			cout<<"\n\tNhap thong nam gioi "<<i+1;
			cin.ignore(1);
			n[i].nhap();
			j++;
		}
		system("pause");
		break;		
				
		case 4:
		system("cls");		
		cout<<"so p la:"<<p;
		cout<<"\t\nThong tin nam gioi!";
		for(int x=0; x<p; x++)
		n[x].in();
		system("pause");
		break;		
		
		case 5:
		system("cls");
		int q;
		cout<<"\n\tNhap so nguoi can them!";
		cin>>q;
		q=q+k;
		for(int x=k; x<q; x++)
		{
			cout<<"\n***********************";
			cout<<"\n\tNhap thong nu gioi "<<x+1;
			cin.ignore(1);
			l[x].nhap();
			k++;
		}
		system("pause");
		break;
		
		case 6:
		system("cls");
		cout<<"\t\nThong tin nu gioi!";
		for(int i=0; i<q; i++)
		l[i].in();
		system("pause");
		break;
		
		case 7:
		system("cls");
		int z;
		cout<<"\n\tNhap so sv can them!";
		cin>>z;
		z=z+h;
		for(int x=h; x<z; x++)
		{
			cout<<"\n***********************";
			cout<<"\n\tNhap thong sinh vien "<<x+1;
			cin.ignore(1);
			sv[x].nhap();
			h++;
		}
		system("pause");
		break;
		
		
		case 8:
		system("cls");
		cout<<"\t\nThong tin sinh vien!";
		for(int i=0; i<h; i++)
		sv[i].in();
		system("pause");
		break;
		
	
		case 10:
		system("cls");
		cout<<"Danh sach sinh vien sau khi sap xep la:";
		for(int i=0; i<z; i++)
		sv[i].sapxepchung(sv,z);
		for(int i=0; i<z; i++)
		sv[i].in();
		system("pause");
		break;

		
		case 9:
		exit(1);
		break;
	}
}while(t>0&&t<12);
	
}




