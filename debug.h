// debug.h  -  universal competitive-programming debugger (C++17 or newer)
//
// Usage in your solution file:
//
//     #include <bits/stdc++.h>
//     using namespace std;
//     #ifdef LOCAL
//     #include "debug.h"
//     #else
//     #define dbg(...)
//     #define dbg_arr(...)
//     #define dbg_range(...)
//     #define dbg_grid(...)
//     #define dbg_time(...)
//     #endif
//
// Compile locally with:  g++ -std=c++17 -DLOCAL sol.cpp
// Do NOT write "#define LOCAL" in the code, then submitting is always safe.
//
// Macros:
//     dbg(a, b, c...)      print any number of variables/expressions with names
//     dbg_arr(arr, n)      print first n elements of a C array / pointer
//     dbg_range(l, r)      print elements of iterator range [l, r)
//     dbg_grid(v)          print a 2D container, one row per line
//     dbg_time()           print elapsed time in ms since program start
//
// Supported: bool, char, all ints (+ __int128), floats, enums, strings, C strings,
// pointers, nullptr, pair, tuple, array, vector (incl. vector<bool>), deque, list,
// forward_list, set, multiset, map, multimap, unordered_*, stack, queue,
// priority_queue, bitset, optional, variant, unique_ptr, shared_ptr, valarray,
// complex, C arrays (1D/2D/...), any nested combination of the above,
// and any user type that has operator<< or begin()/end().

#ifndef DEBUG_H
#define DEBUG_H
#define NO_COLOR

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL

