#pragma once
#pragma once
#include "Matterbot.h"
#include "Header.h"

namespace lospi
{
	struct pause : ICommand {
		std::wstring get_name() override {
			return L"pause";
		}

		std::wstring get_help() override {
			return L"`pause [number]`: `pause` will change challenge the sleep time between challenge requests.";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {

			if (user.find(L"jlafleur") != std::wstring::npos)
			{
				sleepTime = std::stoi(command_text);
				return L"SleepTime request number has been changed to " + command_text;
			}
			else
			{
				return L"\0";
			}
		}
	};
}
