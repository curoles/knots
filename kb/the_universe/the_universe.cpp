#include "the_universe.h"

kno::the_universe::Object::
Object():kno::Object("the_universe")
{
}

kno::the_universe::Object::
~Object()
{
}

extern "C"
void* kno_create(void)
{
    return new kno::the_universe::Object;
}

extern "C"
void kno_destroy(void* object_ptr)
{
    kno::the_universe::Object* object = reinterpret_cast<kno::the_universe::Object*>(object_ptr);
    delete object;
}

