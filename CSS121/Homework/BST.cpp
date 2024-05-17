#include <iostream>
using  namespace std;
struct Node
{
    int key;
    struct Node* left;
    struct Node* right;
};
struct Node* Newnode(int key){
    struct Node* current = new Node; 
    current->key = key;
    current->left = current -> right = nullptr;
    return current;
}
struct Node* insert(struct Node* node,int key){
    if(node == nullptr)return Newnode(key);
    if(key < node->key){
        node->left = insert(node->left,key);
    }
    else if(key > node->key){
        node->right = insert(node->right,key);
    }
    return node;
}
void preorder(Node* subroot){
    if(subroot == nullptr)return;
    cout << subroot->key << " ";
    preorder(subroot->left);
    preorder(subroot->right);
}
void inorder(Node* subroot){
    if(subroot == nullptr)return;
    inorder(subroot->left);
    cout << subroot->key << " ";
    inorder(subroot->right);
}
void postorder(Node* subroot){
    if(subroot == nullptr)return;
    postorder(subroot->left);
    postorder(subroot->right);
    cout << subroot -> key << " ";
}
int main(){
    struct Node* root = nullptr;
    root = insert(root,10);
    insert(root,8);
    insert(root,2);
    insert(root,4);
    insert(root,3);
    insert(root,15);
    insert(root,26);
    insert(root,30);
    insert(root,17);
    insert(root,6);

    cout << "Preorder = ";
    preorder(root);
    cout << "\n" ;
    cout << "Inorder = ";
    inorder(root);
    cout << "\n" ;
    cout << "Postorder = ";
    postorder(root);
}