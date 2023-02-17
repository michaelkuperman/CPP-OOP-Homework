#include <bits/stdc++.h>
using namespace std;

class myBiTree
{
    // array which will contain all the nodes' data
    int tree[1000];

    // variable to keep record of number of nodes in
    // binary tree
    int n;

public:
    // constructor
    myBiTree()
    {
        long i;
        for(i = 0; i < 1000; i++) {
            tree[i] = INT_MIN;
        }
        n = 0;
    }

    // Function to add root to the binary tree
    // It is called by insert() function
    // It returns false if there was no node in binary tree
    bool root(int key)
    {
        if(tree[0] == INT_MIN) {
            tree[0] = key;
            return false;
        }
        return true;
    }

    // Function to insert data in binary tree
    void insert(int key)
    {
        // call root() to add root, if it returns true,
        // that means a root already exists, so insert data in the array
        if(root(key)) {
            int i;
            for(i = 0; i < 1000; i++) {
                if(tree[i] == INT_MIN) {
                    tree[i] = key;
                    break;
                }
            }
        }

        n++;
    }

    // Function to find the deepest and rightmost node
    // in binary tree, which will be the last element of the array
    int deepestRightMost()
    {
        int deepest;
        deepest = tree[n - 1];
        return deepest;
    }

    // Function delete key from the binary tree
    // To delete a node, it will be replaced by deepest
    // and rightmost node of the tree, i.e., the last element
    bool deleteBi(int key)
    {
        int i;

        // Loop to traverse array
        for(i = 0; i < n; i++) {
            // if key is found
            if(tree[i] == key) {
                // replace it with deepest and rightmost
                // element and deepest rightmost element is replaced by INT_MIN
                tree[i] = deepestRightMost();

                n--;
                return true;
            }
        }

        // if reach here, that means the key was not found in array
        return false;
    }

    // Function to get index of left child of parent index
    int get_left(int parent)
    {
        if(tree[parent] != INT_MIN && ((2 * parent) + 1) < n) {
            return (2 * parent) + 1;
        }

        return -1;
    }

    // Function to get index of right child of parent index
    int get_right(int parent)
    {
        if(tree[parent] != INT_MIN && ((2 * parent) + 2) < n) {
            return (2 * parent) + 2;
        }
        return -1;
    }

    // Funcion to print preorder traversal of binary tree
    void preOrderPrintAll(int index)
    {
        if(index >= 0 && tree[index] != INT_MIN) {
            cout << tree[index] << " ";
            preOrderPrintAll(get_left(index));
            preOrderPrintAll(get_right(index));
        }
    }

    // Function to print inorder traversal of binary tree
    void inOrderPrintAll(int index)
    {
        if(index >= 0 && index < n && tree[index] != INT_MIN) {
            inOrderPrintAll(get_left(index));
            cout << tree[index] << " ";
            inOrderPrintAll(get_right(index));
        }
    }

    // Function to print postorder traversal of binary tree
    void postOrderPrintAll(int index)
    {
        if(index >= 0 && index < n && tree[index] != INT_MIN) {
            postOrderPrintAll(get_left(index));
            postOrderPrintAll(get_right(index));
            cout << tree[index] << " ";
        }
    }
};

int main()
{
    cout << "Michael Kuperman:10/10/2021" << endl;
    // create object of class myBiTree
    myBiTree T1;

    // insert nodes
    T1.insert(15);
    T1.insert(9);
    T1.insert(21);
    T1.insert(3);
    T1.insert(11);
    T1.insert(17);
    T1.insert(42);

    // print preorder traversal
    cout << "Preorder: ";
    T1.preOrderPrintAll(0);
    cout << endl;

    //      print inorder traversal
    cout << "Inorder: ";
    T1.inOrderPrintAll(0);
    cout << endl;

    // print postorder traversal
    cout << "Postorder: ";
    T1.postOrderPrintAll(0);
    cout << endl;

    //      delete element 17
    //      if 17 is not found in array
    T1.deleteBi(17);

    //      print preorder traversal after trying to delete 17
    cout << "Preorder: ";
    T1.preOrderPrintAll(0);
    cout << endl;

    return 0;
}