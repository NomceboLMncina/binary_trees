#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least one child in binary tree
 * @tree: Pointer to the root node of the tree to count the nodes from
 *
 * Return: Number of nodes with at least one child in the tree
 *         0 if the tree is NULL
 *
 * Description: This function recursively traverses the binary tree and counts
 *              the nodes that have at least one child (either left or right).
 *              A node is counted if it has either a left or a right child.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree || (!tree->left && !tree->right))
	return (0);

	return (binary_tree_size(tree) - binary_tree_leaves(tree));
}

/**
 * binary_tree_size - Measures the total number of nodes in a binary tree
 * @tree: Pointer to the root node of the tree to measure the size of
 *
 * Return: Size of the tree (total number of nodes)
 *         0 if the tree is NULL
 *
 * Description: This function recursively calculates the total number of nodes
 *              in the tree by traversing the entire tree, adding 1
 *              for each node.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
	return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_leaves - Counts the leaf nodes in a binary tree
 * @tree: Pointer to the root node of the tree to count the leaves from
 *
 * Return: Number of leaf nodes in the tree
 *         0 if the tree is NULL
 *
 * Description: This function recursively counts the leaf nodes
 * in the binary tree.
 *              A leaf node is defined as a node that has no
 *             children (neither left nor right).
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
	return (0);

	if (!tree->left && !tree->right)
	return (1);

	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
