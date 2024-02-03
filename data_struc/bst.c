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
int checkBST(node* root){//is a modified inorder
    static node* prev=NULL;
    if(root==NULL) return 1;
    if(!checkBST(root->left)) return 0;
    if(prev != NULL && prev->data>=root->data) return 0;
    prev=root;
    return(checkBST(root->right));
}
int max(int a,int b){
    if(b>a) return b;
    else return a;
}
int getHeight(node* root){
    // Write your code here
    if(root == NULL) return(-1);
    return(1 + max(getHeight(root->left),getHeight(root->right)));
}
node* search(node* root,int num){
    if(root!=NULL){
        if(num<root->data) return search(root->left,num);
        else if(num==root->data) return(root);
        else if(num>root->data) return search(root->right,num);
    }else return NULL;
}
node* insert(node* root,int key){
    /*if empty tree, create new node
    if key less than root data, recurse into the left subtree
    else                      , recurse into the right subtree*/
    if(root==NULL) return create(key);
    if(key<root->data) root->left=insert(root->left,key);
    if(key>root->data) root->right=insert(root->right,key);
    return(root);
}
node* least_common_anscestor(node *root, int v1, int v2 ) {
    if((v1<=root->data && root->data<=v2) || (v2<=root->data && root->data<=v1))
        return(root);//v1,v2 are on diffrent subtress of root, then lca of v1,v2 is root itself
    if(v1<root->data)//v1 and v2 are on he left subtree of root 
        return (least_common_anscestor(root->left,v1,v2));
    if(v1>root->data)//v1 and v2 are on the right subtree of root
        return (least_common_anscestor(root->right,v1,v2));
    return NULL;
}
void swap(node* root){
    node* temp=root->left;
    root->left=root->right;
    root->right=temp;
}
/* void insert(node* root,int num){
    while(1){
        if(root==NULL){
            root=create(num);
            return;
        }
        if(num<root->data){
            if(root->left==NULL){
                root->left=create(num);
                return;
            }
            else root=root->left;
        }
        if(num>root->data){
            if(root->right==NULL){
                root->right=create(num);
                return;
            }
            else root=root->right;
        }
    }
} */
/* 
void putin(node* root,int num){
    if(root==NULL){root=create(num);return;}
    if(root->left==NULL){root->left=create(num);return;}
    if(root->right==NULL){root->right=create(num);return;}
    if(num<=root->data){putin(root->left,num);}
    else{putin(root->right,num);}
}
int bstif(node* root){
    if(root->left==NULL&&root->right==NULL){
        return 1;
    }
    if((root->left==NULL) != (root->right==NULL)){
        return 0;
    }
    if(root->left->data>=root->right->data){
        return 0;
    }
    else{
        return(bstif(root->left)&&bstif(root->right));
    }
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
    root->right->right->left=create(13);//makes this not a bst (must be <15)
    root->right->right->right=create(15);
    root->right->right->right->right=create(16);
    if(checkBST(root)) printf("\nis bst\n");
    else printf("\nnot bst\n");
    preorder(root);printf("\n");
    inorder(root);printf("\n");
    postorder(root);printf("\n");
    printf("\n%d\n",modified_inorder(root));
    printf("%ld\n",sizeof(int));

    return 0;
}

/* void insert(node* root,int* num,int size){
    int i=0;
    if(root==NULL){
        root=create(num[i]);
        i++;
    }
    if(root->left==NULL){
        root->left=create(num[i]);
        i++;
    }
    if(root->right==NULL) {root->right=create(num[i]);}
    if(num<=root->data) {insert(root->left,num[i],size);}
    else {insert(root->right,num[i],size);}
} */