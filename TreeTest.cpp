/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;
  ariel::Tree testtree;
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  
  testtree.insert(9);
  
  ariel::Tree mytree;  

  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_EQUAL (emptytree.contains(5), false)
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_THROWS(threetree.left(6))
  .CHECK_OK    (threetree.print())
  .print()
  
   .CHECK_EQUAL (testtree.size(),1)
   .CHECK_EQUAL (testtree.contains(9), true)
   .CHECK_EQUAL (testtree.contains(5), false)
   .CHECK_OK (testtree.insert(7))
   .CHECK_THROWS(testtree.remove(5))
   .CHECK_OK(testtree.remove(7))
   .CHECK_EQUAL(testtree.left(9),NULL)
   .CHECK_EQUAL(testtree.right(9),NULL)
   .CHECK_THROWS (testtree.insert(9))
   .CHECK_OK (testtree.insert(3))
   .CHECK_OK (testtree.insert(15))
   .CHECK_OK (testtree.insert(7))
   .CHECK_OK (testtree.insert(1))
   .CHECK_EQUAL(testtree.left(9),3)
   .CHECK_EQUAL(testtree.right(3),15)
   .CHECK_EQUAL(testtree.parent(1),3)
   .CHECK_EQUAL(testtree.root(),9)
;


  
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}