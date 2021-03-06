#include "topalg.h"

TopAlg::TopAlg()
{}

TopAlg::~TopAlg(){}


/*************************************************
 * Runs the over-relaxation algorithm
 * on a Mesh which has defined boundary
 * conditions
 *************************************************/
void TopAlg::runAlgorithm(){
    
    double tempvalue;
    
    //start the clock
    clock_t t1,t2;
    t1=clock();
    
    //Solution one iteration ahead
    //using the Jacobi method	
    for (int i = 1 ; i<_dimx-1 ; i++){
	for (int j = 1 ; j<_dimy-1 ; j++){
	    if (!_PMesh.getisBoundary(i,j)){
		double tempvalue = (_PMesh.getV(i+1,j) + 
		    _PMesh.getV(i-1,j) + 
		    _PMesh.getV(i,j+1) + 
		    _PMesh.getV(i,j-1))/4;
		    _SMesh.setV(tempvalue,i,j);		    
	    }
	    setEdges(i,j);
	}
    }
    _iter++;
    // While the error is bigger than the tolerated one
    // carry on with approximating the solution further
    // until it is reached.
    //calculate the error between two meshes
    calcError();
    while (_err > _tol){
    //main algorithm
    for (int i = 1 ; i<_dimx-1 ; i++){
	for (int j = 1 ; j<_dimy-1 ; j++){
	    if (!_SMesh.getisBoundary(i,j)){
	    double tempvalue = ((1-_orp)*_PMesh.getV(i,j) + 
		    (_orp/4)*(_PMesh.getV(i+1,j) + 
		    _SMesh.getV(i-1,j) + 
		    _PMesh.getV(i,j+1) + 
		    _SMesh.getV(i,j-1)));
	    
	    _SMesh.setV(tempvalue,i,j);
	    }
	    setEdges(i,j);
	}
    }
    
    _iter++;
    calcError();
    // Set old potential = new potential
    _PMesh = _SMesh;
    }
    
    _maxError = calcError();
    
    //stop the clock and find the difference
    t2=clock();
    double diff ((float)t2-(float)t1);
    _time = diff / CLOCKS_PER_SEC;
}


/*************************************************
 * Returns the number of iterations of the 
 * algorithm
 *************************************************/
double TopAlg::getIter(){
 return _iter;
}

/*************************************************
 * Returns the time needed for the 
 * algorithm to run
 *************************************************/
double TopAlg::getTime(){
 return _time;
}

/*************************************************
 * Returns the tolerance
 *************************************************/
double TopAlg::getTolerance(){
    return _tol;
}





/*************************************************
 * Puts the potential values into a data file
 * Arguments are needed to produce different
 * text files.
 * 
 * Arguments: 
 * 1 => analytical
 * 2 => numerical with circle inside
 * 3 => numerical from an image
 * 
 * The output is in a X by Y matrix 
 * filled with potetial values at each point,
 * where X and Y are dimensions of the array
 *************************************************/
void TopAlg::printGNUPLOT(int i)
{
    /*
    std::ofstream file1,file2,file3,file4,file5,file6;
    if ( i == 1){
	file1.open("PotentialField/Vanalytical1.txt");
	file1 << _PMesh;
    }else if ( i == 2){
	file2.open("PotentialField/VnumCircle1.txt");
	file2 << _PMesh;
    }else if ( i == 3){
	file3.open("PotentialField/Vnumerical2.txt");
	file3 << _PMesh;
    }else if ( i == 4){
	file4.open("PotentialField/VnumCircle2.txt");
	file4 << _PMesh;
    }else if ( i == 5){
	file5.open("PotentialField/Vnumerical3.txt");
	file5 << _PMesh;
    }else if ( i == 6){
	file6.open("PotentialField/VnumCircle3.txt");
	file6 << _PMesh;
    }*/
    
    std::ofstream file;
    if ( i == 1){
	file.open("PotentialField/Vanalytical.txt");
	file << _PMesh;
    }else if ( i == 2){
	file.open("PotentialField/VnumCircle.txt");
	file << _PMesh;
    }else if ( i == 3){
	file.open("PotentialField/Vnumerical.txt");
	file << _PMesh;
    }
    
    file.close();
    
}


