#ifndef IO_HPP
#define IO_HPP

#include <fstream>
#include <string>

class IO {
public:
    IO(const std::string& file_path);
    ~IO();
    std::fstream& getFileStream();  // <-- Return by reference here also!

private:
    std::fstream file_stream;
};

#endif
