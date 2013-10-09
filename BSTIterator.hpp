#ifndef BSTITERATOR_HPP
#define BSTITERATOR_HPP
#include "BSTNode.hpp"

#include <list>
#include <iterator>

template<typename Data>
class BSTIterator : public std::iterator<std::input_iterator_tag,Data> {
    
private:
    
    BSTNode<Data>* curr;
    
public:
    
    /** Constructor.  Use the argument to initialize the current BSTNode
     *  in this BSTIterator.
     */ // TODO
    BSTIterator(BSTNode<Data>* curr) {
        //*this = curr;  //
        this->curr = curr;
    }
    
    /** Dereference operator. */
    Data operator*() const {
        if (curr != 0) {
            return this->curr->data;
        }
        return 0;
        
    }
    
    /** Pre-increment operator. */
    BSTIterator<Data>& operator++() {
        curr = curr->successor();
        return *this;
    }
    
    /** Post-increment operator. */
    BSTIterator<Data> operator++(int) {
        BSTIterator before = BSTIterator(curr);
        ++(*this);
        return before;
    }
    
    /** Equality test operator. */
    bool operator==(BSTIterator<Data> const & other) const {
        return curr->data == other.curr->data;
    }
    
    /** Inequality test operator. */
    bool operator!=(BSTIterator<Data> const & other) const {
        return curr->data != other.curr->data;
    }
    //    bool empty(){
    //        if (curr == 0) {
    //            return 1;
    //        }
    //        return 0;
    //    }
    //    bool isEnd(){
    //        if (curr->successor() == 0) {
    //            return 1;
    //        }
    //        return 0;
    //    }
    BSTNode<Data>* getCurr(){//for delete function
        return curr;
    }
};

#endif //BSTITERATOR_HPP
