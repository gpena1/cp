#include <bits/stdc++.h>
class node{
public:
    char value=0;
    node* left=nullptr;
    node* right=nullptr;
    node(char c){
        this->value=c;
    }
    bool operator<=(const node& other){
        return this->value<=other.value;
    }
};
class binary_search_tree{
    int height_t(node* r, int currentHeight){
        if (r->right&&r->left){
            return std::max(height_t(r->right,currentHeight+1),height_t(r->left,currentHeight+1));
        }
        if (r->right) return height_t(r->right,currentHeight+1);
        if (r->left) return height_t(r->left,currentHeight+1);
        return currentHeight;
    }
    int internal_path_length_t(node* r, int currentHeight){
        if (r->right&&r->left){
            int s1= internal_path_length_t(r->left,currentHeight+1);
            int s2= internal_path_length_t(r->right,currentHeight+1);
            return currentHeight+s1+s2;
        }
        if (r->right) return currentHeight+ internal_path_length_t(r->right,currentHeight+1);
        if (r->left) return currentHeight+ internal_path_length_t(r->left,currentHeight+1);
        return currentHeight;
    }
    int two_children(node* r){
        if(r->right&&r->left) {
            std::cout<<(r->value)<<' ';
            return 1+two_children(r->right)+two_children(r->left);
        }
        if(r->right) return two_children(r->right);
        if(r->left) return two_children(r->left);
        return 0;
    }
    int one_child(node* r){
        if(r->right&&r->left){
            return one_child(r->right)+one_child(r->left);
        }
        if (r->right){
            std::cout<<(r->value)<<' ';
            return 1+one_child(r->right);
        }
        if (r->left){
            std::cout<<(r->value)<<' ';
            return 1+one_child(r->left);
        }
        return 0;
    }
    int zero_children(node* r){
        if(r->right&&r->left) return zero_children(r->right)+ zero_children(r->left);
        if(r->right) return zero_children(r->right);
        if(r->left) return zero_children(r->left);
        std::cout<<r->value<<' ';
        return 1;
    }
public:
    node* root;
    int nodes=1;
    binary_search_tree(node* r){
        this->root=r;
    }
    void insert(node* t){
        node* q=root;
        while(true){
            if(*t<=*q){
                if(!q->left) {
                    q->left=t;
                    break;
                } else q=q->left;
            }else{
                if(!q->right){
                    q->right=t;
                    break;
                }else q=q->right;
            }
        }
        ++nodes;
    }
    int height(){
        return height_t(this->root, 0);
    }
    int internal_path_length(){
        return internal_path_length_t(this->root,0);
    }
    int external_path_length(){
        return internal_path_length()+(nodes<<1);
    }
    int zero_children(){
        return zero_children(this->root);
    }
    int one_child(){
        return one_child(this->root);
    }
    int two_children(){
        return two_children(this->root);
    }
};
int main(){
    std::string chill="INSERT STRING HERE";
    binary_search_tree* bst;
    for(int i=0;i<chill.length();++i){
        switch(i){
            case 0:
                bst=new binary_search_tree(new node(chill[0]));
                break;
            default:
                bst->insert(new node(chill[i]));
                break;
        }
    }
}
