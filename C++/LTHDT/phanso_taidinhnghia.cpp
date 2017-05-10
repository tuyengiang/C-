/*
Xay dung lop phan so. tai dinh nghia phep tinh tong,hieu,tich,thuong. Khai bao
phan so p1,p2. in dl lieu tong,hieu,tich,thuong.*/

#include<iostream.h>
#include<math.h>
#include<stddef.h>
#include<conio.h>
class phanso{
	private: 
	   int tu,mau;
    public:
      friend ostream & operator<<(ostream &os, phanso &ps){
      	os<<ps.tu<<"/"<<ps.mau;
      	return os;
      }
      friend istream & operator>>(istream &is, phanso &ps){
      	cout<<"     + Tu= "; is>>ps.tu; cout<<"     + Mau= "; is>>ps.mau;
      	return is;
      }
      phanso operator+(phanso a){
      	phanso p;
      	p.tu=(tu*a.mau)+(mau*a.tu);
      	p.mau=mau*a.mau;
      	
      	return p;
      }
      phanso operator-(phanso a){
      	phanso p;
      	p.tu=(tu*a.mau)-(mau*a.tu);
      	p.mau=mau*a.mau;
      	
      	return p;
      }
      phanso operator*(phanso a){
      	phanso p;
      	p.tu=tu*a.tu;
      	p.mau=mau*a.mau;
      	return p;
      }
      phanso operator /(phanso a){
      	phanso p;
      	p.tu=tu*a.mau;
      	p.mau=mau*a.tu;
      	return p;
      }
};
int main(){
	phanso p1,p2,q;
	cout<<"+ Nhap phan so:\n";
	cout<<"  + Phan so 1: \n"; cin>>p1;
	cout<<"  + Phan so 2: \n"; cin>>p2;

	cout<<"+ Ket qua tinh toan: \n";
	cout<<"   > Tong 2 so phuc: ";
	  q=p1+p2; 
	  cout<<p1<<" + "<<p2<<"= "<<q<<endl;
	  q=p1-p2;
	cout<<"   > Hieu 2 so phuc: "; 
      cout<<p1<<" - "<<p2<<"= "<<q<<endl;
      q=p1*p2;
	cout<<"   > Tich 2 so phuc: "; 
	   cout<<p1<<" * "<<p2<<"= "<<q<<endl;
      q=p1/p2;
	cout<<"   > Thuong 2 so phuc: "; 
	   cout<<p1<<" / "<<p2<<"= "<<q<<endl;
    cout<<"\t\t \3\3\3 \t\t\n";
	return 0;
}