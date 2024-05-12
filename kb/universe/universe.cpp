#include "universe.h"

kno::universe::Object::
Object():kno::Object("universe")
{
}

kno::universe::Object::
~Object()
{
}

extern "C"
kno::Object* kno_create(void)
{
    return new kno::universe::Object;
}

extern "C"
void kno_destroy(kno::Object* object_ptr)
{
    delete object_ptr;
}

extern "C"
kno::Object* kno_query(kno::Object* object_ptr)
{
    kno::universe::Object* object [[maybe_unused]] =
        dynamic_cast<kno::universe::Object*>(object_ptr);
    return nullptr;
}
