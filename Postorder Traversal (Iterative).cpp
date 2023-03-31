// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution{
    public:
    vector<int> postOrder(Node* node) {
        // code here
        vector<int> postorder;
        if(node == NULL)
            return postorder;
        stack<Node*> s1,s2;
        s1.push(node);
        while(!s1.empty())
        {
            node = s1.top();
            s1.pop();
            s2.push(node);
            if(node->left != NULL)
                s1.push(node->left);
            if(node->right != NULL)
                s1.push(node->right);
        }
        while(!s2.empty())
        {
            Node* temp = s2.top();
            s2.pop();
            postorder.push_back(temp->data);
        }
        return postorder;
    }
};
