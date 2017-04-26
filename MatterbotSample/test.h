#pragma once
#include "Matterbot.h"
#include "Header.h"
#include <algorithm>

namespace lospi {
	struct test : ICommand {
		explicit test(std::shared_ptr<Matterbot> bot) : bot{ bot } { }
		std::wstring get_name() override { return L"test"; }

		std::wstring get_help() override { return L"`test [who knows]`: `test` will do random shit depending on what is being tested."; }

		std::wstring handle_command(const std::wstring& team, const std::wstring& channel,
			const std::wstring& user, const std::wstring& command_text) override {

			if (user.find(L"jlafleur") == std::wstring::npos)
			{
				std::string alpha = "hsoj";
				std::map<Md5Digest, std::vector<char>> aMap;

				Combinator combo(alpha, 1);

				while (combo.has_next())
				{
					auto c = combo.next();

					copy(passwd.begin(), passwd.end(), back_inserter(c));
					aMap.emplace(compute_md5(c.data(), c.size()), c);
				}

				std::wstring rtn;
				for (const auto& it : aMap)
				{
					std::wstring test(it.second.begin(), it.second.end());
					rtn.append(L" " + test);
				}
				
				return rtn;
			}
			else
			{
				return L"\0";
			}
		}
	private:
		std::shared_ptr<Matterbot> bot;
	};
}