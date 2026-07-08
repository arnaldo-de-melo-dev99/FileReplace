#include "FileM.hpp"

int main(void) {

    std::string fileName;
    std::string s1;
    std::string s2;

    ReadFileRplace(&fileName, &s1, &s2);

    FileM *newFile = new FileM((char *)fileName.c_str());

    if (fileName.empty() || s1.empty() || s2.empty()) return (std::cout << "Invalid args", 1);
    
    newFile->createFile((char *)s1.c_str(), (char *)s2.c_str());
    
    newFile->showOriginFile();
    std:: cout << "\n" << std::endl;

    if (newFile) delete newFile;
    return (0);
}
