//
// Created by Xingyuan Guo & Monami Mukhopadhyay on 10/15/18.
//

// This program can only do fixed number of resolution on cylinders, can be changed later, but requires work
#ifndef EE553_HW_GROUP_HW_STL_SHAPES_H
#define EE553_HW_GROUP_HW_STL_SHAPES_H

// Reference
// http://www.sc.ehu.es/ccwgamoa/docencia/Material/FileFormats/STL-FileFormat.htm
// http://svn.scratchcomputing.com/CAD-Format-STL/trunk/files/cube.stl
// http://emlab.utep.edu/ee5390em21/Lecture%2019%20--%20Interfacing%20MATLAB%20with%20CAD.pdf
// https://danbscott.ghost.io/writing-an-stl-file-from-scratch/
// normal can be left as 'facet normal 0 0 0'? translator will automatically translate
// https://en.wikibooks.org/wiki/OpenSCAD_User_Manual/Primitive_Solids


#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>    // std::replace



class Cube {
    std::string file_loc;
    double side;
public:
    explicit Cube(double s);

    void translate(double x, double y, double z); //modify center according to args

    double volume() { return side * side * side; }

    std::string get_file_loc(){ return file_loc;}
};

class Cylinder {
    std::string file_loc;
public:
    Cylinder(double r, double h); // This constructor contains actual work
    std::string get_file_loc(){ return file_loc;}

};


class Design {
    std::string file_name;
    std::vector<std::string> stl_vector;
public:
    explicit Design(const std::string &s);

    void write(const std::string &s);
    void write();

    void add(Cube c);
    void add(Cylinder cyl);

};


#endif //EE553_HW_GROUP_HW_STL_SHAPES_H
