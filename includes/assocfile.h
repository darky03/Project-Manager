#pragma once
#include <iostream>
#include "structures.h"
#include "fileinc.h"
#include "strfuncs.h"

/*
    std::string line;
    std::string *splits,*splitsext;
    int total,ftotal,i;
    AssocStructure newkey;
    std::vector<std::string> keys,values;
    while(!m_file.eof())
    {
        keys.clear();
        values.clear();
        getline(m_file,line);
        splits = strfuncs::strsplit(line,total,assocval);
        std::string mstr;
        
        if(strfuncs::find(splits[0],",") > 0)
        {
            splitsext = strfuncs::strsplit(splits[0],ftotal,',');
            for(i = 0; i < ftotal; i++)
            {
                newkey.keys.push_back(splitsext[i]);
            }
            keys.push_back(newkey);
        }
        else
        {
            newkey.keys.push_back(splits[0]);
        }
        if(strfuncs::find(splits[1],",") > 0)
        {
            splitsext = strfuncs::strsplit(splits[0],ftotal,',');
            for(i = 0; i < ftotal; i++)
            {
                newkey.assocs.push_back(splitsext[i]);
            }
        }
        else
        {
            newkey.assocs.push_back(splits[1]);
        }
    }
*/

class AssocFile : public File
{
    private:
        bool assocvalset;
        std::string assocval;
        std::vector<AssocStructure> keys;
        void RewriteChanges()
        {

        }
        void ReadFile()
        {
            if(m_file.is_open())
            {
                if(!assocvalset) return;
                m_file.seekp(0);
                m_file.seekg(0);
                std::string line;
                std::string *basicsplit,*othersplit;
                AssocStructure newkey;
                int total,ftotal,i,j;
                while(!m_file.eof())
                {
                    getline(m_file,line);
                    basicsplit = strfuncs::strsplit(line,total,assocval);
                    if(strfuncs::find(basicsplit[0],",") > 0)
                    {
                        othersplit = strfuncs::strsplit(basicsplit[0],ftotal,',');
                        for(i = 0; i < ftotal; i++)
                            newkey.keys.push_back(othersplit[i]);
                    }
                    else
                    {
                        newkey.keys.push_back(basicsplit[0]);
                    }
                    if(strfuncs::find(basicsplit[1],",") > 0)
                    {
                        othersplit = strfuncs::strsplit(basicsplit[1],ftotal,',');
                        for(i = 0; i < ftotal; i++)
                            newkey.assocs.push_back(othersplit[i]);
                    }
                    else
                    {
                        newkey.assocs.push_back(basicsplit[1]);
                    }
                    keys.push_back(newkey);
                }
            }
        }
    public:
        AssocFile();
        AssocFile(const std::string &filepath,bool forcecreate = false);
        void OpenAssocFile(const std::string &filepath,bool forcecreate = false);
        void DisplayKeyPair();
        void SetAssocVal(const std::string &val);
        ~AssocFile();
};
AssocFile::AssocFile()
{
    assocvalset = false;
}
void AssocFile::OpenAssocFile(const std::string &filepath,bool forcecreate)
{
    m_file.open(filepath.c_str(),std::fstream::in | std::fstream::out);
    if(!m_file.good())
    {
        if(forcecreate)
        {
            m_file.close();
            m_file.open(filepath.c_str(),std::fstream::app);
            m_file.close();
            m_file.open(filepath.c_str(),std::fstream::in | std::fstream::out);
        }
    }
    else
    {
        ReadFile();
    }
}
void AssocFile::DisplayKeyPair()
{
    int j = 0,k = 0;
    std::cout << "Displaying key pair" << std::endl;
    for(int i = 0; i < keys.size(); i++)
    {
        for(j = 0; j < keys[i].keys.size(); j++)
        {
            std::cout << keys[i].keys[j] << ",";
        }
        std::cout << " : ";
        for(j = 0; j < keys[i].assocs.size(); j++)
        {
            std::cout << keys[i].assocs[j] << ",";
        }
        std::cout << std::endl;
    }
}
void AssocFile::SetAssocVal(const std::string &val)
{
    assocvalset = true;
    assocval = val;
}
AssocFile::AssocFile(const std::string &filepath,bool forcecreate)
{
    assocvalset = false;
    m_file.open(filepath.c_str(),std::fstream::in | std::fstream::out);
    if(!m_file.good())
    {
        if(forcecreate)
        {
            m_file.close();
            m_file.open(filepath.c_str(),std::fstream::app);
            m_file.close();
            m_file.open(filepath.c_str(),std::fstream::in | std::fstream::out);
        }
    }
    else
    {
        ReadFile();
    }
}

AssocFile::~AssocFile()
{
    if(m_file.is_open()) m_file.close();
}
