#include "console_log.h"
#include <stdio.h>

int defaultConsoleHandler(int lvl, const char* format, va_list argList){
    switch (lvl){
    case ConsoleLogger::LOG_ERROR:
    case ConsoleLogger::LOG_WARN:
        return vfprintf(stderr, format, argList);
    case ConsoleLogger::LOG_INFO:
    default:
        return vfprintf(stdout, format, argList);
    }
}

consoleHandler ConsoleLogger::handle = defaultConsoleHandler;
