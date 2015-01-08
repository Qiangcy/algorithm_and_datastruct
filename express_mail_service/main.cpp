#include "express_mail.h"
int main()
{
    express_mail *e = new express_mail();
    while(1) {
        cout<<"\n\n********welcome!Please input the number of operation you want to take*********"<<endl;
        cout<<"\t1.input packages\t2.output all packages\t\n\t3.get_package\t4.sort by phone and time\n\t5.search by name\n\ninput 0 to exit"<<endl;
        char *name;
        char oper = ' ';
        cin>>oper;
        switch(oper) {
            case '0':
                return 0;
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
            case '5':
                      name = new char(100);
                      cin>>name;
                      e->search_by_name(e, name);
                      delete name;
                      break;
            default:
                      cout<<"No operation"<<endl<<"please input ag"<<endl;
                      break;
        }
    }
}
