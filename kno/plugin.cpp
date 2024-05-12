#include "plugin.h"

#include <dlfcn.h>


kno::Plugin::
Plugin(kno::dlhandle handle):lib_(handle)
{
    *(void **) (&object_create_func) = dlsym(handle, "kno_create");
    *(void **) (&object_destroy_func) = dlsym(handle, "kno_destroy");
    *(void **) (&object_query_func) = dlsym(handle, "kno_query");

    object_ = reinterpret_cast<kno::Object*>(object_create_func());
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

void //[[nodiscard]]
kno::do_query(vector_plugins const& plugins)
{
    if (plugins.empty()) {
        return;
    }

    //plugins.at(0).query([1..len]);
}
