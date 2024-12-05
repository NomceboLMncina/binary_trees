#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a node is the root of a binary tree
 * @node: Pointer to the node to check
 *
 * Return: 1 if the node is the root (has no parent),
 *         0 if the node is not the root or is NULL.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	return ((!node || node->parent) ? 0 : 1);
}
