#include "Log.hpp"

#include <iostream>
#include <string>

namespace logger {

void log(Logtype t, std::string message) {
	switch (t) {
		case EVENT:
			std::cout << "[Event] ";
			break;
		case ERROR:
			std::cerr << "[Error] " << messsage << std::endl;
			break;
		case WARNING:
			std::cout << "[Warning] ";
			break;
		case STATUS:
			std::cout << "[Status] ";
			break;
		case INFO:
			std::cout << "[Info] ";
			break;
	}
	if (t != ERROR)
		std::cout << message << std::endl;
}
}
