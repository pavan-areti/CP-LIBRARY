#define err(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); error(true, _it, args); }
 
void error(bool newline, istream_iterator<string> it) {}
template<typename T, typename... Args>
void error( bool newline, istream_iterator<string> it, T a, Args... args) {
    cout << "[ " << *it << " = " << a << " ] ";
    error(false, ++it, args...);
    if(newline) cout << '\n';
}

/* eg. err(x, y)
       err(a[i])
*/

