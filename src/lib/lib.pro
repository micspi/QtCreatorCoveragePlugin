TEMPLATE = lib

QTC_PLUGIN_NAME = CodeCoverage
QTC_SOURCE = $$(QTC_SOURCE)
QTC_BUILD  = $$(QTC_BUILD)

DEFINES += CODECOVERAGE_LIBRARY

# Qt Creator linking

## set the QTC_SOURCE and QTC_BUILD environment variable to override the setting here
IDE_SOURCE_TREE = $$QTC_SOURCE
IDE_BUILD_TREE = $$QTC_BUILD
PROVIDER = VendorName

QTC_PLUGIN_DEPENDS += coreplugin texteditor projectexplorer qmakeprojectmanager

# CodeCoverage files
include($$QTC_SOURCE/src/qtcreatorplugin.pri)

include(codecoverage.pri)
OTHER_FILES = CodeCoverage.pluginspec

QMAKE_CXXFLAGS += -std=c++0x
CXXFLAGS="-std=c++0x" ./configure
