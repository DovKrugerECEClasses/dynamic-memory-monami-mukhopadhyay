//
// Created by Xingyuan Guo on 10/10/18.
//

#include "hw_STL_shapes.h"
#include <iostream>

#define PI 3.14159265
#define ZERO 0.0

using namespace std;

string facet_normal = "  facet normal 0 0 0 \n"; // 2 space
string outer_loop = "    outer loop \n"; // 4 space
string end_loop = "    endloop \n"; // 4 space
string end_facet = "  endfacet \n"; // 2 space


Cylinder::Cylinder(double r, double h) {

    file_loc = "cylinder.stl";
    // number of facet is 12
    double side_1 = r * sin(30 * PI / 180);
    double side_1_neg = -side_1;
    double side_2 = r * sin(60 * PI / 180);
    double side_2_neg = -side_2;

    //================================================================
    // generate the upper and bottom sides first,
    vector<vector<vector<double> > > coord_vec_top_bottom{
            {
                    {ZERO,       (-r),       9999.0},
                    {ZERO, ZERO, 9999.0},
                    {side_1,     side_2_neg, 9999.0}},


            {
                    {side_1,     side_2_neg, 9999.0},
                    {ZERO, ZERO, 9999.0},
                    {side_2,     side_1_neg, 9999.0}
            },

            {
                    {side_2,     side_1_neg, 9999.0},
                    {ZERO, ZERO, 9999.0},
                    {r,  ZERO,               9999.0}
            },

            {
                    {r,  ZERO,               9999.0},
                    {ZERO, ZERO, 9999.0},
                    {side_2,     side_1,     9999.0}
            },


            {
                    {side_2,     side_1,     9999.0},
                    {ZERO, ZERO, 9999.0},
                    {side_1,     side_2,     9999.0}
            },

            {
                    {side_1,     side_2,     9999.0},
                    {ZERO, ZERO, 9999.0},
                    {ZERO,       r,          9999.0}
            },

            {
                    {ZERO,       r,          9999.0},
                    {ZERO, ZERO, 9999.0},
                    {side_1_neg, side_2,     9999.0}
            },

            {
                    {side_1_neg, side_2,     9999.0},
                    {ZERO, ZERO, 9999.0},
                    {side_2_neg, side_1,     9999.0}
            },

            {
                    {side_2_neg, side_1,     9999.0},
                    {ZERO, ZERO, 9999.0},
                    {-r, ZERO,               9999.0}
            },

            {
                    {-r, ZERO,               9999.0},
                    {ZERO, ZERO, 9999.0},
                    {side_2_neg, side_1_neg, 9999.0}
            },

            {
                    {side_2_neg, side_1_neg, 9999.0},
                    {ZERO, ZERO, 9999.0},
                    {side_1_neg, side_2_neg, 9999.0}
            },

            {
                    {side_1_neg, side_2_neg, 9999.0},
                    {ZERO, ZERO, 9999.0},
                    {ZERO,       -r,         9999.0}
            }
    };

    vector<vector<vector<double> > > coord_vec_top_bottom_cp = coord_vec_top_bottom;

    ofstream o_file;
    o_file.open(file_loc);

    for (auto &i : coord_vec_top_bottom) {

        o_file << facet_normal; //facet normal ...
        o_file << outer_loop; //outer loop

        for (auto j = i.begin(); j != i.end(); ++j) {

            std::stringstream ss;
            ss.str(std::string()); //clear the stringstream after each iter

            std::replace(j->begin(), j->end(), 9999.0, h); // replace place holder 9999 with height

            for (double &k : *j) {
                ss << k << ' ';
            }
            //cout << *k << ' '; //each line
            o_file << "      vertex " << ss.rdbuf() << '\n';
        }

        o_file << end_loop; //endloop
        o_file << end_facet; //endfacet

        ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

        o_file << facet_normal; //facet normal ...
        o_file << outer_loop; //outer loop

        for (auto j = i.begin(); j != i.end(); ++j) {

            std::stringstream ss;
            ss.str(std::string()); //clear the stringstream after each iter

            std::replace(j->begin(), j->end(), h, 0.0); // replace place holder 9999 with height

            for (double &k : *j) {
                ss << k << ' ';
            }
            //cout << *k << ' '; //each line
            std::replace(j->begin(), j->end(), 0.0, 9999.0); // revert it back to 9999.0
            o_file << "      vertex " << ss.rdbuf() << '\n';
        }

        o_file << end_loop; //endloop
        o_file << end_facet; //endfacet

    }
    o_file << '\n' << '\n';
    o_file.close();
    //================================================================
    vector<vector<double>> coord_vec_top(12, vector<double>(3, ZERO));

    for (auto &i : coord_vec_top_bottom_cp)
        for (auto j = i.begin(); j != i.end(); ++j)
            std::replace(j->begin(), j->end(), 9999.0, h);

    for (auto i = 0; i < coord_vec_top_bottom_cp.size(); ++i)
        for (auto j = 0; j < coord_vec_top_bottom_cp[i].size(); j += 3)
            for (auto k = 0; k < coord_vec_top_bottom_cp[i][j].size(); ++k)
                coord_vec_top[i][k] = coord_vec_top_bottom_cp[i][j][k];

    vector<vector<double>> coord_vec_bot = coord_vec_top;

    for (int i = 0; i < coord_vec_top.size(); i++) { // Size 12
        for (int j = 0; j < coord_vec_top[i].size(); j += 1) { // Size 3
            coord_vec_bot[i][2] = coord_vec_top[i][j] - 2;
            // std::cout << coord_vec_bot[i][j] << ' ';
        }
        // cout << '\n';
    }
    //----------------------------------------------------------------
    ofstream outfile;
    outfile.open(file_loc, std::ios_base::app);

    std::stringstream ss_top;
    std::stringstream ss_bot;


    for (int i = 0; i <= coord_vec_top.size() - 1; i++) {

        if (i == 0) {
            // 0 11 0 up down down
            outfile << facet_normal << outer_loop;
            for (int k = 0; k < coord_vec_top[i].size(); k += 1)
                ss_top << coord_vec_top[i][k] << ' ';
            outfile << "      vertex " << ss_top.rdbuf() << '\n';

            for (int k = 0; k < coord_vec_top[i].size(); k += 1)
                ss_top << coord_vec_bot[coord_vec_top.size() - 1][k] << ' ';
            outfile << "      vertex " << ss_top.rdbuf() << '\n';

            for (int k = 0; k < coord_vec_top[i].size(); k += 1)
                ss_top << coord_vec_bot[i][k] << ' ';
            outfile << "      vertex " << ss_top.rdbuf() << '\n';

            outfile << end_loop << end_facet;


        } else {

            outfile << facet_normal; //facet normal ...
            outfile << outer_loop; //outer loop

            for (int k = 0; k < coord_vec_top[i].size(); k += 1)
                ss_top << coord_vec_top[i][k] << ' '; //1 up
            outfile << "      vertex " << ss_top.rdbuf() << '\n';

            for (int k = 0; k < coord_vec_top[i].size(); k += 1)
                ss_top << coord_vec_bot[i - 1][k] << ' '; //0 down
            outfile << "      vertex " << ss_top.rdbuf() << '\n';

            for (int k = 0; k < coord_vec_top[i].size(); k += 1)
                ss_top << coord_vec_bot[i][k] << ' ';//1 down
            outfile << "      vertex " << ss_top.rdbuf() << '\n';

            outfile << end_loop; //endloop
            outfile << end_facet; //endfacet
        }

    }

    ss_top.str(std::string()); //clear the stringstream after each iter
    ss_bot.str(std::string()); //clear the stringstream after each iter

    for (int i = 0; i <= coord_vec_top.size() - 1; i++) {

        if (i == 0) {

            // 0 0 1 up down up
            outfile << facet_normal << outer_loop;
            for (int k = 0; k < coord_vec_top[i].size(); k += 1)
                ss_top << coord_vec_top[i][k] << ' ';
            outfile << "      vertex " << ss_top.rdbuf() << '\n';

            for (int k = 0; k < coord_vec_top[i].size(); k += 1)
                ss_top << coord_vec_bot[i][k] << ' ';
            outfile << "      vertex " << ss_top.rdbuf() << '\n';

            for (int k = 0; k < coord_vec_top[i].size(); k += 1)
                ss_top << coord_vec_top[i + 1][k] << ' ';
            outfile << "      vertex " << ss_top.rdbuf() << '\n';

            outfile << end_loop << end_facet;

            // 11 11 0 up down up
            outfile << facet_normal << outer_loop;
            for (int k = 0; k < coord_vec_top[i].size(); k += 1)
                ss_top << coord_vec_top[coord_vec_top.size() - 1][k] << ' ';
            outfile << "      vertex " << ss_top.rdbuf() << '\n';

            for (int k = 0; k < coord_vec_top[i].size(); k += 1)
                ss_top << coord_vec_bot[coord_vec_top.size() - 1][k] << ' ';
            outfile << "      vertex " << ss_top.rdbuf() << '\n';

            for (int k = 0; k < coord_vec_top[i].size(); k += 1)
                ss_top << coord_vec_top[0][k] << ' ';
            outfile << "      vertex " << ss_top.rdbuf() << '\n';

            outfile << end_loop << end_facet;

        } else {

            outfile << facet_normal; //facet normal ...
            outfile << outer_loop; //outer loop
            if (i <= 10) {
                for (int k = 0; k < coord_vec_top[i].size(); k += 1)
                    ss_top << coord_vec_top[i][k] << ' ';//1 down
                outfile << "      vertex " << ss_top.rdbuf() << '\n';

                for (int k = 0; k < coord_vec_top[i].size(); k += 1)
                    ss_top << coord_vec_bot[i][k] << ' '; //0 down
                outfile << "      vertex " << ss_top.rdbuf() << '\n';

                for (int k = 0; k < coord_vec_top[i].size(); k += 1)
                    ss_top << coord_vec_top[i + 1][k] << ' ';//1 down
                outfile << "      vertex " << ss_top.rdbuf() << '\n';
            }

            outfile << end_loop; //endloop
            outfile << end_facet; //endfacet
        }
    }


}

