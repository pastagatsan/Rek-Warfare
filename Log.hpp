#pragma once

#include <string>

namespace rekwarfare {
namespace client {
enum Logtype { EVENT, ERROR, WARNING, STATUS, INFO };
/**
* Log information
*/
void log(Logtype t, std::string message);
}
}
