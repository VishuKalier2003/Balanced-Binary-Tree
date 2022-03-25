/* Implementation of Binary Trees... A Binary Tree Node can have maximum Two Child Nodes...
The Maximum Nodes with level x is 2^x... The Maximum Nodes in Tree of Height h is 2^h - 1... For x
Nodes the minimum possible level is log(x + 1)... A Binary tree with n leaves has atleast 
log(n + 1) + 1 number of levels */
#include <iostream>
#include <queue>
using namespace std;
class Node                    // Node class created for each Tree Node creation
{
    public:
    int data;         // Data member
    Node* left;      // Left Node pointer
    Node* right;     // Right Node pointer
    Node* root;      // Root Node pointer
    public:
    Node (int val)    // Parametrized Constructor
    {
        data = val;
        left = NULL;
        right = NULL;
        root = NULL;
    }
};
class BinaryTree     //  Class created for Binary Tree Implementation ( Non-Linear Data Structure )
{
    public:
    Node* InsertNodeInTree(Node* root, int val)   // Inserting Node recursively.. O(log n) time
    {
        if(root == NULL)               // If No root node is there, create one
            return new Node(val);
        if(val <= root -> data)   // If data is lesser than or equal to parent store in left subtree
            root -> left = InsertNodeInTree(root -> left, val);
        else         // If data is greater than the parent stor it in right subtree
            root -> right = InsertNodeInTree(root -> right, val);
        return root;
    }
    void ShowTree(Node* root)   // Displaying tree with Node.. O(log n) time
    {
        Node* temp = root;
        if(temp == NULL)    // If Tree is empty nothing to show
            return;                            // Control moves out of the function
        ShowTree(temp -> left);     // Recursive Call
        cout << "Node: " << endl;
        if(temp -> left != NULL)    // If left subtree is not empty
            cout << "\t" << temp -> data << " ---> " << temp -> left -> data << "\t Left ( Occupied )" << endl;
        else      // If left subtree is empty
            cout << "\t" << temp -> data << "\t\t Left ( Empty )" << endl;
        if(temp -> right != NULL)   // If right subtree is not empty
            cout << "\t" << temp -> data << " ---> " << temp -> right -> data << "\t Right ( Occupied ) " << endl;
        else     // If right subtree is empty
            cout << "\t" << temp -> data << "\t\t Right ( Empty )" << endl;
        ShowTree(temp -> right);     // Recursive Call
    }
    int Height(Node* root)   // Function to evaluate Height
    {
        if(root == NULL)    // If current Nod3e is empty add zero to the height
            return 0;
        int lh = Height(root -> left);    // Adding Left Subtree height
        int rh = Height(root -> right);   // Adding Right subtree height
        return max(rh, lh) + 1;             //  Taking the maximum of the Left and Right subtree
    }
    bool BalancedBinarySearchTree(Node* root) // Every Node will be recursively called twice... O(n^2) time
    {       // Recursive Call
        if(root == NULL)          // If current Node is empty
            return true;      //  The Node is automatically balanced
        if(BalancedBinarySearchTree(root -> left) == false)    // If any Left Node is Unbalanced
            return false;      // Return false
        if(BalancedBinarySearchTree(root -> right) == false)   // If any Right Node is Unbalanced
            return false;      //  Return false
        int left_height = Height(root -> left);      // Evaluating height of the Left subtree
        int right_height = Height(root -> right);    // Evaluating height of the Right subtree
        if(abs(left_height - right_height) <= 1)   //  If the absolute difference is less than or equal to one
            return true;
        else
            return false;
    }
    bool BalancedBinaryTree(Node* root, int* height)  // Every Node will be Recursively called Once... O(n) time
    {
        if(root == NULL)   // If root ( current ) becomes empty return true, it will always be balanced
            return true;
        int lh = 0, rh = 0; 
        if(BalancedBinaryTree(root -> left, &lh) == false)  // Recursive Call for Left Subtree
            return false;
        if(BalancedBinaryTree(root -> left, &rh) == false)  // Recursive Call for Right Subtree
            return false;
        *height = max(lh, rh) + 1;   // Height pointer to store height of each current Node during Recursion 
        if(abs(lh - rh) <= 1)       // Evaluating absolute value
            return true;
        else
            return false;
    }
};
int main()
{
    Node* root = NULL;      // Root node initialization
    BinaryTree binarytree;      // Object creation of Binary Tree
    int s, x;
    cout << "Enter root Node value : ";
    cin >> x;
    root = binarytree.InsertNodeInTree(root, x);    // Root Node created
    cout << "Enter the number of Nodes to Insert in the Binary Search Tree : ";
    cin >> s;
    for(int i = 1; i <= s; i++)   // Loop begins
    {
        cout << "Enter the New Node value : ";
        cin >> x;
        binarytree.InsertNodeInTree(root, x);   // Calling Insert Tree function
    }
    binarytree.ShowTree(root);
    if(binarytree.BalancedBinarySearchTree(root))
        cout << "The Binary Tree is Balanced Binary Search Tree ( BBST ) !!" << endl;
    else
        cout << "The Binary Tree is Unbalanced Binary Search Tree !!" << endl;
    int h = 0;
    if(binarytree.BalancedBinaryTree(root, &h))
        cout << "The Binary Search Tree is Balanced Binary Search Tree !!" << endl;
    else
        cout << "The Binary Search Tree is Unbalanced !!" << endl;
    return 0;          // End of Program
}