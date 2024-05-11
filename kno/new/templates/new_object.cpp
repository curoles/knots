R"(#include "{{name}}.h"

kno::{{name}}::Object::
Object():kno::Object("{{name}}")
{
}

kno::{{name}}::Object::
~Object()
{
}

extern "C"
void* kno_create(void)
{
    return new kno::{{name}}::Object;
}

extern "C"
void kno_destroy(void* object_ptr)
{
    kno::{{name}}::Object* object = reinterpret_cast<kno::{{name}}::Object*>(object_ptr);
    delete object;
}
)"
