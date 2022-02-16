const char filename[120] = "/home/nikolas/Desktop/example/icoFoamT3/thermochimica/data/JRC-2021-fluoride-noSUBM.dat";

std::vector<double> molFrac_KF;
std::vector<double> partialPressure_KF;
std::vector<double> molFrac_NaF;
std::vector<double> partialPressure_NaF;
std::vector<double> molFrac_LiF;
std::vector<double> partialPressure_LiF;
std::vector<double> molFrac_CsF;
std::vector<double> partialPressure_CsF;

std::vector<double> SolnPhaseMol_solid1;
std::vector<double> SolnPhaseMol_LiF_NaF;
std::vector<double> SolnPhaseMol_FLi_solids;
std::vector<double> SolnPhaseMol_SALTsoln;
std::vector<double> SolnPhaseMol_SALTsoln_frac;
std::vector<double> SolnPhaseMol_gas_ideal;
std::vector<double> SolnPhaseMol_gas_ideal_frac;

std::vector<double> Total_SolnPhaseMol_gas_ideal_frac;

SetThermoFilename(filename);
FORTRAN_CALL(setstandardunits)();
int iElement = 0;
double dMass = 0.0;

//Composition: 0.65 LiF + 0.350001 CsF

FORTRAN_CALL(setelementmass)(&iElement, &dMass);
iElement = 3; //Li
dMass = 0.250;
FORTRAN_CALL(setelementmass)(&iElement, &dMass);
iElement = 55; //Cs
dMass = 0.750001;
FORTRAN_CALL(setelementmass)(&iElement, &dMass);
iElement = 9; //F
dMass = 1.00;
FORTRAN_CALL(setelementmass)(&iElement, &dMass);

double dTemperature = Tave[i];
double dPressure = 1;   //[atm]
FORTRAN_CALL(settemperaturepressure)(&dTemperature, &dPressure);
FORTRAN_CALL(ssparsecsdatafile)();
FORTRAN_CALL(thermochimica)();

int iflag;
FORTRAN_CALL(checkinfothermo)(&iflag);
//printf("Debug flag: %i\n",iflag);
int iPrintMode = 2;

FORTRAN_CALL(setprintresultsmode)(&iPrintMode);
//FORTRAN_CALL(printresults)();

//char phaseName1[25] = "solid1";
//char phaseName2[25] = "LiF-NaF";
//char phaseName3[25] = "FLi_solid(s)";
char phaseName4[25] = "SALTsoln";
char phaseName5[25] = "gas_ideal";

//double molesPhase_solid1;
//double molesPhase_LiF_NaF;
//double molesPhase_FLi_solids;
double molesPhase_SALTsoln;
double molesPhase_gas_ideal;

//har speciesName1[8] = "LiF";
//char speciesName2[8] = "ThF4";
char speciesName3[8] = "CsF";

//double moleFraction_KF;
//double moleFraction_NaF;
//double moleFraction_LiF;
//double moleFraction_ThF4;

int info;
FORTRAN_CALL(checkinfothermo)(&info);
//printf("Information: %i\n",info);

// PostProcess Thermochmica

double moleFraction_CsF;

GetOutputMolSpeciesPhase(phaseName5, speciesName3, &moleFraction_CsF, &info);
molFrac_CsF.push_back(moleFraction_CsF);
//printf("%s in %s: %e\n\n", speciesName3, phaseName5, moleFraction_CsF); //fala CsF mol fraction para cada elemento i

Info << "size molFrac_CsF: " << molFrac_CsF[i] << '\n'; //why is this vector size 1?

GetSolnPhaseMol(phaseName4, &molesPhase_SALTsoln, &info);
SolnPhaseMol_SALTsoln.push_back(molesPhase_SALTsoln);
//printf("%s fraction as a stable solution phase: %e\n\n", phaseName4, molesPhase_SALTsoln);

GetSolnPhaseMol(phaseName5, &molesPhase_gas_ideal, &info);
SolnPhaseMol_gas_ideal.push_back(molesPhase_gas_ideal);
//printf("%s fraction as a stable solution phase: %e\n\n", phaseName5, molesPhase_gas_ideal);

FORTRAN_CALL(resetthermoall)();
