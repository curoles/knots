#include "options.h"

#include "third-party/CLI11.hpp"

bool Options::parse(int argc, char** argv)
{
    CLI::App app{"Evaluate KNOTS expression"};

    this->search_path = "NO SEARCH PATH PROVIDED";

    app.add_flag("-v,--verbose", this->verbose, "verbose output");
    app.add_flag("-u,--update", this->update_objects, "rebuild objects");

    //app.add_option("-l,--log", this->log_file, "log file")->
    //    each([this](const std::string &){this->is_log_enabled = true;});

    app.add_option("-s,--search-path", this->search_path, "objects search path")
        ->required()
        ->check(CLI::ExistingPath);

    app.add_option("-o,--output-path", this->output_path, "compiled objects location")
        ->required();

    // Positional option, query string
    app.add_option("query", this->query, "query")
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

