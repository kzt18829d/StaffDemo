#ifndef STAFFDEMO_LOGGER_H
#define STAFFDEMO_LOGGER_H

#include <string>
#include <vector>
#include <ctime>
#include <vector>
#include <fstream>
#include <iostream>
#include <memory>
#include "StaffExceptions.h"

namespace StaffDemo::Utils {
    class Logger {
    public:
        enum LogLevel { INFO, WARNING, ERROR };

        class LogEntry {
        private:
            std::string message;
            std::string timestamp;
            LogLevel level;

            std::string levelToString();

        public:
            explicit LogEntry(const std::string& msg, LogLevel logLevel = INFO);
            std::string format();
        };

        void logToConsole(const std::string& msg, LogLevel level = INFO);
    };

    class FileHandler {
    protected:

        class Buffer {
        private:
            std::vector<std::string> lines;
        public:
            void add(const std::string& line);
            std::vector<std::string> getLines();
            void clear();
        };

        Buffer buffer;
        std::string fileDirectory;

    public:
        explicit FileHandler(const std::string& fileDir);
        ~FileHandler();

        void bufferLine(const std::string& line);
        void flushToFile();
    };

    class FileLogger : public FileHandler, public Logger {
    private:
        explicit FileLogger(const std::string& fileDir) : FileHandler(fileDir) {}
        static std::unique_ptr<FileLogger> inst;
    public:
        FileLogger(const FileLogger&) = delete;
        FileLogger& operator=(const FileLogger&) = delete;
        ~FileLogger();
        static void initialize(const std::string& fileDir);
        static FileLogger& instance();
        void log(const std::string& msg, LogLevel level = INFO);
        void flush();
    };
}

#endif //STAFFDEMO_LOGGER_H
