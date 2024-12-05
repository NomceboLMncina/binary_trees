#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverses a binary tree using post-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node's value
 *
 * Description: This functn performs a post-order traversal of the binary tree,
 *              calling the provided function `func` on the value of each node
 *              after recursively traversing its left and right children.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
	return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
