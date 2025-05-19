#include "utils/Logger.h"

namespace StaffDemo {

    std::string Utils::Logger::LogEntry::levelToString() {
        switch (level) {
            case INFO: return "INFO";
            case WARNING: return "WARN";
            case ERROR: return "ERROR";
            default: return "Undefined";
        }
    }

    Utils::Logger::LogEntry::LogEntry(const std::string &msg, Utils::Logger::LogLevel logLevel) : level{logLevel} {
        time_t now = time(nullptr);
        timestamp = ctime(&now);
        if (!timestamp.empty() && timestamp.back() == '\n') timestamp.pop_back();
    }

    std::string Utils::Logger::LogEntry::format() {
        return "[" + timestamp + "] [" + levelToString() + "] " + message;
    }

    void Utils::Logger::logToConsole(const std::string& msg, Utils::Logger::LogLevel level) {
        LogEntry entry(msg, level);
        std::cout << entry.format() << std::endl;
    }

    void Utils::FileHandler::Buffer::add(const std::string &line) {
        lines.push_back(line);
    }

    std::vector<std::string> Utils::FileHandler::Buffer::getLines() {
        return lines;
    }

    void Utils::FileHandler::Buffer::clear() {
        lines.clear();
    }

    Utils::FileHandler::FileHandler(const std::string &fileDir) : fileDirectory(std::move(fileDir)) {}

    Utils::FileHandler::~FileHandler() = default;

    void Utils::FileHandler::bufferLine(const std::string &line) {
        buffer.add(line);
    }

    void Utils::FileHandler::flushToFile() {
        std::ofstream file(fileDirectory, std::ios::app);
        if (file.is_open()) {
            for (const auto& line : buffer.getLines()) file << line << std::endl;
            buffer.clear();
            file.close();
        } else throw std::ios_base::failure("File don't open.");
    }

    namespace Utils {
        std::unique_ptr<FileLogger> FileLogger::inst = nullptr;
    }

    void Utils::FileLogger::initialize(const std::string &fileDir) {
        if (!inst) inst.reset(new StaffDemo::Utils::FileLogger(fileDir));
    } // да ебануться

    Utils::FileLogger &Utils::FileLogger::instance() {
        if (!inst) throw std::runtime_error("Logger not initialized.");
        return *inst;
    }

    void Utils::FileLogger::log(const std::string &msg, Utils::Logger::Logger::LogLevel level) {
        LogEntry entry(msg, level);
        buffer.add(entry.format());
        if (buffer.getLines().size() >= 10) flush();
    }

    void Utils::FileLogger::flush() {
        flushToFile();
    }

    Utils::FileLogger::~FileLogger() {
        flush();
    }
} // StaffDemo