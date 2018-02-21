#include<stdio.h>
#include<stdlib.h>

/*structure of an AVL tree.*/
struct node{
    int data;
    struct node *left;
    struct node *right;
    int ht;
};

int max(int a,int b){   //function for finding maximum.
    if(a >= b)
        return a;
    else
        return b;
}

int height(struct node *n){         //function for finding the height of a node.
    if(n == NULL)
        return -1;
    else{
        return(max(height(n->left),height(n->right))+1);
    }
}

int balance_factor(struct node *n){         //function for finding balance factor for each node(key factor for any node in AVL tree).
    int count1=0,count2=0;
    struct node *temp = n;
    while(temp->left != NULL){
        count1++;
        temp = temp->left;
    }
    temp = n;
    while(temp->right != NULL){
        count2++;
        temp = temp->right;
    }
    return(count1-count2);
}

struct node *rotateleft(struct node *r){        //function for left rotation of a tree about a node r.
    struct node *temp,*T1;

    temp = r->right;
    T1 = temp->left;

    r->right = T1;
    temp->left = r;

    r->ht = height(r);                          //updating the height.
    temp->ht = height(temp);

    return temp;
}

struct node *rotateright(struct node *r){           //function for left rotation of a tree about a node r.
    struct node *temp,*T2;

    temp = r->left;
    T2 = temp->right;

    r->left = T2;
    temp->right = r;

    r->ht = height(r);                      //updating the height.
    temp->ht = height(temp);

    return temp;
}

struct node *createnode(int val){           //function for creation of an AVL node.
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    newnode->ht = 1;
    return newnode;
}

struct node *update_Avl(struct node *root,int data){            //function for updating the root balance factor.
    int balance = balance_factor(root);

    /*Right-Right Case.*/
    if(balance < -1 && data > root->right->data){
        return rotateleft(root);
    }
    /*Left-Left Case.*/
    else if(balance > 1 && data < root->left->data){
        return rotateright(root);
    }
    /*Right-Left Case.*/
    else if(balance < -1 && data < root->right->data){
        root->right = rotateright(root->right);
        return rotateleft(root);
    }
    /*Left-Right Case.*/
    else if(balance > 1 && data > root->left->data){
        root->left = rotateleft(root->left);
        return rotateright(root);
    }
    return root;
}

struct node *insert(struct node *root,int data){        //function for insertion of a node having 'data' field value data.
    if(root == NULL)
        return(createnode(data));

    if(data < root->data)
        root->left = insert(root->left,data);
    else if(data > root->data)
        root->right = insert(root->right,data);
    else
        return root;
    root = update_Avl(root,data);           //calling update function.
    return root;
}

struct node* Find(struct node* root,int data1){  //function to return the node address, whose data field value is data1.
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
void print_avl_inorder(struct node *root){          //Recursive function for In-order traversal.
    if(root == NULL)
        return;

    print_avl_inorder(root->left);
    printf("->%d bf = %d\n",root->data,balance_factor(root));
    print_avl_inorder(root->right);
}

void print_avl_preorder(struct node *root){             //Recursive function for Pre-order traversal.
    if(root == NULL)
        return;

    printf("->%d bf = %d\n",root->data,balance_factor(root));
    print_avl_preorder(root->left);
    print_avl_preorder(root->right);
}

void print_avl_postorder(struct node *root){                //Recursive function for Post-order traversal.
    if(root == NULL)
        return;

    print_avl_postorder(root->left);
    print_avl_postorder(root->right);
    printf("->%d bf = %d\n",root->data,balance_factor(root));
}

struct node *find_node(struct node *root,int data1){            //function for returning the node address whose 'data' field value is data1.
    if(root == NULL)
        return root;
    struct node *temp = root;
    while(temp->data != data1){
        if(temp->data > data1)
            temp = temp->left;
        else if(temp->data < data1)
            temp = temp->right;
    }
    return temp;
}

struct node* findmin(struct node* root){                  //function for finding the node having minimum data field value.
    if(root ==  NULL)
        return NULL;

