#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Height of the tree (num of edges on the longest path from the root)
 *         0 if the tree is NULL
 *
 * Description: This functn calc the height of a binary tree by recursively
 *              determining the h of its left and right subtrees, and returning
 *              the greater of the two heights, plus 1 for the current node.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
	return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}
