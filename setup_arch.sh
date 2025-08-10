#!/usr/bin/env bash
set -x
set -e

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
pushd "$SCRIPT_DIR" >/dev/null

downloadHighPolySuv=true

MIN_CMAKE_VERSION=3.10.0
# On macOS, make sure we have a CMake that will support CMAKE_APPLE_SILICON_PROCESSOR.
if [ "$(uname)" == "Darwin" ]; then
    MIN_CMAKE_VERSION=3.19.2
fi

DEBUG="${DEBUG:-false}"
function version_less_than_equal_to() { test "$(printf '%s\n' "$@" | sort -V | head -n 1)" = "$1"; }

# brew gives error if package is already installed
function brew_install() { brew list "$1" &>/dev/null || brew install "$1"; }

# Parse command line arguments
while [[ $# -gt 0 ]]
do
key="$1"

case $key in
    --debug)
        DEBUG=true
        ;;
    --no-full-poly-car)
        downloadHighPolySuv=false
        shift # past value
        ;;
esac

done

# llvm tools
if [ "$(uname)" == "Darwin" ]; then # osx
    brew update
    # Update below line for newer versions
    #brew install llvm@8
    brew install llvm
else #linux
    if [[  -n "${whoami}" ]]; then #this happens when running in travis
        sudo /usr/sbin/useradd -G dialout "$USER"
        sudo usermod -a -G dialout "$USER"
    fi

    # install additional tools

fi # End USB setup, CMake install


# Download rpclib
if [ ! -d "external/rpclib/rpclib-2.3.0" ]; then
    echo "*********************************************************************************************"
    echo "Downloading rpclib..."
    echo "*********************************************************************************************"

    wget https://github.com/rpclib/rpclib/archive/v2.3.0.zip

    # remove previous versions
    rm -rf "external/rpclib"

    mkdir -p "external/rpclib"
    unzip -q v2.3.0.zip -d external/rpclib
    rm v2.3.0.zip
fi

# Download high-polycount SUV model
if $downloadHighPolySuv; then
    if [ ! -d "Unreal/Plugins/AirSim/Content/VehicleAdv" ]; then
        mkdir -p "Unreal/Plugins/AirSim/Content/VehicleAdv"
    fi
    if [ ! -d "Unreal/Plugins/AirSim/Content/VehicleAdv/SUV/v1.2.0" ]; then
            echo "*********************************************************************************************"
            echo "Downloading high-poly car assets.... The download is ~37MB and can take some time."
            echo "To install without this assets, re-run setup.sh with the argument --no-full-poly-car"
            echo "*********************************************************************************************"

            if [ -d "suv_download_tmp" ]; then
                rm -rf "suv_download_tmp"
            fi
            mkdir -p "suv_download_tmp"
            cd suv_download_tmp
            wget  https://github.com/CodexLabsLLC/Colosseum/releases/download/v2.0.0-beta.0/car_assets.zip
            if [ -d "../Unreal/Plugins/AirSim/Content/VehicleAdv/SUV" ]; then
                rm -rf "../Unreal/Plugins/AirSim/Content/VehicleAdv/SUV"
            fi
            unzip -q car_assets.zip -d ../Unreal/Plugins/AirSim/Content/VehicleAdv
            cd ..
            rm -rf "suv_download_tmp"
    fi
else
    echo "### Not downloading high-poly car asset (--no-full-poly-car). The default unreal vehicle will be used."
fi

echo "Installing Eigen library..."

if [ ! -d "AirLib/deps/eigen3" ]; then
    echo "Downloading Eigen..."
    wget -O eigen3.zip https://gitlab.com/libeigen/eigen/-/archive/3.4.0/eigen-3.4.0.zip
    unzip -q eigen3.zip -d temp_eigen
    mkdir -p AirLib/deps/eigen3
    mv temp_eigen/eigen*/Eigen AirLib/deps/eigen3
    rm -rf temp_eigen
    rm eigen3.zip
else
    echo "Eigen is already installed."
fi

popd >/dev/null

set +x
echo ""
echo "************************************"
echo "AirSim setup completed successfully!"
echo "************************************"
