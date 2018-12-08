#ifndef BRIDGES_FINDER_PRINTER_H
#define BRIDGES_FINDER_PRINTER_H

#include <iostream>
#include <string>

namespace bridges_finder {

class Printer
{
public:
    static void printInvalidFile() {
        std::cout << "Invalid parsing graph from file!" << std::endl;
    }

    static void printRawGraph(const std::string& name, const std::string& raw) {
        std::cout << "************* Graph " << name << " *************" << std::endl;
        std::cout << raw << std::endl;
    }

    Printer() = delete;

    Printer(const Printer &) = delete;

    Printer(Printer &&) = delete;

    Printer &operator=(const Printer &) = delete;

    Printer &operator=(Printer &&) = delete;
};

} // bridges_finder

#endif //BRIDGES_FINDER_PRINTER_H
