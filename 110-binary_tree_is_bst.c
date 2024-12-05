#include "binary_trees.h"

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary
 * Search Tree (BST)
 * @tree: A pointer to the root node of the tree to check
 *
 * A valid BST must satisfy the following:
 * - The left subtree of a node contains only nodes with values less
 *   than the node's value
 * - The right subtree of a node contains only nodes with values greater
 *   than the node's value
 * - Both subtrees must also be binary search trees
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (btib_helper(tree, INT_MIN, INT_MAX));
}

/**
 * btib_helper - Recursively checks if a binary tree is a valid
 * Binary Search Tree
 * @tree: A pointer to the root node of the tree to check
 * @min: The lower bound for the current node's value
 * @max: The upper bound for the current node's value
 *
 * This function ensures that every node's value lies between the
 * specified bounds.
 * The left child must be smaller than its parent, and the right
 * child must be greater.
 * The bounds are adjusted as we move down the tree.
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int btib_helper(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (btib_helper(tree->left, min, tree->n - 1) &&
		btib_helper(tree->right, tree->n + 1, max));
}
