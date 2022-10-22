//#include "multidimensional_arrays.h"
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	int j = 0x21;
//	size_t n1 = CreateArrayAtMemory(nullptr, 2);
//	vector<char> a1(n1);
//	char* f1 = (char*)a1.data();
//	CreateArrayAtMemory(f1, 2);
//	for (int i1 = 0; i1 < 2; i1++)
//	{
//		f1[i1] = j++;
//	}
//	for (int i1 = 0; i1 < 2; i1++)
//	{
//		std::cout << (int)f1[i1] << " ";
//	}
//	std::cout << std::endl << n1 << " bytes used " << std::endl;
//
//    system("pause");
//    cout << "\n";
//
//
//    //int j = 0x21;
//    size_t n2 = CreateArrayAtMemory<short>(nullptr, 2, 3);
//    vector<char> a2(n2);
//    short** f2 = (short**)a2.data();
//    CreateArrayAtMemory(f2, 2, 3);
//    for (int i1 = 0; i1 < 2; i1++)
//    {
//        for (int i2 = 0; i2 < 3; i2++)
//        {
//            f2[i1][i2] = j++;
//        }
//    }
//    // Dump
//    for (int i1 = 0; i1 < 2; i1++)
//    {
//        for (int i2 = 0; i2 < 3; i2++)
//        {
//            std::cout << (int)f2[i1][i2] << " ";
//        }
//    }
//    std::cout << std::endl << n2 << " bytes used " << std::endl;
//    std::cout << std::endl;
//    system("pause");
//    cout << "\n";
//
//    ////int j = 0x21;
//    //size_t n5 = CreateArrayAtMemory<int>(a5, 2, 3, 4, 5, 6);
//    //vector<char> a5(n5);
//    //int***** f5 = (int*****)a5.data();
//    //CreateArrayAtMemory(f5, 2, 3, 4, 5, 6);
//    //for (int i1 = 0; i1 < 2; i1++)
//    //{
//    //    for (int i2 = 0; i2 < 3; i2++)
//    //    {
//    //        for (int i3 = 0; i3 < 4; i3++)
//    //        {
//    //            for (int i4 = 0; i4 < 5; i4++)
//    //            {
//    //                for (int i5 = 0; i5 < 6; i5++)
//    //                {
//    //                    f5[i1][i2][i3][i4][i5] = j++;
//    //                }
//    //            }
//    //        }
//    //    }
//    //}
//
//    //// Dump
//    //for (int i1 = 0; i1 < 2; i1++)
//    //{
//    //    for (int i2 = 0; i2 < 3; i2++)
//    //    {
//    //        for (int i3 = 0; i3 < 4; i3++)
//    //        {
//    //            for (int i4 = 0; i4 < 5; i4++)
//    //            {
//    //                for (int i5 = 0; i5 < 6; i5++)
//    //                {
//    //                    std::cout << (int)f5[i1][i2][i3][i4][i5] << " ";
//    //                }
//    //            }
//    //        }
//    //    }
//    //}
//    //std::cout << std::endl << n5 << " bytes used " << std::endl;
//    //std::cout << std::endl;
//
//
//	system("pause");
//	return 0;
//}