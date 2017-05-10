#include<iostream.h>

template <class T>
class hcn
{
	private:
	T dai, rong;
	public:
	hcn()
	{
		dai=0; 
		rong=0;
	}
	~hcn(){}
	void nhap()
	{
		cout<<"Chieu dai";
		cin>>dai;
		cout<<"Chieu rong";
		cin>>rong;
	}
	
	void in()
	{
		cout<<"Chieu dai="<<dai<<endl;
		cout<<"Chieu rong="<<rong<<endl;
	}
	
	float chuvi()
	{
		return (dai+rong)*2;
	}
};

void main()
{
	hcn <int> h1;
	hcn <float> h2;
	cout<<"Hinh 1:"<<endl;
	h1.nhap();
	cout<<"Hinh 2:";
	h2.nhap();
	if(h1.chuvi()>h2.chuvi())
	{
		cout<<"Hinh chu nhat co chu vi lon hon la:";
		h1.in();
	}
		
	else 
	{
		cout<<"Hinh chu nhat co chu vi lon hon la:";
		h2.in();
	}
		
}
