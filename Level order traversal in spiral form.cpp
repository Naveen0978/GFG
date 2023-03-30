

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
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


//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> ans;
    if(root == NULL)
        return ans;
    deque<Node*> dq;
    dq.push_back(root);
    bool reverse=true;
    while(!dq.empty())
    {
        int n = dq.size();
        
        if(!reverse)
        {   
            for(int i=0;i<n;i++)
            {   Node* node = dq.front();
                if(node->left != NULL)
                    dq.push_back(node->left);
                if(node->right != NULL)
                    dq.push_back(node->right);
                ans.push_back(node->data);
                dq.pop_front();
            }
            reverse = !reverse;
        }
        else
        {
            for(int i=0;i<n;i++)
            {   Node* node = dq.back();
                if(node->right != NULL)
                    dq.push_front(node->right);
                if(node->left != NULL)
                    dq.push_front(node->left);
                ans.push_back(node->data);
                dq.pop_back();
            }
            reverse = !reverse;
        }
    }
    return ans;
}
