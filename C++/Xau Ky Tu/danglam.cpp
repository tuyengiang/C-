#include<iostream.h>
#include<stdio.h>
#include<math.h>
class timkiem{
	int xval,yval;
	public:
	 void nhap(int,int);
	 void tim(int,int);


};
void timkiem::nhap(int a,int b)
{
	xval=a;
	yval=b;
	cout<<"+ Nhap 2 so: \n";
	cout<<"  > Nhap so 1= "; cin>>xval;
	cout<<"  > Nhap so 2= "; cin>>yval;
}
void timkiem::tim(int a,int b)
{
	int max,min;
	xval+=a; yval+=b;
	max=xval; min=0;
    if(max < yval){
    	max=yval;    
    }
    else min=yval;
    cout<<"+ So lon nhat: "<<max<<endl;
}
main()
{
    timkiem tk;
	int a,b,max,min;
	tk.nhap(a,b);
	tk.tim(a,b);
	return 0;
	
}