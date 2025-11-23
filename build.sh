set -e
set -o errexit
set -o pipefail
cd stable
chmod +x build.sh
./build.sh
cd ../src/QapGenV2025
chmod +x build.sh
./build.sh
