#include "options.h"

#include "third-party/CLI11.hpp"

bool Options::parse(int argc, char** argv)
{
    CLI::App app{"Create new KNOT"};

    this->output_path = "NO OUTPUT PATH PROVIDED";

    app.add_flag("-v,--verbose", this->verbose, "verbose output");

    //app.add_option("-l,--log", this->log_file, "log file")->
    //    each([this](const std::string &){this->is_log_enabled = true;});

    app.add_option("-o,--output-path", this->output_path, "generated files location")
        ->required()
        ->check(CLI::ExistingPath);

    app.add_option("-p,--prj-path", this->kno_prj_dir, "main project path")
        ->required()
        ->check(CLI::ExistingPath);

    // Positional option, object name
    app.add_option("object_name", this->object_name, "object_name")
        ->required();

    try
    {
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError& e)
    {
        app.exit(e);
        return false;
    }

    return true;
}

