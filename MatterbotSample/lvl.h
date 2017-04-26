#pragma once
#include "Matterbot.h"
#include "collision.h"
#include "Header.h"

namespace lospi
{
	struct lvl : ICommand {
		std::wstring get_name() override {
			return L"lvl";
		}

		std::wstring get_help() override {
			return L"`lvl`: `lvl` will update the current level for rivestment.";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {

			if (user.find(L"jlafleur") != std::wstring::npos || user.find(L"sabot") != std::wstring::npos)
			{
				if (command_text.empty())
				{
					level = 1;
				}
				else
				{
					level = std::stoi(command_text);
				}
				return L"rivestment level " + std::to_wstring(level);
			}
			else
			{
				return L"\0";
			}
		}
	};
}
