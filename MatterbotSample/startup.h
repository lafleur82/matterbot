
#pragma once
#include "Matterbot.h"
#include <algorithm>

namespace lospi {
	struct startup : ICommand {
		explicit startup(std::shared_ptr<Matterbot> bot) : bot{ bot } { }
		std::wstring get_name() override { return L"startup"; }

		std::wstring get_help() override { return L"`startup [level 1-12]`: `startup` preps Sabot for rivestment with the provided starting level."; }

		std::wstring handle_command(const std::wstring& team, const std::wstring& channel,
			const std::wstring& user, const std::wstring& command_text) override {

			if (user.find(L"jlafleur") != std::wstring::npos)
			{
				bot->post_message(L"rivestment register Sabot");
				_sleep(1000);

				bot->post_message(L"rivestment password");
				_sleep(1000);

				std::wstring lvl = std::to_wstring(4);
				if (!command_text.empty())
				{
					lvl = command_text;
				}
				level = std::stoi(lvl);
				bot->post_message(L"rivestment level " + lvl);
				_sleep(1000);

				return L"Startup complete, ready to compete.";
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
