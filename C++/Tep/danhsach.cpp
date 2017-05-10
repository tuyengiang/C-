#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<alloc.h>
struct node{
	int data;
	node *next;
};
void them(node* &p, int x)
{
	node* newnode;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=x;
	newnode->next=p;
	p=newnode;
}
void in (node *p)
{
	node *temp;
	temp=p;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	};
	cout<<endl;
}
void Freenode (node* &p)
{
	free(p);
}
int IsEmpty(node* phead){
	return (phead==NULL);
}
void DeleteFirst(node* &phead)
{
	node *p;
	if (IsEmpty(phead))
		cout<<"List is empty"<<endl;
	else {
		p= p->next;
		phead = phead->next;
		Freenode(p);
	}
}
void in1 (node *phead)
{
	node *temp;
	temp=phead;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	};
	cout<<endl;
}
main()
{
	int x;
	node* p; p=NULL;
	node *phead; phead=NULL;
	cout<<"+ Nhap x: "; cin>>x;
	cout<<"+ Them x vao danh sach: ";
	 them(p,1);
	 them(p,2);
	 them(p,3);
	 them(p,x);
	 in(p);
    cout<<"+ Ds sau khi xoa ptu cuoi : ";
	 DeleteFirst(phead);
	 in1(phead);
	 
}