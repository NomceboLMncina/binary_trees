#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: A pointer to the first node to find the ancestor.
 * @second: A pointer to the second node to find the ancestor.
 *
 * This function traverses the parent pointers of both nodes to determine
 * their lowest common ancestor. It adjusts for different depths by moving
 * up the tree and compares the nodes iteratively until a common ancestor
 * is found.
 *
 * Return: A pointer to the lowest common ancestor node, or
 *         NULL if no common ancestor exists.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t depth_first, depth_second;

	if (!first || !second)
		return (NULL);

	depth_first = binary_tree_depth(first);
	depth_second = binary_tree_depth(second);

	/* Equalize the depth of the two nodes */
	while (depth_first > depth_second)
	{
		first = first->parent;
		depth_first--;
	}
	while (depth_second > depth_first)
	{
		second = second->parent;
		depth_second--;
	}

	/* Traverse both nodes upwards until the ancestor is found */
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: A pointer to the node to calculate the depth of.
 *
 * This function counts the number of edges from the node to the root of the
 * tree to determine its depth.
 *
 * Return: The depth of the node. Returns 0 if the node is NULL (indicating
 *         the root or an absent node).
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);

	/* Traverse up the tree to count the number of parent nodes */
	while (tree->parent)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}
