#include <iostream>
using namespace std;
int main()
{
    cout << "Primul laborator OOP";
    return 0;
}
//PROBLEMA 1

//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cstring>
//using namespace std;
//int main()
//{
//	FILE* fin = fopen("in.txt", "r");
//
//	if (fin == NULL)
//	{
//		printf("Eroare la deschiderea fisierului.");
//		exit(1);
//	}
//
//	int sum = 0;
//	char c[50];
//	for (int i = 0;i < 4;i++)
//	{
//		fgets(c, 50, fin);
//		int x=0;
//		for (int j = 0;j < strlen(c); j++)
//		{	
//			if(c[j]>='0' && c[j]<='9')
//			x = x * 10 + c[j] - '0';
//		}
//		sum += x;
//	}
//
//	printf("%d", sum);
//	fclose(fin);
//	return 0;
//}


//PROBLEMA 2

//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cstring>
//using namespace std;
//int main()
//{	
//	printf("Introduceti o propozitie:");
//	char s[100],*cuvinte[100],*p;
//	fgets(s, sizeof(s), stdin);
//	s[strlen(s) - 1] = NULL;
//	int n = 0;
//	
//	p = strtok(s, " ");
//	while (p)
//	{
//		cuvinte[n++] = p;
//		p = strtok(NULL, " ");
//
//	}
//
//	for(int i=0;i<n-1;i++)
//		for(int j=i+1;j<n;j++)
//			if (strlen(cuvinte[i]) < strlen(cuvinte[j]) || (strlen(cuvinte[i]) == strlen(cuvinte[j]) && strcmp(cuvinte[i], cuvinte[j]) > 0))
//			{
//				char* aux = cuvinte[i];
//				cuvinte[i] = cuvinte[j];
//				cuvinte[j] = aux;
//			}
//
//	for (int i = 0;i < n;i++)
//		printf("%s\n", cuvinte[i]);
//	return 0;
//}




//PROBLEMA 3

//#include <iostream>
//using namespace std;
//
//bool isPrime(int n)
//{
//    for (int tr = 2; tr < n / 2; tr++)
//        if ((n % tr) == 0)
//            return false;
//    return true;
//}
//int main()
//{
//    int n;
//    cout << "Enter a number:";
//    cin >>n;
//    if (isPrime(n))
//        cout << n << " is prime !";
//    else
//        cout << n << " is NOT prime !";
//    return 0;

