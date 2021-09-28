#ifndef TIC_TAC_TOE_OPERATIONSYSTEM_H
#define TIC_TAC_TOE_OPERATIONSYSTEM_H

class OperationSystem // ** Singleton ** //
{
public:
    static OperationSystem &getInstance() // get instance of operating system class
    {
        static OperationSystem instance;
        return instance;
    }
    std::string getOsName() // return your os type
    {
        #ifdef _WIN32
            return "Windows 32-bit";
        #elif _WIN64
            return "Windows 64-bit";
        #elif __APPLE__ || __MACH__
            return "Mac OSX";
        #elif __linux__
            return "Linux";
        #elif __FreeBSD__
            return "FreeBSD";
        #elif __unix || __unix__
            return "Unix";
        #else
            return "Other";
        #endif
    }
    std::string linuxExecute(const char* cmd) // execute linux commands
    {
        std::array<char, 128> buffer;
        std::string result;
        std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
        if (!pipe) {
            throw std::runtime_error("popen() failed!");
        }
        while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
            result += buffer.data();
        }
        return result;
    }
    std::string exec(const char* cmd) // execute command by recognizing your operating system type (only support Linux for temporary period)
    {
        if(getOsName() == "Linux")
            return linuxExecute(cmd);
    }


private:
    OperationSystem() {}
    OperationSystem(const OperationSystem&) = delete;
    void operator=(const OperationSystem&) = delete;
};
#endif //TIC_TAC_TOE_OPERATIONSYSTEM_H
