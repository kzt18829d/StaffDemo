#ifndef STAFFDEMO_STAFFEXCEPTIONS_H
#define STAFFDEMO_STAFFEXCEPTIONS_H

#include <exception>
#include <string>
#include <utility>


namespace StaffDemo::Utils::except {

    class StaffException : public std::exception {
    private:
        std::string exceptionText;
    public:
        StaffException() : StaffException("") {}
        explicit StaffException(std::string except) : exceptionText{std::move(except)} {}
        explicit StaffException(const char *except) : exceptionText{except} {}
        ~StaffException() override = default;
        bool operator==(const StaffException &other) const { return this->exceptionText == other.exceptionText; }
        bool operator!=(const StaffException &other) const { return this->exceptionText != other.exceptionText; }
        StaffException &operator=(const std::string &exceptText) = delete;
        StaffException &operator=(const char *exceptText) = delete;

        const char *what() const noexcept override { return exceptionText.c_str(); }
        const char *what_() const noexcept { return exceptionText.c_str(); }
    };

    class InformationMessage : public StaffException {
    public:
        InformationMessage() : InformationMessage("Information Message") {}
        explicit InformationMessage(const std::string& infoMessage) : StaffException(infoMessage) {}
        explicit InformationMessage(const char* infoMessage) : StaffException(infoMessage) {}
        ~InformationMessage() override = default;
    };

    class Duplicate : public StaffException {
    public:
        Duplicate() : Duplicate("Object is duplicate one of current elements.") {}
        explicit Duplicate(const std::string &except) : StaffException(except) {}
        explicit Duplicate(const char *except) : StaffException(except) {}
        ~Duplicate() override = default;
    };

    class notFind : public StaffException {
    public:
        notFind() : notFind("Object don\'t find.") {}
        explicit notFind(const std::string& except) : StaffException(except) {}
        explicit notFind(const char* except) : StaffException(except) {}
        ~notFind() override = default;
    };

    class previouslyAdded : public StaffException {
    public:
        previouslyAdded(): previouslyAdded("Object was added earlier.") {}
        explicit previouslyAdded(const std::string& except) : StaffException(except) {}
        explicit previouslyAdded(const char* except) : StaffException(except) {}
        ~previouslyAdded() override = default;
    };

    class IncorrectField : public StaffException {
    public:
        IncorrectField(): IncorrectField("Field Incorrectly.") {}
        explicit IncorrectField(const std::string& except) : StaffException(except) {}
        explicit IncorrectField(const char* except) : StaffException(except) {}
        ~IncorrectField() override = default;
    };

} // except

#endif //STAFFDEMO_STAFFEXCEPTIONS_H
