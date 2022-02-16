scalar totalTime = mesh.time().value();
scalar dt = mesh.time().deltaTValue();
std::vector<double> AveTempMatrix{};

forAll(Tave, i)
{
	Tave[i] = (totalTime * Tave[i] + dt * T[i] ) / (totalTime + dt);
	Info << endl << "Element number #: " << i << endl;
	Info<< Tave[i] << endl;

	AveTempMatrix.push_back(Tave[i]);

  Info << "size: " << AveTempMatrix.size() << '\n'; //corresponds to i

	Info << "Valor de temperatura na posicao " << i << " = " << AveTempMatrix.at(i) << endl << endl;

	#include "ThermochimicaCalc.H"

}
