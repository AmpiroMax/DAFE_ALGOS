//#include <iostream>
//#include <vector>

// using namespace std;

// class DumbWaysToDie
//{
//  private:
//    vector<vector<size_t>> data;
//    size_t N;

//  public:
//    DumbWaysToDie(int _N) : N(_N + 1)
//    {
//        // cout << "There" << endl;
//        data = vector<vector<size_t>>(N, vector<size_t>(N, 0));

//        for (size_t i = 0; i < N; ++i)
//        {
//            data[i][0] = 1;
//            data[i][1] = 1;
//        }
//        // data[0][1] = 0;
//        // cout << "Gonne, will be back soon" << endl;
//    }

//    size_t counter()
//    {
//        // cout << "HERE" << endl;
//        for (int i = 1; i < N; ++i)
//            for (int j = 2; j < N; ++j)
//            {
//                if (j - i < 0)
//                {
//                    data[i][j] = data[i - 1][j];
//                }
//                else
//                {
//                    data[i][j] = data[i - 1][j] + data[i][j - i];
//                }
//            }

//        return data[N - 1][N - 1];
//    }
//    void answer() { cout << data[N - 1][N - 1]; }
//};

// int main()
//{
//    int n;
//    while (cin >> n)
//    {
//        DumbWaysToDie triangles(n);
//        triangles.counter();
//        triangles.answer();
//        cout << endl;
//    }
//    return 0;
//}

#include <iostream>
#include <vector>

using namespace std;

class DumbWaysToDie
{
  private:
    vector<vector<size_t>> data;
    size_t N;

  public:
    DumbWaysToDie(int _N) : N(_N + 1)
    {
        // cout << "There" << endl;
        data = vector<vector<size_t>>(N, vector<size_t>(N, 0));

        for (size_t i = 1; i < N; ++i)
        {
            data[0][i] = 1;
            data[1][i] = 1;
        }
        // data[0][1] = 0;
        // cout << "Gonne, will be back soon" << endl;
    }

    size_t counter()
    {
        // cout << "HERE" << endl;
        for (size_t i = 2; i < N; ++i)
        {

            for (size_t j = 2; j <= i; ++j)
            {

                data[i][j] = data[i - j][j - 1] + data[i][j - 1];
            }
            for (size_t j = i + 1; j < N; ++j)

                data[i][j] = data[i][j - 1];
        }

        return data[N - 1][N - 1];
    }
    void answer() { cout << data[N - 1][N - 1]; }
};

int main()
{
    size_t n;
    cin >> n;
    DumbWaysToDie pyramidki(n);

    cout << pyramidki.counter();
}
