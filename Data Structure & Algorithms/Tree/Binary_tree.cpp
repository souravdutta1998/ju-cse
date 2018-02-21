#include <iostream>
using namespace std;

// A Binary Tree Node
struct Node
{
    int data;
    Node *left, *right;
};

// A utility function to create a new Binary
// Tree Node
Node *newNode(int item)
{
    Node *temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Returns -1 if x doesn't exist in tree. Else
// returns distance of x from root
int findDistance(Node *root, int x)
{
    // Base case
    if (root == NULL)
      return -1;

    // Initialize distance
    int dist = -1;

    // Check if x is present at root or in left
    // subtree or right subtree.
    if ((root->data == x) ||
        (dist = findDistance(root->left, x)) >= 0 ||
        (dist = findDistance(root->right, x)) >= 0)
        return dist + 1;

    return dist;
}

// Driver Program to test above functions
int main()
{
    Node *root = newNode(5);
    root->left = newNode(10);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->left->right = newNode(25);
    root->left->right->right = newNode(45);
    root->right->left = newNode(30);
    root->right->right = newNode(35);

    cout << findDistance(root, 45);
    return 0;
}
