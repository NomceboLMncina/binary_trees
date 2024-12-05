#include "binary_trees.h"

/**
 * binary_tree_is_avl - Checks if a binary tree is an AVL tree
 * @tree: Pointer to the root node of the tree
 *
 * An AVL tree is a Binary Search Tree (BST) where:
 * - The heights of the two child subtrees of any node differ by at most one.
 * - Both child subtrees are also AVL trees.
 *
 * This function verifies both the BST properties and the AVL balance
 * conditions.
 *
 * Return: 1 if the tree is an AVL tree
 *         0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (btia_helper(tree, INT_MIN, INT_MAX));
}

/**
 * btia_helper - Helper function to check if a binary tree is an AVL tree
 * @tree: Pointer to the root node of the tree
 * @min: Minimum allowable value for the current subtree
 * @max: Maximum allowable value for the current subtree
 *
 * This function ensures:
 * - The binary search tree (BST) property is satisfied for the node values.
 * - The balance condition is satisfied for each node (height difference
 *   ≤ 1).
 *
 * Return: 1 if the tree is an AVL tree
 *         0 otherwise
 */
int btia_helper(const binary_tree_t *tree, int min, int max)
{
	int path_l, path_r;

	if (!tree)
		return (1);

	/* Check if current node value satisfies BST property */
	if (tree->n < min || tree->n > max)
		return (0);

	/* Calculate the heights of the left and right subtrees */
	path_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	path_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	/* Check if the balance condition is satisfied */
	if (abs(path_l - path_r) > 1)
		return (0);

	/* Recursively check left and right subtrees */
	return (btia_helper(tree->left, min, tree->n - 1) &&
		btia_helper(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Height is defined as the number of edges in the longest path from the node
 * to a leaf. A NULL tree has a height of 0.
 *
 * Return: Height of the tree
 *         0 if the tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	/* Measure the heights of the left and right subtrees */
	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	/* Return the greater height */
	return (height_l > height_r ? height_l : height_r);
}
