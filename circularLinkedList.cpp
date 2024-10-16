#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* next;
};
struct node* create(struct node* start){
    struct node* newnode,*ptr;
    int num;
    cout<<"Enter -1 for ending the loop\n";
    cout<<"Enter a number = ";
    cin>>num;
    while(num!=-1){
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=num;
        newnode->next=NULL;
        if(start==NULL){
            start=newnode;
            ptr=start;
        }
        else{
            if(ptr->next!=NULL)
            ptr=ptr->next;
            ptr->next=newnode;
        }
        newnode->next=start;
        cout<<"Enter a number = ";
        cin>>num;
    }
    return start;
}
void display(struct node* start){
    struct node* ptr;
    ptr=start;
    do {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != start);
}
int main(){
    struct node* start=NULL;
    start=create(start);
    display(start);
    return 0;
}