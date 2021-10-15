#include "bintree.h"
#include "nodedata.h"
//---------------------------------------------------------------------------
// BinTree()
// 
// Constructor for a binTree object. Establishes a new root node & initializes
// the left and right pointers from the root. 
BinTree::BinTree()
{
    root = new Node();
    root->left = nullptr;
    root->right = nullptr;
}

BinTree::~BinTree() {
    if (root->data != nullptr) {
        destroyForDestructor(root);

    }
}

void BinTree::destroyForDestructor(Node* current) {
    if (current != nullptr) {
        destroyForDestructor(current->left);
        destroyForDestructor(current->right);
        delete current;
    }
}

//---------------------------------------------------------------------------
//isEmpty
// 
// Determines if tree is empty based on root values. If the root has no leaves
// to left or right, tree is empty.
// Pre: A properly established tree with a root
// Post: No changes to the tree

bool BinTree::isEmpty() const {
    if (root->data == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

//---------------------------------------------------------------------------
// insert
// 
// Inserts a given node into the tree. Returns bool dictating if insert was 
// successful. Traverses the tree based on insertion value being lesser or 
// greater than the root value. LHS of tree is less, RHS is greater. Before 
// any insertion operations are taken, determines if tree is empty. 
bool BinTree::insert(NodeData* dataptr) {
    Node* ptr = new Node;     // exception is thrown if memory is not allocated
    ptr->data = dataptr;
    dataptr = nullptr;
    ptr->left = ptr->right = nullptr;
    if (isEmpty()) {
        root = ptr;
    }
    else {
        Node* current = root;
        bool inserted = false;

        // if item is less than current item, insert in left subtree,
        // otherwise insert in right subtree
        while (!inserted) {
            if (*ptr->data < *current->data) {
                if (current->left == nullptr) {           // at leaf, insert left
                    current->left = ptr;
                    inserted = true;
                }
                else
                    current = current->left;               // one step left
            }
            else if (*ptr->data == *current->data) {
                inserted = true;
            }
            else {
                if (current->right == nullptr) {          // at leaf, insert right
                    current->right = ptr;
                    inserted = true;
                }
                else
                    current = current->right;              // one step right
            }
        }
    }
    return true;
}

// Retrieve a NodeData, the sibling of a given object in the
// tree(via pass - by - reference, second parameter which may
// initially be garbage).It will be a copy of the actual object in the 
// tree(if param 1 exists and is found). SPECIAL INSTRUCTIONS : For this 
// function, you do not get to know that the tree is a binary search tree. You
// must solve the problem for a general binary tree where data could be stored
// anywhere(e.g., tree T4 above).

// Retrieve a NodeData* of a given object in the tree (via pass-by-reference,
// the second parameter). Return whether found.The second parameter may 
// initially be garbage, will point to the actual object in the tree if 
// it is found.

bool BinTree::retrieve(const NodeData& nodeToFind, NodeData*& pointerToAssign)
    const {

    Node* current = new Node;
    current = root;


    return retrieveHelper(nodeToFind, pointerToAssign, current);

}

bool BinTree::retrieveHelper(const NodeData& nodeToFind, 
    NodeData*& pointerToAssign, Node* current) const {

    Node* holdData = new Node;
    *holdData->data = nodeToFind;

    if (current == nullptr) {
        return false;
    }
    else if (current->data == holdData->data) {
        pointerToAssign = current->data;
        return true;
    }

    // if left is available travel left
    if (current->left != nullptr) {

        bool returnLeftValue = retrieveHelper(nodeToFind, pointerToAssign, current->left);
        if (returnLeftValue == true) {
            return true;
        }
    }
    if (current->right != nullptr) {
        bool returnRightValue = retrieveHelper(nodeToFind, pointerToAssign, current->right);
        if (returnRightValue == true) {
            return true;
        }
    }
    else if (current->left == nullptr && current->right == nullptr) {
        return false;
    }
    return false;
}












//---------------------------------------------------------------------------
// displaySideways 
// Displays a binary tree as though you are viewing it from the side.
// Turn head 90 degrees counterclockwise (to the left) to see tree structure.
// Hard coded displaying to standard output.

void BinTree::displaySideways() const {
    sidewaysHelper(root, 0);
}

void BinTree::sidewaysHelper(Node* current, int level) const {
    if (current != nullptr) {
        level++;
        sidewaysHelper(current->right, level);

        // indent for readability, same number of spaces per depth level 
        for (int i = level; i >= 0; i--) {
            cout << "      ";
        }

        cout << *current->data << endl;        // display information of object
        sidewaysHelper(current->left, level);
    }
}
