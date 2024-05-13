#pragma once

#include <string>

namespace kno {

class Object;

class Object
{
    std::string name_;

    Object* list_next_ = nullptr;

public:
    explicit Object(std::string name_):
        name_(std::move(name_)), list_next_(nullptr)
    {}

    virtual ~Object(){}

    std::string const& name() const {
        return name_;
    }

    void set_list_next(Object* next) {list_next_ = next;}
    Object* get_list_next(){return list_next_;}
};

#if 0
inline void objects_list_delete(kno::Object* objects_list) {
    kno::Object* next;
    for (kno::Object* current = objects_list; current != nullptr; current = next) {
        next = current->get_list_next();
        //printf("delete %s\n", current->name().c_str());
        delete current;
    }
}
#endif

} // namaspace kno
