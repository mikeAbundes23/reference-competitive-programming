
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/**
 * Algoritmo radix sort que ordena pares, o bien, digitos en numeros, usa counting sort como algoritmo
 * auxiliar.
 */
void radix_sort(vector<pair<pair<int, int>, int>> &a)
{
    int n = a.size();
    {
        vector<int> cnt(n);

        for (auto b : a)
        {
            cnt[b.first.second]++;
        }

        vector<int> pos(n);

        vector<pair<pair<int, int>, int>> a_new(n);

        pos[0] = 0;

        for (int i = 1; i < n; i++)
        {
            pos[i] = pos[i - 1] + cnt[i - 1];
        }

        for (auto &x : a)
        {
            int i = x.first.second;
            a_new[pos[i]] = x;
            pos[i]++;
        }

        a = a_new;
    }

    {
        vector<int> cnt(n);

        for (auto b : a)
        {
            cnt[b.first.first]++;
        }

        vector<int> pos(n);

        vector<pair<pair<int, int>, int>> a_new(n);

        pos[0] = 0;

        for (int i = 1; i < n; i++)
        {
            pos[i] = pos[i - 1] + cnt[i - 1];
        }

        for (auto &x : a)
        {
            int i = x.first.first;
            a_new[pos[i]] = x;
            pos[i]++;
        }

        a = a_new;
    }
}

/**
 * Algoritmo Suffix array que sirve para patern matching, se construye en O(nlogn)
 * con ayuda del algoritmo radix sort (que ordena linealmente en pares)
 */
void suffixArray()
{
    string s;
    cin >> s;
    // delimitador, debe ser un char menor a cualquier letra del alfabeto,
    // para asi hacerla ciclica la string.
    s += "$";
    int n = s.size();

    // c = vector de clases de equivalencia
    // p = suffix array (ya ordenado) con el valor del primer indice del sufijo.
    vector<int> c(n), p(n);
    // para k = 0 (strings de tam 1 ya que 2^0 es 1).
    vector<pair<char, int>> a(n);

    for (int i = 0; i < n; i++)
    {
        a[i] = {s[i], i};
    }

    // se ordena las cadenas de tam 1de los sufijos.
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
    {
        p[i] = a[i].second;
    }

    // se crean las clases de la equivalencia entre los sufijos de tam 1 (dos cadenas estan en la  misma clase
    // si son iguales)
    c[p[0]] = 0;

    for (int i = 1; i < n; i++)
    {
        if (a[i].first == a[i - 1].first)
        {
            c[p[i]] = c[p[i - 1]];
        }
        else
        {
            c[p[i]] = c[p[i - 1]] + 1;
        }
    }

    // ahora se itera sobre k hasta que 2^k > n.
    int k = 0;
    while ((1 << k) < n)
    {
        // transis. k -> k+1

        // el vec. a va a ser un vector de par de pares donde el par mas interno es la clase de equivalencia
        // del iesimo caracter y el i+(1<<k)%n es el siguiente caracter de tal manera que se cicle la string,
        // el ssegundo par mas externo es el indice del string, para asi crear el arreglo p.
        vector<pair<pair<int, int>, int>> a(n);
        for (int i = 0; i < n; i++)
        {
            a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
        }

        // paso que permite que la complejdiad sea O(nlogn), ya que sorte los pares de a en tiempo O(n).
        radix_sort(a);
        for (int i = 0; i < n; i++)
        {
            p[i] = a[i].second;
        }

        c[p[0]] = 0;

        // mismo paso de comparacion de "cadenas" pero ahora se compara las clases de equivalencia ya computadas,
        // no las cadenas perse
        for (int i = 1; i < n; i++)
        {
            if (a[i].first == a[i - 1].first)
            {
                c[p[i]] = c[p[i - 1]];
            }
            else
            {
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
        k++;
    }

    // suffix array con los sufijos de un string s ya ordenados lexicograficamente.
    for (int i = 0; i < n - 1; i++)
    {
        cout << p[i] << " ";
    }

    cout << p[n - 1] << "\n";
}

int main()
{
    suffixArray();

    return 0;
}