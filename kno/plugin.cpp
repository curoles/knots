#include "plugin.h"

#include <dlfcn.h>


kno::Plugin::
Plugin(kno::dlhandle handle):lib_(handle)
{
    *(void **) (&object_create_func) = dlsym(handle, "kno_create");
    *(void **) (&object_destroy_func) = dlsym(handle, "kno_destroy");

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
