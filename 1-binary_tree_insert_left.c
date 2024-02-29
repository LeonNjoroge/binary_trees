#include "binary_trees.h"

/**
 * binary_tree_insert_left -puts a node as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 *
 * Return: Pointer to the newly created node
 *         NULL on failure
 *         NULL if parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{

	binary_tree_t *latest;

	if (!parent)
		return (NULL);

	latest = malloc(sizeof(binary_tree_t));

	if (!latest)
		return (NULL);

	latest->n = value;
	latest->parent = parent;
	latest->right = NULL;

	latest->left = parent->left;
	parent->left = latest;

	if (latest->left)
		latest->left->parent = latest;
	return (latest);
}
