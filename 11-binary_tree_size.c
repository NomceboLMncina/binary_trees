#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Size of the tree (total number of nodes)
 *         0 if the tree is NULL
 *
 * Description: This function calculates the size of the tree by recursively
 *              counting the nodes in the left and right subtrees, and adding
 *              1 for the current node.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
	return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
