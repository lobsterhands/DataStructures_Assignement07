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

void bst_insert(btNode*& bst_root, int insInt) {

   cout << "trying to add: " << insInt << endl;

   btNode *current = new btNode;
   btNode *parent = new btNode;

   if (bst_root == NULL) { // BST is empty; insert here

      btNode *insert = new btNode;
      insert->data = insInt;
      insert->left = NULL;
      insert->right = NULL;
      bst_root = insert;

   } else { // Traverse BST to find insertion point

      current = bst_root;

      while (current != NULL) {

         if (current->data == insInt) { // If insInt is already in the list
            current->data = insInt; // overwrite the value and return
            cout << "shit already exists" << endl;
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

      cout << "added: " << insInt << endl;
   }
}

// pre:  bst_root is root pointer of a binary search tree (may be 0 for
//       empty tree)
// post: If remInt was in the tree, then remInt has been removed, bst_root
//       now points to the root of the new (smaller) binary search tree,
//       and the function returns true. Otherwise, if remInt was not in the
//       tree, then the tree is unchanged, and the function returns false.
// write definition for bst_remove here
bool bst_remove(btNode*& bst_root, int remInt) {
   bool found = false;

   if (bst_root != NULL) {
      btNode *current = new btNode;
      current = bst_root;

      // Search for remInt in the list
      if (current->data != remInt) {
         if (remInt > current->data) {
            if (current->right != NULL) {
               bst_remove(current->right, remInt);
            } else {
            }
         } else if (remInt < current->data) {
            if (current->left != NULL) {
               bst_remove(current->left, remInt);
            } else {
            }
         }
      } else {
         found = true;
         cout << "shit found. Current node: " << current->data << endl;

         btNode *deletePtr = new btNode;

            // if the node to delete has no children
         if (current->left == NULL && current->right == NULL) {
            deletePtr = current;
            current = NULL;
            delete deletePtr;
            // if the node to delete has only a right child
         } else if (bst_root->left == NULL) {
            deletePtr = current;
            current = current->right;
            delete deletePtr;
            // if the node to delete has only a left child
         } else if (bst_root->right == NULL) {
            deletePtr = current;
            current = current->left;
            delete deletePtr;
            // if the node to delete has two children
         } else {
            cout << "calling remMax on current->left: " << current->left->data << endl;
            bst_remove_max(current->left, current->data);
         }

      }
   }
   return found;
}

// pre:  bst_root is root pointer of a non-empty binary search tree
// post: The largest item in the binary search tree has been removed, and
//       bst_root now points to the root of the new (smaller) binary search
//       tree. The reference parameter, removed, has been set to a copy of
//       the removed item.
// write definition for bst_remove_max here
void bst_remove_max(btNode*& bst_root, int &data) {
   btNode* current = new btNode;
   current = bst_root;
   btNode* deletePtr = new btNode;
   deletePtr = 0;

   if (current->right == NULL) {
      data = current->data;
      deletePtr = current;
      bst_root = bst_root->left;
      delete deletePtr;
   } else {
      bst_remove_max(current->right, data);
   }

}






