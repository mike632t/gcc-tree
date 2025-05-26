/*
 *
 * gcc-tree.c
 *
 * Copyright(C) 2025   MEJT
 *
 * Creates a binary tree structure.  
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.   See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 * 
 * 20 May 25  0.1  001 - Initial version - MT
 *
 */

#include <stdio.h>
#include <stdlib.h>

struct leaf
{
   int data;
   struct leaf *left;
   struct leaf *right;
};

typedef struct leaf leaf;

leaf *h_new(int i_data) /* Create a new leaf */
{
   leaf *h_leaf;
   h_leaf = (leaf*)malloc(sizeof(*h_leaf));
   h_leaf->data = i_data;
   h_leaf->left = NULL;
   h_leaf->right = NULL;
   return h_leaf;
}
leaf *h_add(leaf *h_root, int i_value) /*  Adds a leaf to the tree */
{
   if (h_root != NULL)
      if (i_value < h_root->data) 
         h_root->left = h_add (h_root->left, i_value);
      else
         h_root->right = h_add (h_root->right, i_value);
   else
      h_root = h_new(i_value); /* Create leaf */
   return h_root;
}

void v_inorder(leaf *h_root)
{
   if (h_root != NULL)
   {
      v_inorder(h_root->left); /* Print left sub-tree */
      printf("%d ", h_root->data);
      v_inorder(h_root->right); /* Print right sub-tree */
   }
}

int main()
{
   int i_array[] = { 5, 1, 3, 8, 4, 9, 6, 0, 2, 7 };
   
   leaf *h_root = NULL;
   int i_size = sizeof(i_array) / sizeof(i_array[0]);
   for (int i_count = 0; i_count < i_size; ++i_count)
      h_root = h_add(h_root, i_array[i_count]); /* Add values to tree */
   v_inorder(h_root); /* Display tree */
   printf("\n");

   return 0;
}
