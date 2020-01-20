#include "pt.h"
#include <stdio.h>

struct pt pt1;
struct pt pt2;
int pt_flag1;
int pt_flag2;

int pt_1(struct pt *protothread)
{
	PT_BEGIN(protothread);
	for (;;)
	{
		PT_WAIT_UNTIL(protothread, pt_flag2 != 0);
		printf("Pt1...\n");
		pt_flag2 = 0;
		pt_flag1 = 1;
	}
	PT_END(protothread);
}

int pt_2(struct pt *protothread)
{
	PT_BEGIN(protothread);
	for (;;)
	{
		pt_flag2 = 1;
		PT_WAIT_UNTIL(protothread, pt_flag1 != 0);
		printf("Pt2...\n");
		pt_flag1 = 0;
	}
	PT_END(protothread);
}

int main(void)
{
	PT_INIT(&pt1);
	PT_INIT(&pt2);
	for (;;)
	{
		PT_SCHEDULE(pt_1(&pt1));
		PT_SCHEDULE(pt_2(&pt2));
	}
	return 0;
}