
#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct Node
{
    int val;
    Node *next = NULL;
    Node(int val) {
        this->val = val;
    }

    void append(int val)
    {
        Node *head = this;
        Node *newNode = new Node(val);
        while(head->next != NULL) {
            head = head->next;
        }
        head->next = newNode;
    }

    void show()
    {
        Node *currentNode = this;
        cout<<"Show"<<endl;
        while(currentNode != NULL) {
            cout<<currentNode->val<<" ";
            currentNode = currentNode->next;
        }
        cout<<endl<<"finished"<<endl<<endl;
    }
};
int main()
{
    int n; // number of nodes
    cin>>n;
    unordered_map<int,bool>seen;
    Node *head = NULL;
    for(int i = 1 ; i <= n ; i++) {
        int x;
        cin>>x;
        if(head == NULL) {
            head = new Node(x);
        }
        else {
            head->append(x);
        }
    }
    if(head == NULL) {
        return 0 ;
    }
    head->show();
    Node *currentNode = head;
    while(currentNode && currentNode->next) {
        seen[currentNode->val] = true;
        int val = currentNode->next->val;
        if(seen[val]) {
            Node *node = currentNode->next;
            while(node && seen[node->val]) {
                node = node->next;
            }
            currentNode->next = node;
        }
        else {
            seen[val] = true;
        }
        currentNode = currentNode->next;
    }
    cout<<"distinct values"<<endl;
    head->show();
    return 0;

}
