#include "Test.h"

Test::Test()
    : m_name("not initialize")
{
}

Test::~Test()
{
}

const std::string Test::GetName() const 
{
    return m_name ;
}

void Test::SetName(const std::string& name)
{
    m_name = name ;
}