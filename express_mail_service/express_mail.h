#include "../my_includes/LinkList.h"
#include "package.h"
class express_mail
{
    public:
        int number_of_packages;
        LinkList<package> *package_list;
        express_mail()
        {
            package_list = new LinkList<package>;
            number_of_packages=0;
        }
        void input_packages_list(express_mail *& E);
        void output_packages_list(express_mail *& E);
        void get_package(express_mail *& E, int n);
};

void express_mail::input_packages_list(express_mail *& E)
{
    cout<<"cin packages "<<endl;
    int number;
    cin>>number;
    for(int i=0; i<number; ++i) {
        package *p = new package();
        cout<<endl<<"cin number "<<i+1<<" package :   "<<endl;
        if(i == 0) {
            p->input_package_msg(p);
            E->package_list->data = *p;
            E->package_list->next = NULL;
        }else {
            p->input_package_msg(p);
            E->package_list->insert_element(E->package_list, i, *p);
        }
    }
}

void express_mail::output_packages_list(express_mail *& E)
{
    LinkList<package> *backup = E->package_list;
    while(E->package_list) {
        E->package_list->data.output_package_msg( &(E->package_list->data) );
        E->package_list = E->package_list->next;
    }
    E->package_list = backup;
}

void express_mail::get_package(express_mail*& E, int n)
{
    cout<<"get number "<<n<<"package"<<endl;
    E->package_list->delete_element(E->package_list, n);
    cout<<"get finish"<<endl;
}

void express_mail::output_packages_list(express_mail *& E)
