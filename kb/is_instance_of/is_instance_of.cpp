#include "is_instance_of.h"

kno::is_instance_of::Object::
Object():kno::Object("is_instance_of")
{
}

kno::is_instance_of::Object::
~Object()
{
}

extern "C"
kno::Object* kno_create(void)
{
    return new kno::is_instance_of::Object;
}

extern "C"
void kno_destroy(kno::Object* object_ptr)
{
    //kno::is_instance_of::Object* object = reinterpret_cast<kno::is_instance_of::Object*>(object_ptr);
    delete object_ptr;
}

extern "C"
kno::Object* kno_query(kno::Object* object_ptr)
{
    kno::is_instance_of::Object* object [[maybe_unused]] =
        dynamic_cast<kno::is_instance_of::Object*>(object_ptr);
    return nullptr;
}

bool
kno::is_instance_of::Object::
operator()(kno::Object const* type [[maybe_unused]], kno::Object const* instance [[maybe_unused]]) const
{
    //if (instance.has_method("is_instance_of")) {
        //kno::Object* result;
        //instance->call_method("is_instance_of", {type}, &result);
        //if result.name() is "boolean"
        //return true|false;
    //}
    return false;
}

