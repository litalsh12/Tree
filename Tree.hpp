#include <iostream>
using namespace std;
namespace ariel
{
    class Tree;
    class node{
    public:
        node(int value);
        ~node();
        int value;
        Tree* left;
        Tree* right;      
    };

    class Tree{
        public:
        int _size;
            Tree(); 
            ~Tree(); 
            int root();
            bool contains(int i);
            Tree& insert(int i);
            Tree& remove(int i);
            Tree& insertTree(Tree* addTree);
            int size();
            int sizeReset();
            int right(int i);
            int left(int i);
            int parent(int i);
            void print();
        private:
            node* head;
    };


};