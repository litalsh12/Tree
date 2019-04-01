#include <iostream>
#include "Tree.hpp"
using namespace std;
using namespace ariel;

int count=0;
//counstractor and destructor for Tree
Tree::Tree():head(NULL) {
    int _size=0;
}
Tree::~Tree(){
  delete head;
}
//counstractor and destructor for TreeNode
node::node(int i):right(NULL),left(NULL) {
    value=i;

}
node::~node(){
  delete right;
  delete left;
}
int Tree::root(){
    if(!head) {throw std::exception();}
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
    if(!contains(i)){
        throw std::exception();
            }
            else if (head){ 
                if(head->value==i){
                  if(!(head->left && head->right))
                   {
                       head=NULL;
                        this->_size--;

                      return *this;

                   }
                   else if((!head->left)){
                       head=head->right->head;
                     this->_size--;

                       return *this;
                   }
                   else if(!(head->right)){
                       head=head->left->head;
                        this->_size--;

                       return *this;

                   }
                    else{
                        return *this;
                //        node* temp=head->right->head;
                //        head=head->left->head;
                //        head->right->head=temp;
                //        return *this;

                    }
                }
                   else if(head->value < i){
                       return head->right->remove(i);
                   this->_size--;

                   }
                   else{
                       return head->left->remove(i);
                       this->_size--;

                   }

                }
                                       return *this;

            }
            int Tree::size(){
                return _size;
                // int countTemp=0;
                // int left=0;
                // int right=0;
                // if (head){
                //    if (head->right){right=head->right->sizeReset();}
                //    if (head->left){left=head->left->sizeReset();}
                // }
                // countTemp=count;
                // count=0;
                // return countTemp;
            }
        // int Tree::sizeReset(){
            
        //     if(!head){
        //         return count;
        //     }
        //     else{
        //       count++;

        //         if((head->left)){
        //          head->left->size();
        //         }
        //     }
        //          if((head->right)){
        //             head->right->size();
        //          }
        //          return count;
        //     }
        
        int Tree::right(int i){
//            if(!contains(i)){
  //            throw std::exception();
      //      }
    //        if(head){
          //      if(head->value==i){
        //            if(head->right){
              //          return head->right->head->value;
            //        }
                //    else{
                  //   throw std::exception();
        //            }
          //      }
            //    if((head->value)<i){
              //      return head->right->right(i);
               // }else{
                 //   return head->left->right(i);
          //      }
           // }
            return -1;
        }
        int Tree::left(int i){
/*                 if(!contains(i)){
              throw std::exception();
            }
            if(head){
                if(head->value==i){
                    if(head->right){
                        return head->left->head->value;
                    }
                    else{
                     throw std::exception();
                    }
                }
                if((head->value)<i){
                    return head->right->left(i);
                }else{
                    return head->left->left(i);
                }
            }*/
            return -2;
            }
        int Tree::parent(int i){
           if(!head){
                throw std::exception();
            }
            else{
                if((head->right)){
                if(head->right->head->value==i){
                 return head->value;
                }
                }
                else if((head->left)){
                    if(head->left->head->value==i){
                        return head->value;
                    }
                }
            }    
            if(head->right && head->value < i){
                return head->right->parent(i);
            }
            else if( head->left&&head->value < i ){
                return head->left->parent(i);
            }
            else return 0;
            
        }
       // return 0;
           


        void Tree::print(){
         if (head){
            if (head->left){head->left->print() ;}
        cout<<head->value<<" ";
        if (head->right){head->right->print();}
    }  
        }
