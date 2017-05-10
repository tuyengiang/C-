#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
 
struct sinhvien
{
    char hoten[30];
    float diemtb;
};
sinhvien sv[30];
 
void nhap(sinhvien sv[],int &n)
{
    int i;
    float diem;
    printf(" Nhap so sinh vien:");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        fflush(stdin);
        printf("\n Ho ten:");
        gets(sv[i].hoten);
        diem=sv[i].diemtb;
        printf(" Diem trung binh:");
        scanf("%f",&diem);
        sv[i].diemtb=diem;
    }
}
 
char*ToWestern(const char*s)
{
    char*ptok,name[30];
    strcpy(name,s);
    char*tmp=(char*)malloc(30);
    tmp[0]='\0';
 
    ptok=strtok( name, " " );
    while ( ptok != NULL )
    {
        strcat( tmp, " ");
        strcat( tmp, strrev( ptok ) );
        ptok=strtok( NULL, " " );
    }
    strrev( tmp );
    return tmp;
}
 
int NameCmp(char*s1,char*s2 )
{
    return strcmpi(ToWestern( s1 ), ToWestern( s2 ));
}
 
void Swap(sinhvien *a, sinhvien *b)
{
    sinhvien tmp=*a;
    *a=*b;
    *b=tmp;
}
 
void BubbleSort(sinhvien a[],int n)
{
    for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
    if (NameCmp( a[j].hoten, a[i].hoten ) < 0)
    Swap(a+i,a+j);
    //else if (NameCmp( a[j].hoten, a[i].hoten ) == 0)
    //hoan vi theo diem
}
 
void hienthi(sinhvien sv[],int n)
{
    int i;
    printf("\n                                         Danh sach vua nhap la");
    for (i=0;i<n;i++)
    {
        printf("\n Ho ten:%s",sv[i].hoten);
        printf("\n Diem trung binh:%f\n",sv[i].diemtb);
    }
}
main()
{
    int n;
    nhap(sv,n);
    BubbleSort(sv,n);
    hienthi(sv,n);
    getch();
}