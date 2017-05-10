/*Bai 4 Trâ`n Ngo?c Tân
xay dung lop ma tran gom cac thanh phan
DL: So dong, so cot, mang cac phan tu
PT: nhap, in, kiem tra ma tran co la don vi khong
ham mai
nhap ma tran a
thong bao co la ma tran don vi khong
in ma tran
*/



#include<iostream.h>
#include<conio.h>

class matrix
{
	private:
	int t, a;
	float **n;
	public:

	matrix (int r=3,int c=3,float v=0)
	{
                   int i,j;
                   t=r;
                   a=c;

 
 n=new float*[t];
                   float *temp=new float[t*a];
                   for(i=0;i<t;i++)
				   	{
                                      n[i]=temp;
                                      temp+=a;
                                      }

                   for(i=0;i<t;i++)
                    for(j=0;j<a;j++)
                     n[i][j]=v;
		
	}

~matrix()
	{
		for(int i=0;i<a; i++)
                  delete []n[i];
                  delete []n;
                  }
	void nhap();
	void in();
	int ktra();
};

void matrix::nhap()
{
	cout<<"Nhap so hang la:";
	cin>>t;
	cout<<"Nhap so cot la:";
	cin>>a;
	n= new float*[t];
	for (int i=0; i<t; i++)
	n[i]=new float[a];
	for (int i=0; i<t; i++)
	for (int j=0; j<a; j++)
	{
		cout<<"T["<<i<<","<<j<<"]:";
		cin>>n[i][j];
	}
	
}

void matrix::in()
{
	for (int i=0; i<t; i++)
	{
		for (int j=0; j<a; j++)
		{
			cout<<n[i][j]<<"    ";
		}
		cout<<endl;
	}
}


 int matrix::ktra()
{
    int isOK = 0;
    for(int i=0;i<t;i++)
    {
        for(int j=0;j<a;j++)
        {
            if (i == j)  //Xet phan tu thioc duong cheo chinh
            {
                if (n[i][j] == 1) //Neu = 1 OK
                {
                    isOK = 1;
                }
                else // Neu khac 1 thi Not OK, thoat ra lien
                {
                    isOK = 0;
                    break;
                }
            }
            else //Xet cac phan tu ko thuoc duong cheo chinh
            {
                if (n[i][j] == 0) // =0 thi OK
                {
                    isOK = 1;
                }
                else // khac 0 thi Not OK, thoat ra lien;
                {
                    isOK = 0;
                    break;
                }
            }
        }
    }
    return(isOK);
}
    
void main()
{
	matrix a;
	a.nhap();
	a.in();
	if (a.ktra()==1)
	cout<<"La ma tran don vi!";
	else cout<<"Khong la ma tran don vi!";
}













/*

if(m==n) 
    { 
                tong=0;tich=1; 
               for(i=0;i<n;i++) 
               for(j=0;j<n;j++) 
               { 
                               
                               tong+=a[i][j]; 
                               tich*=a[i][i]; 
               } 
                
               if((tong==n)&&(tich==1)) 
               printf("\n Day la ma tran don vi"); 
    } 
else 
    printf("\n day khong phai la ma tran don vi");     
        
    
    int laMatranDonVi(int A[10][10], int n)
{
    int isOK = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if (i == j)  //Xet phan tu thioc duong cheo chinh
            {
                if (A[i][j] == 1) //Neu = 1 OK
                {
                    isOK = 1;
                }
                else // Neu khac 1 thi Not OK, thoat ra lien
                {
                    isOK = 0;
                    break;
                }
            }
            else //Xet cac phan tu ko thuoc duong cheo chinh
            {
                if (A[i][j] == 0) // =0 thi OK
                {
                    isOK = 1;
                }
                else // khac 0 thi Not OK, thoat ra lien;
                {
                    isOK = 0;
                    break;
                }
            }
        }
    }
    return(isOK);
}*/
