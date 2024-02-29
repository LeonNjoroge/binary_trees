#include "binary_trees.h"

/**
 *
 * binary_tree_node - makes a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 *
 * Return: The Pointer to the newly created node
 * and NULL on failure
 *
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{

	binary_tree_t *latest;


	latest = malloc(sizeof(binary_tree_t));
	if (!latest)
		return (NULL);

	latest->n = value;
	latest->parent = parent;

	latest->left = NULL;
	latest->right = NULL;

	return (latest);
}
