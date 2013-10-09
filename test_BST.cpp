#include "BST.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::vector;


/**
 * A simple test driver for the BST class template.
 * P1 CSE 100 2012
 * Author: P. Kube (c) 2012
 */
int main() {
    
    /* Create an STL vector of some ints */
    vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(1);
    v.push_back(100);
    v.push_back(-33);
    v.push_back(99);
    
    /* Create an instance of BST holding int */
    BST<int> b;
    
    /* Insert a few data items. */
    vector<int>::iterator vit = v.begin();
    cout<<*vit<<endl;//Test
    
    vector<int>::iterator ven = v.end();//Is this an iterator????
    cout<<*ven<<endl;//Test
    
    
    for(; vit != ven; ++vit) {
        // all these inserts are unique, so should return true
        if(! b.insert(*vit) ) {
            cout << "Incorrect return value when inserting " << *vit << endl;
            return -1;
        }
    }
    
    //    vit = v.begin();
    //    for(; vit != ven; ++vit) {
    //        // all these inserts are duplicates, so should return false
    //        if( b.insert(*vit) ) {
    //            cout << "Incorrect return value when re-inserting " << *vit << endl;
    //            return -1;
    //        }
    //    }
    //cout<<"everything is okay"<<endl;
    
    /* Test size. */
    cout << "Size is: " << b.size() << endl;
    cout<<"V size is "<<v.size()<<endl;
    
    if(b.size() != v.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }
    
    /* Test find return value. */
    vit = v.begin();
    cout<<"1 everything is okay"<<endl;
    cout<<"begin is "<<*vit<<endl;
    
    BST<int>::iterator en = b.end();
    
    cout<<"end is "<<*en<<endl;//end() is not correct
    b.find(50);
    // b.del(3);
    for(; vit != ven; ++vit) {
        if(*(b.find(*vit)) != *vit) {
            cout << "Incorrect return value when finding " << *vit << endl;
            return -1;
        }
    }
    
    
    /* Sort the vector, to compare with inorder iteration on the BST */
    sort(v.begin(),v.end());
    cout<<"everything is okay"<<endl;
    
    /* Test BST iterator; should iterate inorder */
    cout << "traversal using iterator:" << endl;
    vit = v.begin();
    // BST<int>::iterator en = b.end();//Unused variable 'en'
    BST<int>::iterator it = b.begin();
    for(; vit != ven; ++vit) {
        cout << *it << endl;
        if(*it != *vit) {
            cout << *it << "," << *vit << ": Incorrect inorder iteration of BST." << endl;
            return -1;
        }
        ++it;
    }
    
    cout << "OK." << endl;
    
    // cout<<"Everything is okay"<<endl;
}