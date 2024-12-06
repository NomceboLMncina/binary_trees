#include "binary_trees.h"

/**
 * find_min_value_node - Finds the node with the minimum value in a subtree.
 * @node: Pointer to the subtree root.
 *
 * Return: Pointer to the node with the smallest value.
 */
avl_t *find_min_value_node(avl_t *node)
{
    while (node->left != NULL)
        node = node->left;
    return (node);
}

/**
 * update_balance - Rebalances an AVL tree after a deletion.
 * @root: Pointer to the root of the subtree.
 *
 * Return: Pointer to the new root of the subtree.
 */
avl_t *update_balance(avl_t *root)
{
    int balance;

    if (!root)
        return (NULL);

    /* Calculate balance factor */
    balance = binary_tree_balance(root);

    /* Left-heavy */
    if (balance > 1)
    {
        if (binary_tree_balance(root->left) < 0)
            root->left = binary_tree_rotate_left(root->left);
        return (binary_tree_rotate_right(root));
    }

    /* Right-heavy */
    if (balance < -1)
    {
        if (binary_tree_balance(root->right) > 0)
            root->right = binary_tree_rotate_right(root->right);
        return (binary_tree_rotate_left(root));
    }

    return (root);
}

/**
 * avl_remove - Removes a node from an AVL tree and rebalances it.
 * @root: Pointer to the root node of the tree.
 * @value: The value to remove.
 *
 * Return: Pointer to the new root of the tree after removal and rebalancing.
 */
avl_t *avl_remove(avl_t *root, int value)
{
    avl_t *temp;

    if (!root)
        return (NULL);

    /* Search for the node to remove */
    if (value < root->n)
        root->left = avl_remove(root->left, value);
    else if (value > root->n)
        root->right = avl_remove(root->right, value);
    else
    {
        /* Node with one or no children */
        if (!root->left || !root->right)
        {
            temp = root->left ? root->left : root->right;
            free(root);
            return (temp);
        }

        /* Node with two children */
        temp = find_min_value_node(root->right);
        root->n = temp->n; /* Replace with in-order successor's value */
        root->right = avl_remove(root->right, temp->n);
    }

    /* Update height and rebalance */
    return (update_balance(root));
}