/*************************************************
 * Creates a file with the potential data, but with
 * a different spacing. ROOT can plot the electric
 * field using the potential field values, but it 
 * needs data to be more spaced out, otherwise it 
 * takes too long. 
 * 
 * First argument: 
 * i = 2 => numerical with circle inside
 * i = 3 => numerical from an image
 * 
 * Second argument:
 * spacing between mesh points put to a file
 * 
 *************************************************/
void TopAlg::printROOT(int i, int spacing){

    std::ofstream file;
    if ( i == 1){
	file.open("ElectricField/Eanalytical.txt");
    }else if ( i == 2){
	file.open("ElectricField/EnumCircle.txt");
    }else if ( i == 3){
	file.open("ElectricField/Enumerical.txt");
    }
    
    //put data into a text file
    //it will have (X,Y,Edx,Edy,|E|) format
    if (spacing != 0){
	for (int X = 1 ; X<_dimx-1 ; X=X+sqrt(_dimx)/3){
	    for (int Y = 1 ; Y<_dimy-1 ; Y=Y+sqrt(_dimx)/3){
		file << X << " " << Y << " " << _PMesh.getV(X,Y) << std::endl;
	    }
	}
    }else{
	for (int X = 1 ; X<_dimx-1 ; X++){
	    for (int Y = 1 ; Y<_dimy-1 ; Y++){
		file << X << " " << Y << " " << _PMesh.getV(X,Y) << std::endl;
	    }
	}
    }
}




/*************************************************
 * Takes the difference between two Meshes
 * and produces a text file
 * 
 * The format of the file is a X by Y matrix,
 * where X and Y are the coordinates of the Mesh
 * 
 * Also give the average differece between arrays
 *************************************************/
double TopAlg::difference(TopAlg& other, int index)
{
    if (_dimx != other._dimx || _dimy != other._dimy){ 
	std::cout << "array size mismatch\n";
    }
    
    double accumulator=0;
    double diff;
    
    Mesh diffmesh = Mesh(_dimx, _dimy);
    
    for (int i=0; i<_dimx; i++){
	for (int j=0; j<_dimy; j++){
	    diff = fabs( _PMesh.getV(i,j) - other._PMesh.getV(i,j) );
	    diffmesh.setV(diff,i,j);
	    //gets the total potential at all mesh points
	    accumulator = accumulator + diff;
	}
    }
    
    //gets the average
    double average = accumulator/(_dimx*_dimy);
    //gets the percentage of the total potential difference
    double answer = average/other._V * 100;
    
    if (index == 1){
	std::ofstream file;
	file.open("PotentialField/Vdifference.txt");
	file << diffmesh;
	file.close();
    }
    return answer;
}


/*************************************************
 * Return the potential value
 *************************************************/
double TopAlg::getPotential(){
	return _V;
}


/*************************************************
 * Takes the ratio between the two Meshes 
 * and produces a text file with the differences
 * 
 * The format of the file is a X by Y matrix,
 * where X and Y are the coordinates of the Mesh
 * 
 * Returns the average of potential ratios
 *************************************************/
double TopAlg::ratio(TopAlg& other, int index){
    
    if (_dimx != other._dimx || _dimy != other._dimy){ 
	std::cout << "array size mismatch\n";
    }
    
    double accumulator=0;
    double diff;

    Mesh diffmesh = Mesh(_dimx, _dimy);
    for (int i=0; i<_dimx; i++){
	for (int j=0; j<_dimy; j++){
	    if (!other._PMesh.getisBoundary(i,j) && other._PMesh.getV(i,j) != 0){
		double diff = fabs(_PMesh.getV(i,j) / other._PMesh.getV(i,j));
		diffmesh.setV(diff,i,j);
		    
		//gets the total potential ratio at all mesh points
		accumulator = accumulator + diff;
	    }
	}
    }
    
    //gets the average
    double average = accumulator/(_dimx*_dimy);
    
    //gets the percentage of the total potential difference
    double answer = average/other._V * 100;
    
    if (index == 1){
	std::ofstream file;
	file.open("PotentialField/Vratio.txt");
	file << diffmesh;
	file.close();  
    }
    
    return answer;
}

/*************************************************
 * Calculates the error term for the algorithm
 * 
 * It compares the solutions of the algorithm
 * between one iteration and another, which is
 * by 1 iteration further.
 * 
 * Then it find the maximum difference and returns it
 * 
 * Then the algorithm compares it with the tolerance
 *************************************************/
