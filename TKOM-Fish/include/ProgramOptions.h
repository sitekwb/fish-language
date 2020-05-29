//
// Created by Wojtek on 02/05/2020.
//

#ifndef FISH_PROGRAMOPTIONS_H
#define FISH_PROGRAMOPTIONS_H

#include <boost/program_options.hpp>
#include <ostream>
#include <fstream>

namespace po = boost::program_options;

class ProgramOptions {
    po::options_description desc;
    po::variables_map vm;
    bool debug;
public:
    ProgramOptions(int argc, char *argv[]);

    std::unique_ptr<std::ifstream> getInputFile();

    bool isDebug() const;
    bool isFileSource();

    friend std::ostream &operator<<(std::ostream &os, const ProgramOptions &options);
};


#endif //FISH_PROGRAMOPTIONS_H
