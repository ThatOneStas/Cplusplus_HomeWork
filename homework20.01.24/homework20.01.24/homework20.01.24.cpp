#include <iostream>
using namespace std;

#define COMPARE(num1,num2) \
if(num1 > num2){ \
    cout << num1 << endl; \
} \
else if(num2 > num1){ \
    cout << num2 << endl; \
} \
else { \
    cout << num1 << " = " << num2 << endl; \
} \

#define SQUARE(num) cout << num*num << endl;

#define EXPONENTIATION(num, degree) \
int result = num; \
for(int i = 1; i < degree; i++) \
{ \
    result = result*num; \
} \
cout << result << endl; \

#define CHECKPARITY(num) \
if(num % 2 == 0){ \
    cout << "even number" << endl; \
} \
else { \
    cout << "not even number" << endl; \
} \


int main()
{
    COMPARE(12, 12);
    SQUARE(5);
    EXPONENTIATION(2, 4);
    CHECKPARITY(3)
}
