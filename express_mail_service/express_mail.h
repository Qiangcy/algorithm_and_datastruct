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
        void output_packages_list(express_mail * E);
};

void express_mail::input_packages_list(express_mail *& E)
{
    cout<<"cin packages "<<endl;
    int number;
    cin>>number;
    package *p = new package();
    for(int i=0; i<number; ++i) {
        p->input_package_msg(p);
        E->package_list->insert_element(E->package_list, i, *p);
        p->output_package_msg(p);
    }
}

void express_mail::output_packages_list(express_mail * E)
{
    while(E->package_list) {
        E->package_list->data.output_package_msg( &(E->package_list->data) );
        E->package_list = E->package_list->next;
    }

}
