#include <stdio.h>
#include <execinfo.h>

void foo()
{
	printf("Hi there!\n");
}

void* bar(void *data)
{
	printf("Hello World!\n");
}

typedef void* (*func_name) (void* ptr);		// Note the syntax here. Its not in general format of "typedef existing_type new_type_name" 

int main()
{
	void *p = &foo;
	void *buffer[1] = {p};
	char **strings = backtrace_symbols(buffer, 1);
	printf("%p\n", p);
	printf("%s\n", strings[0]);

	func_name f = &bar;
	printf("%p\n", f);
}
