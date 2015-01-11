#include <iostream>
using namespace std;
class HashTable {
    public:
        bool *is_empty;
        int *element;
        int number;
        HashTable() {
            is_empty = NULL;
            element = NULL;
        }
        void init_hash_talbe(HashTable* &H);
        int hash(HashTable* &H, int element);
        void insert_hash_talbe(HashTable* &H, int element);
        int search_hash_talbe(HashTable* &H, int element);
        void output_hash_talbe(HashTable* &H);
};

void HashTable::init_hash_talbe(HashTable* &H)
{
    cout<<"cin memory size"<<endl;
    cin>>H->number;
    H->is_empty = new bool(H->number);
    H->element = new int(H->number);
    for(int i=0; i<H->number; ++i)
        H->is_empty[i] = 1;
}

int HashTable::hash(HashTable* &H, int key)
{
    return key%H->number;
}

void HashTable::insert_hash_talbe(HashTable* &H,int element)
{
    int addr = hash(H, element);
    while(! H->is_empty[addr]) {
        addr = hash(H, addr+1);
    }
    H->element[addr] = element;
    H->is_empty[addr] = 0;
}

int HashTable::search_hash_talbe(HashTable* &H, int element)
{
    int addr = H->hash(H, element);
    while(element != H->element[addr]) {
        cout<<element<<" element finding at addr"<<addr<<endl;
        if(H->is_empty[addr]) {
            cout<<element<<" not found"<<endl;
            return 0;
        }
        addr = H->hash(H, addr+1);
    }
    cout<<"element "<<element<<"find at "<<addr<<endl<<endl;
    return addr;
}

void HashTable::output_hash_talbe(HashTable* &H)
{
    for(int i=0; i<H->number; ++i) {
        cout<<H->element[i]<<"\t";
    }
    cout<<endl;
    for(int i=0; i<H->number; ++i) {
        cout<<H->is_empty[i]<<"\t";
    }
    cout<<endl;
}
