# AirSim Project

**This is a fork from Colosseum and some modifications have been made to meet development on UE 5.2/ UE5.3**


## Modifications:

 - ESC button Function: free cursor from window capture mode.
 - RPC Api: add moveOnPathWithGimbalPose to enable the drone fly with specified path along with camera poses at each path point.


## Build Environment

  Please build this project in Docker Ubuntu 20.04 with clang-12/clang++-12. Then you can feel free to copy the airsim plugin folder to UE projects on Host machine.

  **Backward Capability: Branch UE-5.3 can both support UE5.3 and UE 5.2. It has been verified on UE5.2.1.**
  *When on UE5.2 project, it will promote that Airsim plugin has been build with different Engine version when open with UE5.2, please rebuild the project follow its instrucitons.*
 

## License

This project is released under the MIT License. Please review the [License file](LICENSE) for more details.


