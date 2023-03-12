#include "../../include/System/System.h"

namespace dl
{
    bool System::isInitSystem = false;
    std::string System::pachToRootFolder = "";
    Outputer* System::outputer = nullptr;

    TypeError dl::System::initSystem(int argc, char** argv, TypeOutput tpOutp)
    {
        System::setOutputer(tpOutp);

        TypeError result = TypeError::EMPTY_ERROR;
        System::pachToRootFolder = System::downPach(std::string(argv[0]));

        System::isInitSystem = !((bool)((int)result));

        return result;
    }

    void System::unInitSystem()
    {
        delete System::outputer;
    }

    std::string dl::System::downPach(std::string inputPach)
    {
        size_t sizeNewPach = inputPach.size();
        if (inputPach[sizeNewPach - 1] == '\\')
            sizeNewPach--;
        while (sizeNewPach > 0 && (inputPach[sizeNewPach - 1] != '\\'))
            sizeNewPach--;
        return std::string(inputPach.begin(), inputPach.begin() + sizeNewPach);
    }

    std::string& dl::System::getRootPach()
    {
        if (System::isInitSystem)
            return System::pachToRootFolder;
        else
            System::failInitSystem();
    }

    void System::setOutputer(TypeOutput tpOut)
    {
        delete System::outputer;
        switch (tpOut)
        {
            case dl::TypeOutput::CONSOLE: {System::outputer = new ConsoleOutputer(); }break;
            case dl::TypeOutput::UI: {System::outputer = new UIOutputer(); }break;
        }
    }

    const Outputer& System::getOutputer()
    {
        return *System::outputer;
    }

    void System::failInitSystem()
    {
        Error failInit(TypeError::FAIL_INIT,
            "Fail initialization dl system!", true);
        System::process(failInit);
    }

    void System::process(Log& lg)
    {
        Loger::process(lg, *System::outputer);
    }
}