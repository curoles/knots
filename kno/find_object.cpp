#include "find_object.h"

/** Return path to the Object or empty path if not found.
 *
 */
std::filesystem::path
kno::find_object(std::string const& obj_name, std::filesystem::path const& search_path)
{
    std::filesystem::path obj_path(search_path);

    obj_path /= obj_name;
    if (std::filesystem::exists(obj_path)) {
        return obj_path;
    }

    obj_path.clear(); // make empty path for caller to know we did not find it

    return obj_path;
}

/** Build Object and return path to binary file or empty path if error.
 *
 */
std::filesystem::path
kno::build_object(std::string const& obj_name [[maybe_unused]], std::filesystem::path const& obj_path [[maybe_unused]])
{
    std::filesystem::path bin_path;
    std::string cmd_output;

    execute_shell_cmd("ls", cmd_output);
    //printf("output: %s\n", cmd_output.c_str());

    return bin_path;
}

/** Execute shell command.
 *
 * @param output string with the stdout contents
 * @return process exit code
 */
int
kno::execute_shell_cmd(std::string const& cmd, std::string& output)
{
    std::array<char, 128> buffer;

    auto pipe = popen(cmd.c_str(), "r");
    if (!pipe) {
        output += "Error: popen() failed!";
        return -1;
    }

    size_t count;
    do {
        if ((count = fread(buffer.data(), 1, buffer.size(), pipe)) > 0) {
            output.insert(output.end(),
                std::begin(buffer),
                std::next(std::begin(buffer), count));
        }
    } while(count > 0);

    int process_exit_status = pclose(pipe);

    return process_exit_status;
}

