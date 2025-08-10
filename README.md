# AirSim Project

**This is a fork from Colosseum and some modifications have been made to meet development on UE 5.**


## Modifications:

 - ESC button Function: free cursor from window capture mode.
 - RPC Api: add moveOnPathWithGimbalPose to enable the drone fly with specified path along with camera poses at each path point.


## Build Environment

  Please build this project with VS2022  latest version & UE5.5.4.
  Note: **Eigen latest version doesn't support C++20 Standard, to fix compile errors, set MACRO ‘#define EIGEN_HAS_STD_RESULT_OF 0’ to disable features that removed by C++17/20.**

## License
This project is released under the MIT License. Please review the [License file](LICENSE) for more details.


## First Build on Windows

1. install cmake and git
```
  winget install cmake, git
```

2. make sure necessary visual studio components are installed.
![necessary tools](./figures/01.png)
![necessary sdk](./figures/02.png)

3. open **'X86 Native Tools Command Promote for VS 2022'**, under ${AirsimRootFolder} directory, run build.cmd, it will install required dependencies and build airsim plugin. you may see build failed messages for Eigen source code .
search MACRO **EIGEN_HAS_STD_RESULT_OF** in file "Unreal\Environments\Blocks\Plugins\AirSim\Source\AirLib\deps\eigen3\Eigen\src\Core\util\Macros.h", edit EIGEN_HAS_STD_RESULT_OF defination like following:
```
// Does the compiler support result_of?
#define EIGEN_HAS_STD_RESULT_OF 0
```

4. Then， re-run build.cmd till the process become completed and no errors occured .

Now, you can open UE5 project with everything running well.


## Airsim plugin modifications sync
When UE5 scene or relevant changes belongs to Airsim plugin has been made, run **'update_to_git.bat'** to sync changes to git when these changes have been validated.