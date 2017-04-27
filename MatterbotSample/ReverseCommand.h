#pragma once
#include "Matterbot.h"
#include <algorithm>

namespace lospi {
  struct ReverseCommand : ICommand {
    explicit ReverseCommand(std::shared_ptr<Matterbot> bot) : bot{bot} { }
    std::wstring get_name() override { return L"reverse"; }

    std::wstring get_help() override { return L"`reverse [MESSAGE]`: `reverse` will respond with the original message and its reverse."; }

    std::wstring handle_command(const std::wstring& team, const std::wstring& channel,
                                const std::wstring& user, const std::wstring& command_text) override {

		if (user.find(L"jlafleur") != std::wstring::npos)
		{
			bot->post_message(command_text);
			auto reversed{ command_text };
			reverse(reversed.begin(), reversed.end());
			return reversed;
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
