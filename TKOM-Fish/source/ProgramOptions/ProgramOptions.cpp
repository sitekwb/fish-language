//
// Created by Wojtek on 02/05/2020.
//

#include "ProgramOptions.h"
#include <iostream>
#include <Sources/CommandLineSource.h>
#include <Sources/FileSource.h>

using namespace std;

ProgramOptions::ProgramOptions(int argc, char **argv) : desc("Program execute options"), vm(){
    desc.add_options()
            ("help", "Print help message")
            ("file", po::value<string>(), "Set input file")
            ("verbose", "Print all information to user")
            ;

    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);
}

std::ostream &operator<<(std::ostream &os, const ProgramOptions &options) {
    auto vm = options.vm;
    auto desc = options.desc;

    if (vm.count("help")) {
        cout << desc << endl;
        exit(1);
    }
    return os;
}

std::unique_ptr<std::ifstream> ProgramOptions::getInputFile() {
    if(vm.count("file")){
        auto stream = make_unique<ifstream>(vm["file"].as<string>());
        if(!stream->is_open()){
            throw runtime_error("Couldn't find file");
        }
        return move(stream);
    }
    return nullptr;
}

unique_ptr<Source> ProgramOptions::getSource(){
    auto inputFile = getInputFile();

    unique_ptr<Source> source;
    if(inputFile) {
        return make_unique<FileSource>(move(inputFile));
    }

    return make_unique<CommandLineSource>();
}
