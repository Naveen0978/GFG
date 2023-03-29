//User function Template for C++

/*struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}*/

class Solution{
public:

    void create_tree(node* root0, vector<int> &vec){
        //Your code goes here
        int n=vec.size();
       queue<node *>q;
       q.push(root0);
       
       for(int i=1;i<n;i++){
           node *start=q.front();
           q.pop();
           node *left=newNode(vec[i]);
           i++;
           start->left=left;
           q.push(left);
           
           node*right=newNode(vec[i]);
         //  i++;
           start->right=right;
           q.push(right);
         //  i++;
       }
        
    }

};
