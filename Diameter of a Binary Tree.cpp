/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    
    int height(Node* root, int &dia)
    {
        if(!root)
            return 0;
        int lh = height(root->left, dia);
        int rh = height(root->right, dia);

        dia = max(dia,lh+rh);

        return 1+max(lh,rh);
    }
    
    int diameter(Node* root) {
        // Your code here
        int dia = 0;
        height(root,dia);
        
        return dia+1;
    }
};
