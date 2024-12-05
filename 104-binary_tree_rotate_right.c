#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * A right rotation involves shifting the root to the right, making its left
 * child the new root, and the original root becomes the right child of the
 * new root. This operation is commonly used to maintain balance in binary
 * search trees, such as AVL trees or Red-Black trees.
 *
 * Return: Pointer to the new root node of the tree after rotation,
 *         NULL upon failure (if the tree is NULL or does not have a left child).
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tmp = NULL, *parent;

	if (!tree || !tree->left)
		return (NULL);

	tmp = tree;
	parent = tree->parent;
	tree = tree->left;
	tree->parent = NULL;

	if (tree->right)
	{
		tmp->left = tree->right;
		tree->right->parent = tmp;
	}
	else
		tmp->left = NULL;

	tmp->parent = tree;
	tree->right = tmp;

	if (parent)
		parent->left = tree;

	tree->parent = parent;

	return (tree);
}
