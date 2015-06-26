#pragma once

#include <string>

namespace logger {
enum Logtype { EVENT, ERROR, WARNING, STATUS, INFO };
/**
* Log information
*/
void log(Logtype t, std::string message);
}
