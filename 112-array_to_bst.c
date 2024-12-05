#include "binary_trees.h"

/**
 * array_to_bst - Builds a Binary Search Tree (BST) from an array
 * @array: A pointer to the first element of the array to be converted
 * into a BST
 * @size: The number of elements in the array
 *
 * This function takes an array of integers and inserts each element into a
 * Binary Search Tree. The elements are inserted one by one using the
 * `bst_insert` function, which ensures that the resulting tree follows
 * the Binary Search Tree property:
 * - The left child contains values smaller than the parent node.
 * - The right child contains values larger than the parent node.
 *
 * Return: A pointer to the root node of the newly created BST
 *         NULL if an error occurs or memory allocation fails
 */
bst_t *array_to_bst(int *array, size_t size)
{
	unsigned int i;
	bst_t *root = NULL;

	for (i = 0; i < size; i++)
		bst_insert(&root, array[i]);

	return (root);
}
