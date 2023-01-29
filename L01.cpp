#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *right;
        Node *left;

        Node(int data){
            this->data = data;
            this->right = NULL;
            this->left = NULL;
        }
};

// inserting node in binary search tree
Node * insert(Node * root, int data){
    if(root == NULL){
        Node *temp = new Node(data);
    }

    if(root->data > data){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }

    return root;
}

// searching node in binary search tree
bool search(Node * root, int data){
    if(root == NULL){
        return 0;
    }

    if(root->data == data){
        return true;
    }

    if(root->data > data){
        return search(root->left, data);
    }
    else{
        return search(root->right, data);
    }
}

//finding max value in BST
int max(Node * root){
    Node *temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp->data;
}

int min(Node * root){
    Node *temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->data;
}

Node * del(Node * root, int data){
    if(root == NULL){
        return root;
    }

    if(root->data == data){
        // 0 child
        if(root->right != NULL && root->left != NULL){
            delete root;
            return NULL;
        }
        // 1 child 
        // left child
        else if(root->right == NULL && root->left != NULL){
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // right child
        else if (root->right != NULL && root->left == NULL){
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        else if(root->right != NULL && root->left != NULL){
            int mini = min(root->right);
            root->data = mini;
            root->right = del(root->right, mini);
            return root;
        }
    }

    if(root->data > data){
        root->left = del(root->left, data);
    }
    else{
        root->right = del(root->right, data);
    }

    return root;
}