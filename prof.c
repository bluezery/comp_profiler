#include <stdio.h>
#include <stdlib.h>

static int ttt = 0;
static int ttt2 = 0;

static void doo2()
{
	int *c = malloc(4);
	free(c);
}

static void doo3()
{
	int *c = malloc(4);
	free(c);
}

static void doo()
{
	ttt++;
	int *c = malloc(4);
	free(c);
	if (ttt % 2)	doo2();
	else	doo3();
}

static void cycle2();
static void cycle3();

static void cycle()
{
	if (ttt2%2) cycle2();
	else ttt2++;
}

static void cycle2()
{
	cycle3();
}

static void cycle3()
{
	ttt2++;
	cycle();
}

int main()
{
	// Simple function call
	while (ttt < 100000000) {
		doo();
	}

	// Cycling function call
	ttt2 = 1;
	while (ttt2 < 100000000) {
		cycle();
	}
	return 0;
}

