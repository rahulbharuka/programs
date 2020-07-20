#include <stdlib.h>
#include <stdio.h>

class C {
	public:
		void func() {
			printf("func called\n");
		}

		virtual void virtualFunc() {
			printf("virtual func called\n");
		}
};

int main (int argc, char ** argv) {
	C * obj = NULL;
	/* What does the following print? */
	obj->func();
	/* What does the following print? */
	obj->virtualFunc();
	/* What's the difference? */
}