namespace dbg_impl {

// ---------------------------------------------------------------- colors
#ifndef NO_COLOR
inline constexpr const char* C_LINE = "\033[1;33m";
inline constexpr const char* C_NAME = "\033[1;32m";
inline constexpr const char* C_END = "\033[0m";
#else
inline constexpr const char* C_LINE = "";
inline constexpr const char* C_NAME = "";
inline constexpr const char* C_END = "";
#endif

// ---------------------------------------------------------------- traits
template <class T>
struct d_is_pair : false_type {};
template <class A, class B>
struct d_is_pair<pair<A, B>> : true_type {};

template <class T>
struct d_is_tuple : false_type {};
template <class... A>
struct d_is_tuple<tuple<A...>> : true_type {};

template <class T>
struct d_is_optional : false_type {};
template <class A>
struct d_is_optional<optional<A>> : true_type {};

template <class T>
struct d_is_variant : false_type {};
template <class... A>
struct d_is_variant<variant<A...>> : true_type {};

template <class T>
struct d_is_stack : false_type {};
template <class A, class C>
struct d_is_stack<stack<A, C>> : true_type {};

template <class T>
struct d_is_queue : false_type {};
template <class A, class C>
struct d_is_queue<queue<A, C>> : true_type {};

template <class T>
struct d_is_pq : false_type {};
template <class A, class C, class P>
struct d_is_pq<priority_queue<A, C, P>> : true_type {};

template <class T>
struct d_is_bitset : false_type {};
template <size_t N>
struct d_is_bitset<bitset<N>> : true_type {};

template <class T>
struct d_is_unique_ptr : false_type {};
template <class A, class D>
struct d_is_unique_ptr<unique_ptr<A, D>> : true_type {};

template <class T>
struct d_is_shared_ptr : false_type {};
template <class A>
struct d_is_shared_ptr<shared_ptr<A>> : true_type {};

template <class T, class = void>
struct d_is_iterable : false_type {};
template <class T>
struct d_is_iterable<T, void_t<decltype(std::begin(declval<const T&>())),
                               decltype(std::end(declval<const T&>()))>> : true_type {};

template <class T, class = void>
struct d_is_streamable : false_type {};
template <class T>
struct d_is_streamable<T, void_t<decltype(declval<ostream&>() << declval<const T&>())>>
    : true_type {};

// ---------------------------------------------------------------- helpers
inline void print_u128(unsigned __int128 u, bool neg) {
    if (u == 0) {
        cerr << '0';
        return;
    }
    string s;
    while (u) {
        s += char('0' + (int)(u % 10));
        u /= 10;
    }
    if (neg) s += '-';
    reverse(s.begin(), s.end());
    cerr << s;
}

// copy an adapter into a vector (stack: bottom->top, queue: front->back, pq: top->...)
template <class S>
auto d_drain(S s) {
    vector<typename S::value_type> v;
    if constexpr (d_is_stack<S>::value) {
        while (!s.empty()) {
            v.push_back(s.top());
            s.pop();
        }
        reverse(v.begin(), v.end());
    } else if constexpr (d_is_queue<S>::value) {
        while (!s.empty()) {
            v.push_back(s.front());
            s.pop();
        }
    } else {
        while (!s.empty()) {
            v.push_back(s.top());
            s.pop();
        }
    }
    return v;
}

// ---------------------------------------------------------------- core printer
template <class T>
void dbg_print(const T& x) {
    if constexpr (is_same_v<T, bool>) {
        cerr << (x ? "true" : "false");
    } else if constexpr (is_same_v<T, char>) {
        cerr << '\'' << x << '\'';
    } else if constexpr (is_same_v<T, signed char> || is_same_v<T, unsigned char>) {
        cerr << (int)x;
    } else if constexpr (is_same_v<T, __int128>) {
        print_u128(x < 0 ? -(unsigned __int128)x : (unsigned __int128)x, x < 0);
    } else if constexpr (is_same_v<T, unsigned __int128>) {
        print_u128(x, false);
    } else if constexpr (is_null_pointer_v<T>) {
        cerr << "nullptr";
    } else if constexpr (is_convertible_v<const T&, string_view> &&
                         !is_pointer_v<decay_t<T>>) {
        cerr << '"' << string_view(x) << '"';
    } else if constexpr (is_pointer_v<decay_t<T>> &&
                         is_convertible_v<const T&, const char*>) {
        const char* p = x;
        if (!p) cerr << "nullptr";
        else cerr << '"' << p << '"';
    } else if constexpr (is_integral_v<T> || is_floating_point_v<T>) {
        cerr << x;
    } else if constexpr (is_enum_v<T>) {
        cerr << +static_cast<underlying_type_t<T>>(x);
    } else if constexpr (is_pointer_v<T>) {
        if (!x) cerr << "nullptr";
        else cerr << (const void*)x;
    } else if constexpr (d_is_pair<T>::value) {
        cerr << '{';
        dbg_print(x.first);
        cerr << ", ";
        dbg_print(x.second);
        cerr << '}';
    } else if constexpr (d_is_tuple<T>::value) {
        cerr << '<';
        size_t i = 0;
        apply([&](const auto&... a) { ((cerr << (i++ ? ", " : ""), dbg_print(a)), ...); }, x);
        cerr << '>';
    } else if constexpr (d_is_optional<T>::value) {
        if (x.has_value()) {
            cerr << "some(";
            dbg_print(*x);
            cerr << ')';
        } else cerr << "nullopt";
    } else if constexpr (d_is_variant<T>::value) {
        if (x.valueless_by_exception()) cerr << "valueless";
        else visit([](const auto& v) { dbg_print(v); }, x);
    } else if constexpr (is_same_v<T, monostate>) {
        cerr << "monostate";
    } else if constexpr (d_is_unique_ptr<T>::value || d_is_shared_ptr<T>::value) {
        if (!x) cerr << "nullptr";
        else {
            cerr << "ptr(";
            dbg_print(*x);
            cerr << ')';
        }
    } else if constexpr (d_is_bitset<T>::value) {
        cerr << x.to_string();
    } else if constexpr (d_is_stack<T>::value || d_is_queue<T>::value || d_is_pq<T>::value) {
        dbg_print(d_drain(x));
    } else if constexpr (d_is_streamable<T>::value) {
        cerr << x;
    } else if constexpr (d_is_iterable<T>::value) {
        size_t f = 0;
        cerr << '{';
        for (const auto& e : x) {
            cerr << (f++ ? ", " : "");
            dbg_print(e);
        }
        cerr << '}';
    } else {
        cerr << "<unprintable:" << typeid(T).name() << '>';
    }
}

// ---------------------------------------------------------------- name splitting
inline string d_trim(const string& s) {
    size_t l = 0, r = s.size();
    while (l < r && isspace((unsigned char)s[l])) l++;
    while (r > l && isspace((unsigned char)s[r - 1])) r--;
    return s.substr(l, r - l);
}

// split "a, f(x, y), v[i]" on top-level commas
inline vector<string> d_split_names(const string& s) {
    vector<string> res;
    string cur;
    int depth = 0;
    bool inq = false;
    char qc = 0;
    for (size_t i = 0; i < s.size(); i++) {
        char c = s[i];
        if (inq) {
            cur += c;
            if (c == '\\' && i + 1 < s.size()) cur += s[++i];
            else if (c == qc) inq = false;
            continue;
        }
        if (c == '"' || c == '\'') {
            inq = true;
            qc = c;
            cur += c;
            continue;
        }
        if (c == '(' || c == '[' || c == '{') depth++;
        else if (c == ')' || c == ']' || c == '}') depth--;
        if (c == ',' && depth == 0) {
            res.push_back(d_trim(cur));
            cur.clear();
        } else cur += c;
    }
    res.push_back(d_trim(cur));
    return res;
}

inline void d_header(int line) { cerr << C_LINE << "[L" << line << "] " << C_END; }

// ---------------------------------------------------------------- entry points
template <class... A>
void dbg_run(int line, const char* names, const A&... args) {
    vector<string> nm = d_split_names(names);
    d_header(line);
    size_t i = 0;
    ((cerr << (i ? " | " : "") << C_NAME << (i < nm.size() ? nm[i] : string("?")) << C_END
           << " = ",
      dbg_print(args), ++i),
     ...);
    cerr << '\n';
}

template <class T>
void dbg_run_arr(int line, const char* name, const T* p, size_t n) {
    d_header(line);
    cerr << C_NAME << name << C_END << " = {";
    for (size_t i = 0; i < n; i++) {
        cerr << (i ? ", " : "");
        dbg_print(p[i]);
    }
    cerr << "}\n";
}

template <class It>
void dbg_run_range(int line, const char* name, It l, It r) {
    d_header(line);
    cerr << C_NAME << name << C_END << " = {";
    bool first = true;
    for (; l != r; ++l) {
        cerr << (first ? "" : ", ");
        first = false;
        dbg_print(*l);
    }
    cerr << "}\n";
}

template <class T>
void dbg_run_grid(int line, const char* name, const T& g) {
    d_header(line);
    cerr << C_NAME << name << C_END << " =\n";
    for (const auto& row : g) {
        cerr << "  ";
        dbg_print(row);
        cerr << '\n';
    }
}

inline const auto d_start_time = chrono::steady_clock::now();

inline void dbg_run_time(int line) {
    double ms = chrono::duration<double, milli>(chrono::steady_clock::now() - d_start_time).count();
    d_header(line);
    cerr << "time = " << ms << " ms\n";
}

}  // namespace dbg_impl

#define dbg(...) dbg_impl::dbg_run(__LINE__, #__VA_ARGS__, ##__VA_ARGS__)
#define dbg_arr(a, n) dbg_impl::dbg_run_arr(__LINE__, #a, (a), (size_t)(n))
#define dbg_range(l, r) dbg_impl::dbg_run_range(__LINE__, #l ".." #r, (l), (r))
#define dbg_grid(g) dbg_impl::dbg_run_grid(__LINE__, #g, (g))
#define dbg_time() dbg_impl::dbg_run_time(__LINE__)

#else  // not LOCAL: everything compiles to nothing

#define dbg(...)
#define dbg_arr(...)
#define dbg_range(...)
#define dbg_grid(...)
#define dbg_time(...)

#endif  // LOCAL

#endif  // DEBUG_H