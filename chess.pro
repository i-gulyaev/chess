TEMPLATE = subdirs

CONFIG += ordered

SUBDIRS = lib \
          gui

gui.depends = lib
