const int MOD = 1e9 + 7;
const long long MOD2 = static_cast<long long>(MOD) * MOD;

struct Matrix
{
    vector<vector<int>> mat;
    int rows, cols;

    Matrix() {}

    Matrix(vector<vector<int>> values) : mat(values), rows(values.size()), cols(values[0].size()) {}

    static Matrix identity_matrix(int n)
    {
        vector<vector<int>> values(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            values[i][i] = 1;
        return values;
    }

    Matrix operator*(const Matrix &other) const
    {
        int n = rows, m = cols;
        vector<vector<int>> result(rows, vector<int>(cols, 0));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                long long tmp = 0;
                for (int k = 0; k < cols; k++)
                {
                    tmp += mat[i][k] * 1ll * other.mat[k][j];
                    while (tmp >= MOD2)
                        tmp -= MOD2;
                }
                result[i][j] = tmp % MOD;
            }
        return move(Matrix(move(result)));
    }

    inline bool is_square() const
    {
        return rows == cols;
    }
};

Matrix pw(Matrix a, int p)
{
    Matrix result = Matrix::identity_matrix(a.cols);
    while (p > 0)
    {
        if (p & 1)
            result = a * result;
        a = a * a;
        p = p >> 1;
    }
    return result;
}