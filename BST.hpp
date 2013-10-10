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
            else {
                cout<<"Can't not insert, Duplicate items"<<endl;
                return 0;
            }
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
    
    //      virtual bool insert(const Data& item) {
    //              return insertHelper(item, root);
    //
    //          }
    
    
    //
    //    case1: if there is no child, delete it directly
    //    case2: if there is one child, link the child to its parent and delete it
    //    case3: if there are two children, find the successor and create a node with the same data of the successor and call the removeHelp function to delete the successor
    
    bool remove(const Data& item){
        iterator it = find(item); // use iterator provided to find the node to delete
        BSTNode<Data>* current = it.getCurr();
        if (current == 0) {
            cout<<"No such item to delete"<<endl; // error control
            return 0;
        }
        if (current->left == 0 || current->right == 0) {
            removeHelp(current);
            return 1;
        }
        else if (current->left != 0 && current->right != 0){
            BSTNode<Data>* succ = current->successor();
            BSTNode<Data>* repl = new BSTNode<Data>(succ->data);
            
            repl->left = current->left;
            repl->right = current->right;
            removeHelp(succ);
            return 1;
        }
        return 0;
    }
    
    bool removeHelp(BSTNode<Data>* current){// assisting function to remove when there is one or no child
        
        BSTNode<Data>* pcurr = current->parent;
        if (current->right == 0 && current->left == 0) {
            if (current->isLeft())
                pcurr->left = 0;
            else pcurr->right = 0;
        }
        else if(current->right == 0 && current->left != 0){
            if (current->isLeft())
                pcurr->left =current->left;
            else
                pcurr->right = current->left;
            current->left->parent = pcurr;
        }
        else if(current->left == 0 && current->right != 0){
            if (current->isLeft())
                pcurr->right = current->right;
            else
                pcurr->right = current->right;
            current->right->parent = pcurr;
        }
        delete current;
        cout<<current->data<<" Node deleted"<<endl;
        return 1;
    }
    
    
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
        
        return typename BST<Data>::iterator(0);
    }
    
    /** Perform an inorder traversal of this BST.
     */
    void inorder() const {
        inorder(root);
    }
    void print(){ // printing  the order of the tree, to verify result
        iterator i = begin();
        for (; i.getCurr() != 0; i++) {
            cout<<i.getCurr()->data<<" ";
            cout<<i.getCurr()<<endl;
        }
        cout<<endl;
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
