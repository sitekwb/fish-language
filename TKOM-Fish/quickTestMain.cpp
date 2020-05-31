
#include <Controller.h>
#include <iostream>
#include <Sources/CommandLineSource.h>
#include <ProgramOptions.h>
#include <Sources/FileSource.h>
#include <Analizator/EndOfFileException.h>

using namespace std;

int main(int argc, char *argv[]) {
    int a = 5;
    if(bool b = (a == 5)){
        bool c = b;
    }
    bool d = b;

    return 0;
}
