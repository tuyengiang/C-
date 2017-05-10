#include<iostream.h>
#include<conio.h>
#include<string.h>

class nguoi
{
	private:
	char hoten[50];
	public:
	nguoi(char *ht)
	{
		strcpy(hoten,ht);		
	}
	virtual int duockhenthuong()=0;
	virtual void xuat()
	{
		cout<<"Ho ten:"<<hoten<<endl;
	}
};

class sinhvien:public nguoi
{
	private:
	float dtb;
	public:
	sinhvien(char *ht, float dtb1):nguoi(ht)
	{
		dtb=dtb1;
	}
	virtual int duockhenthuong()
	{
		return (dtb>8?1:0);
	}
	virtual void xuat()
	{
		nguoi::xuat();
		cout<<endl<<"Diem trung binh!"<<dtb<<endl;				
	}	
};
class giangvien: public nguoi
{
	private:
	int sbb;
	public:
	giangvien(char *ht, int sbb1):nguoi(ht)
	{
		sbb=sbb1;
	}
	virtual int duockhenthuong()
	{
		return sbb>3?1:0;
	}
	virtual void xuat()
	{
		nguoi::xuat();
		cout<<endl<<"SBB"<<sbb<<endl;
	}
};

void main()
{
	nguoi *a[100];
	int chon, k=0;
	while(1)
	{
		cout<<"1. Nhap sinh vien"<<endl;
		cout<<"2. Nhap giang vien"<<endl;
		cout<<"3. Thoat"<<endl;
		cin>>chon;
		if (chon==1)
		{ 
			char hoten[50];
			float dtb;
			cin.ignore(1);
			cout<<"Nhap ten sinh vien";
			cin.getline(hoten,50);
			cout<<"Nhap diem trung binh:";
			cin>>dtb;
			a[k++]=new sinhvien(hoten,dtb);
		}
		else if(chon==2)
		{
			char hoten1[50];
			int sbb1;
			cin.ignore(1);
			cout<<"Nhap ten giang vien";
			cin.getline(hoten1,50);
			cout<<"SBB";
			cin>>sbb1;
			a[k++]=new giangvien(hoten1, sbb1);
		}
		else 
		if (chon==3)
			break;
			
	}
	cout<<"Danh sach duoc khen thuong la:";
	for(int i=0; i<k; i++)
	if(a[i]->duockhenthuong())
	a[i]->xuat();
}

