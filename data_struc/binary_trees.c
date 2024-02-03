#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
typedef struct node node;
node* create(int x){
    node* new=malloc(sizeof(node));
    new->data=x;
    new->left=NULL;
    new->right=NULL;
    return(new);
}
void preorder(node* root){
    if(root !=NULL){
        printf("%d,",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d,",root->data);
    }
}
void inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d,",root->data);
        inorder(root->right);
    }
}
int modified_inorder(node* root){//checks whether given tree is a binary search tree or not
    static node* prev=NULL;

    if(root != NULL){
        if(!modified_inorder(root->left)) return 0;
        if(prev!=NULL && root->data<=prev->data) return 0;
        prev=root;
        return(modified_inorder(root->right));
    }else return 1;
}
node* search(node* root,int num){
    if(root!=NULL){
        if(num<root->data) return search(root->left,num);
        else if(num==root->data) return(root);
        else if(num>root->data) return search(root->right,num);
    }else return NULL;
}
/*
int main(){
    node* root=create(7);
    root->left=create(2);
    root->right=create(3);
    root->left->left=create(1);
    root->right->right=create(4);
    //pre_order of this will be 7[2[1]][3[4]]: 7,2,1,3,4
    //post_order of this will be 1,2,4,3,7
    //in_order of this will be 1,2,7,3,4
    inorder(root);
    return 0;
}
*/
int main(){
    node* root=create(7);
    root->left=create(5);
    root->left->left=create(3);
    root->left->right=create(6);
    root->right=create(9);
    root->right->left=create(8);
    root->right->right=create(11);
    root->right->right->left=create(10);//makes this not a bst (must be 10)
    root->right->right->right=create(15);

    preorder(root);printf("\n");
    inorder(root);printf("\n");
    postorder(root);printf("\n");
    printf("\n%d\n",modified_inorder(root));
    printf("%ld\n",sizeof(int));

    return 0;
}
