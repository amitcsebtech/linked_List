#include<bits/stdc++.h>
using namespace std;
struct node{
    struct node* prev;
    int data;
    struct node* next;
};
struct node* create(struct node* start){
struct node* newnode,*ptr;
int num;
cout<<"Enter -1 for exit the loop\n";
cout<<"Enter a number =";
cin>>num;
while(num!=-1){
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    if(start==NULL){
        newnode->prev=NULL;
        newnode->next=NULL;
        start=newnode;
        ptr=start;
    }
    else{
        if(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=newnode;
        newnode->prev=ptr;
        newnode->prev=NULL;
    }
    cout<<"Enter a number = ";
    cin>>num;
}
return start;
}
void display(struct node* start){
    struct node* ptr;
    ptr=start;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }

}
int main(){
 struct node* start=NULL;
 start=create(start);
 display(start);
    return 0;
}