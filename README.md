u-boot-yse5250
==============

this repo contains u-boot for yse5250 Exynos ARM Board

HOWTO build it u-boot for YSE5250?

* clone this repo
1. git clone https://github.com/fedya/u-boot-yse5250.git

* download linaro's toolchain
2. wget -c https://launchpad.net/linaro-toolchain-binaries/trunk/2013.10/+download/gcc-linaro-arm-linux-gnueabihf-4.8-2013.10_linux.tar.xz

* extract it
3. tar xJf gcc-linaro-arm-linux-gnueabihf-4.8-2013.10_linux.tar.xz

* add to $PATH binaries
4. export CC=`pwd`/gcc-linaro-arm-linux-gnueabihf-4.8-2013.10_linux/bin/arm-linux-gnueabihf-

* make ARCH=arm CROSS_COMPILE=${CC} distclean
* make ARCH=arm CROSS_COMPILE=${CC} yse5250

last command should produce u-boot.bin
