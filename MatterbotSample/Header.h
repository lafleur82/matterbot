#pragma once
#include <string>
#include <map>
#include "Md5Utilities.h"

namespace lospi
{
	// global variables for rivestment
	int level = 4;
	std::string passwd = "03hq6p";
	int challenge_num = 150;
	std::map<Md5Digest, uint64_t> rainbow_table;
}
