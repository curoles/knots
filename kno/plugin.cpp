#include "plugin.h"

#include <filesystem>
#include <dlfcn.h>

#include "kno/object/kno_object.h"

namespace fs = std::filesystem;

kno::Plugin::
Plugin(kno::dlhandle handle):lib_(handle)
{
    *(void **) (&object_create_func) = dlsym(handle, "kno_create");
    *(void **) (&object_destroy_func) = dlsym(handle, "kno_destroy");
    *(void **) (&object_query_func) = dlsym(handle, "kno_query");

    object_ = object_create_func();
    if (!object_) {
        throw std::string(dlerror());
    }
}

kno::Plugin::
~Plugin()
{
    object_destroy_func(object_);
    kno::unload_object(lib_);
}

[[nodiscard]] kno::Plugin*
kno::Plugin::
query(kno::Object* objects_list)
{
    return object_query_func(objects_list);
}

[[nodiscard]] kno::Plugin*
kno::do_query(vector_plugins const& plugins)
{
    if (plugins.empty()) {
        return nullptr;
    }

    kno::Object* objects_list = plugins.front()->get_object();

    /*for (kno::Object* current = objects_list; current != nullptr; current = current->get_list_next()) {
        printf("%s\n", current->name().c_str());
    }*/

    return plugins.front()->query(objects_list);
}

void kno::plugins_list_delete(kno::Plugin* plugins_list)
{
    kno::Plugin* next;
    for (kno::Plugin* current = plugins_list; current != nullptr; current = next) {
        next = current->get_list_next();
        printf("delete %s\n", current->get_object()->name().c_str());
        delete current;
    }
}

kno::Plugin*
kno::Plugin::make(
    std::string const& obj_name
)
{
    Plugin* plugin = nullptr;
    kno::dlhandle handle = kno::find_build_load_object(
        obj_name,
        "/home/lesikigor/prj/knots/knots/kb",
        "/tmp/knots",
        true
    );

    if (handle) {
        plugin = new kno::Plugin(handle);
    }
    else {
        fprintf(stderr, "Error: can not load %s\n", obj_name.c_str());
    }

    return plugin;
}

extern "C" __attribute__((used))  __attribute__((externally_visible))
kno::Plugin* kno_plugin_make(std::string const& obj_name)
{
    return kno::Plugin::make(obj_name);
}
