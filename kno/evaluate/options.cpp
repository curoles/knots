#include "options.h"

#include "third-party/CLI11.hpp"

bool Options::parse(int argc, char** argv)
{
    CLI::App app{"Evaluate KNOTS expression"};

    this->search_path = "NO SEARCH PATH PROVIDED";

    app.add_flag("-v,--verbose", this->verbose, "verbose output");

    //app.add_option("-l,--log", this->log_file, "log file")->
    //    each([this](const std::string &){this->is_log_enabled = true;});

    app.add_option("search_path", this->search_path, "objects search path")
        ->required();
        //->check(CLI::ExistingFile);

    // Positional option, directory with compiled objects
    app.add_option("output_path", this->output_path, "compiled objects location")
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

