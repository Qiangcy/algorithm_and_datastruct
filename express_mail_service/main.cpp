#include "express_mail.h"
int main()
{
    express_mail *e = new express_mail();
    e->input_packages_list(e);
    e->output_packages_list(e);
    e->get_package(e, 1);
    cout<<"after get"<<endl;
    e->output_packages_list(e);
    cout<<"ouput finish"<<endl;
}
