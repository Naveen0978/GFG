/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        stack<Node*> st;
        vector<int> inord;
        Node* node = root;
        while(true)
        {
            if(node != NULL)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                if( st.empty())
                    break;
                node = st.top();
                inord.push_back(node->data);
                st.pop();
                node = node->right;
            }
        }
        return inord;        
    }
};
