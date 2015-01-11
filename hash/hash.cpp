#include "hash.h"
int main()
{
    HashTable *hashtable = new HashTable;
    hashtable->init_hash_talbe(hashtable);
    hashtable->output_hash_talbe(hashtable);
    hashtable->insert_hash_talbe(hashtable, 454);
    hashtable->insert_hash_talbe(hashtable, 9);
    hashtable->insert_hash_talbe(hashtable, 50);
    hashtable->insert_hash_talbe(hashtable, 22);
    hashtable->output_hash_talbe(hashtable);
    hashtable->search_hash_talbe(hashtable, 9);
    hashtable->search_hash_talbe(hashtable, 22);
    hashtable->search_hash_talbe(hashtable, 1);
    hashtable->search_hash_talbe(hashtable, 50);
    hashtable->search_hash_talbe(hashtable, 90);
    delete hashtable;
}
