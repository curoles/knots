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
void* kno_create(void)
{
    return new kno::universe::Object;
}

extern "C"
void kno_destroy(void* object_ptr)
{
    kno::universe::Object* object = reinterpret_cast<kno::universe::Object*>(object_ptr);
    delete object;
}
