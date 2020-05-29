
#include <Controller.h>
#include <iostream>
#include <Sources/CommandLineSource.h>
#include <ProgramOptions.h>
#include <Sources/FileSource.h>

using namespace std;
namespace po = boost::program_options;

unique_ptr<Source> getSource(ProgramOptions &programOptions){
    auto inputFile = programOptions.getInputFile();

    unique_ptr<Source> source;
    if(inputFile) {
        return make_unique<FileSource>(move(inputFile));
    }

    return make_unique<CommandLineSource>();
}

int main(int argc, char *argv[]) {

    try {
        ProgramOptions po(argc, argv);
        cout << po;
        auto source = move(getSource(po));

        Controller controller(*source, po.isDebug(), po.isFileSource());
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
