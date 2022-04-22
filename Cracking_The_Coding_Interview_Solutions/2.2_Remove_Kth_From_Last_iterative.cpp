#include <bits/stdc++.h>
#define ll long long
using namespace std;
int lastIndex = 0;
struct Node
{
    int val;
    Node *next = NULL;
    Node(int val) {
        this->val = val;
    }

    void append(int val) {
        Node *currentNode = this;
        Node *endNode = new Node(val);
        while(currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = endNode;
    }
    void show() {
        Node *currentNode = this;
        cout<<"Showing Nodes"<<endl;
        while(currentNode != NULL) {
            cout<<currentNode->val<<" ";
            currentNode = currentNode->next;
        }
        cout<<endl;
    }
};
Node* kthNodeFromLast(int k, Node *head)
{
    Node *p1 = head;
    Node *p2 = head;
    for(int i = 0 ; i < k ; i++) {
        if(p1 == NULL) return NULL;
        p1 = p1->next;
    }
    while(p1) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p2;
}
int main()
{
    int n; //number of nodes
    Node *head = NULL;
    cin>>n;
    for(int i = 0 ; i < n ; i++) {
        int x;
        cin>>x;
        if(head == NULL) {
            head = new Node(x);
        }
        else {
            head->append(x);
        }
    }
    if(head == NULL) return 0;
    head->show();
    int k ; //  deleted node number from last
    cin>>k;
    Node *node = kthNodeFromLast(k,head);
    if(node) {
        printf("%dth node from last = %d\n",k,node->val);
    } else {
        cout<<"No Element"<<endl;
    }
}
