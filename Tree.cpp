#include "Tree.hpp"
#include <iostream>
using namespace std;
node::node(){
node* n=NULL;
this->right=NULL;
this->left=NULL;
}

node::node(int data){
node* n=NULL;
this->value=data;
this->right=NULL;
this->left=NULL;
}
using  ariel::Tree;

ariel::Tree::Tree(){
 head=NULL;
  int s=0;
}


node* ariel::Tree::insertRec(node* t, int i)
    {
        if(t == NULL)
        {
            t = new node(i);
            s++;
            return t;
        }
        else if(i < t->value){
          t->left=insertRec(t->left , i);
        }
        else {
           t->right = insertRec(t->right , i);
          }
}

void ariel::Tree::insert(int i){
   if(!head){
   head= new node(i);//if the tree is empty
    s=1;
 }
 else if(!contains(i))
{
 insertRec(head,i);
 
 }else {
      throw std::invalid_argument("number already exist");
}

}

bool ariel::Tree::contains(int i){
//return true;
if(!head){
  throw std::invalid_argument("tree isnt exist");
}else{
  temp=head;
  while(temp){
    if(temp->value==i){
      return true;
    }else if(temp->value>i){
      temp=temp->left;
    }else{
      temp=temp->right;
    }
  }
}
return false;
}

node* ariel::Tree::find(int i){
 // return NULL;
  if(head==NULL){
   throw std::invalid_argument("head isn't exist");
   // return NULL;
  }
  temp=head;
  while(temp!=NULL){
   if(temp->value==i){
     return temp;
   }else if(i < temp->value){
     temp=temp->left;
   }else
   {
     temp=temp->right;
   }
}//if(temp==NULL) {
 //  throw std::invalid_argument("number isn't exist");
//}
return NULL; 
}

 
void ariel::Tree::remove(int i){
     temp=find(i);

     if(temp==NULL) {
        throw std::invalid_argument("number isn't exist");
     }else
     {
       delete(temp);
       s--;
     }
}

//int ariel::Tree::parentRec(int data, node* t, node* p){
	//if(t!=NULL)
	//{
		//if(t->value==data)
			//return p->value;
		//if(t->value>data){
			//p=t;
			//return parentRec(data, t->left,p);
		//}
		//else{
		//	p=t;
		//	return parentRec(data, t->right,p);
	//	}
	//}
 // else return -1;
 //return 1;
//}
int ariel::Tree::parent(int data){
      temp = find(data);
      //if(temp==NULL){
          //throw std::invalid_argument("number isn't exist");      
        //   }
      //   else if(data==head->value)
    //     {
  //         throw std::invalid_argument("tree's root");
//}
 //   else{
   if(temp){
     temp=head;
   while(temp!=NULL){
     if(data<temp->value){
       if(temp->left->value==data){
        return temp->value;
       }else{
         temp=temp->left;
       }
     }else{
       if(temp->right->value==data){
         return temp->value;
       }else
       {
         temp=temp->right;
       }
     }

}
throw std::invalid_argument("number isn't exist");
}
}
   int ariel::Tree::left(int i){
    if(!head){
      throw std::invalid_argument("number isn't exist");
    }
    temp=head;
    while(temp){
      if(temp->value==i){
        return temp->left->value;
      }else if(temp->value >i){
        temp = temp->left;
      }else
      {
        temp=temp->right;
      }
    }
    throw std::invalid_argument("number isn't exist");

    //if(!head){
       //throw std::invalid_argument("number isn't exist");
    //}
     //if(!contains(i)){
      //  throw std::invalid_argument("number isn't exist");
     //}
       //temp = head;
       //while(temp){
         //if(temp->value==i){
           //return temp->left->value;
         //}if(i>temp->value){
          // temp = temp->right;
        // }else{
         //  temp = temp->left;
       //  }
     //  }

   } 
    
   int ariel::Tree::right(int i){
    if(!head){
       throw std::invalid_argument("number isn't exist");
     }
  // node* temp=find(i);
    //return temp->right->value; 
   return 3;
   } 
   
int ariel::Tree::root(){ 
  return head->value;
} 

void ariel::Tree::printRec(node* t){ 
	
    if (t != NULL) {  
		printRec(t->right);  
	  
		cout<<endl;  
		for (int i = 0; i < 1; i++)  
			cout<<" ";  
	 	cout<<t->value<<"\n";  
		printRec(t->left);  
	}  
}
void ariel::Tree::print(){ 
	printRec(head);  
}	

int ariel::Tree::size(){
return s;
}

