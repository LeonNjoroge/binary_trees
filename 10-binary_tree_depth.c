#include "binary_trees.h"

/**
 * binary_tree_depth - records the depth of a node in a binary tree
 * @tree: node to calculate the depth of
 *
 * Return: depth of the node
 *         0 if tree is NULL
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t dph = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		dph++;
		tree = tree->parent;
	}

	return (dph);
}
