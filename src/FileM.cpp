#include "FileM.hpp"

void    Bunner(void) {
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "|                                             |" << std::endl;
    std::cout << "|          Welcome to File Replace            |" << std::endl;
    std::cout << "|                                             |" << std::endl;
    std::cout << "-----------------------------------------------" << std::endl;
}

void  shoseToOpenFile(std::string newFile) {
    int op;
    std::cout << "Do you want to open the file? (1 for yes, 0 for no): ";
    std::cin >> op;
    if (op == 1) system(("xdg-open " + newFile).c_str());
    else std::cout << "File is not opened \n";
}

void    ReadFileRplace(std ::string *fileName, std::string *s1, std::string *s2) {
    Bunner();
    std::cout << "\n Enter the file name: ";
    getline(std::cin, *fileName);
    std::cout << "\n Enter string to replace: ";
    getline(std::cin, *s1);
    std::cout << "\n Enter replacement string: ";
    getline(std::cin, *s2);
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

void    FileM::createFile(char *word1, char *word2) {
    if (!origin.is_open()) return;
    while (true) {
        origin.read(buffer, sizeof(buffer));

        bytes = origin.gcount();
        if (bytes == 0) break;;
        line.assign(buffer, origin.gcount());
        line = setNewstring(line, (std::string)word1, (std::string)word2);  
        destin.write(line.c_str(), line.size());
    }
    std::cout << "File is created \n";
    std::cout << "File name is: " << newFile << std::endl;
    shoseToOpenFile(newFile);
}

void    FileM::showOriginFile() {
    if (!origin.is_open()) return;
    while (true) {
        origin.read(buffer, sizeof(buffer));
        bytes = origin.gcount();
        std:: cout << buffer << std::endl;
        if (bytes == 0) break;
    }
}

FileM::~FileM() {
    if (origin.is_open())
        origin.close();
    std:: cout << "File is closed \n";
}