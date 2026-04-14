#configure error handling
$ErrorActionPreference = "Stop"
Set-StrictMode -Version 3

#get folder of CANoe4SW Server Edition
$canoe4sw_se_install_dir = $env:CANoe4SWSE_InstallDir64
$vtt_install_dir = $env:vVIRTUALtarget_InstallDir

#build VTT
& $vtt_install_dir/VttMake.exe make "$PSScriptRoot/LightControl_VisualStudio.vttmake"

#create environment
& $canoe4sw_se_install_dir/environment-make.exe "$PSScriptRoot/venvironment.yaml" -o "$PSScriptRoot"

#create tests for the environment
& $canoe4sw_se_install_dir/test-unit-make.exe "$PSScriptRoot/test/SoftwareTest.vtestunit.yaml" -e "$PSScriptRoot/Default.venvironment" -o "$PSScriptRoot"

#run tests
& $canoe4sw_se_install_dir/canoe4sw-se.exe "$PSScriptRoot/Default.venvironment" -d "$PSScriptRoot/working-dir" --test-unit "$PSScriptRoot/SoftwareTest.vtestunit" --show-progress test-case