    while(root->left != NULL){
        root = root->left;
    }
    //printf("min = %d\n",root->data);
    return root;
}

struct node* findmax(struct node* root){                  //function for finding the node having maximum data field value.
    if(root ==  NULL) return NULL;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

struct node *successor_inorder(struct node *root,int data){     //function for finding the in-order successor.
    struct node *cur = find_node(root,data);
    if(cur->right != NULL)
        return findmin(cur->right);
    else{                     //Case 2. right subtree is not exit.
        struct node* successor = NULL;
        struct node* ancestor = root;
        while(ancestor != cur){
            if(cur->data < ancestor->data){
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

struct node *deletenode(struct node *root,int data){            //function for deletion of a node whose 'data' field value is data.
    if(root == NULL)
        return root;

    if(data < root->data)
        root->left = deletenode(root->left,data);

    else if(data > root->data)
        root->right = deletenode(root->right,data);

    else{
        if(root->left == NULL && root->right == NULL){          //when the required node has none child.
            struct node *temp = root;
            root = NULL;
            free(temp);
        }
        else if(root->left == NULL){                           //when the r.. node has only right child.
            struct node* temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL){                         //when the r.. node has only left child.
            struct node* temp = root;
            root = root->left;
            free(temp);
        }
        else{                                           //when the r.. node has both child.
            struct node* current = findmin(root->right);
            root->data = current->data;
            root->right = deletenode(root->right,current->data);
        }

    }

    // If the tree had only one node then return
    if (root == NULL)
      return root;
    else

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->ht = height(root);

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
    // check whether this node became unbalanced)
    int balance = balance_factor(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case.
    if (balance > 1 && balance_factor(root->left) >= 0)
        return rotateright(root);

    // Left Right Case
    if (balance > 1 && balance_factor(root->left) < 0)
    {
        root->left =  rotateleft(root->left);
        return rotateright(root);
    }

    // Right Right Case
    if (balance < -1 && balance_factor(root->right) <= 0)
        return rotateleft(root);

    // Right Left Case
    if (balance < -1 && balance_factor(root->right) > 0)
    {
        root->right = rotateright(root->right);
        return rotateleft(root);
    }

    return root;
}

int Search(struct node* root,int data){     //function for searching a key from an AVL tree.
    if(root == NULL){
        return 0;
    }
    else if(root->data == data){
        return 1;
    }
    else if(data < root->data){
        return Search(root->left,data);
    }
    else{
        return Search(root->right,data);
    }
}

int main(){
    struct node *root = NULL;
    root = insert(root,12);
    root = insert(root,3);
    root = insert(root,20);
    root = insert(root,42);
    root = insert(root,19);
    root = insert(root,2);
    root = insert(root,100);
    root = insert(root,22);
    root = insert(root,110);
    root = insert(root,4);
    /*
    printf("root = %d\n",root->data);
    printf("root->left = %d\n",root->left->data);
    printf("root->right = %d\n",root->right->data);
    printf("root->left->left = %d\n",root->left->left->data);
    printf("root->right->left = %d\n",root->right->left->data);
    printf("root->right->right = %d\n",root->right->right->data);
    printf("root->right->right->right = %d\n",root->right->right->right->data);
    printf("root->right->right->left = %d\n",root->right->right->left->data);
    int no;
    printf("Enter the number to be searched\n");
    scanf("%d",&no);
    if(Search(root,no) == 1){
        printf("Found\n");
    }
    else printf("Not found\n");*/
    printf("Your AVL tree in-order is:\n");
    printf("Original Root of this AVL tree = %d\n",root->data);
    print_avl_inorder(root);
    int x;
    printf("Enter the value you want to delete from your binary search tree.:\n");
    scanf("%d",&x);
    root = deletenode(root,x);
    printf("Your AVL tree in-order is:\n");
    printf("New Root of this AVL tree = %d\n",root->data);
    print_avl_inorder(root);
    //printf("Your AVL tree Pre-order is:\n");
    //print_avl_preorder(root);
    //printf("Your AVL tree Post-order is:\n");
    //print_avl_postorder(root);
    return 0;
}
