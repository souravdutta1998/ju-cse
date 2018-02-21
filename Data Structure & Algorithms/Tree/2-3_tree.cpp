#include<iostream>
using namespace std;
#include<stdlib.h>

struct node{
    int key1,key2;
    int binary;
    struct node *p1,*p2,*p3;
};

node *create_node(int num){
    node *newnode = new node();
    newnode->key1 = num;
    newnode->binary = 0;
    newnode->p1 = newnode->p2 = newnode->p3 = NULL;
    return newnode;
}

node *Insert(node *root,int num){
    if(root==NULL){
        root = create_node(num);
    }
    if(root->binary == 0){
        root->binary = 1;
        if(root->key1 > num){
            root->key2 = root->key1;
            root->key1 = num;
        }
        else{
            root->key2 = num;
        }
    }
    else{
        if(num < root->key1){
            root->p1 = Insert(root->p1,num);
        }
        else if(num > root->key1 && num < root->key2){
            root->p2 = Insert(root->p2,num);
        }
        else if(num > root->key2){
            root->p3 = Insert(root->p3,num);
        }
    }

    return root;
}
int main(){
    node* root = NULL;
    root = Insert(root,10);
    root = Insert(root,7);
    root = Insert(root,15);
    root = Insert(root,12);
    root = Insert(root,4);
    root = Insert(root,14);
    root = Insert(root,91);
    root = Insert(root,5);
    root = Insert(root,25);
    root = Insert(root,41);
    return 0;
}
