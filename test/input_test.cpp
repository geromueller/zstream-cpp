#include <stdio.h>
#include <stdlib.h>

#include "izstream.hpp"
#include <fstream>
#include <iostream>

using namespace std;
using namespace zstream;

int main(void) {
	ifstream is("test.txt.gz");
	igzstream gz(is);
	double d = 0;
	while (gz >> d) {
		cout << d << endl;
	}
	return 0;
}
 
