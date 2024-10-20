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




// Circular Linked List
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node*next;
};
struct node* create(struct node* start){
    start=NULL;
    struct node* newnode,*ptr;
    int num;
    cout<<"Enter -1 for exit the loop\n";
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
            if(ptr->next!=NULL){
                ptr=ptr->next;
            }
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
while(ptr->next!=start){
    cout<<ptr->data<<" ";
    ptr=ptr->next;
}
    cout<<ptr->data<<endl;
}
struct node* add_start(struct node* start){
    struct node* newnode,*ptr;
    int num;
    cout<<"Enter a number = \n";
    cin>>num;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    ptr=start;
    while(ptr->next!=start){
        ptr=ptr->next;
    }
    ptr->next=newnode;
    newnode->next=start;
    start=newnode;
    return start;
}
struct node* add_end(struct node* start){
    struct node* newnode,*ptr;
    int num;
    cout<<"Enter a number = \n";
    cin>>num;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    ptr=start;
    while(ptr->next!=start){
        ptr=ptr->next;
    }
    ptr->next=newnode;
    newnode->next=start;
    return start;
}
struct node* add_after(struct node* start){
    struct node* preptr, *ptr,*newnode;
    int val,num;
    cout<<"Enter a value after you are added node\n";
    cin>>val;
    cout<<"Enter a number = \n";
    cin>>num;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    preptr=start;
    ptr=preptr->next;
    while(preptr->data!=val){
        preptr=preptr->next;
        ptr=ptr->next;
    }
    preptr->next=newnode;
    newnode->next=ptr;
    return start;

}
struct node* delete_first(struct node* start){
    struct node* ptr;
    ptr=start;
    while(ptr->next!=start){
        ptr=ptr->next;
    }
    ptr->next=start->next;
    ptr=start;
    start=start->next;
    free(ptr);
    return start;
}
struct node* delete_last(struct node* start){
    struct node* ptr,*preptr;
    preptr=start;
    ptr=preptr->next;
    while(ptr->next!=start){
        preptr=preptr->next;
        ptr=ptr->next;
    }
   preptr->next=start;
    free(ptr);
    return start;
}
struct node* delete_node(struct node* start){
    int val;
    cout<<"Enter a node = \n";
    cin>>val;
    struct node* ptr,*preptr;
    preptr=start;
    ptr=preptr->next;
    while(ptr->data!=val){
        preptr=preptr->next;
        ptr=ptr->next;
    }
   preptr->next=ptr->next;
    free(ptr);
    return start;
}
int main(){
    struct node* start;
    char check;
    cout<<"Enter in circular linked list y or n\n";
    cin>>check;
    int op;
    while(check=='y'){
        cout<<"Enter 1 for creating linked list\n";
        cout<<"Enter 2 for display linked list\n";
        cout<<"Enter 3 for add node starting of linked list\n";
        cout<<"Enter 4 for add node end of linked list\n";
        cout<<"Enter 5 for add node after the node\n";
        cout<<"Enter 6 for delete first node of linked list\n";
        cout<<"Enter 7 for delete last node of linked list\n";
        cout<<"Enter 8 for delete  node of linked list\n";
        cin>>op;
        switch (op)
        {
        case 1:
            start=create(start);
            break;
        case 2:
            display(start);
            break;
        case 3:
            start=add_start(start);
            break;
        case 4:
            start=add_end(start);
            break;
        case 5:
            start=add_after(start);
            break;
        
        case 6:
            start=delete_first(start);
            break;
        case 7:
            start=delete_last(start);
            break;
        case 8:
            start=delete_node(start);
            break;
        
        default:
            break;
        }
    cout<<"Enter in circular linked list y or n\n";
    cin>>check;
    }
  
    return 0;
}
