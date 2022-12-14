/*
Implemented by Mohamed Ahmed and Ammar Yasser
we are students in Faculty of Computers and Artificial Intelligence - Cairo University
*/

#include <iostream>
#include <sstream>
#include <bitset>
#include <string>
#include <cmath>
#include<cstdlib>
#define ll long long
using namespace std;


ll cipher[1000];
ll pprime[1000];
ll qprime[1000];
ll dA[1000];
ll eA[1000];

string DecimalToBinary(int dec)
{
    if (dec < 1) return "0";

    string binStr = "";

    while (dec > 0)
    {
        binStr = binStr.insert(0, string(1, (char)((dec % 2) + 48)));

        dec /= 2;
    }

    return binStr;
}
string ASCIIToBinary(string str)
{
    string bin = "";
    int strLength = str.length();

    for (int i = 0; i < strLength; ++i)
    {
        string cBin = DecimalToBinary(str[i]);
        int cBinLength = cBin.length();

        if (cBinLength < 8)
        {
            for (size_t i = 0; i < (8 - cBinLength); i++)
                cBin = cBin.insert(0, "0");
        }

        bin += cBin;
    }
    return bin;
}
string BinaryToASCII(string binaryString)
{
    string text = "";
    stringstream sstream(binaryString);
    while (sstream.good())
    {
        bitset<8> bits;
        sstream >> bits;
        text += char(bits.to_ulong());
    }
    return text;
}
int BinaryToDecimal(string binaryString)
{
    int value = 0;
    int indexCounter = 0;
    for (int i = binaryString.length() - 1; i >= 0; i--)
    {

        if (binaryString[i] == '1')
        {
            value += pow(2, indexCounter);
        }
        indexCounter++;
    }
    return value;
}



ll SquareAndMultiply(ll base, ll exponent, ll modulas)
{
    string H = DecimalToBinary(exponent);
    ll x = base;
    for (int i = 1; i < H.length(); i++)
    {
        x = x*x % modulas;
        if (H[i] == '1')
             x = x*base % modulas;   
    }
    return x;
}

bool fermatTest(ll pnumber, int s)// s is a parameter that determines the number of times to test for primality
{

    if (pnumber != 1)
    {
        for (int i = 1; i < s; i++)
        {
            ll randomNum = 2 + rand() % (pnumber - 2);// random number between 2 and prime number - 2
            if (SquareAndMultiply(randomNum, pnumber - 1, pnumber) != 1)
            {
                return false;
            }
        }
    }
    return true;
}

int gcd(int a, int b)
{
    int R;
    while ((a % b) > 0)
    {
        R = a % b;
        a = b;
        b = R;
    }
    return b;
}

ll EEA(ll r0, ll r1)
{

    ll t[100], s[100], r[100], q[100];
    int  i = 1;
    t[0] = 0;
    t[1] = 1;
    s[0] = 1;
    s[1] = 0;
    r[0] = r0;
    r[1] = r1;
    ll tump;
    while (true)
    {
        i++;
        r[i] = r[i - 2] % r[i - 1];
        q[i - 1] = (r[i - 2] - r[i]) / r[i - 1];
        s[i] = s[i - 2] - (q[i - 1] * s[i - 1]);
        t[i] = t[i - 2] - (q[i - 1] * t[i - 1]);
        if (r[i] == 0)
            break;
    }
    tump = t[i - 1];
    ll counter = 0;
    if (tump < 0)
    {
        while (true)
        {
            if (tump % r[0] == 0)
            {
                tump = t[i - 1] - tump;
                break;
            }
            tump = tump - 1;
        }
    }
    return tump;
}

void RSAEncryption(string txt)
{
    ll q, p, n, alpha, e, d,yy ,xe;
    string ch ,tump1,ciphertxt="";
    ll tump = 0;
    bool test = false;
    cout<<"\n --------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\tIndex\t|" << "\tChar" <<"\t"<<"|\tp" <<"\t"<<"|\tq" <<"\t" << "|\te"<<"\t"<<"|\td"<<endl;
    cout<<" --------------------------------------------------------------------------------------------------"<<endl;
    for (int l = 0; l < txt.length(); l++)
    {
        ch = txt[l];
        ch = ASCIIToBinary(ch);
        tump = BinaryToDecimal(ch);
        test = false;
        while (test == false)
        {
            q = 1 + rand() % 32767;
            test = fermatTest(q, 100);
        }
        qprime[l] = q;
        test = false;
        while (test == false)
        {
            p = tump + rand();
            test = fermatTest(p, 100);
        }
        pprime[l] = p;

        n = q * p;
        alpha = (q - 1) * (p - 1);
        test = false;
        while (test == false)
        {
            e = 1 + (rand() % alpha - 1);
            if (gcd(e, alpha) == 1)
                test = true;
        }
        eA[l] = e;

        d = EEA(alpha, e);
        dA[l] = d;
        cout<<"\t"<<l+1<<"\t|\t "<< txt[l]<< "\t|\t" <<p << "\t|\t" <<q << "\t|\t"<< e << "\t|\t"<<d <<endl;
        cout<<" --------------------------------------------------------------------------------------------------"<<endl;
        tump1 = txt[l];
        tump1 = ASCIIToBinary(tump1);
        yy = BinaryToDecimal(tump1);
        xe = SquareAndMultiply(yy, e, n);
        cipher[l] = xe;
        ciphertxt += xe;
    }
    cout<< "\nCipher Text : "<< ciphertxt<<endl;
}

void RSADecryption(string txt)
{
    string tump1,plaintxt="";
    ll yp, yq, dp, dq, xp, xq, cp, cq,xe;
    for (int i = 0; i < txt.length(); i++)
    {
        yp = cipher[i] % pprime[i];
        yq = cipher[i] % qprime[i];

        dp = dA[i] % (pprime[i] - 1);
        dq = dA[i] % (qprime[i] - 1);

        xp = SquareAndMultiply(yp, dp, pprime[i]);
        xq = SquareAndMultiply(yq, dq, qprime[i]);

        cp = EEA(pprime[i], qprime[i]);
        cq = EEA(qprime[i], pprime[i]);

        xe = ((qprime[i] * cp) * xp + (pprime[i] * cq) * xq) % (qprime[i] * pprime[i]);

        tump1 = DecimalToBinary(xe);
        tump1 = BinaryToASCII(tump1);
        plaintxt += tump1;
    }
    cout << "\nPlain Text : " << plaintxt <<endl;

}

int main()
{
    string txt;
    cout << "Enter the Message: ";
    getline(cin,txt);
    RSAEncryption(txt);
    RSADecryption(txt);
    return 0;
}
