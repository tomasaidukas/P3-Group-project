
//**************************************//	
//	Electric field array calculator		//	
//**************************************//
void Algorithm::eField(Mesh& array){
	for (int X = 0 ; X<_dimx-1 ; X++){
		for (int Y = 0 ; Y<_dimy-1 ; Y++){
			// Components of the electric field
			md_field = array.getV(X+1,Y) - _SMesh.getV(X,Y);
			EF_dxMesh.setV(md_field,X,Y);
			md_field =  array.getV(X,Y+1) - _SMesh.getV(X,Y); 
			EF_dyMesh.setV(md_field,X,Y);
			
			// Magnitude of E	
			//md_field = sqrt(pow(EF_dxMesh.getV(X,Y),2) + pow(EF_dyMesh.getV(X,Y),2));
			//use magnitude 1 to get normal arrow sizes
			md_field = 5;
			EF_Mesh.setV(md_field,X,Y);
		}
	}
}
