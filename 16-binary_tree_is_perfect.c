#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect
 * and 0 if the tree is not perfect
 * and 0 if tree is NULL
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t heig = 0;
	size_t nd = 0;
	size_t pw = 0;

	if (!tree)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	heig = binary_tree_height(tree);
	nd = binary_tree_size(tree);

	pw = (size_t)_pow_recursion(2, heig + 1);
	return (pw - 1 == nd);
}

/**
 *_pow_recursion - it returns the value of x raised to the power of y
 *@x: the value to exponentiate
 *@y: the power to raise x to
 *Return: x to the power of y, or -1 if y is negative
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);

	else
		return (x * _pow_recursion(x, y - 1));

}

/**
 * binary_tree_size - checks the size of a binary tree
 * @tree: tree to measure the size of
 *
 * Return: size of the tree
 *         0 if tree is NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_height - checks the height of a binary tree
 * @tree: tree to measure the height of
 *
 * Return: height of the tree
 * is 0 if tree is NULL
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
