#include "projectV/core/logger.hpp"

int main()
{
    using projectv::core::Logger;

    Logger::info("Hello from project-v core!");
    Logger::warn("This is a warning from the project-v core sandbox.");
    Logger::error("This is an error example from project-v.");

    return 0;
}