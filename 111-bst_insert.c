#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a Binary Search Tree (BST)
 * @tree: A double pointer to the root node of the BST
 * @value: The value to store in the new node to be inserted
 *
 * This function inserts a value into the correct location in
 * a Binary Search Tree
 * according to the BST property:
 * - The left subtree of a node contains only nodes with values
 *   less than the node's value.
 * - The right subtree contains only nodes with values greater
 *   than the node's value.
 * Duplicate values are not allowed in the BST.
 *
 * Return: A pointer to the created node if insertion is successful
 *         NULL if the value is already in the tree or an error occurs
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *tmp = NULL;
	bst_t *second = NULL;
	bst_t *new = NULL;

	if (!tree)
		return (NULL);
	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	tmp = *tree;
	while (tmp)
	{
		second = tmp;
		if (value < tmp->n)
			tmp = tmp->left;
		else if (value > tmp->n)
			tmp = tmp->right;
		else if (value == tmp->n)
			return (NULL);
	}

	new = binary_tree_node(NULL, value);
	if (second == NULL)
		second = new;
	else if (value < second->n)
	{
		second->left = new;
		new->parent = second;
	}
	else
	{
		second->right = new;
		new->parent = second;
	}

	return (new);
}
