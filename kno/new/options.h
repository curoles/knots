#pragma once

#include <string>
#include <cstdint>

/// Container of command line options.
///
struct Options
{
    bool verbose{false}; ///< if true show details of the execution

    std::string object_name;  ///< name of the new Object
    std::string output_path;  ///< location to store generated Object text files
    std::string kno_prj_dir;  ///< path to main project

    //bool is_log_enabled{false};
    //std::string log_file{"assembler.log"};


public:
    /// Parse this tool command line options.
    bool parse(int argc, char** argv);
};

