#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a given node
 * @node: a pointer to the node to find the uncle for
 *
 * Return: pointer to the uncle node
 *         NULL if the node or its parent is NULL
 *         NULL if the node has no uncle (i.e., the parent has no sibling)
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	return (binary_tree_sibling(node->parent));
}

/**
 * binary_tree_sibling - finds the sibling of a given node
 * @node: a pointer to the node to find the sibling for
 *
 * Return: pointer to the sibling node
 *         NULL if the node or its parent is NULL
 *         NULL if the node has no sibling (i.e., it is the only child)
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node == node->parent->left)
		return (node->parent->right);
	return (node->parent->left);
}
