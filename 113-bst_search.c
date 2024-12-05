#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree
 * @tree: A pointer to the root node of the BST to search within
 * @value: The value to search for in the tree
 *
 * This function performs a search for a given value in the Binary Search Tree.
 * It takes advantage of the properties of the BST, where:
 * - All nodes in the left subtree of a node contain values smaller
 *   than the node.
 * - All nodes in the right subtree contain values greater than the
 *   node.
 *
 * The search proceeds by comparing the target value with the current node’s
 * value:
 * - If the value matches, the function returns the node containing that value.
 * - If the target value is smaller, the function moves to the left child.
 * - If the target value is greater, the function moves to the right child.
 *
 * Return: A pointer to the node containing an int equal to `value` if found
 *         NULL if the tree is empty or if the value is not found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *node = (bst_t *)tree;

	if (!tree)
		return (NULL);

	while (node)
	{
		if (value == node->n)
			return (node);
		if (value < node->n)
			node = node->left;
		else if (value > node->n)
			node = node->right;
	}

	return (NULL);
}
