#include<iostream>
using namespace std;
#define null NULL
class Node {
    public:
    int data;
    Node *next;
    Node(int data) {
        this->data=data;
        next=null;
    }
};
Node *takeInput() {
    int data;
    cin >>data;
    Node *head = null;
    Node *tail = null;
    while(data != -1) {
        Node *newNode = new Node(data);
        if(head==null) {
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
// void reverseLL(Node *head) {
//     if(head==null)
//     return;
//     reverseLL(head->next);
//     print(head);
// }
void print(Node *head) {
    Node *temp = head;
    while(temp != null) {
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << endl;
} 
void reverseLL(Node *head) {
    if(head==null)
    return;
    reverseLL(head->next);
    cout << head->data << " ";
}
int main() {
    Node *head = takeInput();
    reverseLL(head);
    //print(head);
}