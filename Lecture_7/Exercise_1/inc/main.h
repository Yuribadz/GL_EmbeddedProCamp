#ifndef MAIN_H
#define MAIN_H

#include "pt.h"
/**
 * @brief Protothread 1 flag
 */
extern int pt_flag1;
/**
 * @brief Protothread 2 flag
 */
extern int pt_flag2;
/**
 * @brief Protothread 3 flag
 */
extern int pt_flag3;

/**
 * @brief Lc switch structure that Protothread lib macros are used on
 */
extern struct pt pt1;
/**
 * @brief Lc switch structure that Protothread lib macros are used on
 */
extern struct pt pt2;
/**
 * @brief Lc switch structure that Protothread lib macros are used on
 */
extern struct pt pt3;
/**
 * @brief Protothread function, sets its flag to 1, other two to 0
 * @param protothread structure pointer holding protothread type to execute protothread macro
 * @return int number with status of execution
 */
int pt_1(struct pt *protothread);
/**
 * @brief Protothread function, sets its flag to 1, other two to 0
 * @param protothread structure pointer holding protothread type to execute protothread macro
 * @return int number with status of execution, it can be either of those  
 * PT_WAITING 0
 * PT_YIELDED 1
 * PT_EXITED  2
 * PT_ENDED   3
 */
int pt_2(struct pt *protothread);
/**
 * @brief Protothread function, sets its flag to 1, other two to 0
 * @param protothread structure pointer holding protothread type to execute protothread macro
 * @return int number with status of execution
 */
int pt_3(struct pt *protothread);

#endif