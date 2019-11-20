#pragma once
#include <string>

class Test
{
    ///@brief  name
    std::string m_name ;

public:
    Test();
    ~Test();

    const std::string GetName() const ;
    void SetName(const std::string& name);
};