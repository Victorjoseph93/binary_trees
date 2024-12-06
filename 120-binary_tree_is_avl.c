#include "binary_trees.h"

/**
 * get_max_min - get the maximum or minimum value of a BST.
 * (very right or very left node of tree.)
 * @tree: pointer to the node of the tree to get max value.
 * @str: string determining the value to be
 * measured (maximum or minimum).
 *
 * Return: the maximum or minimum value.
 */
int get_max_min(const binary_tree_t *tree, char *str)
{
	int val;
	binary_tree_t *cursor = (binary_tree_t *)tree;

	if (strcmp(str, "max") == 0)
	{
		while (cursor->right)
			cursor = cursor->right;
		val = cursor->n;
	}
	else if (strcmp(str, "min") == 0)
	{
		while (cursor->left)
			cursor = cursor->left;
		val = cursor->n;
	}
	return (val);
}

/**
 * is_bst - checks if a tree is a valid BST.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is valid BST and 0 otherwise.
 */
int is_bst(const binary_tree_t *tree)
{
	int bst_flag = 1, min_right, max_left;

	if (tree == NULL)
		return (1);

	/* checking for max and min numbers of subtrees */
	if (tree->left)
	{
		max_left = get_max_min(tree->left, "max");
		if (max_left >= tree->n)
			return (0);
	}
	if (tree->right)
	{
		min_right = get_max_min(tree->right, "min");
		if (min_right <= tree->n)
			return (0);
	}

	/* checking if left and right subtrees are AVLs */
	bst_flag &= is_bst(tree->left);
	bst_flag &= is_bst(tree->right);
	return (bst_flag);
}

/**
 * get_height - calculates the height of a binary tree.
 * @tree: pointer to the tree we're measuring height of.
 *
 * Return: height of tree.
 */
int get_height(const binary_tree_t *tree)
{
	size_t lheight = 0, rheight = 0;

	if (tree == NULL)
		return (0);

	lheight = 1 + get_height(tree->left);
	rheight = 1 + get_height(tree->right);

	return (lheight > rheight ? lheight : rheight);
}

/**
 * check_heights - checks if a tree is balanced.
 * @tree: pointer of the root of a binary tree.
 *
 * Return: 1 if binary tree is balanced, 0
 * otherwise.
 */
int check_heights(const binary_tree_t *tree)
{
	int lh, rh, avl_flag = 1;

	if (tree == NULL)
		return (1);

	lh = get_height(tree->left);
	rh = get_height(tree->right);

	if (abs(lh - rh) > 1)
		avl_flag = 0;
	avl_flag &= check_heights(tree->left);
	avl_flag &= check_heights(tree->right);

	return (avl_flag);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL tree.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is valid AVL and 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int avl_flag = 1;

	if (tree == NULL)
		return (0);

	else
	{
		avl_flag &= is_bst(tree);
		avl_flag &= check_heights(tree);
	}
	return (avl_flag);
}
