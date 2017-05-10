#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<math.h>
int n;
int menu()
{
	int chon=0;
	cout<<"|___________Menu Chuong___________|\n";
	cout<<"|1 |Chuong 1| Trung sinh          |\n";
	cout<<"|--|--------|---------------------|\n";
	cout<<"|2 |Chuong 2|                     |\n";
	cout<<"|--|--------|---------------------|\n";
	cout<<"|3 |Chuong 3|                     |\n"; 
	cout<<"|--|--------|---------------------|\n";
	cout<<"Moi ban nhap chuong: "; cin>>chon;
	cout<<endl;
	return chon;
}
void chuong1(){
	cout<<"\t\t\t CHUONG I: TRUNG SINH\n";
	cout<<"Giang mai yeu trang\n"<<"suot doi suot kiep\n"<<"khong bao h sieu long\n";
    cout<<"|---------------------------------|\n"
	    <<"| Moi ban chon chuong de doc tiep |\n"
        <<"|---------------------------------|\n"
        <<endl<<endl<<endl;
}
void chuong2(){
	cout<<"Anh yeu em\n";
}
void chuong3(){
	cout<<"Anh yeu em\n";
}
int main()
{
	int chon;
  do
   {
   chon=menu();
  switch(chon)
  {
  	case 1:
  	    chuong1();
  	    break;
    case 2:
  	    chuong2();
    case 3:
  	    chuong3();
  }
   }while(chon!=4);

}
