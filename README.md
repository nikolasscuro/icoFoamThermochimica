# OpenFOAM-and-Thermochimica-Coupling
A numerical coupling between OpenFOAM as a CFD tool and Thermochimica as a CT tool

Install OpenFOAM V9: https://openfoam.org/version/9/

Before compiling this code:

1) git clone https://github.com/ORNL-CEES/thermochimica (inside this solver folder)
2) Compile Thermochimica (make)
3) Modify location of libthermoc.a and libthermochimica.a libraries in file "options" inside folder "Make"
4) Change ThermochimicaCalc.H according to your own chemistry calculation (1st line)

wclear
wmake
