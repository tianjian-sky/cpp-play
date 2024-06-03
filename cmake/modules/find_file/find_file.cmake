#[[

find_file (
          <VAR>
          name | NAMES name1 [name2 ...]
          [HINTS [path | ENV var]... ]
          [PATHS [path | ENV var]... ]
          [REGISTRY_VIEW (64|32|64_32|32_64|HOST|TARGET|BOTH)]
          [PATH_SUFFIXES suffix1 [suffix2 ...]]
          [VALIDATOR function]
          [DOC "cache documentation string"]
          [NO_CACHE]
          [REQUIRED]
          [NO_DEFAULT_PATH]
          [NO_PACKAGE_ROOT_PATH]
          [NO_CMAKE_PATH]
          [NO_CMAKE_ENVIRONMENT_PATH]
          [NO_SYSTEM_ENVIRONMENT_PATH]
          [NO_CMAKE_SYSTEM_PATH]
          [NO_CMAKE_INSTALL_PREFIX]
          [CMAKE_FIND_ROOT_PATH_BOTH |
           ONLY_CMAKE_FIND_ROOT_PATH |
           NO_CMAKE_FIND_ROOT_PATH]
         )


If NO_DEFAULT_PATH is specified, then no additional paths are added to the search. 
If NO_DEFAULT_PATH is not specified, the search process is as follows:
1 If called from within a find module or any other script loaded by a call to find_package(<PackageName>), search prefixes unique to the current package being found. See policy CMP0074.

	New in version 3.12.

		Specifically, search paths specified by the following variables, in order:

		<PackageName>_ROOT CMake variable, where <PackageName> is the case-preserved package name.

		<PACKAGENAME>_ROOT CMake variable, where <PACKAGENAME> is the upper-cased package name. See policy CMP0144.

	New in version 3.27.

		<PackageName>_ROOT environment variable, where <PackageName> is the case-preserved package name.

		<PACKAGENAME>_ROOT environment variable, where <PACKAGENAME> is the upper-cased package name. See policy CMP0144.

	New in version 3.27.

		
2 Search paths specified in cmake-specific cache variables. These are intended to be used on the command line with a -DVAR=value. The values are interpreted as semicolon-separated lists. This can be skipped if NO_CMAKE_PATH is passed or by setting the CMAKE_FIND_USE_CMAKE_PATH to FALSE.
	<prefix>/include/<arch> if CMAKE_LIBRARY_ARCHITECTURE is set, and <prefix>/include for each <prefix> in CMAKE_PREFIX_PATH

	CMAKE_INCLUDE_PATH

	CMAKE_FRAMEWORK_PATH
3 Search paths specified in cmake-specific environment variables. These are intended to be set in the user's shell configuration, and therefore use the host's native path separator (; on Windows and : on UNIX). This can be skipped if NO_CMAKE_ENVIRONMENT_PATH is passed or by setting the CMAKE_FIND_USE_CMAKE_ENVIRONMENT_PATH to FALSE.

	<prefix>/include/<arch> if CMAKE_LIBRARY_ARCHITECTURE is set, and <prefix>/include for each <prefix> in CMAKE_PREFIX_PATH

	CMAKE_INCLUDE_PATH

	CMAKE_FRAMEWORK_PATH

4 Search the paths specified by the HINTS option. These should be paths computed by system introspection, such as a hint provided by the location of another item already found. Hard-coded guesses should be specified with the PATHS option.

5 Search the standard system environment variables. 

6 Search cmake variables defined in the Platform files for the current system. The searching of CMAKE_INSTALL_PREFIX and CMAKE_STAGING_PREFIX can be skipped if NO_CMAKE_INSTALL_PREFIX is passed or by setting the CMAKE_FIND_USE_INSTALL_PREFIX to FALSE. All these locations can be skipped if NO_CMAKE_SYSTEM_PATH is passed or by setting the CMAKE_FIND_USE_CMAKE_SYSTEM_PATH to FALSE.

	<prefix>/include/<arch> if CMAKE_LIBRARY_ARCHITECTURE is set, and <prefix>/include for each <prefix> in CMAKE_SYSTEM_PREFIX_PATH

	CMAKE_SYSTEM_INCLUDE_PATH

	CMAKE_SYSTEM_FRAMEWORK_PATH

7 Search the paths specified by the PATHS option or in the short-hand version of the command. These are typically hard-coded guesses.



]]




if(WIN32)
    find_file(notepad_path notepad.exe)
    message("${notepad_path}") # 输出：C:/Windows/System32/notepad.exe
endif()

# 使用tree .查看当前目录的树形结构
# ├── a
# │   └── b
# │       └── 1.txt     
# ├── b
# │   └── a
# │       └── 1.txt     
# └── find_file.cmake   

find_file(res1 1.txt HINTS a b PATH_SUFFIXES b)
message("${res1}") # 输出：.../CMake-Book/src/ch009/find_file/a/b/1.txt

find_file(res2 1.txt HINTS a b PATH_SUFFIXES a)
message("${res2}") # 输出：.../CMake-Book/src/ch009/find_file/b/a/1.txt
