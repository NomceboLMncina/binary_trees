#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * A left rotation involves shifting the root to the left, making its right
 * child the new root, and the original root becomes the left child of the
 * new root. This is a common operation in balanced binary search trees.
 *
 * Return: Pointer to the new root node of the tree after rotation,
 *         NULL upon failure (if the tree is NULL or does not have a
 *         right child).
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp = NULL, *parent;

	if (!tree || !tree->right)
		return (NULL);

	tmp = tree;
	parent = tree->parent;
	tree = tree->right;
	tree->parent = NULL;

	if (tree->left)
	{
		tmp->right = tree->left;
		tree->left->parent = tmp;
	}
	else
		tmp->right = NULL;

	tmp->parent = tree;
	tree->left = tmp;

	if (parent)
		parent->right = tree;

	tree->parent = parent;

	return (tree);
}
