#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<fstream.h>
#include<iomanip.h>
struct sinhvien{
	char ten[30],nam[15];
	float toan,ly,hoa;
};
void doctep(sinhvien *sv,int &n){
	ifstream tep("giang.inp",ios::in);
	if(!tep){
		cout<<"khong mo dc tep"<<endl;
		exit(1);
	}
	tep>>n;
	tep.seekg(sizeof(char)*1,ios::beg);
	for(int i=1;i<=n;i++){
		
		tep.getline(sv[i].ten,30);
		tep.ignore(1);
     	tep.getline(sv[i].nam,15);
	    tep>>sv[i].toan;
	     tep>>sv[i].ly;
	    tep>>sv[i].hoa;
	}
	tep.close();
}
main(){
	int n;
	struct sinhvien *sv;
	sv=new sinhvien[100];
	cout<<"+ Sv can nhap ds: ";
	doctep(sv,n);
	cout<<n<<endl;
	for(int i=0;i<n;i++){
		cout<<"| "<<sv[i].ten<<"|"<<sv[i].nam<<"| "<<sv[i].toan<<"| "
	 <<sv[i].ly<<"| "<<sv[i].hoa<<endl;
	}
}