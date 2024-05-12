#include "plugin.h"

#include <dlfcn.h>

#include "kno/object/kno_object.h"

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

[[nodiscard]] kno::Object*
kno::Plugin::
query(kno::Object* objects_list)
{
    return object_query_func(objects_list);
}

[[nodiscard]] kno::Object*
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
