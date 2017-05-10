#include<iostream.h>
#include<stddef.h>
#include<math.h>
#include<conio.h>
#include<iomanip.h>
#include<stdio.h>
#include<string.h>
class nguoi{
	char ht[30],scm[30],gt[5];
	public:
	nguoi(){
		strcpy(ht," "); strcpy(scm,""); strcpy(gt,"");
	}
	nguoi(char t[30],char s[30],char g[3]){
	    strcpy(ht,t); strcpy(scm,s); strcpy(gt,g);
	}
	~ nguoi(){	}
	void nhap();
	void in();	
};
void nguoi::nhap(){
	cin.ignore(1);
	cout<<" + Nhap ho ten: "; cin.getline(ht,30);
	cout<<" + Nhap so chung minh thu: "; cin.getline(scm,30);
	cout<<" + Gioi tinh: "; cin.getline(gt,5);
}
void nguoi::in(){
	cout<<setw(10)<<ht<<setw(10)<<scm<<setw(10)<<gt;
}
class hs:public nguoi{
	char cn[20];
	float dtk;
	public:
	hs(){
		strcpy(cn,"");
		dtk=1;
	}
	hs(char n[20],float diem){
		strcpy(cn,n);
		dtk=diem;
	}
	~hs(){}
	void nhap();
	void in();
	void xeploai();
    double DTKET()
    {
  	return dtk;
    }
	friend bool operator >(hs &a, hs &b);	
};
void hs::nhap(){
	nguoi::nhap();
	cout<<" + Nhap nganh: "; 
	    cin.getline(cn,20);
	cout<<" + Nhap diem TK: ";
	    cin>>dtk;
}
void hs::in(){
	nguoi::in();
	cout<<setw(10)<<cn<<setw(10)<<dtk<<endl;
}
void hs::xeploai(){
	if(dtk<=7.9){
		cout<<" Kha \n";
	}
	else{
		cout<<" Gioi\n";
	}
	if(dtk<=4.9){
		cout<<" Yeu \n";
	}
}
friend bool operator >(hs &a, hs &b){
	if(a.dtk>b.dtk){
		return true;
	}
	else{
		return false;
	}
}
int main(){
	hs hs[50];
	int n;
	cout<<"+ n= ";
	cin>>n;
	for(int i=0;i<n;i++){
	  cout<<"Thong tin hoc sinh thu "<<i+1<<" la: "<<endl;
	hs[i].nhap();
	}
	cout<<setw(10)<<"Ho Ten"<<setw(10)<<"So CM"<<setw(10)<<"GT"<<setw(10)<<"Nganh"
	<<setw(10)<<"Diem TK"<<endl;
	for(int i=0;i<n;i++){
	hs[i].in();
	}
	for(int i=0;i<n;i++)
	{
		cout<<"+ Hoc sinh thu "<<i+1<<" xep loai: ";
		hs[i].xeploai();
	}
}