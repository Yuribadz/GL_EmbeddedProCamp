#ifndef QUEUE_H
#define QUEUE_H

/**
 * @brief Queue size
 */
#define Q_SIZE 10
/**
 * @brief Queue head position counter.
 */
int q_head =  0;
/**
 * @brief Queue tail position counter.
 */
int q_tail = -1;
/**
 * @brief Queue storage array.
 */
int queue[Q_SIZE];
/**
 * @brief Element count.
 */
int count = 0;

/**
 * Function puts new element into queue array.
 * @param data int number to be stored in queue.
 * @return int number. -1 if queue of size is full, 0 on success.
 */
int put(int data);

/**
 * Function returns first to be taken from queue array and removes it from queue.
 * @return int Last stored number in array, INT_MAX on error.
 */
int get();

/**
 * Function return first element of queue.
 * @return int first element of queue.
 */
int read();

#endif
