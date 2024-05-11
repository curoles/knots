#pragma once

#include "kno/object/kno_object.h"

namespace kno::is_instance_of {

class Object : public kno::Object
{
public:
    Object();
    ~Object();

    bool operator()(kno::Object const* type, kno::Object const* instance) const;
};


} // namespace kno::is_instance_of
