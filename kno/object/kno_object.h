#pragma once

#include <string>

namespace kno {

class Object
{
    std::string name_;

public:
    explicit Object(std::string name_):
        name_(std::move(name_))
    {}

    virtual ~Object(){}

    std::string const& name() const {
        return name_;
    }

};


} // namaspace kno
