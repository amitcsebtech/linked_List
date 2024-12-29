#include<iostream>
using namespace std;

// structure of Node
class Node{
    public :
    int data;
    Node* next;
    Node (int val){
        data=val;
        next=NULL;
    }
};


// create all function
class List{
Node* head;
Node* tail;
public :
// constructor when Linked List is create then head and tail are intialize to NULL
List(){
    head = tail =NULL;
}
// push the element to last of list
void pushBack(int val){
    Node* newNode=new Node (val);
    if(head==NULL){
        head=newNode;
        tail=head;
    }
    else {
        if(tail->next!=NULL)
        tail=tail->next;
        tail->next=newNode;
        tail=newNode;
    }
}
// push the element starting of list
void pushFront(int val){
    Node* newNode=new Node (val);
    if(head==NULL){
        head=newNode;
        tail=head;
    }
    else{
        newNode->next=head;
        head=newNode;
    }
}
// to delete the last element of list
void popBack(){
    Node* ptr=head;
    if(ptr==NULL){
        cout<<"List is empty\n";
        return ;
    }
    while(ptr->next!=tail){
        ptr=ptr->next;
    }
    ptr->next=NULL;
    delete(tail);
    tail=ptr;
}
// to delete the first element of list
void popFront(){
    Node* ptr=head;
    if(ptr==NULL){
        cout<<"List is empty\n";
        return ;
    }
    head=head->next;
    delete(ptr);
}
void insert(int val, int idx){
    if(idx<0){
        cout<<"Invalid Index\n";
        return ;
    }
    if(idx==0){
        pushFront(val);
        return;
    }
    
    Node* ptr=head;
    Node* newNode=new Node(val);
    idx--;
    while(idx>0){
        ptr=ptr->next;
        if(ptr==NULL){
            cout<<"Invalid Index\n";
            return ;
        }
        idx--;
    }
    newNode->next=ptr->next;
    ptr->next=newNode;
    
}
void search(int val){
    if(head==NULL){
        cout<<"List is empty\n";
        return ;
    }
    Node* ptr=head;
    int idx=0;
    while(ptr!=NULL){
        if(ptr->data==val){
            cout<<"Element is present at index="<<idx<<endl;
            return ;
        }
        ptr=ptr->next;
        idx++;
    }
    cout<<"Element is not present \n";
}
// remove the particular element 
void remove(int val){
    if(head==NULL){
        cout<<"List is empty\n";
        return ;
    }
    if(head->data==val)
    popFront();
    if(tail->data==val)
    popBack();
    Node* prev=head;
    Node* ptr=head->next;
    while(ptr!=NULL){
        if(ptr->data==val){
            prev->next=ptr->next;
            delete(ptr);
            return ;
        }
        prev=ptr;
        ptr=ptr->next;
    }
    cout<<"Element is not present\n";
}
// here we are print the list 
void printLL(){
    Node* ptr=head;
    if(ptr==NULL){
    cout<<"List is empty\n";
    return ;
    }
    
    while(ptr!=NULL){
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
    cout<<"NULL\n";
}
};
int main(){
cout<<"Amit Singh Guatam\n";
List l1;
cout<<"Push Back\n";
l1.pushBack(4);
l1.pushBack(3);
l1.pushBack(7);
l1.printLL();
cout<<"Push Front\n";
l1.pushFront(2);
l1.pushFront(1);
l1.pushFront(0);
l1.printLL();
cout<<"Pop Back\n";
l1.popBack();
l1.printLL();
cout<<"Pop Front\n";
l1.popFront();
l1.printLL();
cout<<"Insert element at index\n";
l1.insert(5,3);
l1.printLL();
cout<<"Remove the element\n";
l1.remove(5);
l1.printLL();
cout<<"Searching a element \n";
l1.search(4);
    return 0;
}