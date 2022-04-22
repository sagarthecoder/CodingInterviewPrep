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
Node* deleteAt(int k, Node *currentNode, Node * prev)
{
    if(currentNode == NULL) {
        return NULL;
    }
    Node *n = deleteAt(k,currentNode->next, currentNode);
    lastIndex++;
    if(lastIndex == k) {
        if(prev == NULL) {
            return currentNode->next;
        }
        else {
            prev->next = currentNode->next;
        }
    }
    return currentNode;
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
    Node *newHead = deleteAt(k,head,NULL);
    if(newHead) {
        newHead->show();
    } else {
        cout<<"No Element"<<endl;
    }
}