double TopAlg::calcError(){

    //largest difference value
    double difference;
    _err=0;
    for (int X = 0 ; X<_dimx ; X++){
	for (int Y = 0 ; Y<_dimy ; Y++){
	    difference = fabs(_SMesh.getV(X,Y) - _PMesh.getV(X,Y));
	    //std::cout << difference << std::endl;
	    //find the largest difference value
	    if (_err < difference){
		_err = difference;
	    }
	}
    }
    return _err;
}



/*************************************************
 * Calculates the over-relaxation parameter
 *************************************************/
double TopAlg::ORP(){
	double T=cos(PI/_dimx) + cos(PI/_dimy);
	_orp = ( (8-sqrt(64-16*pow(T,2))) / pow(T,2));
	return _orp;
}

/*************************************************
 * The algorithm cannot operate on edges, since
 * it uses the neighbourhing values to find the
 * solution and there are not enough values.
 * 
 * So, this function sets them to be equal
 * to their nearest neighbourh
 *************************************************/
void TopAlg::setEdges(int i,int j)
{
    // Check whether the boundaries of the mesh have a plate or not
    // if they have a plate, then leave it alone. If not,
    // set it equal to the neighbourh value in order to eliminate
    // the zeros. This is for all four boundaries

    //j and i go from 1 to dim-2 in the main algorithm
    //we want them to go from 0 to dim-1
    //hence, we add 0 and dim-1 separately
    double tempvalue;
    
    
    // THE EDGE AT X=0 THROUGH ALL Y VALUES
    if ( !_SMesh.getisBoundary(0,j) ){
	tempvalue = _SMesh.getV(1,j);
	_SMesh.setV(tempvalue,0,j);}
    
    if ( !_SMesh.getisBoundary(0,0) ){
	tempvalue = _SMesh.getV(1,0);
	_SMesh.setV(tempvalue,0,0);
    }
    if ( !_SMesh.getisBoundary(0,_dimy-1) ){
	tempvalue = _SMesh.getV(1,_dimy-1);
	_SMesh.setV(tempvalue,0,_dimy-1);
    }
    
    
    // THE EDGE AT X=_dimx-1 THROUGH ALL Y VALUES
    if ( !_SMesh.getisBoundary(_dimx-1,j) ){				
	tempvalue = _SMesh.getV(_dimx-2,j);
	_SMesh.setV(tempvalue,_dimx-1,j);
    }
    //ADD THE ENDS
    if ( !_SMesh.getisBoundary(_dimx-1,0) ){				
	tempvalue = _SMesh.getV(_dimx-2,0);
	_SMesh.setV(tempvalue,_dimx-1,0);
    }
    if ( !_SMesh.getisBoundary(_dimx-1,_dimy-1) ){
	tempvalue = _SMesh.getV(_dimx-2,_dimy-1);
	_SMesh.setV(tempvalue,_dimx-1,_dimy-1);
    }
    
    
    // THE EDGE AT Y=0 THROUGH ALL X VALUES
    if ( !_SMesh.getisBoundary(i,0) ){						
	tempvalue = _SMesh.getV(i,1);
	_SMesh.setV(tempvalue,i,0);
    }
    //ADD THE ENDS
    if ( !_SMesh.getisBoundary(0,0) ){			
	tempvalue = _SMesh.getV(0,1);
	_SMesh.setV(tempvalue,0,0);
    }
    if ( !_SMesh.getisBoundary(_dimx-1,0) ){			
	tempvalue = _SMesh.getV(_dimx-1,1);
	_SMesh.setV(tempvalue,_dimx-1,0);
    }
   
    // THE EDGE AT Y=_dimy-1 THROUGH ALL X VALUES
    if ( !_SMesh.getisBoundary(i,_dimy-1) ){						
	tempvalue = _SMesh.getV(i,_dimy-2);
	_SMesh.setV(tempvalue,i,_dimy-1);
    }
    //ADD THE ENDS
    if ( !_SMesh.getisBoundary(0,_dimy-1) ){
	tempvalue = _SMesh.getV(0,_dimy-2);
	_SMesh.setV(tempvalue,0,_dimy-1);
    }
    if ( !_SMesh.getisBoundary(_dimx-1,_dimy-1) ){
	tempvalue = _SMesh.getV(_dimx-1,_dimy-2);
	_SMesh.setV(tempvalue,_dimx-1,_dimy-1);
    }
}
