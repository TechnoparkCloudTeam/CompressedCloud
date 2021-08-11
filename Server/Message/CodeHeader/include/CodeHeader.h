#pragma once

#include <vector>
#include <string>
#include <boost/cstdint.hpp>

#define header_size 4

class CodeHeader
{
public:
    unsigned decodeHeader(std::vector<boost::uint8_t> &buf);
    
    std::string encodeHeader(std::vector<boost::uint8_t> &buf, unsigned size);
};