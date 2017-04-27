#pragma once
#include "Matterbot.h"
#include <algorithm>

namespace lospi {
	struct scraps : ICommand {
		explicit scraps(std::shared_ptr<Matterbot> bot) : bot{ bot } { }
		std::wstring get_name() override { return L"scraps"; }

		std::wstring get_help() override { return L"`scraps`: `scraps` will request scraps from rivestment and attempt to solve them or start the challenges loop if there are no scraps."; }

		std::wstring handle_command(const std::wstring& team, const std::wstring& channel,
			const std::wstring& user, const std::wstring& command_text) override {

			if (user.find(L"jlafleur") != std::wstring::npos)
			{
				return L"rivestment scraps";
			}
			else if (user.find(L"rivestment") != std::wstring::npos)
			{
				if (!command_text.empty())
				{
					bot->post_message(explosions(command_text));
					_sleep(sleepTime);
					return L"rivestment scraps";
				}
				else
				{
					return L"rivestment challenge " + std::to_wstring(challenge_num);
				}
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