Cube::Cube(double s) : side(s) { this->file_loc = "cube.stl"; }

void Cube::translate(double x, double y, double z) {

    vector<vector<vector<double> > > coord_vec{
            {
                    {0 + x,    side + y, side + z},
                    {side + x, 0 + y,    side + z},
                    {side + x, side + y, side + z}},

            {
                    {side + x, 0 + y,    side + z},
                    {0 + x,    side + y, side + z},
                    {0 + x,    0 + y,    side + z}},

            {
                    {0 + x,    0 + y,    0 + z},
                    {side + x, side + y, 0 + z},
                    {side + x, 0 + y,    0 + z}},

            {
                    {side + x, side + y, 0 + z},
                    {0 + x,    0 + y,    0 + z},
                    {0 + x,    side + y, 0 + z}},

            {
                    {0 + x,    0 + y,    0 + z},
                    {side + x, 0 + y,    side + z},
                    {0 + x,    0 + y,    side + z}},

            {
                    {side + x, 0 + y,    side + z},
                    {0 + x,    0 + y,    0 + z},
                    {side + x, 0 + y,    0 + z}},

            {
                    {side + x, 0 + y,    side + z},
                    {side + x, side + y, 0 + z},
                    {side + x, side + y, side + z}},

            {
                    {side + x, side + y, 0 + z},
                    {side + x, 0 + y,    side + z},
                    {side + x, 0 + y,    0 + z}},

            {
                    {side + x, side + y, 0 + z},
                    {0 + x,    side + y, side + z},
                    {side + x, side + y, side + z}},

            {
                    {0 + x,    side + y, side + z},
                    {side + x, side + y, 0 + z},
                    {0 + x,    side + y, 0 + z}},

            {
                    {0 + x,    0 + y,    0 + z},
                    {0 + x,    side + y, side + z},
                    {0 + x,    side + y, 0 + z}},

            {
                    {0 + x,    side + y, side + z},
                    {0 + x,    0 + y,    0 + z},
                    {0 + x,    0 + y,    side + z}}
    };

    ofstream o_file;
    o_file.open(file_loc);

    for (auto &i : coord_vec) {

        o_file << facet_normal; //facet normal ...
        o_file << outer_loop; //outer loop

        for (auto j = i.begin(); j != i.end(); ++j) {

            std::stringstream ss;
            ss.str(std::string()); //clear the stringstream after each iter

            for (double &k : *j) {
                ss << k << ' ';
            }
            //cout << *k << ' '; //each line
            o_file << "      vertex " << ss.rdbuf() << '\n';
        }

        o_file << end_loop; //endloop
        o_file << end_facet; //endfacet
    }
}

