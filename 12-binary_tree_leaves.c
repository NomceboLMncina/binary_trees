#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree to count the leaves from
 *
 * Return: Number of leaves in the tree
 *         0 if the tree is NULL
 *
 * Description: This function counts the leaves of the tree by recursively
 *              traversing the left and right subtrees. A leaf is a node
 *              that has no children (both left and right pointers are NULL).
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
	return (0);

	if (!tree->left && !tree->right)
	return (1);

	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
