#include "binary_trees.h"

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal
 * @tree: A pointer to the root of the tree to traverse.
 * @func: A pointer to a function to call for each node. The function takes
 *        an integer value (node's value) as an argument.
 *
 * This function traverses the binary tree level by level, starting from the
 * root. For each level, it calls the provided function for each node at
 * that level.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t level, maxlevel;

	if (!tree || !func)
		return;

	/* Get the maximum level of the tree */
	maxlevel = binary_tree_height(tree) + 1;

	/* Traverse each level from 1 to maxlevel */
	for (level = 1; level <= maxlevel; level++)
		btlo_helper(tree, func, level);
}

/**
 * btlo_helper - Traverses a binary tree recursively for a specific level
 * @tree: A pointer to the tree to traverse.
 * @func: A pointer to a function to call for each node at the given level.
 * @level: The current level in the tree to process.
 *
 * This helper function traverses the tree recursively to process all nodes
 * at the specified level by calling the provided function for each node.
 */
void btlo_helper(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (level == 1)
		func(tree->n);  /* Call func when reaching the current level's node */
	else
	{
		/* Recurse to the next level for left and right subtrees */
		btlo_helper(tree->left, func, level - 1);
		btlo_helper(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the tree. Returns 0 if the tree is NULL.
 *         The height is the lengt of the longest path from the root to a leaf.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	/* Compute the height of the left and right subtrees */
	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	/* Return the maximum of the two heights */
	return (height_l > height_r ? height_l : height_r);
}
