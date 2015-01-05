#include "binary_tree.h"
void func(Binary_tree<int>* &B);
int main()
{
    Binary_tree<int> *root = new Binary_tree<int>;
    root->data = 0;
    root->insert(root, 30);
    root->insert(root, 443);
    root->insert(root, 12);
    root->insert(root, 14);
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

    cout<<endl<<"search"<<endl;
    root = root->search(root, 29);
    cout<<"data:"<<root->data<<endl;
    cout<<endl<<"finish"<<endl;

}
void func(Binary_tree<int>* &B)
{
    return;
}
