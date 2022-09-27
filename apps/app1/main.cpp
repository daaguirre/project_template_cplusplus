#include "app1.h"

int main(int, char**)
{
    int result = EXIT_SUCCESS;
    try
    {
        app1();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        result = EXIT_FAILURE;  // abnormal termination of program
    }

    return result;
}
