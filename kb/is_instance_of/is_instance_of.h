#pragma once

namespace kno::is_instance_of {

class Object : public kno::Object
{
    bool operator()(kno::Object const* type, kno::Object const* instance) const;
};


} // namespace kno::is_instance_of
