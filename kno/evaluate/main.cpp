#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <filesystem>

#include "kno/find_object.h"

int main(int argc [[maybe_unused]], char* argv[] [[maybe_unused]])
{
    std::vector<std::string> query {"the_universe", "is_instance_of", "universe"};

    for (auto const& obj_name : query) {
        printf("find object: %s\n", obj_name.c_str());
        std::filesystem::path kb("../knots/kb");

        auto obj_path = kno::find_object(obj_name, kb);
        if (obj_path.empty()) {
            printf("could not find object '%s'\n", obj_name.c_str());
            return EXIT_FAILURE;
        }

        auto obj_bin_path = kno::build_object(obj_name, obj_path);
    }

    return EXIT_SUCCESS;
}
