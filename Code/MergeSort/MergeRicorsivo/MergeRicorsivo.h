#ifndef MERGERICORSIVO_H
#define MERGERICORSIVO_H

template <typename T>
class MergeRicorsivo
{
    private:
    static void merge(T*, T*, int, T*, int);

    public:
    static void mergeSort(T [], int, int);
};

template <typename T>
void MergeRicorsivo<T> :: merge(T* c, T*a, int n, T*b, int m)
{
    if(n > 0 && m > 0)
    {
        if(a[0] < b[0])
        {
            c[0] = a[0];
            merge(c+1, a+1, n-1, b, m);
        }
        else
        {
            c[0] = b[0];
            merge(c+1, a, n, b+1, m-1);
        }
    }
    else if(n>0)
    {
        c[0] = a[0];
        merge(c+1, a+1, n-1, b, m);
    }
    else if(m > 0)
    {
        c[0] = b[0];
        merge(c+1, a, n, b+1, m-1);
    }
}

template <typename T>
void MergeRicorsivo<T> ::mergeSort(T a[], int left, int right)
{
    if(left < right)
    {
        int center = (left+right)/2;

        mergeSort(a, left, center);
        mergeSort(a, center+1, right);

        int totElemSx = center-left+1;
        int totElemDx = right-center;
        int dimOut = right-left+1;

        T *out = new T[dimOut];

        merge(out, a+left, totElemSx, a+(center+1), totElemDx);

        for(int i=0; i < right-left+1; i++)
        {
            a[left+i]= out[i];
        }
        delete []out;
    }
}

#endif //MERGERICORSIVO_H