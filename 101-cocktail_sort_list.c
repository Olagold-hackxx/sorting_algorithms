#include "sort.h"

/**
* cocktail_sort_list - sort using cocktail algorithm
* @list: list to sort
*/

void cocktail_sort_list(listint_t **list)
{
	if ((list == NULL) || (*list == NULL) || ((*list)->next == NULL))
		return;

	cocktailSort(list, 0);
	while ((*list)->prev != NULL)
		*list = (*list)->prev;
}

/**
* cocktailSort - sort using cocktail algorithm
* @list: ptr to node to be sorted
* @direction: direction to sort - left to right = 0
* right to left = 1
*/
void cocktailSort(listint_t **list, int direction)
{
	listint_t *tmp, *val;
	int swapped = 0;

	if (direction == 0)
	{
		tmp = *list;
		while (tmp)
		{
			if ((tmp->next != NULL) && (tmp->n > tmp->next->n))
			{
				val = tmp;
				swap(&tmp);
				swapped = 1;
			}
			else
				tmp = tmp->next;
		}
		if (swapped != 0)
			cocktailSort(&val->prev, 1);
	}
	else
	{
		tmp = *list;

		while (tmp && (tmp->prev != NULL))
		{
			if (tmp->n < tmp->prev->n)
			{
				val = tmp;
				swap_back(&tmp);
				swapped = 1;
			}
			else
				tmp = tmp->prev;
		}
		if (swapped != 0)
			cocktailSort(&val->next, 0);
	}
}

/**
* swap - swap a node in list forward
* @top: ptr to node to swap
*/

void swap(listint_t **top)
{
	listint_t *tmp, *val;

	if (*top == NULL || top == NULL)
		return;

	tmp = *top;
	val = tmp->next;
	if (*top != NULL)
	{
		if (tmp->prev != NULL)
		{
			val->prev = tmp->prev;
			tmp->prev->next = val;
		}
		else
			val->prev = NULL;
		tmp->prev = val;
		if (val->next == NULL)
			tmp->next = NULL;
		else
		{
			tmp->next = val->next;
			val->next->prev = tmp;
		}
		val->next = tmp;
	}
	while (tmp->prev != NULL)
		tmp = tmp->prev;
	print_list(tmp);
}

/**
* swap_back - swap a node in list backward
* @top: ptr to node to swap
*/

void swap_back(listint_t **top)
{
	listint_t *tmp, *val;

	if (*top == NULL || top == NULL)
		return;
	tmp = *top;
	val = tmp->prev;
	if (val != NULL)
	{
		if (tmp->next != NULL)
		{
			val->next = tmp->next;
			tmp->next->prev = val;
		}
		else
			val->next = NULL;
		tmp->next = val;
		if (val->prev == NULL)
			tmp->prev = NULL;
		else
		{
			tmp->prev = val->prev;
			val->prev->next = tmp;
		}
		val->prev = tmp;
	}
	while (tmp->prev != NULL)
		tmp = tmp->prev;
	print_list(tmp);
}
