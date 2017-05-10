#include<iostream.h>
#include<conio.h>
int main()
{
	int m,n,logic;
	cout<<"> Nhap m: "; cin>>m;
	cout<<"> Nhap n: "; cin>>n;
	logic=0;
	for(int i=1;i<m;i++)
	{
		if(m%i==0)
		   logic==1;
        if(logic==0){
        	cout<<"=> "<<m<<" La so nguyen to."<<endl;
        	
        	
        }
        else
           {
		   cout<<"=> "<<m<<" Khong la so nguyen to."<<endl;
        }
        int i=2;
        cout<<"Phan tich so "<<m<<"= ";
	   while(i <= m)
        {
 	
            if(m % i == 0)
	  	     {
             	cout<<i;
             		m/= i;
             	if(m != 1)
			 	cout<<"*";
             }
        	else i++;
        }
        	break;
        	
        	cout<<endl;
        
    }


	logic=0;
	for(int j=1;j<n;j++)
	{
		if(n%j==0)
		   logic==1;
        if(logic==0){
        	cout<<"=> "<<n<<" La so nguyen to."<<endl;
        }
        else{
           cout<<"=> "<<n<<" Khong la so nguyen to."<<endl;
           int j=2;
           cout<<"Phan tich so "<<n<<": ";
		while(j <= n)
        {
            if(n % j == 0)
	  	     {
             	cout<<j;
             		n /= j;
             	if(n != 1)
			 	cout<<"*";
             }
        	else j++;
        }
        	cout<<endl;
        	break;
        }

     }
}



