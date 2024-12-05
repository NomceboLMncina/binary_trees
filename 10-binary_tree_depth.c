#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: Pointer to the node to calculate the depth of
 *
 * Return: Depth of the node (number of edges from the node to the root)
 *         0 if the node is NULL
 *
 * Description: This function calculates the depth of a node by traversing
 *              upwards through the tree to the root, counting the number
 *              of edges encountered along the way.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
	return (0);

	while (tree->parent)
	{
	depth++;
	tree = tree->parent;
	}

	return (depth);
}
