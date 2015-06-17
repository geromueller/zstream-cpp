#include <stdio.h>
#include <stdlib.h>

#include "ozstream.hpp"
#include <fstream>
#include <iostream>

using namespace std;
using namespace zstream;

int main(void) {
	ofstream os("test.txt.gz");
	ogzstream gz(os);
	for (size_t i = 0; i < 2000; i++) {
		gz << drand48() << endl;
	}
	return 0;
}
 
