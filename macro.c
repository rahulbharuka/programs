#include <stdio.h>

//#define __TN(type, name, comment) "part_"#name"_rahul_"#type
//#define __TNC(type, name, comment) type part_##name##_cn

#define __PVALFUNC(func) 0, func
#define __TN(type, name, func) int arr[] = {sizeof(type), func}

//#define nslist_partition_stats \
//__TN(u32bits, part_bw, __PVALFUNC(ns_get_BW))

int main()
{
	//__TNC(int, val, for_test) = 2504;
	//printf("%s\n", __TN(int, temp, for_test));
	//printf("%d\n", part_val_cn);
	__TN(int, "rahul", __PVALFUNC(sizeof(char)));
	printf("%d %d %d\n", arr[0], arr[1], arr[2]);
	
}

