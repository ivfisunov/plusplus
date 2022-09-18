#include <iostream>

#include "product/command.h"
#include "product/console_processing.h"
#include "product/file_processing.h"

int main(int argc, char** argv)
{
    if (argc < 2) {
        std::cerr << "Provide command block size." << std::endl;
        std::cerr << "Usage: " << argv[0] << "3" << std::endl;
        return 1;
    }

    bulk::Command cmd(std::stoi(argv[1]));

    bulk::ConsoleProcessing cp(&cmd);
    bulk::FileProcessing fp(&cmd);

    cmd.StartProcessing();

    return 0;
}
