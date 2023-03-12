//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* reverse(Node* head)
    {
        Node* temp = NULL;
        
        while(head != NULL)
        {
            Node* nextp = head->next;
            head->next = temp;
            temp = head;
            head = nextp;
        }
        return temp;
    }
    struct Node* addnum(struct Node* l1, struct Node* l2)
    {
        struct Node* Ans = new struct Node(0);
        struct Node* temp = Ans;
        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry)
        {
            int sum = 0;
            if( l1 != NULL)
            {
                sum += l1->data;
                l1 = l1->next;
            }
            if(l2 != NULL)
            {
                sum += l2->data;
                l2 = l2->next;
            }
            sum+=carry;
            carry = sum/10;
            struct Node* node = new struct Node(sum%10);
            temp->next = node;
            temp = temp->next;
        }
        return Ans->next;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        struct Node* f = reverse(first);
        struct Node* s = reverse(second);
        
        struct Node* res = addnum(f,s);
        
        return reverse(res);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends
