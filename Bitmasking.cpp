template < class T > inline T SET(T n,T pos)   { return n |((T)1<<pos); }
template < class T > inline T RESET(T n,T pos) { return n & ~((T)1<<pos); }
template < class T > inline T isOn(T n,T pos)  { return (bool)(n & ((T)1<<pos)); }