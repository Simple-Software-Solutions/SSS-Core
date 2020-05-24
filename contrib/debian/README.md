
Debian
====================
This directory contains files used to package sssd/sss-qt
for Debian-based Linux systems. If you compile sssd/sss-qt yourself, there are some useful files here.

## sss: URI support ##


sss-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install sss-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your sss-qt binary to `/usr/bin`
and the `../../share/pixmaps/sss128.png` to `/usr/share/pixmaps`

sss-qt.protocol (KDE)

