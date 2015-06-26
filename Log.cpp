#include "Log.hpp"

#include <iostream>
#include <string>

void log(Logtype t, std::string message) {
	if (LOGGING) {
		switch (t) {
			case EVENT:
				std::cout << "[Event] ";
				break;
			case ERROR:
				std::cout << "[Error] ";
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
		std::cout << message << std::endl;
	}
}
