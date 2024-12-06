#include "binary_trees.h"

/**
 * get_height - calculates the height of a binary tree.
 * @tree: pointer to the root node of the tree to measure
 * the height of.
 *
 * Return: the height of the tree or 0 if tree is NULL.
 */
size_t get_height(const binary_tree_t *tree)
{
	size_t lheight = 0, rheight = 0;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);

	lheight = 1 + get_height(tree->left);
	rheight = 1 + get_height(tree->right);

	return (lheight > rheight ? lheight : rheight);
}

/**
 * get_depth - measures the depth of a node in a binary tree.
 * @tree: pointer to the node to measure the depth.
 *
 * Return: depth of pointer or 0 if node is NULL.
 */
size_t get_depth(const binary_tree_t *tree)
{
	size_t depth = 0;
	binary_tree_t *cursor = (binary_tree_t *)tree;

	if (tree == NULL)
		return (0);
	while (cursor->parent != NULL)
	{
		depth++;
		cursor = cursor->parent;
	}
	return (depth);
}

/**
 * execute_level_nodes - executes a fun to only nodes with
 * the depth/level provided.
 * @tree: pointer to root node of the tree to traverse.
 * @func: pointer to the function to call for each node.
 * @level: level whoes nodes will be traversed.
 *
 * Return: void.
 */
void execute_level_nodes(const binary_tree_t *tree,
			 void (*func)(int), size_t level)
{
	if (tree == NULL)
		return;
	if (get_depth(tree) == level)
		func(tree->n);
	execute_level_nodes(tree->left, func, level);
	execute_level_nodes(tree->right, func, level);
}

/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
 * @tree: pointer to the root node of the tree to traverse.
 * @func: pointer to the function to call for each node.
 *
 * Return: void.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, level;

	if (tree == NULL || func == NULL)
		return;
	height = get_height(tree);
	for (level = 0; level <= height; level++)
	{
		execute_level_nodes(tree, func, level);
	}
}
