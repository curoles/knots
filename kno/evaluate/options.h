#pragma once

#include <string>
#include <cstdint>

/// Container of command line options.
///
struct Options
{
    bool verbose{false}; ///< if true show details of the execution

    std::string search_path;  ///< where to search for objects
    std::string output_path;  ///< where to store compiled objects
    std::string query;

    bool update_objects{false};

    // Use only when assembler emits ELF *executable*
    //uint64_t prog_load_addr{0x1000};

    //bool is_log_enabled{false};
    //std::string log_file{"assembler.log"};


    public:
    /// Parse this tool command line options.
    bool parse(int argc, char** argv);
};

