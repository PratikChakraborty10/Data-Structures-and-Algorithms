#include<iostream>
using namespace std;
#define null NULL
class Node {
    public:
        int data;
        Node *next;
        Node(int data) {
            this->data=data;
            this->next = null;
        }
};
Node *takeInput() {
    int data;
    Node *head = null;
    Node *tail = null;
    while (data != -1) {
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
Node *midPoint(Node *head) {
    if(head==null || head->next==null) {
        return head;
    }
    Node *slow = head;
    Node *fast = head->next;
    while(fast != null || fast->next != null) {
        slow = head->next;
        fast = head->next->next;
    }
    return head;
}
int main() {
    Node *head = takeInput();
    Node *mid = midPoint(head);
    if(mid != null) {
        cout << mid->data;
    }
    cout << endl;
}