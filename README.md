QtCreator Coverage Plugin
====

Supported QtCreator version: 3.4.2 (Qt 5.5)
![1](http://cs410716.vk.me/v410716701/3369/jM11dQoBDg8.jpg)


# How to build
At this moment only *nix are supported, sorry. Reason is - you have to compile your test project with gcc.

1. Download precompiled binaries Qt 5.5 with QtCreator from [here](http://qt-project.org/downloads) and Install it
2. Download source code of QtCreator in some directory. 
2. Clone this repository in some directory.
3. Compile this plugin:
```
cd PLUGIN_PATH
export QTC_SOURCE=/path/to/qtcreator/source # Example: /home/uglide/Downloads/qt-creator-opensource-src-3.4.2/
export QTC_BUILD=/path/to/qtcreator/folder/in/qt # Example: /home/uglide/Qt5/Tools/QtCreator/
qmake -r
make
```
4. Install `lcov`. If you use deb-like system, type `sudo apt-get install lcov`
5. After that, run QtCreator
6. There must be new green button at the left panel. Don't click on it yet.
7. (Optional, but recommended) Read gcov and/or lcov start guide.
8. Create your test subproject. Add compile flags to it:
```
LIBS += -lgcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
```
9. Compile and run test subproject. After that, activate colorizing through `Tools/CodeCoverage/Show code coverage` or type `Ctrl+H`

## AUTHORS:
 - [3Hren](https://github.com/3Hren)
 - [Typz](https://github.com/Typz)
 - [uglide](https://github.com/uglide)
