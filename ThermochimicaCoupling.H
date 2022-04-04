//scalar totalTime = mesh.time().value();
//scalar dt = mesh.time().deltaTValue();

forAll(T, i)
{
	T[i];
	Info << endl << "Cell N°: " << i << endl;
	Info<< "Time = " << runTime.timeName() << endl;
	Tave[i] = T[i];

	//AveTempMatrix.push_back(T[i]);
	//Info <<  "Average Temperature = " << AveTempMatrix.at(i) << " K" << nl;
   Info <<  "Temperature = " << T[i] << " K" << nl;
	 Info <<  "Average Temperature = " << Tave[i] << " K" << nl;


	#include "ThermochimicaCalc.H"
  //X.correctBoundaryConditions();
//	C.correctBoundaryConditions();
}
