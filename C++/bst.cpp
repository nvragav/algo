#include <iostream>

#include <queue>
using namespace std;
/* 
OUTPUT:
-------
--- Depth First Traversal ---
1->2->3->4->5->
--- Breadth First Traversal ---
5->4->2->1->3->
Is available ? : 1
Is available ? : 0
*/
  
class bst {

  public:
    struct bstNode {
        int data;
        struct bstNode* right;
        struct bstNode* left;
    };  
  struct bstNode* root = NULL;
  struct bstNode* createNode(int data){
      auto node = new  bstNode();
      node->data = data;
      return(node);
  }
  struct bstNode* insertNode(struct bstNode* &root, struct bstNode* node) {
      
      if( root == NULL)
      {
          root = node;
      }
      else
      {
        if(node->data < root->data )
        {
            if(root->left != NULL)
                insertNode(root->left,node);
            else
                root->left = node;
        }
        else
        {
            if(root->right != NULL)
                insertNode(root->right,node);
            else
                root->right = node;          
        }
      }
      return root;
  }
  //Depth first traversal
  int traverseBst(struct bstNode* root)
  {
      
      if(root == NULL)
        return 0;
        
    traverseBst(root->left);
    cout << root->data << "->" ;
    traverseBst(root->right);
        
  }
  //Level order or Breadth first traversal
  int levelOrderTraversal(struct bstNode* root)
  {
    queue<struct bstNode*> que;
    struct bstNode* node;
    
    que.push(root);
    while(!que.empty())
    {
        node = que.front();
        cout << node->data << "->";
        if(node->left != NULL)
            que.push(node->left);
        if(node->right != NULL)
            que.push(node->right);
        
        que.pop();
    }
    return 1;
  }
  
  //Searching 
  bool searchBst(struct bstNode* root, int data)
  {
      if( root == NULL)
        return false;
        
    if(data == root->data)
    {
        return true;
    }
    else if(data < root->data)
    {
        return(searchBst(root->left,data));
    }
    else{
        return(searchBst(root->right, data));
    }
    
    return false;
  }
  
};
int main() {
    // Write C++ code here
    bst bs;
    
    bs.insertNode(bs.root,bs.createNode(5));
    bs.insertNode(bs.root,bs.createNode(4));
    bs.insertNode(bs.root,bs.createNode(2));
    bs.insertNode(bs.root,bs.createNode(3));
    bs.insertNode(bs.root,bs.createNode(1));

    cout << "--- Depth First Traversal ---" << endl;
    bs.traverseBst(bs.root);
    cout << "\n--- Breadth First Traversal ---" << endl;
    
    bs.levelOrderTraversal(bs.root);
    
    cout << endl;
    cout << "Is available ? : " << bs.searchBst(bs.root,1) << endl;
    cout << "Is available ? : " << bs.searchBst(bs.root,10) << endl;
    return 0;
}