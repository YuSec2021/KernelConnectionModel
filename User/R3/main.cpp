#include "comm\comm.h"
#include <cstdio>

int main() {

	Test t = { 0 };
	t.x = 2000;
	t.y = 3000;

	DriverComm(TEST, &t, sizeof(t), NULL, NULL);

	printf("[db]: %x-------%x\r\n", t.x, t.y);
	system("pause");
	return 0;
}