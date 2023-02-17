#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string data;
    Node* left;
    Node* right;

public:
    Node(string data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* createNode(Node* root, string data)
{
    if(root == NULL) {
        Node* n = new Node(data);
        return n;
    }
    if(data < root->data) {
        root->left = createNode(root->left, data);

    } else if(data > root->data) {
        root->right = createNode(root->right, data);
    }
    return root;
}

void inorder(Node* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{

    cout << " Your name - Due date " << endl;

    myBTS BTS1; // Declare/Instanitate an instance of the BTS

    BTS1.inTree("Fred");

    BTS1.inTree("Able");

    BTS1.inTree("Tuyet");

    BTS1.inTree("Mojo");

    BTS1.inTree("Linda");

    BTS1.inTree("Leena");

    BTS1.inTree("Xoe");

    BTS1.inTree("Zohe");

    BTS1.inTree("Alfred");

    BTS1.inTree("Thanos");

    BTS1.inTree("koji");

    BTS1.inTree("Hally");

    BTS1.inTree("Lee");

    BTS1.inTree("Mode");

    cout << "Number of names in the tree: " << BTS1.count() << endl;

    if(BTS1.verify()) // Function returns a Boolean value

    {
        cout << "BST Verified" << endl;
    }

    else

    {
        cout << "Not a BST" << endl;
    }

    cout << "Current Tree height: " << BTS1.currentTreeHeight() << endl;

    BTS1.inOrderPrintTree();

    BTS1.reBalance();

    cout << "Current Tree height: " << BTS1.currentTreeHeight() << endl;

    BTS1.detree("Hally");

    if(BTS1.find("Hally")) // Function returns a Boolean value

    {
        cout << "Hally is in the List"
    }
    << endl;
}

else

{
    cout << "Hally is not in the List" << endl;
}

cout << "Deleted Hally" << endl;

cout << "Number of names in tree: " << BTS1.count() << endl;

if(BTS1.find("Hally")) // Function returns a Boolean value

{
    cout << "Hally is in the List"
}
<< endl;
}

else

{
    cout << "Hally is not in the List" << endl;
}

BTS1.reBalance();

BTS1.inOrderPrintTree();

if(BTS1.find("Thanos")) // Function returns a Boolean value

{
    cout << "Thanos is in the List"
}
<< endl;
}

else

{
    cout << "Thanos is not in the List" << endl;
}
}: