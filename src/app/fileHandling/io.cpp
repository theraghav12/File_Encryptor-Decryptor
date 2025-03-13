#include<iostream>
#include "io.hpp"
using namespace std;



IO::IO(const string& file_path){
    file_stream.open(file_path, ios::in | ios::out | ios::binary);
    if(!file_stream.is_open()){
        cout<<"Unable to oprn file:"<<file_path<< endl;
    }
}

IO::~IO(){
    if(file_stream.is_open()){
        file_stream.close();
    }
}
fstream IO::getFileStream(){
    return std:: move(file_stream);
}