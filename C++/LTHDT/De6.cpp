#include<iostream.h>
#include<stddef.h>
#include<iomanip.h>
#include<math.h>
#include<conio.h>
class Developer{
	char hoten[30];
    int namsinh;
    long luong;
    public:
    Developer(){
    	strcpy(hoten,""); namsinh=1; luong=1;
    }
    Developer(char ht[30],int nam, long l){
    	strcpy(hoten,ht); namsinh=nam; luong=l;
    }
    ~Developer(){}
    void nhap();
    void in();
};
void Developer::nhap(){
	cin.ignore(1);
	cout<<"   > Nhap ho ten: "; cin.getline(hoten,30);
	cout<<"   > Nhap nam sinh: "; cin>>namsinh;
	cout<<"   > Nhap luong: "; cin>>luong;
}
void Developer::in(){
	cout<<setw(10)<<hoten<<setw(10)<<namsinh<<setw(10)<<luong;
}
class Teampled1:public Developer{
	long luongtn;
	public:
	Teampled1(){
		luongtn=1;
	}
	Teampled1(long ln){
		luongtn=ln;
	}
	~Teampled1(){}
	long get_luong(){
		return luong;
	}
	friend ostream & operator <<(ostream &os, Teampled1 &tem){
		tem.in();
		os<<setw(10)<<tem.luongtn<<endl;
		return os;
	}
	friend istream & operator >>(istream &is, Teampled1  &tem){
		tem.nhap();
		cout<<"   > Nhap luong trach nhiem: "; is>>tem.luongtn;
		return is;
	}
	void kiemtra(){
		return luong-luongtn;
	}
};
int main(){
	Teampled1 tem[100];
	int n;
	do{
		cout<<"+ Nhap n= "; cin>>n;
	}while(n<0 || n>100);
	for(int i=0;i<n;i++){
		cout<<"  + Nguoi thu"<<i+1<<endl;
		cin>>tem[i];
	}
	cout<<setw(10)<<"Ho Ten"<<setw(20)<<"Nam Sinh"<<setw(10)<<"Luong"<<setw(10)<<"Luong Trach Nhiem"<<endl;
	for(int i=0;i<n;i++){
		cout<<tem[i];
	}
	return 0;
}