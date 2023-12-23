#include "sort.hy"
#include "deck.hy"

void swap_it(deck_node_t **deck, deck_node_t *node);
size_t d_len(const deck_node_t *hy);
int card2int(deck_node_t *node);
/**
 * swap_it - swaps adjacent nodes
 * @deck: ptr of pointer to head
 * @node: node to swap
 */
void swap_it(deck_node_t **deck, deck_node_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*deck = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
 * d_len - lngth of card deck
 * @hy: head to deck
 * Return: returns size of the deck
 */
size_t d_len(const deck_node_t *hy)
{
	size_t c = 0;

	while (hy != NULL)
	{
		c++;
		hy = hy->next;
	}

	return (c);
}

/**
 * card2int - gives unique value to each card
 * @node: Card to extract value from
 * Return: returns a unique card id
 */

int card2int(deck_node_t *node)
{
	int idx;
	char *values[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
			"10", "Jack", "Queen", "King"};

	for (idx = 0; idx < 13; idx++)
	{
		if (!strcmp(node->card->value, values[idx]))
			return (idx + (13 * node->card->kind));
	}

	printf("Uh-oh. Card is out of range. idx'm gonna crash now.");
	exit(EXIT_FAILURE);
}

/**
 * sort_deck - sorts the deck with cocktail shaker
 * @deck: the card deck to be sorted
 */

void sort_deck(deck_node_t **deck)
{
	int swpd = 1, a, b;
	size_t lo = 0, hi = (d_len(*deck) - 1), idx = 0;
	deck_node_t *tmp = *deck;

	if (!deck || !(*deck) || !((*deck)->next))
		return;
	while (swpd)
	{
		swpd = 0;
		for (; idx < hi; idx++)
		{
			a = card2int(tmp);
			b = card2int(tmp->next);
			if (b < a)
			{
				swap_it(deck, tmp);
				swpd = 1;
			}
			else
				tmp = tmp->next;
		}
		if (!swpd)
			break;
		swpd = 0;
		for (; idx > lo; idx--)
		{
			a = card2int(tmp);
			b = card2int(tmp->prev);
			if (b > a)
			{
				swap_it(deck, tmp->prev);
				swpd = 1;
			}
			else
				tmp = tmp->prev;
		}
		hi -= 1;
		lo += 1;
	}
}
