#include "../my_includes/LinkList.h"
#include "package.h"
#include "string.h"

class express_mail
{
    public:
        LinkList<package> *package_list;
        express_mail()
        {
            package_list = new LinkList<package>;
        }
        void input_packages_list(express_mail *& E);
        void output_packages_list(express_mail *& E);
        void get_package(express_mail *& E, int n);
        void swap(LinkList<package> *head, LinkList<package> *&a,LinkList<package> *&b);
        void bubble_sort_packages(express_mail *& E);
        void chosse_sort_packages(express_mail *& E);
        void search_by_name(express_mail *& E, char *name);
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

void express_mail::swap(LinkList<package> *head, LinkList<package> *&a,LinkList<package> *&b)
{
    LinkList<package> *record = head;
    LinkList<package> *a_piotr = NULL;
    LinkList<package> *b_piotr = NULL;
    //cout<<"a is"<<a<<endl;
    //cout<<"a is"<<a->data.phone_number<<endl;
    //cout<<"b is"<<b<<endl;
    //cout<<"b is"<<b->data.phone_number<<endl;
    LinkList<package> *temp = NULL;
    while((!a_piotr || !b_piotr) && head->next!=0) {
        //cout<<"head is"<<head<<endl;
        //cout<<"head is"<<head->data.phone_number<<endl;
        //cout<<"head.next is"<<head->next<<endl;
        //cout<<"head.next is"<<head->next->data.phone_number<<endl;
        if(head->next && head->next == a) {
            //    cout<<"a_piotr=head"<<endl;
            a_piotr = head;
        }else if(head->next && head->next == b) {
            //   cout<<"b_piotr=head"<<endl;
            b_piotr = head;
        }
        //        cout<<"head=head->next"<<endl;
        head = head->next;
        //       cout<<"end head is"<<head<<endl;
        //       cout<<"head next"<<endl;
    }
    //       cout<<"finish"<<endl;
    //   cout<<"a_piotr is"<<a_piotr<<endl;
    //    cout<<"a_piotr is"<<a_piotr->data.phone_number<<endl;
    //   cout<<"b_piotr is"<<b_piotr<<endl;
    //   cout<<"b_piotr is"<<b_piotr->data.phone_number<<endl;
    if(!a_piotr) {
        //       cout<<"a_piotr==null"<<endl;
        b_piotr->next = a;
    }
    //  else if(!b_piotr) {
    //      cout<<"b_piotr==null"<<endl;
    //      a_piotr->next = b;
    //  }
    else {
        //      cout<<"in else"<<endl;
        if(a_piotr->next == b_piotr)
            a_piotr->next = b;
        else{
            a_piotr->next = b;
            b_piotr->next = a;
        }
        if(head->next == a) {
            //cout<<"a_piotr=head"<<endl;
            a_piotr = head;
        }
        else if(head->next == b)
        {
            //cout<<"a_piotr=head"<<endl;
            b_piotr = head;
        }
        head = head->next;
        //        cout<<"head next"<<endl;
    }
    cout<<"ptr swap"<<endl;
    if(a->next == b) {
        a->next = b->next;
        b->next = a;
    }
    else{
        temp = b->next;
        b->next = a->next;
        a->next = temp;
    }
    cout<<"ptr swap finish"<<endl;
}

void express_mail::bubble_sort_packages(express_mail *& E)
{
    ;
}

void express_mail::chosse_sort_packages(express_mail *& E)
{
    LinkList<package> *min = E->package_list;
    LinkList<package> *first = E->package_list;
    LinkList<package> *second = E->package_list;
    long long int number_a, number_b, base;
    number_a = number_b = base = 0;
    bool first_flag = 1;
    while(first) {
        cout<<"sort start"<<endl;
        min = second = first;
        while(second) {
            //            char x;
            //            cin>>x;
            //            cout<<"secnod "<<second<<endl;
            //            cout<<"second.num"<<second->data.phone_number<<endl;
            //            cout<<"second start"<<endl;
            //     while(number_a > 10) {
            //         cout<<number_a<<endl;
            //         number_a %= base;
            //         base %= 10;
            //     }
            //     base = 10000000000;
            //     while(number_b > 10) {
            //         cout<<number_b<<endl;
            //         number_b %= base;
            //         base %= 10;
            //     }
            if(second->data.receive_time <= min->data.receive_time)
                if(second->data.phone_number%10 < min->data.phone_number%10)
                    min = second;
            second = second->next;
        }
        if(first != min) {
            //output_packages_list(E);
            swap(E->package_list, first, min);
            if(first_flag) {
                E->package_list = min;
                first_flag = 0;
            }
            //          cout<<"swap end"<<endl;
            //output_packages_list(E);
        }
        //        cout<<"origin first"<<first<<endl;
        //        cout<<"origin first.num :"<<first->data.phone_number<<endl;
        first = min->next;
        //        cout<<"first"<<first<<endl;
        //        char x;
        //        cin>>x;
    }
}

void express_mail::search_by_name(express_mail *& E, char *name)
{
    LinkList<package> *backup = E->package_list;
    int num = 0;
    while(E->package_list) {
        if(strcmp(E->package_list->data.receiver_name, name) != 0) {
            E->package_list = E->package_list->next;
            num++;
        }else {
            cout<<"Found!!!"<<endl;
            cout<<num<<endl;
            E->package_list->data.output_package_msg(&E->package_list->data);
            break;
        }
    }
    if(! E->package_list)
            cout<<"NOT  Found!!!"<<endl;
}
