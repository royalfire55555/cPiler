#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string createExe(string exeName, string filePath)
{
    string cmd = "g++ -o " + exeName + " " + filePath;
    const char *cmdChars = cmd.c_str();
    system(cmdChars);
}

int main(int argsNum, char **args)
{
    /*
    args[0] = exe?
    args[1] = cpp File
    */
    string exeFile;
    string file;

    stringstream ss;
    ss << args[1];
    ss >> exeFile;

    file = exeFile;

    size_t pos = string::npos;
    string ext = ".cpp";

    while ((pos = exeFile.find(".cpp")) != string::npos)
    {
        exeFile.erase(pos, ext.length());
    }

    cout << endl
         << "creating executable " << exeFile << " from c++ file: " << file << endl
         << endl;
    system("g++ --version");
    createExe(exeFile, file);
}