#include "binary_tree.h"
void func(Binary_tree<int>* &B);
int main()
{
    Binary_tree<int> *root = new Binary_tree<int>;
    root->data = 0;
    Binary_tree<int> *p = root->insert_right_child(root, 1);
    p->insert_right_child(p, 2);
    p->insert_left_child(p, 20);
    root->insert_left_child(root, 30);
    root->insert_right_child(root, 3);
    cout<<endl<<"**pre order**"<<endl;
    void (*FunP)(Binary_tree<int>* &B);
    FunP = &func;
    root->pre_order(root, FunP);
    cout<<endl<<"**in order**"<<endl;
    root->in_order(root);
    cout<<endl<<"**post order**"<<endl;
    root->post_order(root);
    cout<<endl<<"**level order**"<<endl;
    cout<<"********************"<<endl;
    root->level_order(root);

    root->search(root, 3);
    cout<<endl<<"finish"<<endl;

}
void func(Binary_tree<int>* &B)
{
    return;
}