#include<iostream.h>
#include<conio.h>
#include<math.h>
void nhap(int a[],int n)
{ 
    int i;
	cout<<"+ Nhap phan tu cua mang: \n";
	for(int i=1;i<n;i++)
	{
		cout<<"   > a["<<i<<"]= "; cin>>a[i];
	}
}
int sapxep(int a[],int n)
{
	int tg,j;
	for(int i=1;i<n-2;i++)
	for(int j=i+2;j<n;j++)
	  if(a[i]<a[j])
    {
    	tg=a[i];
    	a[i]=a[j];
    	a[j]=tg;
    }
    cout<<"=> Sap xep tang dan cua mang: ";
	for(int i=1;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
int ktra(int so)
{
	int dem=0,i=0;
	for(int i=1;i<so;i++)
	{
		if(so%i==0)
		  dem+=1;
        if(dem==1)
          return 1;
    	else return 0;
        
	}
}
int maxnt(int a[],int n)
{
	int max=0,i;
	for(int i=1;i<=n;i++)
	{
	  if(ktra(a[i])==1)
	    max=a[i];
		break;	
	}
	for(int i=1;i<n;i++)
	{
		if(ktra(a[i])==1 && a[i]>max)
		  max==a[i];
		  return max;
	}
}
int main(){
 	int a[100],n;
 	cout<<"+ Nhap n: "; cin>>n;
 	nhap(a,n);
 	cout<<"----- In Ket Qua ----- \n";
 	sapxep(a,n);
 	cout<<endl;
	if(maxnt(a,n)!=0)
	{
	 cout<<"=> So nguyen to lon nhat: "<<maxnt(a,n)<<endl;	
	}
}

