#pragma once

#include <string>
#include <vector>

#include "find_object.h"

namespace kno {

class Object;

class Plugin final
{
    kno::dlhandle lib_;
    kno::Object* object_;

private:
    typedef kno::Object* (*object_create_func_t)(void);
    typedef void  (*object_destroy_func_t)(kno::Object*);
    typedef kno::Object* (*object_query_func_t)(kno::Object*);

    object_create_func_t object_create_func;
    object_destroy_func_t object_destroy_func;
    object_query_func_t object_query_func;

public:
    explicit Plugin(kno::dlhandle handle);
    virtual ~Plugin();

    kno::Object* get_object() {return object_;}

    //kno::Object* query();
};


using vector_plugins = std::vector<std::unique_ptr<kno::Plugin> >;

void //[[nodiscard]]
do_query(vector_plugins const& plugins);

} // namespace kno
