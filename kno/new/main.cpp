#include <cstdlib>
#include <cstring>
//#include <string>
//#include <vector>
#include <cstdio>
#include <fstream>
#include <filesystem>

#include "third-party/inja.hpp"

#include "options.h"

namespace fs = std::filesystem;
using json = nlohmann::json;

static int generate_files(Options const& options);

int main(int argc, char* argv[])
{
    Options options;

    if (!options.parse(argc, argv)) {
        return EXIT_FAILURE;
    }

    return generate_files(options);
}

struct TemplateArgs final {
    char const* text;
    std::string filename;
};

static int generate_file(
    TemplateArgs const& template_args,
    fs::path const& output_path,
    json data
)
{
    std::ofstream file((output_path / template_args.filename).c_str());
    if (!file.is_open()) {
        printf("Error: could not create file '%s'\n", template_args.filename.c_str());
        return EXIT_FAILURE;
    }

    inja::render_to(file, template_args.text, data);

    file.close();

    return EXIT_SUCCESS;
}

static const char object_h_template[] =
#include "templates/new_object.h"
;
static const char object_cpp_template[] =
#include "templates/new_object.cpp"
;
static const char object_cmake_template[] =
#include "templates/new_CMakeLists.txt"
;

static int generate_files(Options const& options)
{
    fs::path output_dir(fs::path(options.output_path) / options.object_name);

    if (!fs::exists(output_dir)) {
        if (!fs::create_directory(output_dir)) {
            printf("Error: can not create '%s'\n", output_dir.c_str());
            return EXIT_FAILURE;
        }
    }

    std::array<TemplateArgs, 3> templates {
        TemplateArgs {object_h_template, options.object_name + ".h"},
        TemplateArgs {object_cpp_template, options.object_name + ".cpp"},
        TemplateArgs {object_cmake_template, "CMakeLists.txt"}
    };

    json data;
    data["name"] = options.object_name;

    for (auto const& template_args : templates) {
        if (generate_file(template_args, output_dir, data) != EXIT_SUCCESS) {
            printf("Error: failed to use template '%s'\n", template_args.text);
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}
