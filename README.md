# hscompile
This is a forked and modified version of hscompile. For detailed installation instruction and other information, please visit [here](https://github.com/kevinaangstadt/hscompile.git).

## Extended features:
- Added *regex_filter.cpp*

    **Usage**
    ```bash
    ./regex_filter <snort_regex_file_name> <filtered_snort_regex_file_path>
    ```

    **Purpose**

    It takes a file of regular expressions and determine if they can be compiled by [hyperscan](https://github.com/intel/hyperscan.git)<br />
    It generates possibly two files: failedPCRE.regex (containing those regex which did NOT pass hyperscan compilation) and succeedPCRE.regex (containing those regex which passed hyperscan compilation)

    **Parameters**

    Param 1: <snort_regex_file_name> path to the input regex file.<br />
    Param 2: <filtered_snort_regex_file_path> path to the output regex files.

- Modified *pcre2mnrl.cpp*

    **Usage**
    ```bash
    ./pcre2mnrl [FLAG] <regex file path> <mnrl file path> 
    ```
    FLAG is optional. By deafult, pcre2mnrl supports backwards compatibility.<br />
    -f, --force Force compilation by discarding invalid modifiers.

    **Purpose**

    It converts a collection of regex to a single .mnrl file (automaton description).<br />
    It generates one .mnrl file.

    **Parameters**

    Param 1: <regex file path> path to the input regex file.<br />
    Param 2: <mnrl file path> path to the output .mnrl file.
