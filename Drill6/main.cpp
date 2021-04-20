#include "std_lib_facilities.h"

template<class T> struct S {
    S() : val(T()) { }
    S(T d) : val(d) { }
    T& operator=(const T&);
    T& get();
    const T& get() const;
    void set(const T& d);
private:
    T val;
};

template<class T> T& S<T>::operator=(const T& d)
{
    val = d;
    return val;
}

template<class T> T& S<T>::get() { return val; }

template<class T> const T& S<T>::get() const { return val; }

template<class T> void S<T>::set(const T& d) { val = d; }


template<class T> istream& operator>>(istream& is, S<T>& ss)
{
    T v;
    cin >> v;
    if (!is) return is;
    ss = v;
    return is;
}

template<class T> void read_val(T& v)
{
    cin >> v;
}

template<class T> ostream& operator<<(ostream& os, const vector<T>& d)
{
    os << "{ ";
    for (int i = 0; i<d.size(); ++i) {
        os << d[i];
        if (i<d.size()-1) os << ',';
        os << ' ';
    }
    os << "}";
    return os;
}

template<class T> istream& operator>>(istream& is, vector<T>& d)
{
    char ch1;
    char ch2;
    T temp;
    vector<T> v_temp;
    is >> ch1;
    if (!is) return is;
    if (ch1!='{') {
        is.clear(ios_base::failbit);
        return is;
    }
    while (cin>>temp>>ch2 && ch2==',') {
        v_temp.push_back(temp);
    }
    if (ch2!='}') {
        is.clear(ios_base::failbit);
        return is;
    }
    v_temp.push_back(temp);

    d = v_temp;
}



int main()
try {
    S<int> s_int(5);
    S<char> s_char('x');
    S<double> s_dbl(3.14);
    S<string> s_strg("String1");
    vector<int> vi;
    vi.push_back(1);
    vi.push_back(2);
    vi.push_back(3);
    S< vector<int> > s_v_int(vi);

    cout << "s_int: " << s_int.val << "\n";
    cout << "s_char: " << s_char.val << "\n";
    cout << "s_dbl: " << s_dbl.val << "\n";
    cout << "s_strg: " << s_strg.val << "\n";
    for (int i = 0; i<s_v_int.val.size(); ++i)
           cout << "s_v_int[" << i << "]: " << s_v_int.val[i] << "\n";


    cout << "s_int: " << s_int.get() << "\n";
    cout << "s_char: " << s_char.get() << "\n";
    cout << "s_dbl: " << s_dbl.get() << "\n";
    cout << "s_strg: " << s_strg.get() << "\n";
    for (int i = 0; i<s_v_int.get().size(); ++i)
        cout << "s_v_int[" << i << "]: " << s_v_int.get()[i] << "\n";
    cout << s_v_int.get() << "\n";int main(){

  int x = 17;
  int* pi = &x;

  double e = 2.71828;
  double* pd = &e;

  cout << "pi==" << pi << "; contetnts of pi==" << *pi << "\n";
  cout << "pd==" << pd << "; contetnts of pd==" << *pd << "\n";


  vector<int> v(1000);
  cout << "Meret: " << sizeof(v);

  double* p = new double[4];
  double x = *p;
  double y = p[2];

  *p = 7.7;
  p[2]= 10.5;
}

    s_int.set(55);
    s_char.set('y');
    s_dbl.set(4.14);
    s_strg.set("String2");
    vi[1] = 22;
    s_v_int.set(vi);
    cout << "\ns_int: " << s_int.get() << "\n";
    cout << "s_char: " << s_char.get() << "\n";
    cout << "s_dbl: " << s_dbl.get() << "\n";
    cout << "s_strg: " << s_strg.get() << "\n";
    for (int i = 0; i<s_v_int.get().size(); ++i)
        cout << "s_v_int[" << i << "]: " << s_v_int.get()[i] << "\n";
    cout << s_v_int.get() << "\n";

    s_int = 66;
    s_char = 'z';
    s_dbl = 5.14;
    s_strg = "String3";
    vi[1] = 33;
    s_v_int = vi;
    cout << "\ns_int: " << s_int.get() << "\n";
    cout << "s_char: " << s_char.get() << "\n";
    cout << "s_dbl: " << s_dbl.get() << "\n";
    cout << "s_strg: " << s_strg.get() << "\n";
    for (int i = 0; i<s_v_int.get().size(); ++i)
        cout << "s_v_int[" << i << "]: " << s_v_int.get()[i] << "\n";
    cout << s_v_int.get() << "\n";

    const S<int> c_s_int(5);
    cout << "\nc_s_int: " << c_s_int.get() << "\n"; // requires const getter

    cout << "\ns_int: ";
    read_val(s_int);
    cout << "s_char: ";
    read_val(s_char);
    cout << "s_dbl: ";
    read_val(s_dbl);
    cout << "s_strg: ";
    read_val(s_strg);
    cout << "\ns_int: " << s_int.get() << "\n";
    cout << "s_char: " << s_char.get() << "\n";
    cout << "s_dbl: " << s_dbl.get() << "\n";
    cout << "s_strg: " << s_strg.get() << "\n\n";

    cout << "\ns_v_int: ";
    read_val(s_v_int);
    cout << "\ns_v_int: " << s_v_int.get() << "\n";

}
catch (exception& e) {
    cerr << "Exception: " << e.what() << "\n";
}
catch (...) {
    cerr << "Exception\n";
}
