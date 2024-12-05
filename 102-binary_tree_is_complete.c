#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root node of the tree to check.
 *
 * A binary tree is complete if all its levels are fully filled, except possibly
 * for the last level, which is filled from left to right. This function checks
 * if the tree satisfies this property.
 *
 * Return: 1 if the tree is complete,
 *         0 if the tree is not complete,
 *         0 if the tree is NULL.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);

	/* Get the total number of nodes in the tree */
	size = binary_tree_size(tree);

	/* Check if the tree satisfies the complete tree property */
	return (btic_helper(tree, 0, size));
}

/**
 * btic_helper - Recursively checks if a binary tree is complete
 * @tree: A pointer to the root node of the tree to check.
 * @index: The current index of the node being checked.
 * @size: The total number of nodes in the tree.
 *
 * This helper function recursively verifies if the binary tree is complete
 * by ensuring that all nodes are within valid positions, following the
 * property of a complete tree.
 *
 * Return: 1 if the tree is complete,
 *         0 if the tree is not complete,
 *         0 if the tree is NULL.
 */
int btic_helper(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);  /* NULL nodes are valid in the complete tree property */

	/* If the index exceeds the total size, the tree is not complete */
	if (index >= size)
		return (0);

	/* Check recursively for the left and right subtrees */
	return (btic_helper(tree->left, 2 * index + 1, size) &&
		btic_helper(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: A pointer to the root node of the tree to measure.
 *
 * This function recursively counts the total number of nodes in the tree.
 *
 * Return: The size (number of nodes) of the tree,
 *         0 if the tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	/* Recursively calculate the size by summing the left and right subtrees */
	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}
