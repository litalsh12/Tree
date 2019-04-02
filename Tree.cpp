#include <iostream>
#include "Tree.hpp"
using namespace std;
using namespace ariel;

int count=0;
Tree::Tree():head(NULL) { //Constructor for tree
    int _size=0;
}
Tree::~Tree(){
  delete head;
}
node::node(int i):right(NULL),left(NULL) {//Constructor for node

    value=i;
}
node::~node(){
  delete right;
  delete left;
}
int Tree::root(){
    if(!head) { throw std::invalid_argument("root");
}
    return head->value;
}
bool Tree::contains(int i){
    if (!head){
        return false;
        }
    if (head->value==i){
        return true;}
    else if (i<head->value){
        if (!(head->left)){
            return false;
            }
        else return head->left->contains(i);
    }
    else{
        if (!(head->right)){
            return false;}
        else return head->right->contains(i);
    }
    return false;
}

Tree& Tree::insert(int i) {
    if(contains(i)) {
        throw std::exception();
        }
    if (!head){
    head=new node(i);
    _size=1;
    return *this;
    }
    else if(i<head->value){
        if(!(head->left)) {
            head->left=new Tree();
            head->left->head=new node(i);
            head->left->_size=1;
            this->_size++;
            return *this;
            }
        else return head->left->insert(i);
        }
    else{
            if(!(head->right)) {
                head->right=new Tree();
                head->right->_size=1;
                head->right->head=new node(i);
               this->_size++;
                return *this;}
            else return  head->right->insert(i);
            
    }
    return *this;
}
        Tree& Tree::remove(int i){

    if(!head){
      throw std::invalid_argument("remove-head");
            }
            else if(head){ 
                 if(!contains(i)){
      throw std::invalid_argument("remove-contains");
            }
                if(head->value==i){
                  if(!(head->left) && !(head->right))
                   {
                       head=NULL;
                      return *this;

                   }
                   else if((!head->left)){
                       head=head->right->head;
                       return *this;
                   }
                   else if(!(head->right)){
                       head=head->left->head;
                       return *this;
                   }
                    else{
                        Tree* tempTree=head->right;
                        head=head->left->head;
                        insertTree(tempTree);
                        }
                    }else if(head->value < i){
                       return head->right->remove(i);
                   }
                   else{
                       return head->left->remove(i);
                   }
            }
                return *this;
            }

Tree& Tree::insertTree(Tree* t) {
    if (!head){
    head=t->head;
    return *this;
    }
    else if((t->head->value)<(head->value)){
        if(!head->left) {
            head->left=t;
    return *this;
            }
        else return head->left->insertTree(t);
        }
    else{
            if(!head->right) {
                head->right=t;
    return *this;
                }
            else return  head->right->insertTree(t); 
    }
    return *this;
}


            int Tree::size(){
                int countTemp=0;
                int left=0;
                int right=0;
                if (head){
                    count++;
                   if (head->right){right=head->right->sizeReset();}
                   if (head->left){left=head->left->sizeReset();}
                }
                countTemp=count;
                count=0;
                return countTemp;
            }
         int Tree::sizeReset(){
            if(!head){
                return count;
            }
            else{
              count++;

                if((head->left)){
                 head->left->sizeReset();
                }
            }
                 if((head->right)){
                    head->right->sizeReset();
                 }
                 return count;
            }
        
        int Tree::right(int i){
      if(!contains(i)){
              throw std::exception();
            }
            if(head){
                if(head->value==i){
                    if(head->right && head->right->head){
                        return head->right->head->value;
                    }
                    else{
                     throw std::exception();
                    }
                }
                if((head->value)<i){
                    if(head->right){
                    return head->right->right(i);
                    }
                }else {
                    if(head->left){
                    return head->left->right(i);
                }
                }
            }            throw std::exception();

        }
        int Tree::left(int i){
                 if(!contains(i)){
              throw std::exception();
            }
            if(head){
                if(head->value==i){
                    if(head->left && head->left->head){
                        return head->left->head->value;
                    }
                    else{
                     throw std::exception();
                    }
                }
                if((head->value)<i){
                    if(head->right){
                    return head->right->left(i);
                    }
                }else {
                    if(head->left){
                    return head->left->left(i);
                }
                }
            }
            throw std::exception();

            }
        int Tree::parent(int i){
           if(!head){
                throw std::exception();
            }else if(head->value==i){
                throw std::exception();

            }
            else{
                if((head->right) && head->right->head){
                if(head->right->head->value==i){
                 return head->value;
                }
                }
                if((head->left) && head->left->head){
                    if(head->left->head->value==i){
                        return head->value;
                    }
                }
                
            if( head->value < i && head->right ){
                return head->right->parent(i);
            }
            if(head->value > i && head->left ){
                return head->left->parent(i);
            }}
             return 0;
            
        }
       // return 0;
           


        void Tree::print(){
         if (head){
            if (head->left){head->left->print() ;}
        cout<<head->value<<" ";
        if (head->right){head->right->print();}
    }  
        }
