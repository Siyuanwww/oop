#include <iostream>
#include "Example.h"

using namespace std;

int Example::cnt = 0;

Example::Example(int data) {
	id = ++cnt;
	dat = data;
	printf("Example #%d is created\n", id);
}

void Example::getData() {
	printf("The data of Example #%d is %d\n", id, dat);
}

Example::~Example() {
	printf("Example #%d is destroyed\n", id);
}