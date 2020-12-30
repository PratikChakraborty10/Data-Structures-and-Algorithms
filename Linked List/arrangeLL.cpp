// Even after Odd LinkedList
// For a given singly linked list of integers, arrange the elements such that all the even numbers are placed after the odd numbers. The relative order of the odd and even terms should remain unchanged.
// Note :
// No need to print the list, it has already been taken care. Only return the new head to the list.

#include<iostream>
using namespace std;
class node {
    public:
        int data;
        node *next;
        node(int data) {
            this->data=data;
            this->next=NULL;
        }
};
node *takeInput() {
    int data;
    cin >> data;
    node *head=NULL;
    node *tail=NULL;
    while(data != -1) {
        node *newNode = new node(data);
        if(head==NULL) {
            head=newNode;
            tail=newNode;
        } else {
            tail->next=newNode;
            tail=newNode;
        }
        cin >> data;
    }
    return head;
}
node* arrange_LinkedList(node* head){
    node* oddHead = NULL;
    node* oddTail = NULL;
    node* evenHead = NULL;
    node* evenTail = NULL;
    while(head!=NULL){
        if(head->data%2!=0){
            if(oddHead == NULL){
                oddHead=head;
                oddTail=head;
            }
            else{
                oddTail->next=head;
                oddTail=oddTail->next;
            }
        }
        else{
            if(evenHead == NULL){
                evenHead=head;
                evenTail=head;
            }
            else{
                evenTail->next=head;
                evenTail=evenTail->next;
            }
        }
        head = head->next;
        
    }
    
    if(oddTail==NULL){
        return evenHead;
    }
    if(evenHead==NULL){
        return oddHead;
    }
    oddTail->next = evenHead;
    return oddHead;
}

void print(node *head) {
    node *temp=head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << endl;
}
int main() {
    node *head = takeInput();
    head = arrange_LinkedList(head);
    print(head);
}