Design::Design(const string &s) : file_name(s) {
    this->stl_vector.emplace_back("solid OpenSCAD_Model \n");
}

void Design::add(Cube c) {

    std::ifstream inStream;
    inStream.exceptions(std::ifstream::failbit);
    try {
        inStream.open(c.get_file_loc());
        string line;
        while (getline(inStream, line)) {
            stl_vector.push_back(line);
        }
        stl_vector.emplace_back("\n");
    }
    catch (const std::exception &e) {
        std::ostringstream msg;
        msg << "Opening file '" << file_name
            << "' failed, it either doesn't exist or is not accessible.";
        throw std::runtime_error(msg.str());
    }

}

void Design::add(Cylinder c) {

    std::ifstream inStream;
    inStream.exceptions(std::ifstream::failbit);
    try {
        inStream.open(c.get_file_loc());
        string line;
        while (getline(inStream, line)) {
            stl_vector.push_back(line);
        }
        stl_vector.emplace_back("\n");
    }
    catch (const std::exception &e) {
        std::ostringstream msg;
        msg << "Opening file '" << file_name
            << "' failed, it either doesn't exist or is not accessible.";
        throw std::runtime_error(msg.str());
    }

}

void Design::write(const std::string &s) { file_name = s; }

void Design::write() {
    ofstream o_file;
    o_file.open(file_name);

    for (auto &i : stl_vector) {
        for (auto j = i.begin(); j != i.end(); ++j) {
            o_file << *j;
        }
        o_file << '\n';
    }

    o_file << "endsolid OpenSCAD_Model \n";
}

int main() {
    Design d("test.stl");
    double s = 10;
    Cube c(s);
    //=====
    int x = 1;
    int y = 2;
    int z = 3;
    //=====
    c.translate(x, y, z); //where is x,y and z?
    cout << c.volume() << '\n';

    d.write("out.stl"); // how to get all my shapes into the same file

    d.add(c);

    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    double r = 10, height = 2;
    Cylinder cyl(r, height);

    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    d.add(cyl);
    d.write();

    return 0;
}