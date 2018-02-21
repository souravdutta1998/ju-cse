#include<iostream>
using namespace std;
#include<math.h>
#include<stdlib.h>
#include<queue>

struct node{
    int data;
    node* left;
    node* right;
};
node* get_newnode(int number){                  //function for creating node.
      node* newnode = new node();
      newnode->data = number;
      newnode->left = newnode->right = NULL;
      return newnode;
};
node* Insert(node* root,int num){           //function for placing the node in required place so that the tree remains BST.
      if(root == NULL){
         root = get_newnode(num);
      }
      else if(num <= root->data){
         root->left = Insert(root->left,num);
      }
      else {
         root->right = Insert(root->right,num);
      }
      return root;
}
bool Search(node* root,int data){               //boolean function to return if a specific node exits or not.
     if(root == NULL){
        return false;
     }
     else if(root->data == data){
        return true;
     }
     else if(data < root->data){
        return Search(root->left,data);
     }
     else{
        return Search(root->right,data);
     }
}
void print_Preorder(node* root){                //function for pre-order traversal.
     if(root == NULL){
        return;
     }
     cout << root->data << "\n";
     print_Preorder(root->left);
     print_Preorder(root->right);
}
void print_Inorder(node* root){                 //function for In-order traversal.
     if(root == NULL){
        return;
     }
     print_Inorder(root->left);
     cout << root->data << "\n";
     print_Inorder(root->right);
}
void print_Postorder(node* root){               //function for post-order traversal.
     if(root == NULL){
        return;
     }
     print_Postorder(root->left);
     print_Postorder(root->right);
     cout << root->data << "\n";
}

void levelOrder(node * root) {                  //function for level-order traversal.
    if(root == NULL)
        return;
    queue<node*>Q;                              //this create a queue named Q(already defined in c++ library <queue>).
    Q.push(root);
    while(!Q.empty()){
        node *current = Q.front();
        cout<<current->data<<' ';
        if(current->left != NULL)
            Q.push(current->left);
        if(current->right != NULL)
            Q.push(current->right);
        Q.pop();
    }
}

bool IsBSTlesser(node* root,int data){          //check the BST
     if(root == NULL)
        return true;
     if(root ->data <= data && IsBSTlesser(root->left,data) && IsBSTlesser(root->right,data))
        return true;
     else
        return false;
}

bool IsBSTgreater(node* root,int data){
     if(root == NULL)
        return true;
     if(root ->data > data && IsBSTgreater(root->left,data) && IsBSTgreater(root->right,data))
        return true;
     else
        return false;
}

bool IsBST(node* root){                     //function for checking the property of BST.
     if(root == NULL){
        return true;
     }
     if(IsBST(root->left) && IsBST(root->right) && IsBSTlesser(root->left,root->data) && IsBSTgreater(root->right,root->data))
        return true;
     else
        return false;
}

node* findmin(node* root){                  //function for finding the node having minimum data field value.
    if(root ==  NULL) return NULL;
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

node* findmax(node* root){                  //function for finding the node having maximum data field value.
    if(root ==  NULL) return NULL;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

node* Find(node* root,int data1){  //function to return the node address, whose data field value is data1.
    if(root == NULL) return NULL;
    while(data1 != root->data){
        if(data1 < root->data){
            root = root->left;
        }
        else if(data1 > root->data){
            root = root->right;
        }
    }
    return root;  // return the address of binary node where the data stored.
}

node* GetsuccessorInorder(node* root,int data){         /*function for returning the just after node of a particular node
                                                            when they arranged in In-order traversal.*/
    node* current = Find(root,data);
    if(root == NULL) return NULL;

    if(current->right != NULL){   //Case 1. right subtree exit.
        return findmin(current->right);
    }
    else{                     //Case 2. right subtree is not exit.
        node* successor = NULL;
        node* ancestor = root;
        while(ancestor != current){
            if(current->data < ancestor->data){
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else{
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}

node* deletenode(node* root,int data){              //function for deleting a specified node having data field value equals to "data".
    if(root == NULL) return root;
    if(data < root->data)
        root->left = deletenode(root->left,data);

    else if(data > root->data)
        root->right = deletenode(root->right,data);

    else{
        if(root->left == NULL && root->right == NULL){          //when the required node has none child.
            node *temp = root;
            root = NULL;
            delete temp;
        }
        else if(root->left == NULL){                           //when the r.. node has only right child.
            node* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL){                         //when the r.. node has only left child.
            node* temp = root;
            root = root->left;
            delete temp;
        }
        else{                                           //when the r.. node has both child.
            node* current = findmin(root->right);
            root->data = current->data;
            root->right = deletenode(root->right,current->data);
        }
    }
    return root;
}

int findheight(node* root){                 //function for returning the height of BST tree.
    if(root == NULL){
        return -1;
    }
    else
        return max(findheight(root->left),findheight(root->right))+1;
}

int findheight_node(node* root,int data){               //function for returning the height of a particular node.
    node* temp = Find(root,data);
    if(temp == NULL) return -1;
    else
        return max(findheight(temp->left),findheight(temp->right))+1;

}

int main(){
     node* root = NULL;
     root = Insert(root,10);
     root = Insert(root,9);
     root = Insert(root,15);
     root = Insert(root,12);
     root = Insert(root,4);
     root = Insert(root,14);
     root = Insert(root,91);
     root = Insert(root,5);
     root = Insert(root,25);
     root = Insert(root,41);
     /*int value;
     cout << "Enter the node value you would like to find height?:\n ";
     cin >> value;
     cout << "The Height of your node in your Binary search tree is "<< findheight_node(root,value);
     cout << "The Height of your Binary search tree is "<< findheight(root);
     */cout << "The level-Order transversal is:\n";
     levelOrder(root);
     int x;
     /*cout << "Enter the value you want to delete from your binary search tree.:\n";
     cin >> x;
     root = deletenode(root,x);
     cout << "Now,The New Pre-Order transversal is:\n";
     print_Preorder(root);
     /*cout << "Enter the root you want to be successor?:\n ";
     cin >> x;
     cout << "The successor of " << x <<" is "<< (GetsuccessorInorder(root,x)->data);
     if(IsBST(root) == true){
        cout << "The binary tree is a Binary search tree.\n";
     }
     else
        cout << "The binary tree is not a Binary search tree.\n";
     cout << "The Pre-Order transversal is:\n";
     print_Preorder(root);
     cout << "The In-Order transversal is:\n";
     print_Inorder(root);
     cout << "The Post-Order transversal is:\n";
     print_Postorder(root);
     int no;
     cout << "Enter the number to be searched\n";
     cin >> no;
     if(Search(root,no) == true){
        cout << "Found\n" ;
     }
     else cout << "Not found\n";*/

     return 0;
}
/*
void topView(node * root) {
    node *temp;
    int n=0,i,k,*tree;
    temp = root->left;
    if(temp!=NULL){
        tree[n++] = temp->data;
        temp = temp->left;
    }
    k = n;
    temp=root;
    if(temp != NULL){
        tree[n++] = temp->data;
        temp = temp->right;
    }
    for(i=k-1;i>=0;i--){
        cout<<tree[i]<<' ';
    }
    for(i=k;i<n;i++){
        cout<<tree[i]<<' ';
    }

}


void topView(node * root) {

    if (root->left) {
        root->left->right = NULL;
        topView(root->left);
    }

    printf("%d ", root->data);

    if (root->right) {
        root->right->left = NULL;
        topView(root->right);
    }

}*/
