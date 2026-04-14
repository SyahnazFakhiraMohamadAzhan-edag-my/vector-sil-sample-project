# Light Control Sample using Distributed Objects CLI

***Hint: This is a markdown file with links and functional elements. We recommend that you use a Markdown viewer. An 
example is the Visual Studio Code extension. Once this file has been opened in Visual Studio Code and the extension is 
installed, press 'CTRL + SHIFT + V' to view the formatted file.***

This demo is mostly a functional copy of the UI version "Light Control Sample using Distributed Objects", but 
is meant to demonstrate CI usage. For a more detailed functional description see the README 
[here](../LightControl/README.md).

Hint: Starting with CANoe version 17 SP3 it is possible to create CANoe configurations from venvironment.yaml files. 
More information can be found in the CANoe help page "Create Configuration". Please note that vVIRTUALtarget ECUs 
currently require an active bus network to work. The test units of this example can also be imported into a UI CANoe 
configuration.

## Files

This section briefly describes the main artefacts delivered with this sample that are particularly relevant to the CI 
workflow:

- [LightControl_*.vttmake](./LightControl_MinGW.vttmake): These files are the main input file for our CLI tool 
VttMake. This is essentially the CLI tool representation of a *.vttproj file for the UI version of vVIRTUALtarget. 
There are multiple files for different compilers and platforms. Note that the "generalized VTTMAKE file" feature (see this 
[README](../../Programming/VTTMake/GeneralizedVTTMAKE/README.md)) can be used to avoid multiple VTTMAKE files.
- [LightControl.vttpm](./LightControl.vttpm): This file contains the PortMonitoring configuration for this 
sample. You can find out more about this on our help page at vVIRTUALtarget  » AUTOSAR Classic ECUs  » Access to RTE 
Ports.
- [venvironment.yaml](venvironment.yaml), [./test/SoftwareTest.vtesttree.yaml](./test/SoftwareTest.vtesttree.yaml) and 
[./test/SoftwareTest.vtestunit.yaml](./test/SoftwareTest.vtestunit.yaml): These yaml files are the main input for the 
CLI tools of CANoe Server Edition. These files and their structure are explained on the help page of CANoe Server 
Edition.
- [./system-variables/interface.vsysvar](./system-variables/interface.vsysvar): This file is an export of all relevant 
system variables containing their definitions. This file is referenced in the venvironment.yaml.
- [run.ps1](./run.ps1) (PowerShell script to run workflow for Windows)

## How to run

The following sections describe how to run this example on Windows and Linux. Please note that CANoe Server Edition
version 19 or higher is required to run this example. Version 19 SP3 is required for a pure Linux workflow.

### Windows Target

For the sake of readability, relative paths are used.
The working directory for all commands is "X:/path/to/Sample 
Projects/BswEmulation/LightControl_CLI".

1. Use the following commands to change to the working directory:

    ```cmd
    REM Replace X: with the identifier of your drive:
    X:

    cd "X:/path/to/Sample Projects/BswEmulation/LightControl_CLI"
    ```

2. Generate the build environment and build the SUT using VttMake on Windows:

    ```cmd
    "X:/path/to/VttMake/Executable/VttMake.exe" make ./LightControl_MinGW.vttmake
    ```

3. Open CANoe Server Edition Windows prompt.

4. Create the compiled test environment using the following command:

    ```cmd
    environment-make . -o .
    ```

5. Create the compiled test unit using the following command:

    ```cmd
    test-unit-make ./test/SoftwareTest.vtestunit.yaml -e ./Default.venvironment -o .
    ```

6. Run the tests using the following command:

    ```cmd
    canoe4sw-se ./Default.venvironment --test-unit ./SoftwareTest.vtestunit --show-progress tree-element -d ./working-dir
    ```

7. Testreport will be generated in [./working-dir/TestReports](./working-dir/TestReports).

### Linux Target

For a pure Linux workflow, CANoe Server Edition verion 19 SP3 or higher is required. Transfer this project folder 
to your Linux machine (or use the [Windows-Subsystem for Linux](https://learn.microsoft.com/en-us/windows/wsl/install)).

1. Generate the build environment and build the SUT using VttMake on Linux.

    ```bash
    vttmake make ./LightControl_Linux.vttmake
    ```

2. Create the compiled test environment using the following command:

    ```bash
    /opt/vector/canoe-server-edition/environment-make . -o ./linux-gen
    ```

3. Create the compiled test unit using the following command:

    ```bash
    /opt/vector/canoe-server-edition/test-unit-make ./test/SoftwareTest.vtestunit.yaml -e ./linux-gen/Default.venvironment -o ./linux-gen
    ```

4. Run the tests using the following command:

    ```bash
    /opt/vector/canoe-server-edition/canoe4sw-se ./linux-gen/Default.venvironment --test-unit \
    ./linux-gen/SoftwareTest.vtestunit --show-progress tree-element -d ./working-dir 
    ```

5. The test report will be generated in ./working-dir/TestReports.
