#pragma once

#include <string>
#include <vector>

#include "find_object.h"

namespace kno {

class Object;
class Plugin;

class Plugin final
{
    kno::dlhandle lib_;
    kno::Object* object_;

    Plugin* list_next_ = nullptr;

private:
    typedef kno::Object* (*object_create_func_t)(void);
    typedef void  (*object_destroy_func_t)(kno::Object*);
    typedef kno::Plugin* (*object_query_func_t)(kno::Object*);

    object_create_func_t object_create_func;
    object_destroy_func_t object_destroy_func;
    object_query_func_t object_query_func;

public:
    explicit Plugin(kno::dlhandle handle);
    virtual ~Plugin();

    kno::Object* get_object() {return object_;}

    [[nodiscard]] kno::Plugin* query(kno::Object*);

    void set_list_next(Plugin* next) {list_next_ = next;}
    Plugin* get_list_next(){return list_next_;}

    static Plugin* make(std::string const& obj_name);
};


using vector_plugins = std::vector<std::unique_ptr<kno::Plugin> >;

[[nodiscard]] kno::Plugin*
do_query(vector_plugins const& plugins);

void plugins_list_delete(kno::Plugin* plugins_list);

} // namespace kno

extern "C"
kno::Plugin* kno_plugin_make(std::string const& obj_name);
