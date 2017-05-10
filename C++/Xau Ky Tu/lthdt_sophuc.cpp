#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<stddef.h>
#include<iomanip.h>
class complex{
	private:
	 float a,b;
    public:
     void nhap(){
   		 cout<<"  * So phuc:\n";
	     cout<<"\t> Nhap phan thuc: "; cin>>a;
	     cout<<"\t> Nhap phan ao: "; cin>>b;
   	 }
     void xuat(){
   		cout<<"\t=> So phuc: "<<a<<" + "<<b<<"i"<<"\n";
   	 }
     friend complex tong(complex c1, complex c2){
     	complex c;
     	c.a=c1.a+c2.a;
     	c.b=c1.b+c2.b;
     	cout<<"\t=> Tong so phuc: "<<c.a<<" + "<<c.b<<"i\n";
     	return c;
     }
     friend complex hieu(complex c1, complex c2){
	   	complex c;
	   	c.a=c1.a+c2.a;
     	c.b=c1.b+c2.b;
     	cout<<"\t=> Hieu so phuc: "<<c.a<<" + "<<c.b<<"i\n";
     	return c; 		
     }
	  friend complex tich(complex c1, complex c2){
   		complex c;
   		c.a=(c1.a*c2.a)-(c1.b*c2.b);
   		c.b=(c1.b*c2.a)+(c1.a*c2.b);
   		cout<<"\t=> Tich so phuc: "<<c.a<<" + "<<c.b<<"i\n";
   		return c;
   	 }	   
};

int main()
{
	complex c1,c2;
	cout<<"+ Nhap so phuc: \n";
	  c1.nhap();
	  c2.nhap();
    cout<<"+ So phuc vua nhap: \n";
      c1.xuat();
      c2.xuat();
    cout<<"+ Ket qua khi tinh toan \n";
       tong(c1,c2);
       hieu(c1,c2);
       tich(c1,c2);
    cout<<endl;
    cout<<"\t \3\3\3 The End \3\3\3 \t\t\n";
	return 0;
}