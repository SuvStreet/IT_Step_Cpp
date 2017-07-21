#include"System.h"

std::string System::Core::getPrintCore() { return "Hello, I class Core"; }
size_t System::Core::setSystemCore() { return core; }
void System::Core::getValueCore(const size_t value) { core = value; }

std::string System::printSystem() { return "Hello, I class System"; }
std::string System::setSystem() { return system; }
void System::getValueSystem(const std::string value) { system = value; }
