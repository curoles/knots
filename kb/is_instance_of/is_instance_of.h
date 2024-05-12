#pragma once

#include "kno/object/kno_object.h"

namespace kno::is_instance_of {

class Object : public kno::Object
{
public:
    Object();
    ~Object();

    bool query(kno::Object const* instance, kno::Object const* type) const;
};


} // namespace kno::is_instance_of
