  #include "readThermochimicaProperties.H"

volScalarField vapourPressure_Cs
(
    IOobject
    (
        "vapourPressure_Cs",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    dimensionedScalar("", dimPressure, 0)
);

// Cesium fluoride vapour Pressure
volScalarField vapourPressure_CsF
(
    IOobject
    (
        "vapourPressure_CsF",
        runTime.timeName(),
        mesh,
        IOobject::NO_READ,
        IOobject::AUTO_WRITE
    ),
    mesh,
    dimensionedScalar("", dimPressure, 0)
);
