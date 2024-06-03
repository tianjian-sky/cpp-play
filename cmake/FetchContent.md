## FetchContent

### FetchContent_Declare
``` c
FetchContent_Declare(
  <name>
  <contentOptions>...
  [EXCLUDE_FROM_ALL]
  [SYSTEM]
  [OVERRIDE_FIND_PACKAGE |
   FIND_PACKAGE_ARGS args...]
)
```

* The content <name> can be any string without spaces, but good practice would be to use only letters, numbers and underscores. The name will be treated case-insensitively and it should be obvious for the content it represents, often being the name of the child project or the value given to its top level project() command (if it is a CMake project). For well-known public projects, the name should generally be the official name of the project. Choosing an unusual name makes it unlikely that other projects needing that same content will use the same name, leading to the content being populated multiple times.

* The <contentOptions> can be any of the download, update or patch options that the ExternalProject_Add() command understands. The configure, build, install and test steps are explicitly disabled and therefore options related to them will be ignored. The SOURCE_SUBDIR option is an exception, see FetchContent_MakeAvailable() for details on how that affects behavior.

* In most cases, <contentOptions> will just be a couple of options defining the download method and method-specific details like a commit tag or archive hash. For example:

Where contents are being fetched from a remote location and you do not control that server, it is advisable to use a hash for GIT_TAG rather than a branch or tag name. A commit hash is more secure and helps to confirm that the downloaded contents are what you expected.

### ExternalProject_Add

The ExternalProject_Add() function creates a custom target to drive download, update/patch, configure, build, install and test steps of an external project:
``` c
ExternalProject_Add(<name> [<option>...])
```

### FetchContent_MakeAvailable
 
``` c
FetchContent_MakeAvailable(<name1> [<name2>...])
```

This command ensures that each of the named dependencies are made available to the project by the time it returns. There must have been a call to FetchContent_Declare() for each dependency, and the first such call will control how that dependency will be made available, as described below.

### FetchContent_GetProperties
When using saved content details, a call to FetchContent_MakeAvailable() or FetchContent_Populate() records information in global properties which can be queried at any time. This information may include the source and binary directories associated with the content and also whether or not the content population has been processed during the current configure run.
``` c
``` 
FetchContent_GetProperties(
  <name>
  [SOURCE_DIR <srcDirVar>]
  [BINARY_DIR <binDirVar>]
  [POPULATED <doneVar>]
)
```
``` c
# Check if population has already been performed
FetchContent_GetProperties(depname)
if(NOT depname_POPULATED)
  # Fetch the content using previously declared details
  FetchContent_Populate(depname)

  # Set custom variables, policies, etc.
  # ...

  # Bring the populated content into the build
  add_subdirectory(${depname_SOURCE_DIR} ${depname_BINARY_DIR})
endif()
```
The SOURCE_DIR, BINARY_DIR and POPULATED options can be used to specify which properties should be retrieved. Each option accepts a value which is the name of the variable in which to store that property. Most of the time though, only <name> is given, in which case the call will then set the same variables as a call to FetchContent_MakeAvailable(name) or FetchContent_Populate(name). Note that the SOURCE_DIR and BINARY_DIR values can be empty if the call is fulfilled by a dependency provider.

This command is rarely needed when using FetchContent_MakeAvailable(). It is more commonly used as part of implementing the following pattern with FetchContent_Populate(), which ensures that the relevant variables will always be defined regardless of whether or not the population has been performed elsewhere in the project already: