#include <iostream>
#include <sstream>
#include "ConsoleLogger.h"
#include "EchoCommand.h"
#include "ReverseCommand.h"
#include "DadJoke.h"
#include "challenges.h"
#include "cc.h"
#include "scraps.h"
#include "lvl.h"
#include "password.h"
#include "rainbow.h"
#include "hash.h"
#include "startup.h"
#include "Header.h"

#define ERROR_SUCCESS 0
#define ERROR_FAILURE -1

using namespace std;
using namespace lospi;

int main() {
	wstring mattermost_url = L"https://hooks.slack.com",
		incoming_hook_route = L"services/T4Z1QAKSS/B4ZVCS1K5/4HrhHG1PVnfDk4eeMGlDViUz",
		outgoing_hook_route = L"http://127.0.0.1:8000",
    outgoing_hook_token = L"hL7xDphColA72yWtPEPVXm9r",
    welcome_message = L"Prepared to throw shoes in the machinery.";

  try {

    auto bot = make_shared<Matterbot>(mattermost_url, incoming_hook_route, outgoing_hook_route, outgoing_hook_token);
    bot->set_logger(make_unique<ConsoleLogger>());
    bot->register_command(make_shared<EchoCommand>());
    bot->register_command(make_shared<ReverseCommand>(bot));
	bot->register_command(make_shared<DadJoke>());
	bot->register_command(make_shared<challenges>(bot));
	bot->register_command(make_shared<startup>(bot));
	bot->register_command(make_shared<scraps>(bot));
	bot->register_command(make_shared<cc>());
	bot->register_command(make_shared<lvl>());
	bot->register_command(make_shared<password>());
	bot->register_command(make_shared<rainbow>());
	bot->register_command(make_shared<dohash>());
    bot->post_message(welcome_message);
	
    wstring console;
    wclog << ">> Type \'quit\' to quit. Any other input will be sent to the bot." << endl;
    while (getline(wcin, console)) {
      if (L"quit" == console) {
        wclog << ">> Quitting." << endl;
        return ERROR_SUCCESS;
      }
      if (L"" != console) { 
		  bot->post_message(console);
	  }
    }
  }
  catch (exception e) {
    wcerr << "[-] Unhandled exception:" << e.what() << endl;
    return ERROR_FAILURE;
  }
}
