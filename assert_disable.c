// The below program runs fine because NDEBUG is defined
# define NDEBUG
# include <assert.h>

int main()
{
	int x = 7;
	assert (x==5);
	return 0;
}
