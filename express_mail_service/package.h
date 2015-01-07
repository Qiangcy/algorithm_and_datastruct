#include <iostream>
using namespace std;
class package
{
    public:
        char *package_name;
        char *receiver_name;
        char *deliver_name;
        long long int phone_number;
        long long int receive_time;
        package()
        {
            package_name = new char(100);
            receiver_name = new char(100);
            deliver_name = new char(100);
            phone_number = 0;
        }
        void input_package_msg(package* &P);
        void output_package_msg(package* P);
};

void package::input_package_msg(package* &P)
{
    cout<<"input package_name"<<endl;
    cin>>P->package_name;
    cout<<"input receiver_name"<<endl;
    cin>>P->receiver_name;
    cout<<"input deliver_name"<<endl;
    cin>>P->deliver_name;
    cout<<"input phone_number"<<endl;
    cin>>P->phone_number;
    cout<<"input receive_time"<<endl;
    cin>>P->receive_time;
}

void package::output_package_msg(package* P)
{
    cout<<" package_name: "<<P->package_name;
    cout<<" receiver_name: "<<P->receiver_name;
    cout<<" deliver_name: "<<P->deliver_name;
    cout<<" phone_number: "<<P->phone_number;
    cout<<" receive_time: "<<P->receive_time;
    cout<<endl;
}
