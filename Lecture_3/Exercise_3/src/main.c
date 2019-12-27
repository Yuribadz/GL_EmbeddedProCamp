#include <stdio.h>
#include <limits.h>
#include "queue.h"

/**
 * Function puts new element into queue array.
 * @param data int number to be stored in queue.
 * @return int number. -1 if queue of size is full, 0 on success.
 */
int put(int data)
{
    if (count < Q_SIZE)
    {
	    if (q_tail == (Q_SIZE - 1))
	    {
		    q_tail = -1;
	    }
	    queue[++q_tail] = data;
	    ++count;
	    return 0;
    }
    else
    {
	    return -1;
    }
}

/**
 * Function returns first to be taken from queue array and removes it from queue.
 * @return int Last stored number in array, INT_MAX on error.
 */
int get()
{
	int data = 0;
	if (count > 0)
	{

		if (q_head == Q_SIZE)
		{
			q_head = 0;
		}
		data = queue[q_head++];
		--count;
	}
	else
	{
	        return INT_MAX;
	}

	return data;
}

/**
 * Function return first element of queue.
 * @return int first element of queue.
 */
int read()
{
	return queue[q_head];
}

int main(void)
{
	put(5);
	printf("Elem to be taken from queue : %d\n", read());
	printf("Queue elem taken : %d\n", get());
        return 0;
}
