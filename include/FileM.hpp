#ifndef FILEM_H
# define FILEM_H

#include <string>
#include <cstring>
#include <iostream>
#include <fstream>

class FileM {
    private:
        char    buffer[1024];
        std::streamsize bytes;
        std::string line;
        std::string newFile;
        std::fstream origin;
        std::fstream destin;

    public:
        FileM();
        FileM(char *fileName);
        void    createFile(char *word1, char *word2);
        std::string setNewstring(std::string line, std::string s1, std::string s2);
        void    showOriginFile();
        ~FileM();
};

void    Bunner(void);
void    ReadFileRplace(std::string *fileName, std::string *s1, std::string *s2);

#endif
