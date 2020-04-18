
#include <Controller.h>
#include <iostream>
#include <Exceptions/UnknownSignException.h>
#include <Sources/CommandLineSource.h>

using namespace std;

int main() {
    try {
        auto source = make_unique<CommandLineSource>();
        Controller controller(move(source));
        controller.analise();
    }
    catch(std::runtime_error &e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}
