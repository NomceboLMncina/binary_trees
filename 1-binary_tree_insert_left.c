#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left child of a given node
 * @parent: Pointer to the node to insert the left child into
 * @value: Integer value to assign to the new node
 *
 * Return: A pointer to the newly created node on success,
 *         or NULL if memory allocation fails,
 *         or NULL if the parent is NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (!parent)
	return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
	return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->right = NULL;
	new_node->left = parent->left;
	parent->left = new_node;
	if (new_node->left)
	new_node->left->parent = new_node;

	return (new_node);
}
