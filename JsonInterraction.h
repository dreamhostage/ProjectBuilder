#ifndef JSONINTERRACTION_H
#define JSONINTERRACTION_H

#include <fstream>
#include "include/single_include/nlohmann/json.hpp"
#include <iostream>

using json = nlohmann::json;

class JsonInterraction
{
    std::fstream file;
    json j;

public:
    JsonInterraction()
    {
        file.open("data.json");
        if (IsDataEmpty())
        {
            j["RunUATPATH"] = "";
            j["ProjectPATH"] = "";
            file.close();
            std::ofstream fileOp("data.json");
            fileOp << j;
            fileOp.close();
        }
        else
        {
            file.close();
        }
    }

    bool IsDataEmpty()
    {
        if (file.peek() == std::ifstream::traits_type::eof())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    std::string GetRunUATPATH()
    {
        std::ifstream f("data.json");
        json data = json::parse(f);
        f.close();
        return data.value("RunUATPATH", "");
    }

    std::string GetProjectPATH()
    {
        std::ifstream f("data.json");
        json data = json::parse(f);
        f.close();
        return data.value("ProjectPATH", "");
    }

    void SetRunUATPATH(std::string path)
    {
        j["RunUATPATH"] = path;
        std::ofstream fileOp("data.json");
        fileOp << j;
        fileOp.close();
    }

    void SetProjectPATH(std::string path)
    {
        j["ProjectPATH"] = path;
        std::ofstream fileOp("data.json");
        fileOp << j;
        fileOp.close();
    }

    std::string GerReworkedRunUATPATH()
    {

    }
};

#endif // JSONINTERRACTION_H
