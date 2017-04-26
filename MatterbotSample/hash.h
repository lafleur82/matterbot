#pragma once
#include "Matterbot.h"
#include "collision.h"
#include "Header.h"

namespace lospi
{
	struct dohash : ICommand {
		std::wstring get_name() override {
			return L"dohash";
		}

		std::wstring get_help() override {
			return L"`dohash`: `dohash` will take a string and hash it.";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {

			if (user.find(L"jlafleur") != std::wstring::npos)
			{
				auto str = wstring_to_string(command_text);
				
				return get_str_from_md5(compute_md5(str.c_str(), str.length()));
			}
			else
			{
				return L"\0";
			}
		}
	};
}
