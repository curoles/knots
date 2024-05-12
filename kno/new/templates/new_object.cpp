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
kno::Object* kno_create(void)
{
    return new kno::{{name}}::Object;
}

extern "C"
void kno_destroy(kno::Object* object_ptr)
{
    delete object_ptr;
}

extern "C"
kno::Object* kno_query(kno::Object* object_ptr)
{
    kno::{{name}}::Object* object [[maybe_unused]] =
        dynamic_cast<kno::{{name}}::Object*>(object_ptr);
    return nullptr;
}
)"
