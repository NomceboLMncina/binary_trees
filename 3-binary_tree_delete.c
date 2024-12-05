#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: Pointer to the root node of the tree to delete
 *
 * Description: Recursively deletes all nodes of a binary tree,
 *              starting from the leaves and moving up to the root.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
	return;

	binary_tree_delete(tree->right);
	binary_tree_delete(tree->left);
	free(tree);
}
