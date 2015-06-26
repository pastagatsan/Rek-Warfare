#pragma once

#include <string>

enum Logtype { EVENT, ERROR, WARNING, STATUS, INFO };

bool LOGGING = false;
/**
* Log information, only if logging is enabled
*/
void log(Logtype t, std::string message);
