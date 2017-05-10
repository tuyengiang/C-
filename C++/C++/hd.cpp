#include <stdio.h>
#include <conio.h>
#include <string.h>
 
// Dinh nghia cau truc luu tru thong tin sinh vien.
struct SinhVien
{
   char Ma[7];
   char Ten[31];
   char Lop[7];
   float Diem;
};
 
// Khai bao mang de luu tru danh sach sinh vien.
struct SinhVien sv[25];
int n = 0; // Bien luu tru so sinh vien hien tai.
 
// Ham thuc hien in Menu.
int HienThiMenu()
{
   printf("CAC CHUC NANG CHINH CUA CHUONG TRINH\n");
   printf("1. Nhap danh sach thong tin sinh vien\n");
   printf("2. In danh sach thong tin sinh vien\n");
   printf("3. Tim kiem thong tin sinh vien\n");
   printf("4. In danh sach sinh vien thi do\n");
   printf("5. Thoat khoi chuong trinh\n");
   printf("Ban chon: ");
   int chon;
   scanf("%d",&chon);
   return chon;
}
 
// Ham nhap danh sach sinh vien.
void NhapDanhSachSinhVien()
{
    printf("\n----------------------\n");
   printf("NHAP DANH SACH SINH VIEN\n");
   printf("=====================\n");
 
   // Nhap danh sach sinh vien.
   do
   {
      printf("Nguoi thu %d:\n",n+1);
      printf("\tMa: ");
      fflush(stdin);
      gets(sv[n].Ma);
      // Neu Ma la khoang trang thi dung ko nhap tiep.
      // Ma la khoang trang neu do dai cua Ma la 0.
      if (strlen(sv[n].Ma)==0)
      {
        break;
      }
      printf("\tTen: ");
      fflush(stdin);
      gets(sv[n].Ten);
      printf("\tLop: ");
      fflush(stdin);
      gets(sv[n].Lop);
      printf("\tDiem: ");
      scanf("%f",&sv[n].Diem);
      n++;
   }
   while (1==1);
}
 
// Ham in danh sach sinh vien.
void InDanhSachSinhVien()
{
    printf("\n-----------------\n");
   printf("DANH SACH SINH VIEN\n");
   printf("-------------------\n");
 
   printf("%-14s %-25s %-8s  Diem\n","Ma sinh vien", "Ten sinh vien", "Lop");
   for (int i=0; i<n; i++)
   {
        printf("%-14s %-25s %-8s  %.1f\n",sv[i].Ma, sv[i].Ten, sv[i].Lop, sv[i].Diem);
   }
 
   printf("\nBam ENTER de tiep tuc");
   getch();
}
 
// Ham tim kiem.
void TimKiem()
{
    printf("\n----------------\n");
   printf("TIM KIEM THONG TIN\n");
   printf("------------------\n");
   printf("Kieu tim kiem (0 - Tim kiem theo ma, 1 - Tim kiem theo ten\n");
   printf("Ban chon: ");
   int chon;
   scanf("%d",&chon);
 
   if (chon==0)
   {
    char Ma[7];
      printf("Ma: ");
      fflush(stdin);
      gets(Ma);
 
      struct SinhVien svTimThay;
      int timThay = 0;
      for (int i=0; i<n; i++)
      {
        // Neu Ma nhap trung voi ma cua sinh vien thu i
         // -> Tim thay.
         if (strcmp(Ma,sv[i].Ma)==0)
            {
                svTimThay = sv[i];
            timThay = 1;
            break;
         }
      }
 
      printf("Ket qua tim kiem:\n");
      if (timThay==0)
      {
        printf("Khong tim thay sinh vien nao co ma la [%s]\n",Ma);
      }
      else
      {
            printf("%-14s %-25s %-8s  Diem\n","Ma sinh vien", "Ten sinh vien", "Lop");
            printf("%-14s %-25s %-8s  %.1f\n",svTimThay.Ma, svTimThay.Ten, svTimThay.Lop, svTimThay.Diem);
      }
   }
   else
   {
    char Ten[31];
    printf("Ten: ");
      fflush(stdin);
      gets(Ten);
 
      int timThay = 0;
      printf("Ket qua tim kiem:\n");
      printf("%-14s %-25s %-8s  Diem\n","Ma sinh vien", "Ten sinh vien", "Lop");
      for (int i=0; i<n; i++)
      {
        // Neu Ten nhap trung voi Ten cua sinh vien thu i
         // -> Tim thay.
         if (strcmp(Ten,sv[i].Ten)==0)
            {
            timThay = 1;
            printf("%-14s %-25s %-8s  %.1f\n",sv[i].Ma, sv[i].Ten, sv[i].Lop, sv[i].Diem);
         }
      }
 
      if (timThay==0)
      {
        printf("Khong tim thay sinh vien nao co ten la [%s]\n",Ten);
      }
   }
 
   printf("\nBam ENTER de tiep tuc");
   getch();
}
 
// Ham in danh sach sinh vien thi do.
void InDanhSachSinhVienThiDo()
{
    printf("\n------------------------\n");
   printf("DANH SACH SINH VIEN THI DO\n");
   printf("--------------------------\n");
 
   printf("%-14s %-25s %-8s  Diem\n","Ma sinh vien", "Ten sinh vien", "Lop");
   for (int i=0; i<n; i++)
   {
    if (sv[i].Diem>=10)
      {
            printf("%-14s %-25s %-8s  %.1f\n",sv[i].Ma, sv[i].Ten, sv[i].Lop, sv[i].Diem);
      }
   }
 
   printf("\nBam ENTER de tiep tuc");
   getch();
}
 
main()
{
    int chon;
   do
   {
    chon = HienThiMenu();
    switch (chon)
    {
        case 1:
            NhapDanhSachSinhVien();
            break;
        case 2:
            InDanhSachSinhVien();
            break;
        case 3:
            TimKiem();
            break;
        case 4:
            InDanhSachSinhVienThiDo();
            break;
      }
    }
   while (chon!=5);
}