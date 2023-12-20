#ifndef _SORTING_H_
#define _SORTING_H_
#include <stdio.h>
#include <stdlib.h>


/** Struct Double Linked List */

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


void prntArray(const int *array, size_t size);
void prntList(const listint_t *list);

void interChng(listint_t *a, listint_t *b, listint_t **head);
int getMin(int *array, int index, size_t size);
void exchng(int *a, int *b);
int partArray(int *array, int low, int high, size_t size);
size_t getListLen(listint_t *list);
int getMax(int *array, int size);
void stupif(int *array, int heap, int idx, int size);
void lsd(int *array, size_t size, size_t lsd);




void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_recursion(int *array, int left, int right, size_t size);
void shell_sort(int *array, size_t size);
void swapNodes(listint_t **list, listint_t **p);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);

#endif
