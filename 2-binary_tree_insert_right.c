#include "binary_trees.h"

/**
 *
 * binary_tree_insert_right - puts a node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 *
 * Return: Pointer to the newly created node
 * and NULL on failure
 * or if parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *latest;

	if (!parent)
		return (NULL);

	latest = malloc(sizeof(binary_tree_t));
	if (!latest)
		return (NULL);

	latest->n = value;
	latest->parent = parent;
	latest->left = NULL;

	latest->right = parent->right;
	parent->right = latest;

	if (latest->right)
		latest->right->parent = latest;
	return (latest);
}
