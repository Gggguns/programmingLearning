#include "print.h"

void printMessage(const std::string& message) {
    std::cout << message << std::endl;
}
void printDemo() {
    std::string demoMessage = "This is a demo function for printing messages.";
    printMessage(demoMessage);
}