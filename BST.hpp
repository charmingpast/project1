#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <iostream>
using namespace std;

template<typename Data>
class BST {
    
protected:
    
    /** Pointer to the root of this BST, or 0 if the BST is empty */
    BSTNode<Data>* root;
    
    /** Number of Data items stored in this BST. */
    unsigned int isize;
    
public:
    
    /** define iterator as an aliased typename for BSTIterator<Data>. */
    typedef BSTIterator<Data> iterator;
    
    /** Default constructor.
     Initialize an empty BST.
     */
    BST() : root(0), isize(0) {  }
    
    
    /** Default destructor.
     Delete every node in this BST.
     */ // TODO
    virtual ~BST() {
        deleteAll(root);
        isize = 0;
    }
    
    /** Given a reference to a Data item, insert a copy of it in this BST.
     *  Return  true if the item was added to this BST
     *  as a result of this call to insert,
     *  false if an item equal to this one was already in this BST.
     *  Note: This function should use only the '<' operator when comparing
     *  Data items.
     */ // TODO
    virtual bool insert(const Data& item) {
        BSTNode<Data>* tmp = new BSTNode<Data>(item);
        cout<<tmp->data<<endl;
        //creat a new node
        if (root == 0) {//if the root is empty
            root = tmp;
            isize++;
            return 1;
        }
        BSTNode<Data>* current = root;
        BSTNode<Data>* Pcurrent = 0;
        while (current) {
            if (tmp->data > current->data) {
                Pcurrent = current;
                current = current->right;
            }
            else if(tmp->data < current->data){
                Pcurrent = current;
                current = current->left;
            }
            else return 0;
        }
        if (Pcurrent->data < item) {
            tmp->parent = Pcurrent;
            Pcurrent->right = tmp;
            cout<<"success"<<endl;
            isize++;
            return 1;
        }
        if (Pcurrent->data > item) {
            tmp->parent = Pcurrent;
            Pcurrent->left = tmp;
            cout<<"success"<<endl;
            isize++;
            return 1;
            
        }
        
        return 0;
    }
    //    bool insertHelper(const Data& item, BSTNode<Data>* node)
    //        {
    //                if (node->data == item) {
    //                        return false;
    //                    }
    //                if(node->data > item){
    //                        if(node->left == NULL){
    //                                BSTNode<Data>* newNode = new BSTNode<Data>;
    //                                newNode->data = item;
    //                                node->left = newNode;
    //                            }
    //                        else
    //                                return insertHelper(item, node->left);
    //                        }
    //                //node->data < item
    //                else{
    //                        if(node->right == NULL){
    //                                BSTNode<Data>* newNode = new BSTNode<Data>;
    //                                newNode->data = item;
    //                                node->right = newNode;
    //                            }
    //                        else
    //                                return insertHelper(item, node->right);
    //                        }
    //
    //            }
    //      /** Given a reference to a Data item, insert a copy of it in this BST.
    //          *  Return  true if the item was added to this BST
    //          *  as a result of this call to insert,
    //          *  false if an item equal to this one was already in this BST.
    //          *  Note: This function should use only the '<' operator when comparing
    //          *  Data items.
    //          */ // TODO
    //      virtual bool insert(const Data& item) {
    //              return insertHelper(item, root);
    //
    //          }
    //    //
    //    virtual bool del(const Data& item) const{//delete a node
    //
    //        //case1: 如果x没有子节点，直接删除x
    //    //case2: 如果x有一个子节点，x的父节点连结该子节点，删除x
    //    //case3: 如果x有两个子节点，找出x的后继y，复制y的数据到x，递归调用函数删除y（此时y不可能有左子结点，只可能在//case1,case2返回）
    //        iterator it = find(item);
    //        if(it.getCurr() == 0)
    //        {
    //            cout<<"No such node to delete"<<endl;return 0;
    //        }
    //        BSTNode<Data>* current = it.getCurr();
    //        BSTNode<Data>* tmp = current->parent;
    //        if (current->right == 0 && current->left == 0) {
    //            if (tmp->right == current) {
    //                delete current; tmp->right = 0;cout<<item<<" Node deleted"<<endl; return 1;
    //            }
    //            else {delete current; tmp->left = 0; cout<<item<<" Node deleted"<<endl; return 1;}
    //        }
    //        else if (current->right != 0 && current->left ==0) {
    //            if (tmp->right == current) tmp->right = current->right;
    //
    //            else tmp->left = current->right;
    //            delete current; cout<<item<<" Node deleted"<<endl;return 1;
    //        }
    //        else if(current->left != 0 && current->right == 0){
    //            if(tmp->right == current) tmp->right = current->left;
    //            else tmp->left = current->left;
    //            delete current; cout<<item<<" Node deleted"<<endl; return 1;
    //        }
    //        BSTNode<Data>* succ = current->successor();
    //        current->data = succ->data;
    //        del(current, current->data);
    //        return 0;
    //    }
    //    bool delHelper(BSTNode<Data>* current, const Data& item){
    //        iterator it = find(item);
    //        if(it.getCurr() == 0)
    //        {
    //            cout<<"No such node to delete"<<endl;return 0;
    //        }
    
