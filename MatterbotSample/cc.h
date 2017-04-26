#pragma once
#include "Matterbot.h"
#include "Header.h"

namespace lospi
{
	struct cc : ICommand {
		std::wstring get_name() override {
			return L"cc";
		}

		std::wstring get_help() override {
			return L"`cc [number]`: `cc` will change challenge request number up to 500.";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {

			if (user.find(L"jlafleur") != std::wstring::npos)
			{
				challenge_num = std::stoi(command_text);
				return L"Challenge request number has been changed to " + command_text;
			}
			else
			{
				return L"\0";
			}
		}
	};
}
