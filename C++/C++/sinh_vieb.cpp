#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<iomanip.h>
#include<fstream.h>
struct sinhvien{
	char msv[15],ten[30],que[30];
};
void doctep(sinhvien *sv, int &n){
	ifstream fi("sinh_vien.inp",ios::binary|ios::in);
	if(!fi){
		cout<<"=> Khong mo duoc tep"<<fi<<endl;
		exit(1);
	}
	fi>>n;
	fi.seekg(sizeof(char)*1,ios::beg);
	for(int i=1;i<=n;i++){
		fi.seekg(sizeof(char)*1,ios::cur);
		fi.getline(sv[i].msv,15);
		fi.ignore(1);
		fi.getline(sv[i].ten,30);
		fi.getline(sv[i].que,30);
	}
	fi.close();
}
main(){
	int n;
	struct sinhvien *sv;
	sv=new sinhvien[100];
	doctep(sv,n);
	cout<<"=> So sv can nhap: "<<n<<endl;
	cout<<"-----------------------------\n";
	cout<<setw(15)<<"MSV"<<setw(15)<<"Ho Ten"<<setw(15)<<"Que Quan"<<endl;
	for(int i=1;i<=n;i++){
		cout<<setw(15)<<sv[i].msv<<setw(15)<<sv[i].ten<<setw(15)<<sv[i].que<<endl;
	}
	
}