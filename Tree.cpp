#include "Tree.hpp"
#include <iostream>
#include <stdexcept>
#include <exception>
#include <cstdlib>
using namespace std;
static int _size=0;
node::node(){//Default constructor for node
node* n=NULL;
this->value=NULL;
this->right=NULL;
this->left=NULL;
}
node::node(int data){//constructor for node that get data
node* n=NULL;
this->value=data;
this->right=NULL;
this->left=NULL;
}
using  ariel::Tree;

ariel::Tree::Tree(){//constructor for Tree
 head=new node;
 _size=0;
 }

node* ariel::Tree::insertRec(node* t, int i)
    {
       if(t==NULL){//if 
            t = new node;
            t->value = i;
           t->left = t->right = NULL;
       }
        else if(i < t->value){
            t->left = insertRec(t->left , i);
        }
        else if(i > t->value){
            t->right = insertRec(t->right , i);
          }
        return t;
}

void ariel::Tree::insert(int i){
 if(head->value==NULL){
   head=new node(i);//if the tree is empty,
   Tree::_size++;
 }
 else if(contains(i)==false)
{
 node* temp=Tree::head;
 insertRec(temp,i);
 Tree::_size++;
 }
 else {
   throw std::invalid_argument("number already exist");
}

}
node* ariel::Tree::containsRec(node* t, int i)
    {
//private:
        if(t == NULL)
            return NULL;
        else if(i < t->value)
            return containsRec(t->left, i);
        else if(i > t->value)
            return containsRec(t->right, i);
       
            return t;
}

bool ariel::Tree::contains(int i){
// public:
 //node* temp=Tree::head;
 node* ans=containsRec(head,i);
 if(ans==NULL){
   return false;
   }

   return true;
   
}

  node* ariel::Tree::findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
}


node* ariel::Tree::removeRec(node* t , int i)
    {
//private:
        node* temp;
        if(t == NULL)
            return NULL;
        else if(i < t->value)
            t->left = removeRec(t->left , i);
        else if(i > t->value)
            t->right = removeRec(t->right , i);
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->value = temp->value;
            t->right = removeRec( t->right,t->value);
        }
      else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }


 
   void ariel::Tree::remove(int i){
  if(contains(i)==true){
    node* temp=Tree::head;
    removeRec(temp , i);
    Tree::_size--;
   }
   else {
     throw std::invalid_argument("number isn't exist");
  }
}



int ariel::Tree::parentRec(int data, node* t, node* p){
	if(t!=NULL)
	{
		if(t->value==data)
			return p->value;
		if(t->value>data){
			p=t;
			return parentRec(data, t->left,p);
		}
		else{
			p=t;
			return parentRec(data, t->right,p);
		}
	}
  else return -1;
}
int ariel::Tree::parent(int data){
        if(contains(data)==false){
          throw std::invalid_argument("number isn't exist");      
           }
         else if(data==head->value)
         {
           throw std::invalid_argument("tree's root");
}
        else{
        node* temp=head; 
	return parentRec(data, temp, NULL);
}
}
  
   int ariel::Tree::left(int i){
   node* temp=head;
   node* father = containsRec(temp,i);
   if(father==NULL){
      throw std::invalid_argument("number isn't exist");
    }
       return (father->left)->value;
     
   } 
    
   int ariel::Tree::right(int i){
   node* temp=head;
   node* father= containsRec(temp,i);
   if(father==NULL){
      throw std::invalid_argument("number isn't exist");
    }

       return (father->right)->value;
     
   } 
   
int ariel::Tree::root(){
  node* temp=head; 
  return temp->value;
} 

void ariel::Tree::printRec(node* t){ 
	
    if (t != NULL) {  
		printRec(t->right);  
	  
		for (int i = 0; i < 1; i++)  
			cout<<" ";  
	 	cout<<t->value<<"   ";  
	  
		printRec(t->left);  
	}  
}
void ariel::Tree::print(){ 
    node* temp=head;
	printRec(temp);
  cout<<endl;  
  
}	

int ariel::Tree::size(){
return _size;
}
 