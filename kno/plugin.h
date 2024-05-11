#pragma once

#include <string>
#include "find_object.h"

typedef void* (*kno_plugin_object_create_func)(void);
typedef void (*kno_plugin_object_destroy_func)(void*);

namespace kno {

class Object;

class Plugin final
{
    kno::dlhandle lib_;
    kno::Object* object_;

private:
    typedef void* (*object_create_func_t)(void);
    typedef void (*object_destroy_func_t)(void*);

    object_create_func_t object_create_func;
    object_destroy_func_t object_destroy_func;

public:
    explicit Plugin(kno::dlhandle handle);
    virtual ~Plugin();

    kno::Object* get_object() {return object_;}
};


} // namespace kno
