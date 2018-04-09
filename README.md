# This is my silly fork
I do silly stuff here. The real fluxbox is available at https://github.com/fluxbox/fluxbox.

here's a few commands i recommend:

    Xephyr -br -ac -noreset -screen 1080x1280 -screen 1080x640 -dpi 96 -xkb-layout de -xkb-variant nodeadkeys :1 &
    ./autogen.sh
    CXXFLAGS="-g" LDFLAGS="-g" ./configure  --enable-debug
    make --quiet -j$(nproc)|grep -v "Making all in nls"
    find src -type f \( -name "*.hh" -o -name "*.cc" \) -exec clang-format -i {} \;
    clang-format -i src/somefile.cc

# Fluxbox WM
Fluxbox is a windowmanager for X that was based on the Blackbox 0.61.1 code.

It is very light on resources and easy to handle but yet full of features to
make an easy, and extremely fast, desktop experience.

## official Links
[official Fluxbox website](http://fluxbox.org/)

[fluxbox-wiki](http://fluxbox-wiki.org/)

[official fluxbox git repositories](http://git.fluxbox.org/)

## Install
Your distribution most likely provides precompiled packages and you can install with yum, apt and the likes.

Yet some distributions ship with outdated versions of fluxbox and you might want to build and install yourself.

First install dependencies, then, in the project root directory run:

    ./autogen.sh
    ./configure
    make
    make install

For more detailed instructions, read the INSTALL file.

## News
To learn what's new in this release read the NEWS and CHANGELOG files in the project root directory

## Contributing
two things:

- make sure you clean up all compiler warnings
- run clang-format for a consistent code style 

everything else we likely want to talk about.

## Thanks:

  Blackbox team

  People at #fluxbox on irc.freenode.net.

  And all the people who sent bugfixes/patches and helped us making
  Fluxbox a better application, see AUTHORS for an incomplete list
  of people who helped fluxbox.
