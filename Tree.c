#include <stdio.h>
#include <stdlib.h>
    //binary tree node structure
 struct node{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node btree; //binary tree type definition
    // inorder traversal function
void inorder(btree *root){
        if(root != NULL){
            inorder(root->left);
            printf("%3d",root->data);
            inorder(root->right);
        }
    }
    //preorder traversal function
void preorder(btree *root){
        if(root != NULL){
            printf("%3d",root->data);
            preorder(root->left);
            preorder(root->right);
        }
    }
    //postorder traversal function
void postorder(btree *root){
        if(root != NULL){
            postorder(root->left);
            postorder(root->right);
            printf("%3d",root->data);
        }
    }
    //function to create a new node
btree *newnode(int x){ //ilk data
        btree *p;
        p = (btree*)malloc(sizeof(struct node));
        p->data = x;
        p->left = p->right = NULL;
        return p;
    }
    //function to insert a new node
btree *insert(btree *root, int x){
        if(root == NULL)
            root =  newnode(x);
        else{
            if(x<root->data)
                root->left = insert(root->left,x);
            else
                root->right = insert(root->right, x);
        }return root;
    }
    //function to find the minimum value node
int treeMin(btree *root){
        while(root->left != NULL)
            root = root->left;
        return root->data;
    }
    //function to delete a node
btree *deleteNode(btree *root, int x){
        btree *p,*q;
        if(root == NULL)
            return NULL;
        if(root->data == x){  //aranan veri bulundu ...
            if(root->left == root->right){  // null cocuk yok
                free(root);
                return NULL;
            }else{ //
                if(root->left == NULL){
                    p = root->right;
                    free(root);
                    return p;
                }else if(root->right == NULL){  //5 i sil
                    p = root->left;
                    free(root);
                    return p;
                }
                else{ // IKI COCUK...
                        p = q = root->right;
                        while(p->left != NULL)
                            p = p->left;
                        p->left = root->left;
                        free(root);
                        return q;
                    }
            }
        }
        else if(root->data < x){
            root->right = deleteNode(root->right, x);
        }
        else{
            root->left = deleteNode(root->left, x);
        }
        return root;
    }
    //function to calculate the height of the tree
int height(btree *root){
    if(root == NULL)
        return -1;
    else{
        int lheight, rheight;
        rheight = height(root->right);
        lheight = height(root->left);
        if(lheight > rheight)
            return lheight + 1;
        else
            return rheight + 1;
    }
    }
    //function to mirror the tree
int mirror(btree *root){
        if(root != NULL){ 
            btree *temp;
            mirror(root->left);
            mirror(root->right);
            temp = root->right;
            root->right = root->left;
            root->left = temp;
        }
        else
            return 0;
    }
    //main function
void main(){
    btree *myroot = NULL;
    int x,y;
    
    printf("enter numbers to insert into tree (-1 to stop): "); 
    scanf("%d",&x);
    while(x != -1){
        myroot = insert(myroot,x);
        scanf("%d",&x);

    }
    printf("Height of tree: %d\n",height(myroot));
    printf("enter number to delete from tree: ");
    scanf("%d",&y);
    myroot = deleteNode(myroot,y);
    preorder(myroot);
    printf("\nThe new height of tree: %d\n",height(myroot));
    mirror(myroot);
    preorder(myroot);
}