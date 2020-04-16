
#include <Controller.h>
#include <iostream>
#include <Exceptions/UnknownSignException.h>


int main() {
    try {
        Controller controller;
        controller.analise(std::cin, std::cout);
    }
    catch(std::runtime_error &e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}
