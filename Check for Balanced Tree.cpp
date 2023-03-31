/* A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    
    int checkHeight(Node *root)
    {
        if(root == NULL)
            return 0;
        
        int left = checkHeight(root->left);
        if(left == -1) return -1;
        int right = checkHeight(root->right);
        if(right == -1) return -1;
        
        if(abs(left - right) > 1) return -1;
        
        return 1+max(left,right);
    }
    
    bool isBalanced(Node *root)
    {
        //  Your Code here
        return checkHeight(root) != -1;
    }
    
};
