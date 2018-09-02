#include <stdio.h>
#include <string.h>
#include <sstream>
#include <time.h>
#include <set>
#include <iostream>

using namespace std;

int x = 0;
int vetorzin[128];
int tamanho;
int i;
int resposta[2001];
char dicionario[2001][101];
char teste[101];
set<string> palavra;

void calcular(int idx, int i)
{

    int j;

    if (tamanho == 0)
    {

        printf("%s =", teste);

        for (i = 0; i < idx; i++)
        {

            printf(" %s", dicionario[resposta[i]]);

        } //end for

        puts("");

        return;

    } //fim if

    for (; i < x; i++)
    {

        if (palavra.find(dicionario[i]) != palavra.end())
            continue;

        int flag = 0;

        for (j = 0; dicionario[i][j]; j++)
        {

            vetorzin[dicionario[i][j]]--;
            tamanho--;

            if (vetorzin[dicionario[i][j]] < 0)
            {

                while (j >= 0)
                {

                    vetorzin[dicionario[i][j]]++;
                    tamanho++;
                    j--;

                } //fim while

                flag = 1;
                break;

            } //fim fim

        } //fim for

        if (!flag)
        {

            resposta[idx] = i;
            calcular(idx + 1, i + 1);

            for (j = 0; dicionario[i][j]; j++)
            {

                vetorzin[dicionario[i][j]]++;
                tamanho++;

            } //fim for

        } //fim if

    } // fimfor

} //fim calcular

int main()
{

    string in;
    time_t begin, end;

    time(&begin);

    while (cin.getline(dicionario[x], sizeof(dicionario)))
    {

        if (dicionario[x][0] == '#')
            break;

        x++;

    } //fim while

    while (cin.getline(teste, sizeof(teste)))
    {

        if (!strcmp(teste, "#"))
            break;

        stringstream sin;
        sin << teste;
        //string in;
        palavra.clear();

        while (sin >> in)
        {

            palavra.insert(in);

        } //fim while

        memset(vetorzin, 0, sizeof(vetorzin));

        tamanho = 0;

        for (i = 0; teste[i]; i++)
        {

            if (teste[i] == ' ')
            {

                continue;

            } //fim if

            vetorzin[teste[i]]++;
            tamanho++;

        } //fim for

        calcular(0, 0);

    } //fim while

    time(&end);

    return 0;

} //fim main
