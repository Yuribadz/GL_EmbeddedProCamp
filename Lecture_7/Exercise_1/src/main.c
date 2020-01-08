#include "pt.h"
#include <stdio.h>
#include <unistd.h>

struct pt pt1;
struct pt pt2;
struct pt pt3;
int pt_flag1;
int pt_flag2;
int pt_flag3;

int pt_1(struct pt *pt)
{
	PT_BEGIN(pt);
	for (;;)
	{
		pt_flag1 = 1;
		PT_WAIT_UNTIL(pt, pt_flag2 != 0 && pt_flag3 != 0);
		printf("Pt1...\n");
		pt_flag2 = 1;
		pt_flag3 = 0;
	}
	PT_END(pt);
}

int pt_2(struct pt *pt)
{
	PT_BEGIN(pt);
	for (;;)
	{
		pt_flag2 = 1;
		PT_WAIT_UNTIL(pt, pt_flag1 != 0 && pt_flag3 != 0);
		printf("Pt2...\n");
		pt_flag1 = 0;
		pt_flag3 = 1;
	}
	PT_END(pt);
}

static int pt_3(struct pt *protothread)
{
	PT_BEGIN(protothread);
	for (;;)
	{
		pt_flag3 = 1;
		PT_WAIT_UNTIL(protothread, pt_flag1 != 0 && pt_flag2 != 0);
		printf("Pt3...\n");
		pt_flag1 = 1;
		pt_flag2 = 0;
	}
	PT_END(protothread);
}

int main(void)
{
	PT_INIT(&pt1);
	PT_INIT(&pt2);
	PT_INIT(&pt3);
	for(;;) {
		pt_1(&pt1);
		sleep(1); //readable output
		pt_2(&pt2);
		sleep(1);
		pt_3(&pt3);
		sleep(1);
	}
	return 0;
}
