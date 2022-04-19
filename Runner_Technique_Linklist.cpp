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
    // Given a1,a2,a3,a4 ....aN, b1, b2, b3, b4, ....bN
    // need to show like a1,b1,a2,b2,......aN,bN
    int n = 2;
    Node *head = NULL;
    // Building a Linked List;
    for(int i = 1; i <= n ; i++) {
        if(head == NULL) {
            head = new Node(i);
        }
        else {
            head->append(i);
        }
    }
    if(head) {
        head->show();
    }
    else {
        cout<<"Invalid"<<endl;
        return 0;
    }
    // Runner Technique;
    Node *p1 = head->next; // high jump by 2 position
    Node *p2 = head;// low jump by 1 position
    while(p1->next != NULL) {
        p1 = p1->next->next;
        p2 = p2->next;
    }
    Node *currentNode = head;
    p1 = head;
    int i = 0;
    while(p2->next != NULL) {
        Node *p = p2->next; // save p2->next
        p2 = p2->next;
        if(p1 != currentNode) {
            p1->next = currentNode;
            p1 = p1->next;
        }
        currentNode = currentNode->next;
        p1->next = p;
        p1 = p1->next;
    }
    if(head) {
        head->show();
    }
    else {
        cout<<"Invalid"<<endl;
    }
    return 0;

}
