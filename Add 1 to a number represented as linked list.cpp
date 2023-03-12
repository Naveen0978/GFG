//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node* head)
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
    Node* add(Node* head)
    {
        Node* res = head;
        Node* temp = NULL;
        
        int carry = 1, sum=0;
        
        while(head != NULL)
        {
            sum = carry + head->data;
            carry = (sum>=10) ? 1 : 0;
            sum = sum%10;
            head->data = sum;
            
            temp = head;
            head = head->next;
        }
        if(carry > 0)
            temp -> next = new Node(carry);
        
        return res;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        head  = reverse(head);
        head = add(head);
        
        return reverse(head);
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends
