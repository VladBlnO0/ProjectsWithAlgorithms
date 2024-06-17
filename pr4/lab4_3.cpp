/*
Побудувати бінарне дерево пошуку з вхідної послідовності цілих чисел.
Визначити значення вузла, дитина якого містить мінімальне значення.
*/
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};
Node* root = NULL;

void PrintTree(Node* root, int space) {
    if (root == NULL) {
        return;
    }
    space += 10;
    PrintTree(root->right, space);
    for (int i = 10; i <= space; i++) {
        cout << "  ";
    }
    cout << root->data << "\n";
    PrintTree(root->left, space);
}
void InsertNode(int x, Node *leaf) {
    Node* new_node = new Node;
    new_node->data = x;
    new_node->left = NULL; 
    new_node->right = NULL;
    if (leaf == NULL) {
        root = new_node;
    }
    else {
        if (x < leaf->data) {
            if (leaf->left != NULL) {
                InsertNode(x, leaf->left);
            }
            else {
                leaf->left = new_node;
            }
        }
        else {
            if (x >= leaf->data) {
                if (leaf->right != NULL) {
                    InsertNode(x, leaf->right);
                }
                else {
                    leaf->right = new_node;
                }
            }
        }
    }
}
Node* SearchKey(Node* node, int key) {
    if (node == NULL) {
        return NULL;
    } 
    else {
        if (node->left->data == key) {
            cout << node->data << endl; 
            return NULL;
        }
        else {
            return SearchKey(node->left, key);
        }
    }
}
Node* SearchMin(Node* node, int min_value) {
    if (node == NULL) {
        SearchKey(root, min_value);
        return NULL;
    }
    else {
        if (node->data <= min_value) {
            min_value = node->data;
            return SearchMin(node->left, min_value);
        }
    }
}
void FreeMemory(Node *&Tree) {
    if (Tree != NULL) {
        FreeMemory(Tree->left);
        FreeMemory(Tree->right);
        delete Tree;
        Tree = NULL;
    }
}
int main() {
    InsertNode(6, root);
    InsertNode(10, root);
    InsertNode(2, root);
    InsertNode(4, root);
    InsertNode(1, root);
    InsertNode(8, root);
    InsertNode(12, root);
    InsertNode(7, root);
    InsertNode(3, root);
    InsertNode(9, root);
    PrintTree(root, 0);
    cout << endl;
    int min_value = 100;
    SearchMin(root, min_value);

    return 0;
}