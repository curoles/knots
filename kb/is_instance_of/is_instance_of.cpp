#include "is_instance_of.h"

bool
kno::is_instance_of::Object::
operator()(kno::Object const* type, kno::Object const* instance) const
{
    if (instance.has_method("is_instance_of")) {
        //kno::Object* result;
        //instance->call_method("is_instance_of", {type}, &result);
        //if result.name() is "boolean"
        //return true|false;
    }
    return false;
}

