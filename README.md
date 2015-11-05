# TOPPERS-JSP

It runs on Ubuntu 14.04LTS (kernel 3.19.0-31-generic) (i386).

TOPPERS/JSP 1.4.4.1 with the following 3 patches:

https://www.toppers.jp/jsp-kernel.html

(toppers-users 2712) Re: JSPシミュレーション環境へのパッチ
http://www.toppers.jp/TOPPERS-USERS/2008-January/002534.html
TOPPERS/JSP 1.4.3のLinuxシミュレータに対するパッチ
http://www.northern-cross.info/download.html
http://www.northern-cross.info/DL/jsp-143-linux-posix-diff.tar.gz

(Perl5 Getopt issue)
https://github.com/kidasan/toppers/blob/master/patches/patch_1441.diff

(toppers-users 3984) Re: JSP1.4.4の不具合 (原因究明？)
http://www.toppers.jp/TOPPERS-USERS/2012-June/003807.html
(toppers-users 3987) Re: JSP1.4.4の不具合 (原因究明？)
http://www.toppers.jp/TOPPERS-USERS/2012-June/003810.html

Three additional changes are needed:

fix perl5 getopt issues in utils/makedep

disable gcc code optimization (-O2 -> -O0)

fix implicit declaration of exit()

Note:  original TOPPERS proejct and each patch creator has each own copyright and license. Please take care it.
