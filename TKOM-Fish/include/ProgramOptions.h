//
// Created by Wojtek on 02/05/2020.
//

#ifndef FISH_PROGRAMOPTIONS_H
#define FISH_PROGRAMOPTIONS_H

#include <boost/program_options.hpp>
#include <ostream>
#include <fstream>
#include "Sources/Source.h"

namespace po = boost::program_options;

class ProgramOptions {
    po::options_description desc;
    po::variables_map vm;

    std::unique_ptr<std::ifstream> getInputFile();
public:
    ProgramOptions(int argc, char *argv[]);
    std::unique_ptr<Source> getSource();
    friend std::ostream &operator<<(std::ostream &os, const ProgramOptions &options);
};


#endif //FISH_PROGRAMOPTIONS_H
