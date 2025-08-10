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


