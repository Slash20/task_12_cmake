#pragma once

#include <string>

namespace TimeLogger {

    std::string getCurrentTime();

    void logStartTime(const std::string& filePath);

}
