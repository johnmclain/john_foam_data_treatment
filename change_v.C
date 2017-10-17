#include "IOstreams.H"
#include "dictionary.H"
#include "vector.H"
#include "IOobject.H"
#include "fvOptions.H"
#include "fvCFD.H"
#include "fvPatchField.H"
#include "fvPatchFieldsFwd.H"
#include "IOdictionary.H"
#include "GeometricField.H"
#include <fstream>

using namespace Foam;

int main(int argc, char *argv[])
{
        #include "setRootCase.H"
        #include "createTime.H"
        #include "createMesh.H"
        Info<< "Reading field U\n" << endl;
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


        auto patchID = mesh.boundaryMesh().findPatchID("inlet");
        fvPatchVectorField& Uand=U.boundaryFieldRef()[patchID];
        forAll ( Uand, celli )
        {
        Uand[celli].setVectorValue(0.0,value,0.0);
        Info<< Uand[celli] << endl;
        }
    U.write();

}
