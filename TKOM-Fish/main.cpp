
#include <iostream>
#include <Controller.h>
#include <ProgramOptions.h>

using namespace std;
namespace po = boost::program_options;

int main(int argc, char *argv[]) {
    try {
        ProgramOptions po(argc, argv);
        cout << po;

        Controller controller(move(po.getSource()));
        controller.execute();
    }
    catch (std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }
    catch (...) {
        cout << "Unknown exception" << endl;
    }

    return 0;
}
