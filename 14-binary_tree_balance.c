#include "binary_trees.h"

/**
 * binary_tree_balance - checks the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: the balance factor
 *         0 if tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int l_height, r_height;

	if (!tree)
		return (0);

	l_height = tree->left ? (int)binary_tree_height(tree->left) : -1;
	r_height = tree->right ? (int)binary_tree_height(tree->right) : -1;

	return (l_height - r_height);
}

/**
 * binary_tree_height - checks the height of a binary tree
 * @tree: tree to measure the height of
 *
 * Return: height of the tree
 *         0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_height = 0;
	size_t r_height = 0;

	if (!tree)
		return (0);

	l_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	r_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (l_height > r_height ? l_height : r_height);
}
