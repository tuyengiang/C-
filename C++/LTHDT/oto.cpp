#include<iostream.h>
#include<stddef.h>
#include<conio.h>
#include<math.h>
#include<iomanip.h>
class oto{
	char hangoto[30],bienso[10];
	int soghe;
	public:
	oto(){
		strcpy(hangoto,""); strcpy(bienso,"");
		soghe=0;
	}
	oto(char h[30],char b[10],int s=1){
		strcpy(hangoto,h);
		strcpy(bienso,b);
		soghe=s;
	}
	~oto(){ }
	friend istream & operator >>(istream &is, oto &ot){
		cout<<"  + Nhap hang oto: "; is.getline(ot.hangoto,30);
		cout<<"  + Bien so oto: "; is.getline(ot.bienso,10);
		cout<<"  + So ghe: "; is>>ot.soghe;
		return is;
	}
	friend ostream & operator <<(ostream &os, oto &ot){
		os<<ot.hangoto<<" "<<ot.bienso<<""<<ot.soghe<<endl;
		return os;
	}
	void nhap();
	void in();
};
void oto::nhap(){
	cout<<" + Nhap hang oto: "; cin>>hangoto;
	cout<<" + Bien So oto: "; cin>>bienso;
	cout<<" + So ghe cua oto: "; cin>>soghe;
}
void oto::in(){
	cout<<setw(10)<<hangoto<<setw(10)<<bienso<<setw(10)<<soghe;
}
class xebus:public oto{
	int sotuyen;
	public:
	xebus(){
		this->sotuyen=1;
	}
	xebus(int st){
		sotuyen=st;
	}
	~xebus(){}
	void nhap();
	void indl();
};
void xebus::nhap(){
	oto::nhap();
	cout<<" + So tuyen: "; cin>>sotuyen;
}
void xebus::indl(){
	oto::in();
	cout<<setw(10)<<sotuyen<<endl;
}
int main(){
    xebus xe[100];
	int n;
	cout<<"+/ N= "; cin>>n;
	for(int i=0;i<n;i++){
		cout<<" > Oto thu "<<i+1<<endl;
		xe[i].nhap();
	}
	cout<<setw(10)<<"Hang Oto"<<setw(10)<<"Bien So"<<setw(10)<<"So Ghe"<<setw(10)<<"So Tuyen"<<endl;
	for(int i=0;i<n;i++){
		xe[i].indl();
	}
}