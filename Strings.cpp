//  Converting number to string


template < class T > string ToString ( T n )
{
    	ostringstream ss;
    	ss << n;
    	return ss.str();
}



//	String multiplication

string multiply( string a, long long b ) {
        int carry = 0, i;

        for( i = 0; i < a.size(); i++ ) {
            carry += (a[i] - 48) * b;
            a[i] = ( carry % 10 + 48 );
            carry /= 10;
        }

        while( carry ) {
            a += ( carry % 10 + 48 );
            carry /= 10;
        }

        return a;
}

#define d(x) cerr << #x " = " << (x) << endl
