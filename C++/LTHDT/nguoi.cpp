/*
Xay dung lop nguoi bao gom thuoc tinh hoten,diachi ,tuoi, xay dung phuong thuc nhap,in dl cho lop.
xay dung lop nam ke thua tu lop nguoi co them thuoc tinh ban,vo,cha
xy dung lp nu co thuoc tinh ban,chong,me. xay dung phuong thuc nhap in dl cho 2 lop tren.*/
#include<iostream.h>
#include<stddef.h>
#include<conio.h>
#include<iomanip.h>
class nguoi{
    public:
         char hoten[30],diachi[30];
		 int tuoi;
		 void nhap();
		 void in();
		 nguoi(){
 			strcpy(hoten,""); strcpy(diachi,""); tuoi=0;
 		 } 
		  nguoi(char ht[30],char dc[30],int t ) {
		 	   strcpy(hoten,ht);
	 		   strcpy(diachi,dc);
	 		   tuoi=t;
  		}  
		  ~nguoi(){}  
};
void nguoi::nhap(){
	cout<<"\t Hoten: "; cin.getline(hoten,30);
	cout<<"\t Dia chi: "; cin.getline(diachi,30);
	cout<<"\t Tuoi: "; cin>>tuoi;
}
void nguoi::in(){
	cout<<setw(15)<<"Hoten"<<setw(15)<<"Diachi"<<setw(15)<<"Tuoi"<<endl;
	cout<<setw(15)<<hoten<<setw(15)<<diachi<<setw(15)<<tuoi<<endl;
}
class nam:public nguoi{
	public:
	  char ban[20],vo[20],cha[20];
      void nhap();
      void in();
};
void nam::nhap(){
  int t;
	nguoi::nhap();
	cout<<"Co ban? 1=Nam| 2=Nu";
	do{
		cin>>t;
		if( t<1|| t>2)
		cout<<"Nhap lai";
	}while(t<1||t>2);
	switch(t){
		case 1: strcpy(ban,"Nam"); break;
		case 2: strcpy(ban,"Nu"); break;
	}
	cout<<"Co vo khong:? 1=co | 2=khong";
	do{
		cin>>t;
		if(t<1||t>2)
		   cout<<"Nhap lai";
	}while(t<1||t>2);
	switch(t){
		case 1: strcpy(vo,"Co vo"); break;
		case 2: strcpy(vo,"Khong vo"); break;
		default: strcpy(vo,NULL);
	}
	cout<<"Co la cha khong:? 1=co | 2=khong";
	do{
		cin>>t;
		if(t<1||t>2)
		   cout<<"Nhap lai";
	}while(t<1||t>2);
	switch(t){
		case 1: strcpy(cha,"La bo "); break;
		case 2: strcpy(cha,"Khong la bo"); break;
		default: strcpy(cha,NULL);
	}	
}
void nam::in(){
	nguoi::in();
	cout<<setw(15)<<"Ban"<<setw(15)<<"Vo"<<setw(15)<<"Cha"<<endl;
	cout<<setw(15)<<ban<<setw(15)<<vo<<setw(15)<<cha<<endl;
	
}
class nu:public nguoi{
	public: 
	char ban[20],chong[20],me[20];
	   void nhap();
	   void in();
};
void nu::nhap(){
	int t;
	nguoi::nhap();
	cout<<"Co ban? 1=Nam| 2=Nu";
	do{
		cin>>t;
		if( t<1|| t>2)
		cout<<"Nhap lai";
	}while(t<1||t>2);
	switch(t){
		case 1: strcpy(ban,"Nam"); break;
		case 2: strcpy(ban,"Nu"); break;
	}
	cout<<"Co chong khong:? 1=co | 2=khong";
	do{
		cin>>t;
		if(t<1||t>2)
		   cout<<"Nhap lai";
	}while(t<1||t>2);
	switch(t){
		case 1: strcpy(chong,"Co chong"); break;
		case 2: strcpy(chong,"Khong co chong"); break;
		default: strcpy(chong,NULL);
	}
	cout<<"Co la me khong:? 1=co | 2=khong";
	do{
		cin>>t;
		if(t<1||t>2)
		   cout<<"Nhap lai";
	}while(t<1||t>2);
	switch(t){
		case 1: strcpy(me,"La me "); break;
		case 2: strcpy(me,"Khong la me"); break;
		default: strcpy(me,NULL);
		void sapxep();
	}
}
void nu::in(){
	nguoi::in();
	cout<<setw(15)<<"Ban"<<setw(15)<<"Vo"<<setw(15)<<"me"<<endl;
	cout<<setw(15)<<ban<<setw(15)<<chong<<setw(15)<<me<<endl;	
}
int main(){
	
}