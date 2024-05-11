#pragma once

#include <filesystem>
#include <string>

namespace kno {


/** Return path to the Object or empty path if not found.
 *
 */
std::filesystem::path
find_object(std::string const& obj_name, std::filesystem::path const& search_path);

/** Build Object and return path to binary file or empty path if error.
 *
 */
std::filesystem::path
build_object(std::string const& obj_name,
    std::filesystem::path const& obj_path,
    std::filesystem::path const& output_path);

/** Execute shell command.
 *
 * @param output string with the stdout contents
 * @return process exit code
 */
int
execute_shell_cmd(std::string const& cmd, std::string& output);

} // namespace kno
