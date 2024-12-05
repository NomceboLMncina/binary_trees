#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node in a binary tree
 * @node: pointer to the node to find the sibling for
 *
 * A sibling is a node that shares the same parent but is a different child.
 * If the node has no sibling, or if it or its parent is NULL,
 * the function returns NULL.
 *
 * Return: pointer to the sibling node, or
 *         NULL if the node is NULL,
 *         NULL if the parent is NULL,
 *         NULL if the node has no sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node == node->parent->left)
		return (node->parent->right);
	return (node->parent->left);
}
