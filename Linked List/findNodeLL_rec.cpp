#include<iostream>
using namespace std;
#define null NULL
class Node {
    public:
        int data;
        Node *next;
        Node(int data) {
            this->data=data;
            this->next=null;
        }
};
Node *takeInput() {
    int data;
    cin >> data;
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
int findNodeRec(Node *head, int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    if(head==NULL){
       return -1;
    }
    if(head->data==n){
        return 0;
    }
    int smallAns = findNodeRec(head->next , n);
    if(smallAns!= -1){
        smallAns++;
    }
    else{
        return -1;
    }
    return smallAns;
}
int main() {
    Node *head = takeInput();
		int val;
		cin >> val;
		cout << findNodeRec(head, val) << endl;
}