    //        BSTNode<Data>* tmp = current->parent;
    //        if (current->right == 0 && current->left == 0) {
    //            if (tmp->right == current) {
    //                delete current; tmp->right = 0;cout<<item<<" Node deleted"<<endl; return 1;
    //            }
    //            else {delete current; tmp->left = 0; cout<<item<<" Node deleted"<<endl; return 1;}
    //        }
    //        else if (current->right != 0 && current->left ==0) {
    //            if (tmp->right == current) tmp->right = current->right;
    //
    //            else tmp->left = current->right;
    //            delete current; cout<<item<<" Node deleted"<<endl;return 1;
    //        }
    //        else if(current->left != 0 && current->right == 0){
    //            if(tmp->right == current) tmp->right = current->left;
    //            else tmp->left = current->left;
    //            delete current; cout<<item<<" Node deleted"<<endl; return 1;
    //        }
    //    }
    /** Find a Data item in the BST.
     *  Return an iterator pointing to the item, or pointing past
     *  the last node in the BST if not found.
     *  Note: This function should use only the '<' operator when comparing
     *  Data items.
     */ // TODO
    iterator find(const Data& item) const {
        //BSTNode<Data>* BSTnode = BSTNode(item);
        iterator it = begin();
        while (*it != item && it.getCurr() != 0) {
            it++;
        }
        
        if (*it == item) {
            cout<<"find "<<*it<<endl;
            return it;
        }
        
        else cout<<"find "<<item<<" failed"<<endl;
        return 0;
    }
    
    
    /** Return the number of items currently in the BST.
     */ // TODO
    unsigned int size() const {
        return isize;
        //        iterator it = begin();
        //        unsigned int i = 0;
        //        for (i = 0; !(++it).empty(); ) {
        //            i++;
        //        }
        //        return ++i;
    }
    
    /** Return true if the BST is empty, else false.
     */
    bool empty() const {
        if (root == 0) {
            return 0;
        }
        else return 1;
    }
    
    /** Return an iterator pointing to the first item in the BST.
     */ // TODO
    iterator begin() const {
        if (root == 0) {
            return 0;
        }
        BSTNode<Data>* firstNode = first(root);
        iterator it(firstNode);
        //it(firstNode);
        return it;
    }
    
    /** Return an iterator pointing past the last item in the BST.
     */
    iterator end() const {
        //        if (root == 0) {
        //            return 0;
        //        }
        //        iterator it = begin();
        //        //cout<<*it<<endl;
        //        while (!it.isEnd()) {
        //            cout<<*it<<endl;
        //            ++it;
        //        }
        //        cout<<*it<<endl;
        //        return it;
        return typename BST<Data>::iterator(0);//???
    }
    
    /** Perform an inorder traversal of this BST.
     */
    void inorder() const {
        inorder(root);
    }
    
    
private:
    
    /** Recursive inorder traversal 'helper' function */
    void inorder(BSTNode<Data>* n) const {
        if(n==0) return;
        inorder(n->left);
        std::cout << *n << std::endl;
        inorder(n->right);
    }
    
    static BSTNode<Data>* first(BSTNode<Data>* root) {
        if(root == 0) return 0;
        while(root->left != 0) root = root->left;
        return root;
    }
    
    // do a postorder traversal, deleting nodes
    static void deleteAll(BSTNode<Data>* n) {
        if (0 == n) return;
        deleteAll(n->left);
        deleteAll(n->right);
        delete n;
    }
    
    
};
#endif //BST_HPP
