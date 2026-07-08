#include "FileM.hpp"

void    Bunner(void) {
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "|                                             |" << std::endl;
    std::cout << "|          Welcome to File Replace            |" << std::endl;
    std::cout << "|                                             |" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
}

FileM::FileM()  {
    std::cout << "FileM constructor called" << std::endl;

}

FileM::FileM(char *fileName) {
    origin.open(fileName, std::ifstream::in);
    if(origin.is_open()) 
    {
        std::cout << "File is open \n" << std::endl;
        std::cout << fileName << "\n" << std::endl;
        newFile = "./replace/"+(std::string)fileName+".replace";
        destin.open(newFile.c_str(), std::ofstream::out);
    }
    else std::cout << "File is not open \n";
}

std::string FileM::setNewstring(std::string line, std::string s1, std::string s2) {
    size_t pos = 0;

    if (!line.empty()) {
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
    }
    return (line);
}

void    FileM::createFile(char *word1, char *word2)
{
    if (!origin.is_open()) return;
    while (true)
    {
        origin.read(buffer, sizeof(buffer));

        bytes = origin.gcount();
        if (bytes == 0) break;;
        line.assign(buffer, origin.gcount());
        line = setNewstring(line, (std::string)word1, (std::string)word2);  
        destin.write(line.c_str(), line.size());
    }
}

void    ReadFileRplace(std ::string *fileName, std::string *s1, std::string *s2)
{
    Bunner();
    getline(std::cin, *fileName);
    getline(std::cin, *s1);
    getline(std::cin, *s2);
}

void    FileM::showOriginFile()
{
    if (!origin.is_open()) return;
    while (true)
    {
        origin.read(buffer, sizeof(buffer));
        bytes = origin.gcount();
        std:: cout << buffer << std::endl;
        if (bytes == 0) break;
    }
}

FileM::~FileM()
{
    if (origin.is_open())
        origin.close();
    std:: cout << "File is closed \n";
}
