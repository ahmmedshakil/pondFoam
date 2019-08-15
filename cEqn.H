//-solving the transport equation for the tracer test
Info<< "Solving transport equation C\n" << endl;

 {
    fvScalarMatrix CEqn
    (
        fvm::ddt(C)                         //-C[0,0,0,0,0,0,0]
        + fvm::div(phi, C)
        - fvm::laplacian(DT, C)             //-DT [kg m s K mol A cd] = [0,0,-1,0,0,0,0]
        ==
        fvOptions(C)
    );

    CEqn.relax();
    fvOptions.constrain(CEqn);
    CEqn.solve();
    fvOptions.correct(C);
}