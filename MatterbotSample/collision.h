#pragma once
#include "Matterbot.h"
#include "Header.h"
#include <algorithm>

namespace lospi
{
	uint64_t to_tiny_val(std::string &digest) 
	{
		std::map<char, char> hexmap = { { 'h', 0x1 },{ 's', 0x2 },{ 'o', 0x3 },{ 'j', 0x4 } };
		uint64_t myVal = 0x0;

		for (int i = 0; i <digest.size(); i++) 
		{
			myVal <<= 3;
			myVal |= hexmap[digest[i]];
		}

		return myVal;
	}

	std::string from_tiny_val(uint64_t myInt) {
		std::map<char, char> hexmap = { { 0x0, 0x0 },{ 0x1, 'h' },{ 0x2, 's' },{ 0x3, 'o' },{ 0x4, 'j' } };
		std::string myVal;

		for (int i = 0; i < sizeof(uint64_t) * 4; i++) 
		{
			if (hexmap[myInt & 0x7] != 0x0) 
			{
				myVal += hexmap[myInt & 0x7];
			}
			myInt >>= 3;
		}
		reverse(myVal.begin(), myVal.end());

		return myVal;
	}

	void create_rainbow()
	{

		for (int i = 0; i < (level + 10); i++)
		{
			Combinator combo(alpha, (i));

			while (combo.has_next())
			{
				auto c = combo.next();
				std::string p(c.begin(), c.end());
				p = p.substr(0, i);
				
				std::copy(passwd.begin(), passwd.end(), back_inserter(c));
				rainbow_table.emplace(compute_md5(c.data(), c.size()), to_tiny_val(p));
			}
		}
	}

	std::wstring explosions(std::wstring hashes)
	{
		std::vector<Md5Digest> challenge_list;
		std::vector<std::string> answer_list;
		std::wstringstream ss(hashes);
		std::wstring str;

		//split text into challenge list
		while (std::getline(ss, str, L' '))
		{
			challenge_list.push_back(get_md5_from_str(str));
		}

		// do the hash collission here
		for (const auto& cli : challenge_list)
		{
			auto it = rainbow_table.find(cli);
			if (it != rainbow_table.end())
			{
				std::string answer = from_tiny_val(it->second);
				answer_list.push_back(answer);
			}
		}

		// put the answers into a string for theTry
		str = L"";
		do
		{
			std::wstring answer;
			copy(answer_list.back().begin(), answer_list.back().end(), back_inserter(answer));
			answer.append(string_to_wstring(passwd));
			str += L" " + answer;
			answer_list.pop_back();
		} while (!answer_list.empty());

		// convert theAnswers to wstring and try the password list
		std::wstring theTry = L"rivestment try" + str;
		return theTry;
	}
}