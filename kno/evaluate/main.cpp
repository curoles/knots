#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <filesystem>

#include "kno/find_object.h"
#include "kno/plugin.h"
#include "kno/object/kno_object.h"

#include "options.h"

std::vector<std::string> split_string(std::string s, std::string del = ".")
{
    std::vector<std::string> strings;
    int start, end = -1*del.size();
    do {
        start = end + del.size();
        end = s.find(del, start);
        strings.push_back(s.substr(start, end - start));
    } while (end != -1);

    return strings;
}


int main(int argc, char* argv[])
{
    Options options;

    if (!options.parse(argc, argv)) {
        return EXIT_FAILURE;
    }

    std::vector<std::string> query = split_string(options.query);
    std::vector<std::unique_ptr<kno::Plugin> > plugins;

    kno::Object* prev = nullptr;

    for (auto const& obj_name : query) {
        printf("find object: %s\n", obj_name.c_str());
        std::filesystem::path kb(options.search_path);

        auto obj_path = kno::find_object(obj_name, kb);
        if (obj_path.empty()) {
            printf("could not find object '%s'\n", obj_name.c_str());
            return EXIT_FAILURE;
        }

        auto obj_lib_path = kno::build_object(obj_name,
            obj_path, options.output_path, options.update_objects);

        if (!obj_lib_path.empty()) {
            auto handle = kno::load_object(obj_lib_path);
            if (!handle) {
                return EXIT_FAILURE;
            }
            plugins.push_back(std::move(std::make_unique<kno::Plugin>(handle)));
            kno::Object* this_object = plugins.back()->get_object();
            if (prev) {
                prev->set_list_next(this_object);
            }
            prev = this_object;
        }
    }

    if (plugins.size() > 0) {
        kno::Plugin* result = kno::do_query(plugins);
        if (result == nullptr) {
            fprintf(stderr, "Error: no result returned\n");
        }
        else {
            kno::plugins_list_delete(result);
        }
    }

    // Delete objects and unload .so libs.
    plugins.clear();

    return EXIT_SUCCESS;
}
