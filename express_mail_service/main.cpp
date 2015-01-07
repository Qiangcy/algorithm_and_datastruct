#include "express_mail.h"
int main()
{
    express_mail *e = new express_mail();
    while(1) {
        cout<<"\n\n********welcome!Please input the number of operation you want to take*********"<<endl;
        cout<<"1.input packages\t2.output all packages\t\n3.get_package\t4.sort"<<endl;
        char oper = ' ';
        cin>>oper;
        switch(oper) {
            case '1': e->input_packages_list(e); break;
            case '2': e->output_packages_list(e); break;
            case '3':
                      e->output_packages_list(e);
                      int n;
                      cout<<"what package do u want to take"<<endl;
                      cin>>n;
                      e->get_package(e, n);
                      cout<<"after get"<<endl;
                      e->output_packages_list(e);
                      break;
            case '4':
                      e->chosse_sort_packages(e);
                      break;
            default:
                      cout<<"No operation"<<endl<<"please input ag"<<endl;
                      break;
        }
    }
}
