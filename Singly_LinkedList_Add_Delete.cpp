#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct Node
{
    int val;
    Node *next = NULL;
    Node(int val)
    {
        this->val = val;
    }

    void appendToTail(int val)
    {
        Node *tail = new Node(val);
        Node *head = this;
        while(head->next != NULL) {
            head = head->next;
        }
        head->next = tail;
    }

    void show()
    {
        Node *head = this;
        while(head != NULL) {
            cout<<"val = "<<head->val<<endl;
            head = head->next;
        }
    }

    Node* deleteNode(Node *head, int d)
    {
        Node *currentNode = head;
        if(currentNode->val == d) {
            return head->next;
        }
        while(currentNode)
        {
            if(currentNode->next && currentNode->next->val == d) {
                currentNode->next = currentNode->next->next;
                return head;
            }
            currentNode = currentNode->next;
        }
        return head;
    }
};
int main()
{
    Node *head = NULL;
    for(int i = 1 ; i <= 5 ; i++) {
        if(head == NULL) {
            head = new Node(i);
        }
        else {
            head->appendToTail(i);
        }
    }
    head->show();
    while(true)
    {
        int d;
        cout<<"Enter a node that you want to remove"<<endl;
        cin>>d;
        if(head) {
            head = head->deleteNode(head, d);
        }
        cout<<"updated Node"<<endl;
        head->show();
    }
}
