//
// Created by Wojtek on 02/05/2020.
//

#include "ProgramOptions.h"
#include <iostream>

using namespace std;

ProgramOptions::ProgramOptions(int argc, char **argv) : desc("Program execute options"), vm(), debug(false) {
    desc.add_options()
            ("help", "Print help message")
            ("input", po::value<string>(), "Set input file")
            ("verbose", "Print all information to user")
            ("debug", "Print debug information")
            ;

    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if(vm.count("debug")){
        debug = true;
    }
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
    if(vm.count("input")){
        return make_unique<ifstream>(vm["input"].as<string>());
    }
    return nullptr;
}

bool ProgramOptions::isDebug() const {
    return debug;
}

bool ProgramOptions::isFileSource() {
    return vm.count("input");
}
