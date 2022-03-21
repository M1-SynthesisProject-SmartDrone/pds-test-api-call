
if [[ $UID != 0 ]]; then
    echo "Please run this script with sudo:"
    echo "    sudo $0 $*"
    exit 1
fi

sudo mkdir tmp
cd tmp

echo "==== Install packages ===="

sudo apt-get install libssl-dev

echo "==== Install cpr library ===="

git clone https://github.com/whoshuu/cpr.git
cd cpr
git reset --hard e8ee3e38670530ed268c57586d5a751e118471fd # Set to a specific commit
sudo mkdir build && cd build
sudo cmake ..
sudo make
sudo make install

cd ../.. # Return to tmp folder

echo "==== Remove temporary folder ===="

cd ..
sudo rm -r tmp

echo "==== Refresh libs ===="
sudo ldconfig