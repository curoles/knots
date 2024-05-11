#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <filesystem>

#include "kno/find_object.h"
#include "kno/plugin.h"
#include "options.h"

int main(int argc, char* argv[])
{
    Options options;

    if (!options.parse(argc, argv)) {
        return EXIT_FAILURE;
    }

    std::vector<std::string> query {"the_universe", "is_instance_of", "universe"};
    std::vector<std::unique_ptr<kno::Plugin> > plugins;

    for (auto const& obj_name : query) {
        printf("find object: %s\n", obj_name.c_str());
        std::filesystem::path kb(options.search_path);

        auto obj_path = kno::find_object(obj_name, kb);
        if (obj_path.empty()) {
            printf("could not find object '%s'\n", obj_name.c_str());
            return EXIT_FAILURE;
        }

        auto obj_lib_path = kno::build_object(obj_name, obj_path, options.output_path);

        if (!obj_lib_path.empty()) {
            auto handle = kno::load_object(obj_lib_path);
            if (!handle) {
                return EXIT_FAILURE;
            }
            plugins.push_back(std::move(std::make_unique<kno::Plugin>(handle)));
        }
    }

    // Delete objects and unload .so libs.
    plugins.clear();

    return EXIT_SUCCESS;
}
