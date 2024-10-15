#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* next;
};
struct node* start=NULL;
struct node* create(struct node* start){
    start=NULL;
    struct node* new_node,*ptr;
    int num;
    cout<<"\nEnter a number = ";
    cin>>num;
    while(num!=-1){
        new_node=(struct node*)malloc(sizeof(struct node));
        new_node->data=num;
        new_node->next=NULL;
        if(start==NULL){
            start=new_node;
            ptr=start;
        }
        else{
            if(ptr->next!=NULL)
            ptr=ptr->next;
            ptr->next=new_node;
        }
        cout<<"Enter a number = ";
        cin>>num;
    }
    return start;
}
struct node* display(struct node* start){
    struct node* ptr;
    ptr=start;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    return start;
}
struct node* insertion_start(struct node* start){
    struct node* new_node;
    int num;
    cout<<"Enter a number = ";
    cin>>num;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=num;
    new_node->next=start;
    start=new_node;
    return start;
}
struct node* insertion_last(struct node* start){
    struct node *ptr,*new_node;
    ptr=start;
    int num;
    cout<<"Enter a number = ";
    cin>>num;
    new_node=(struct node*)malloc(sizeof(struct node*));
    new_node->data=num;
    new_node->next=NULL;
 
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=new_node;
    return start;

}
struct node* insertion_after(struct node* start){
    struct node *ptr,*new_node,*preptr;
    ptr=start;
    preptr=ptr;
    int num;
    cout<<"Enter a number which you are added = ";
    cin>>num;
    int val;
    cout<<"\nEnter a value after which you are added node = ";
    cin>>val;
    new_node=(struct node*)malloc(sizeof(struct node*));
    new_node->data=num;
    new_node->next=NULL;
 
    while(preptr->data!=val){
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=new_node;
    new_node->next=ptr;
    return start;

}
struct node* deletion_start(struct node* start){
    struct node *ptr;
    ptr=start;
start=ptr->next;
free(ptr);
    return start;

}
struct node* deletion_last(struct node* start){
    struct node *ptr,*preptr;
    ptr=start;
    preptr=ptr;
    while(ptr->next!=NULL){
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=NULL;
    free(ptr);
    return start;

}
struct node* deletion_node(struct node* start){
    struct node *ptr,*preptr;
    ptr=start;
    preptr=ptr;
    int val;
    cout<<"\nEnter a node you are deleted = ";
    cin>>val;
    while(ptr->data!=val){
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=ptr->next;
    free(ptr);
    return start;

}
struct node* sorting_list(struct node* start){
    struct node *ptr1,*ptr2;
    int temp;
    ptr1=start;
    while(ptr1->next!=NULL){
        ptr2=ptr1->next;
        while(ptr2!=NULL){
            if(ptr1->data>ptr2->data){
                temp=ptr1->data;
                ptr1->data=ptr2->data;
                ptr2->data=temp;
            }
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    return start;

}

int main(){
    char flag;
    cout<<"You are entered in linked list enterd y or n\n";
    cin>>flag;
    while(flag=='y'){
        int check;
    cout<<"Enter 1 for create linked list\n";
    cout<<"Enter 2 for display linked list\n";
    cout<<"Enter 3 for insertion at starting \n";
    cout<<"Enter 4 for insertion at last \n";
    cout<<"Enter 5 for insertion after a node \n";
    cout<<"Enter 6 for deletion at starting \n";
    cout<<"Enter 7 for deletion at last \n";
    cout<<"Enter 8 for deletion of node \n";
    cout<<"Enter 9 for sorting of linked list \n";
    cin>>check;
    switch (check)
    {
    case 1:
       start=create(start);
        break;
    case 2:
       start=display(start);
        break;
    case 3:
       start=insertion_start(start);
        break;
    case 4:
       start=insertion_last(start);
        break;
    case 5:
       start=insertion_after(start);
        break;
    case 6:
       start=deletion_start(start);
        break;
    case 7:
       start=deletion_last(start);
        break;
    case 8:
       start=deletion_node(start);
        break;
    case 9:
       start=sorting_list(start);
        break;
    
    default:
        break;
    }
    cout<<"\nYou are entered in linked list enterd y or n\n";
    cin>>flag;

    }



    return 0;
}
