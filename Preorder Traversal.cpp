

/* A binary tree node has data, pointer to left child
   and a pointer to right child  

/*
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

//Function to return a list containing the preorder traversal of the tree.
void traversal(Node* root, vector<int> &preord)
{
    if(root == NULL)
        return;
        
    preord.push_back(root->data);
    traversal(root->left,preord);
    traversal(root->right,preord);
}
vector <int> preorder(Node* root)
{
  // Your code here
    vector<int> preord;

    traversal(root,preord);
    return preord; 
}
