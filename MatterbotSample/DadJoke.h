#pragma once
#include <sstream>
#include "Matterbot.h"

namespace lospi
{
	struct DadJoke : ICommand {
		std::wstring get_name() override {
			return L"DadJoke";
		}

		std::wstring get_help() override {
			return L"`DadJoke [1-22]: `DadJoke` will respond with a random pun.";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {
			
			int selection = std::stoi(command_text);

			std::wstring jokeArray[] =
			{
				L"What time did the man go to the dentist? Tooth hurt-y.",															// 0
				L"Did you hear about the guy who invented Lifesavers? They say he made a mint.",									// 1
				L"A ham sandwich walks into a bar and orders a beer. Bartender says, 'Sorry we don't serve food here.'",			// 2
				L"Why do chicken coops only have two doors? Because if they had four, they would be chicken sedans!",				// 3
				L"Me: Dad, make me a sandwich! Dad: Poof, You’re a sandwich!",														// 4
				L"Why did the Clydesdale give the pony a glass of water? Because he was a little horse!",							// 5
				L"Me: 'Hey, I was thinking… ' My dad: 'I thought I smelled something burning.'",									// 6
				L"How do you make a Kleenex dance? Put a little boogie in it!",														// 7
				L"Two peanuts were walking down the street. One was a salted.",														// 8
				L"I used to have a job at a calendar factory but I got the sack because I took a couple of days off.",				// 9
				L"How do you make holy water? You boil the hell out of it.",														// 10
				L"I farted in my wallet... Now I have gas money.",																	// 11
				L"I bought these shoes off a drug dealer. I don't know what he laced them with, but I've been tripping all day.",	// 12
				L"This list of livers and kidneys are in alphabetical order by patient. It's very... organ-ized.",					// 13
				L"I wasn't able to make a reservation at the library... they were over-booked.",									// 14
				L"What do you do with a sick boat? Take it to the dock!",															// 15
				L"My son asked my to stop singing Oasis songs in public... I said maybe...",										// 16
				L"What did the ocean say to the shore? Nothing, it just waved.",													// 17
				L"You've really got to hand it to short people... because they can't reach it anyway.",								// 18
				L"What do you get when you cross alcohol with literature? Tequila Mockingbird.",									// 19
				L"A man walks into a zoo. The only animal in the zoo is a dog. It's a shitzu.",										// 20
				L"f(x) = |x|... avoid negativity."																					// 21
			};

			if (selection && selection > 0 && selection < (sizeof(jokeArray)/sizeof(jokeArray[0]) + 1))
			{
				return jokeArray[selection - 1];
			}
			else
			{
				return L"Not a valid selection.";
			}
		}
	};
}
