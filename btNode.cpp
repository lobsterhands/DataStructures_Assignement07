#include "btNode.h"

#include <iostream> // LYLE DELETE
using namespace std; // LYLE DELETE

void dumpToArrayInOrder(btNode* bst_root, int* dumpArray)
{
   if (bst_root == 0) return;
   int dumpIndex = 0;
   dumpToArrayInOrderAux(bst_root, dumpArray, dumpIndex);
}

void dumpToArrayInOrderAux(btNode* bst_root, int* dumpArray, int& dumpIndex)
{
   if (bst_root == 0) return;
   dumpToArrayInOrderAux(bst_root->left, dumpArray, dumpIndex);
   dumpArray[dumpIndex++] = bst_root->data;
   dumpToArrayInOrderAux(bst_root->right, dumpArray, dumpIndex);
}

void tree_clear(btNode*& root)
{
   if (root == 0) return;
   tree_clear(root->left);
   tree_clear(root->right);
   delete root;
   root = 0;
}

int bst_size(btNode* bst_root)
{
   if (bst_root == 0) return 0;
   return 1 + bst_size(bst_root->left) + bst_size(bst_root->right);
}

// pre:  bst_root is root pointer of a binary search tree (may be 0 for
//       empty tree)
// post: If no node in the binary search tree has data equals insInt, a
//       node with data insInt has been created and inserted at the proper
//       location in the tree to maintain binary search tree property.
//       If a node with data equals insInt is found, the node's data field
//       has been overwritten with insInt; no new node has been created.
// write definition for bst_insert here
void bst_insert(btNode*& bst_root, int insInt) {

   btNode *current = new btNode;
   btNode *parent = new btNode;

   cout << "Data to insert: " << insInt << endl;

   if (bst_root == NULL) { // BST is empty; insert here
      cout << "root empty" << endl;

      btNode *insert = new btNode;
      insert->data = insInt;
      insert->left = NULL;
      insert->right = NULL;
      bst_root = insert;
   } else { // Traverse BST to find insertion point

      current = bst_root;

      while (current != NULL) {
         if (current->data == insInt) {
            current->data = insInt;
            return;
         }

         parent = current;
         if (insInt < current->data) {
            current = current->left;
         } else {
            current = current->right;
         }
      }

      btNode* insert = new btNode;
      insert->data = insInt;
      insert->left = NULL;
      insert->right = NULL;

      if (insInt < parent->data) {
         parent->left = insert;
      } else {
         parent->right = insert;
      }
   }
}

// write definition for bst_remove here
bool bst_remove(btNode*& bst_root, int remInt) {

   return false;
}
// write definition for bst_remove_max here
void bst_remove_max(btNode*& bst_root) {

}




// pre:  bst_root is root pointer of a binary search tree (may be 0 for
//       empty tree)
// post: If remInt was in the tree, then remInt has been removed, bst_root
//       now points to the root of the new (smaller) binary search tree,
//       and the function returns true. Otherwise, if remInt was not in the
//       tree, then the tree is unchanged, and the function returns false.
// write prototype for bst_remove here

// pre:  bst_root is root pointer of a non-empty binary search tree
// post: The largest item in the binary search tree has been removed, and
//       bst_root now points to the root of the new (smaller) binary search
//       tree. The reference parameter, removed, has been set to a copy of
//       the removed item.
// write prototype for bst_remove_max here
