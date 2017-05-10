#include<iostream.h>
#include<math.h>
#include<stddef.h>
#include<conio.h>

class diem
{
public:
    int x,y;
};
class tamgiac:public diem
{
    diem a,b,c;
public:
    void nhap()
    {
        cout<<"  > Nhap xA: ";
        cin>>a.x;
        cout<<"  > Nhap yA: ";
        cin>>a.y;
        cout<<"  > Nhap xB: ";
        cin>>b.x;
        cout<<"  > Nhap yB: ";
        cin>>b.y;
        cout<<"  > Nhap xC: ";
        cin>>c.x;
        cout<<"  > Nhap yC: ";
        cin>>c.y;
    }
    void kiemtra()
    {
        int ab,bc,ac;
        ab=sqrt((a.x-b.x)*(a.x-b.x)+ (a.y-b.y)*(a.y-b.y));
        bc=sqrt((b.x-c.x)*(b.x-c.x) + (b.y-c.y)*(b.y-c.y));
        ac=sqrt((a.x-c.x)*(a.x-c.x)+ (a.y-c.y)*(a.y-c.y));
        if( ab+bc>ac && ab+ac>bc && ac+bc>ab && ab>0 && bc>0 && ac>0)
        {
            cout<<"=> Day la 1 tam giac \n";
        }
        else
        {
            cout<<"=> Khong la tam giac \n";
        }
    }
};
int main()
{
    tamgiac tg;

    cout<<"+ Nhap cac canh cua tam giac: \n";
    tg.nhap();
    cout<<"+ Ket qua kiem tra: \n";
    tg.kiemtra();
    return 0;
}