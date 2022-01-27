/*successful
    x86-64 gcc 4.1-trunk -O1
    x86-64 clang 3.0.0-trunk -O1
*/
// this is a c++ case
int advance(int mCurrent,int a) {
	if ( mCurrent == 0 )
		return 0;
	while( 1 ){
		if( a > 2 ){
			mCurrent++;
		}
		if( mCurrent == 10 )
			break;
		if( functionReturningBool( mCurrent, a ) )
			break;
	}
	// warning missing return
}

int main(){
	advance(1,1);
}