
#include <ctime>
#include<string>
#include"nameuuid.h"

using namespace std;



string name::uuid[4] = {};
string name::uuid_ = "";

void  setss(int i)
{
	std::time_t t = std::time(0);
	string ss = to_string(t);
	name::uuid_ = ss;
	name::uuid[i - 1] = ss;

}