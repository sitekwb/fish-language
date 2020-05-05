
#include <Controller.h>
#include <iostream>
#include <Sources/CommandLineSource.h>
#include <ProgramOptions.h>
#include <Sources/FileSource.h>

using namespace std;
namespace po = boost::program_options;

int main(int argc, char *argv[]) {

    try {
        ProgramOptions programOptions(argc, argv);
        cout << programOptions;

        auto inputFile = programOptions.getInputFile();

        unique_ptr<Source> source;
        if(inputFile)
            source = make_unique<FileSource>(move(inputFile));
        else
            source = make_unique<CommandLineSource>();

        Controller controller(move(source), programOptions.isDebug());
        controller.execute();
    }
    catch (std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }
    catch(...){
        cout << "Unknown exception" << endl;
    }

    return 0;
}
