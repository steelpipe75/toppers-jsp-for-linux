# toppers-jsp-for-linux

https://www.toppers.jp/jsp-kernel.html

## Platform

* Ubuntu 16.04LTS (i386, x86_64) 
 * avaialble 32bit binary only

## Required packages

* git
* gcc-multilib (5.3.1-1ubuntu1)
* libboost-dev (1.58.0.1ubuntu1)
* libboost-system-dev (1.58.0.1ubuntu1)
* libboost-filesystem-dev (1.58.0.1ubuntu1)
* libboost-program-options-dev (1.58.0.1ubuntu1)
* libboost-regex-dev (1.58.0.1ubuntu1)

## Quick Start (sample1)
    sudo apt-get install git gcc-multilib libboost-dev libboost-system-dev libboost-filesystem-dev libboost-program-options-dev libboost-regex-dev
    git clone https://github.com/morioka/toppers-jsp-for-linux
    cd toppers-jsp-for-linux     
    cd jsp-1.4.4.1-full
    cd cfg
    make clean
    make depend
    make
    cd ..
    mkdir OBJ
    cd OBJ
    ../configure -C linux
    make depend
    make
    ./jsp

---

TOPPERS/JSP 1.4.4.1 with the following 3 patches:
* https://www.toppers.jp/jsp-kernel.html
* setjmp/longjmp and jmpbuf issue
 * (toppers-users 2712) Re: JSPシミュレーション環境へのパッチ
  * http://www.toppers.jp/TOPPERS-USERS/2008-January/002534.html
 * TOPPERS/JSP 1.4.3のLinuxシミュレータに対するパッチ
  * http://www.northern-cross.info/download.html
  * http://www.northern-cross.info/DL/jsp-143-linux-posix-diff.tar.gz
* Perl5 Getopt issue
 * https://github.com/kidasan/toppers/blob/master/patches/patch_1441.diff
* cfg parser issue
 * (toppers-users 3984) Re: JSP1.4.4の不具合 (原因究明？)
  * http://www.toppers.jp/TOPPERS-USERS/2012-June/003807.html
 * (toppers-users 3987) Re: JSP1.4.4の不具合 (原因究明？)
  * http://www.toppers.jp/TOPPERS-USERS/2012-June/003810.html

Three additional changes are needed:
* fix perl5 getopt issues in utils/makedep
* disable gcc code optimization (-O2 -> -O0)
* fix implicit declaration of exit()

Note:  original TOPPERS proejct and each patch creator has each own copyright and license. Please take care it.


```shell:commands

wget https://www.toppers.jp/download.cgi/jsp-1.4.4.1_full.tar.gz
wget http://www.northern-cross.info/DL/jsp-143-linux-posix-diff.tar.gz
wget https://github.com/kidasan/toppers/raw/master/patches/patch_1441.diff

tar xzvf jsp-1.4.4.1_full.tar.gz
tar xzvf jsp-143-linux-posix-diff.tar.gz

pushd jsp-1.4.4.1-full/config/linux
patch -p3 < ../../../jsp-143-linux-posix.diff
popd
pushd jsp-1.4.4.1-full
patch -p0 < ../patch_1441.diff
popd

# apply my patches
patch -p0 < jsp-1441-MakeConfig.diff
patch -p0 < jsp-1441-makedep.diff
patch -p0 < jsp-1441-cpudef.diff
patch -p0 < jsp-1441-parser.diff

# build cfg and sample1
pushd jsp-1.4.4.1-full/cfg
make
popd

pushd jsp-1.4.4.1-full
mkdir OBJ
cd OBJ
../configure -C linux
make depend
make
popd

```
