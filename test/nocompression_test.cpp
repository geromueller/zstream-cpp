#include <stdio.h>
#include <stdlib.h>

#include "zstream.hpp"
#include <fstream>
#include <iterator>
#include <iostream>

using namespace std;
using namespace zstream;

int main(void)
{
	string input = "Hello world \n";
	ostringstream buffer;
	{
		ozstream zipper(buffer, 0);
		zipper << input;
	}
	string zstr = buffer.str();

	istringstream ibuffer(zstr);
	izstream izstream(ibuffer);
	izstream.unsetf(ios_base::skipws);

	string output = std::string((std::istream_iterator<char>(izstream)),
								std::istream_iterator<char>());

	if (output != input)
	{
		cout << "compare failed" << endl;
		return 1;
	}
	else
	{
		cout << "compare succeeded" << endl;
		return 0;
	}
}
