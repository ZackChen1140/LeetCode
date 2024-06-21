class Solution {
public:
    int gcd(int a, int b)
    {
        while (b != 0)
        {
            int tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }
    string gcdOfStrings(string str1, string str2) {
        string bstr = str1.length() > str2.length() ? str1 : str2, sstr = str1.length() > str2.length() ? str2 : str1;
        int gcdn = gcd(bstr.size(), sstr.size());
        string cstr = sstr.substr(0, gcdn);
        for (int i = 0; i < bstr.length(); i += gcdn)
            if (bstr.substr(i, gcdn) != cstr || sstr.substr(i % sstr.length(), gcdn) != cstr)
                return "";
        return cstr;
    }
};