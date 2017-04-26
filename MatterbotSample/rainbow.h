#pragma once
#include "Matterbot.h"
#include "collision.h"
#include "Header.h"

namespace lospi
{
	struct rainbow : ICommand {
		std::wstring get_name() override {
			return L"rainbow";
		}

		std::wstring get_help() override {
			return L"`rainbow`: `rainbow` will generate the rainbow table for rivestment hash crashing.";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {

			if (user.find(L"jlafleur") != std::wstring::npos)
			{
				create_rainbow();

				return L"Rainbow table complete. Ready to compete.";
			}
			else
			{
				return L"\0";
			}
		}
	};
}
