#pragma once
#include "Matterbot.h"
#include "collision.h"
#include "Header.h"

namespace lospi
{
	struct password : ICommand {
		std::wstring get_name() override {
			return L"password";
		}

		std::wstring get_help() override {
			return L"`password`: `password` will request the current password from rivestment.";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {

			if (user.find(L"jlafleur") != std::wstring::npos)
			{
				return L"rivestment password";
			}
			else if (user.find(L"rivestment") != std::wstring::npos)
			{
				passwd = wstring_to_string(command_text);
				return L"Password has been updated to " + command_text;
			}
			else
			{
				return L"\0";
			}
		}
	};
}
