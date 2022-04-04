// Read Thermochimica Properties
    Info<< "\n\nReading Thermochimica properties" << endl;

    IOdictionary thermochimicaPropertiesDict
    (
        IOobject
        (
            "thermochimicaProperties",
            runTime.constant(),
            mesh,
            IOobject::MUST_READ,
            IOobject::NO_WRITE
        )
    );

  label Mass1(readInt(thermochimicaPropertiesDict.lookup("Mass1")));
  Info << "Mass1: " << Mass1 << endl;

  dimensionedScalar MolFraction1("MolFraction1", dimless, thermochimicaPropertiesDict.lookup("MolFraction1"));
  Info << "MolFraction1: " << MolFraction1.value() << endl;

  label Mass2(readInt(thermochimicaPropertiesDict.lookup("Mass2")));
  Info << "Mass2: " << Mass2 << endl;

  dimensionedScalar MolFraction2("MolFraction2", dimless, thermochimicaPropertiesDict.lookup("MolFraction2"));
  Info << "MolFraction2: " << MolFraction2.value() << endl;

  label Mass3(readInt(thermochimicaPropertiesDict.lookup("Mass3")));
  Info << "Mass3: " << Mass3 << endl;

  dimensionedScalar MolFraction3("MolFraction3", dimless, thermochimicaPropertiesDict.lookup("MolFraction3"));
  Info << "MolFraction3: " << MolFraction3.value() << endl;
