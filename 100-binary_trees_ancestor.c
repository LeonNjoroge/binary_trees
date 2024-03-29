#include "binary_trees.h"

/**
 * binary_trees_ancestor - checks the lowest common ancestor of two nodes
 *
 * @first: a pointer to the first node to find the ancestor
 * @second: a pointer to the second node to find the ancestor
 *
 * Return: pointer to the ancestor node
 * and NULL if there is no ancestor node
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	size_t dp_first, dp_second;

	if (!first || !second)
		return (NULL);

	dp_first = binary_tree_depth(first);
	dp_second = binary_tree_depth(second);


	while (dp_first > dp_second)
	{
		first = first->parent;
		dp_first--;
	}
	while (dp_second > dp_first)
	{
		second = second->parent;
		dp_second--;
	}

	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}

/**
 * binary_tree_depth - this the depth of a node in a binary tree
 * @tree: node to calculate the depth of
 *
 * Return: depth of the node
 * and 0 if tree is NULL
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t dp = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		dp++;
		tree = tree->parent;
	}

	return (dp);
}
