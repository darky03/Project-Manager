#pragma once 
#include <iostream>
#include "types.h"
#include "macros.h"
#include "structures.h"
#include "inimanager.h"

class ProjectFile
{
    private:
        std::fstream m_file;
        std::string m_filedir;
        uint8 m_filetype;
    
    public:
        ProjectFile();
        ProjectFile(const uint8 type,const std::string &filedir = "./");
        void Init();
        ~ProjectFile();
};

ProjectFile::ProjectFile()
{
}
ProjectFile::ProjectFile(const uint8 type,const std::string &filedir)
{
    m_filetype = type;
    m_filedir = filedir;
}
void ProjectFile::Init()
{
    std::string m_filefullpath = m_filedir;
    switch(m_filetype)
    {
        case __PROJECT_TTYPE_CPP__:
        {
            m_filefullpath += "/main.cpp";
            m_file.open(m_filefullpath.c_str(),std::fstream::app);
            m_file << "#include <iostream>" << std::endl;
            m_file << std::endl;
            m_file << "int main(int argc,char **argv)" << std::endl;;
            m_file << "{" << std::endl;
            m_file << "\treturn 0;" << std::endl;
            m_file << "}" << std::endl;
            m_file.close();
            break;
        }
        case __PROJECT_TTYPE_C__:
        {
            m_filefullpath += "/main.c";
            m_file.open(m_filefullpath.c_str(),std::fstream::app);
            m_file << "#include <stdio.h>" << std::endl;
            m_file << std::endl;
            m_file << "int main(int argc,char **argv)" << std::endl;;
            m_file << "{" << std::endl;
            m_file << "\treturn 0;" << std::endl;
            m_file << "}" << std::endl;
            m_file.close();
            break;
        }
        case __PROJECT_TTYPE_PHP__:
        {
            m_filefullpath += "/index.php";
            m_file.open(m_filefullpath.c_str(),std::fstream::app);
            m_file << "<?php" << std::endl;
            m_file << "\tsession_start();" << std::endl;
            m_file << "?>" << std::endl;
            m_file << "<html>" << std::endl;
            m_file << "\t<head>" << std::endl;
            m_file << "\t</head>" << std::endl;
            m_file << "\t<body>" << std::endl;
            m_file << "\t</body>" << std::endl;
            m_file << "</html>" << std::endl;
            m_file.close();
            break;
        }
    }
}
ProjectFile::~ProjectFile()
{
}