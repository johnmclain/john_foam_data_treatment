#include "IOstreams.H"
#include "dictionary.H"
#include "vector.H"
#include "IOobject.H"
#include "fvOptions.H"
#include "fvCFD.H"
#include "fvPatchField.H"
#include "IOdictionary.H"
#include "GeometricField.H"
#include <fstream> 	

using namespace Foam;

int main(int argc, char *argv[])
{
	#include "setRootCase.H"
	#include "createTime.H"
	#include "createMesh.H"
	//Info<< "Reading field U\n" << endl;
	volVectorField U
	(
        IOobject (
        "0/U.air",
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
	);

       double value=0;
       ifstream in("input.txt");  
       if (! in.is_open())  
       { cout << "Error opening file"; exit (1); }  
       while (!in.eof() )  
       {  
           in>>value;  
           //cout << value << endl;  
       }  
       
	
	auto patchID = mesh.boundaryMesh().findPatchID("Inlet");
	forAll ( U.boundaryField()[patchID], celli )
    {
    	U.boundaryField()[patchID][celli]=vector(0,0,std::move(value));
       Info << U.boundaryField()[patchID][celli] << endl;
    }
    U.write();
	//U.boundaryField().[patchID]="uniform (0.0,0,0.01)";
	
	//const dictionary& subDict_1(dict.subDict("boundaryField"));
	//Info<< dict.name() << endl;
	//const dictionary& subDict_2(subDict_1.subDict("Inlet"));
	//const vector vectorinlet(subDict_2.lookup("value"));
	//Info<< vectorinlet << endl;
	/*const IOobject U_air(
        "0/U.air",
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    );*/
	//Info<< "IOobject: " << U_air.name()<<endl;
	//IOdictionary dict_U_air{U_air};
	//const dictionary& subDict_1(dict_U_air.subDict("boundaryField"));
	//Info<< subDict_1.name()<<endl;
}
