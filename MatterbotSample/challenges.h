#pragma once
#include "Matterbot.h"
#include "collision.h"
#include "Header.h"
#include "pause.h"
#include <algorithm>

namespace lospi {
	struct challenges : ICommand {
		explicit challenges(std::shared_ptr<Matterbot> bot) : bot{ bot } { }
		std::wstring get_name() override { return L"challenges"; }

		std::wstring get_help() override { return L"`challenges [hash list]`: `challenges` will parse the challenges list and do a hash collision."; }

		std::wstring handle_command(const std::wstring& team, const std::wstring& channel,
			const std::wstring& user, const std::wstring& command_text) override {

			if (user.find(L"jlafleur") != std::wstring::npos)
			{
				if (challenge_num < 1)
				{
					return L"rivestment challenge";
				}
				else
				{
					return L"rivestment challenge " + std::to_wstring(challenge_num);
				}
			}
			else if (user.find(L"rivestment") != std::wstring::npos)
			{
				if (command_text.empty())
				{
					return L"Something bad happened... stopping loop.";
				}
				else
				{
					_sleep(sleepTime);
					bot->post_message(explosions(command_text));
					_sleep(sleepTime);
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

