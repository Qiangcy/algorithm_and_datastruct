#include <iostream>
#include <vector>
using namespace std;
template <typename Type>
class Binary_tree {
    public:
        Binary_tree *left_child, *right_child;
        Type data;
        Binary_tree() {
            left_child = NULL;
            right_child = NULL;
        }
        Binary_tree* insert(Binary_tree* &B, Type insert_data);
        Binary_tree* search(Binary_tree* &B, Type search_data);
        Binary_tree* insert_left_child (Binary_tree* &B, Type insert_data);
        Binary_tree* insert_right_child (Binary_tree* &B, Type insert_data);
typedef void (*FunType)(Binary_tree* &B);
        void pre_order (Binary_tree* &B, FunType fp);
        void in_order (Binary_tree* &B);
        void post_order (Binary_tree* &B);
        void level_order (Binary_tree* &B);
};

template <typename Type>
Binary_tree<Type>* Binary_tree<Type>::insert(Binary_tree* &B, Type insert_data)
{
    cout<<"insert"<<endl;
    if(! B) {
        B = new Binary_tree;
        B->data = insert_data;
        return B;
    }
    if(insert_data < B->data)
        B->left_child = insert(B->left_child, insert_data);
    else
        B->right_child = insert(B->right_child, insert_data);
    return B;
}

template <typename Type>
Binary_tree<Type>* Binary_tree<Type>::search(Binary_tree* &B, Type search_data)
{
    cout<<"search data: "<<search_data<<endl;
    Binary_tree *backup;
    while(B && B->data!=search_data) {
        backup  B;
        if(search_data < B->data)
            B = B->left_child;
        else
            B = B->right_child;
    }
    return backup;
//    if(B->data == search_data)
//        return B;
//    if(search_data < B->data) {
//        if(! B->left_child)
//            return B;
//        B = search(B->left_child, search_data);
//    }else {
//        if(! B->right_child)
//            return B;
//        B = search(B->right_child, search_data);
//    }
}

template <typename Type>
Binary_tree<Type>* Binary_tree<Type>::insert_left_child(Binary_tree* &B, Type insert_data)
{
    Binary_tree *insert_node = new Binary_tree;
    insert_node->data = insert_data;

    insert_node->left_child = B->left_child;
    B->left_child = insert_node;
    return B->left_child;
}


template <typename Type>
Binary_tree<Type>* Binary_tree<Type>::insert_right_child(Binary_tree* &B, Type insert_data)
{
    Binary_tree *insert_node = new Binary_tree;
    insert_node->data = insert_data;

    insert_node->right_child = B->right_child;
    B->right_child = insert_node;
    return B->right_child;
}

template <typename Type>
void Binary_tree<Type>::pre_order(Binary_tree* &B, FunType fp)
{
    if(!B)
        return;
    cout<<' '<<B->data;
    if(!B->right_child && !B->left_child)
        cout<<' '<<B->data<<"is a leaf";
    pre_order(B->left_child, fp);
    pre_order(B->right_child, fp);
}

template <typename Type>
void Binary_tree<Type>::in_order(Binary_tree* &B)
{
    if(!B)
        return;
    in_order(B->left_child);
    cout<<' '<<B->data;
    if(!B->right_child && !B->left_child)
        cout<<' '<<B->data<<"is a leaf";
    in_order(B->right_child);
}

template <typename Type>
void Binary_tree<Type>::post_order(Binary_tree* &B)
{
    if(!B)
        return;
    post_order(B->left_child);
    post_order(B->right_child);
    cout<<' '<<B->data;
    if(!B->right_child && !B->left_child)
        cout<<' '<<B->data<<"is a leaf";
}

template <typename Type>
void Binary_tree<Type>::level_order(Binary_tree* &B)
{
    vector< Binary_tree* > vec;
    vec.push_back(B);
    int cur = 0, end = 1;
    while(cur < vec.size()) {
        end = vec.size();
        while(cur < end) {
            cout<<vec[cur]->data<<' ';
            if (vec[cur]->right_child)
                vec.push_back(vec[cur]->right_child);
            if (vec[cur]->left_child)
                vec.push_back(vec[cur]->left_child);
            ++cur;
        }
        cout<<endl;
    }
}
