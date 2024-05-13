#include "the_universe.h"

#include "kno/plugin.h"

kno::the_universe::Object::
Object():kno::Object("the_universe")
{
}

kno::the_universe::Object::
~Object()
{
}

extern "C"
kno::Object* kno_create(void)
{
    return new kno::the_universe::Object;
}

extern "C"
void kno_destroy(kno::Object* object_ptr)
{
    delete object_ptr;
}

extern "C"
kno::Plugin* kno_query(kno::Object* object_ptr)
{
    kno::the_universe::Object* object [[maybe_unused]] =
        dynamic_cast<kno::the_universe::Object*>(object_ptr);
    return nullptr;
}
