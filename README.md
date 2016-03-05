# PLANT_DB

## Dependencies:
* SQlite3
* Qt5.5
* c++11

## Installation:
- cmake CMakeLists.txt
- sudo make install

## Configuration:
Configuration file gets installed in: /usr/local/etc/plantdb.conf. Modify the content of this file to specify the location in which the plant database is stored (default: ~/.plantdb)

## Run:
Acts as a library for other applications although a GUI is available to edit/view the db content: execute **PlantDB_Editor** on command line. 
