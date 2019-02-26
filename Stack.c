#include<iostream>

#include<exception>

#include<stdlib.h>

using namespace std;

class MyClass

{

	public:

	int stack[100], top, max, i;

	void Push(int key)

	{

		try

		{

			if(top==(max-1))

			throw 1;

			stack[++top] = key;

		}

		catch(int)

		{

			if((2*max)<=100)

			{

				cout<<"Overflow\n";

				max *= 2;

				Push(key);

			}

		}

	}

	void Pop()

	{

		try

		{

			if(top == -1)

			throw 2;

			top--;

		}

		catch(int)

		{

			cout<<"Underflow\n";

		}

	}

	void Print()

	{

		try

		{

			if(top == -1)

			throw 3;

			for(i=0; i<=top; i++)

			cout<<stack[i]<<"\t";

			cout<<endl;

		}

		catch(int)

		{

			cout<<"No element in stack\n";

		}

	}

};

main()

{

	MyClass ob;

	cout<<"\nSize : ";

	cin>>ob.max;

	ob.top=-1;

	int n, a;

	for(;;)

	{

		cout<<"\n1. Push\n2. Pop\n3. Print\n4. Exit\n";

		cin>>n;

		switch(n)

		{

			case 1:

			cout<<"Element :";

			cin>>a;

			ob.Push(a);

			break;

			case 2:

			ob.Pop();

			break;

			case 3:

			ob.Print();

			break;

			case 4:

			exit(0);

		}

	}

}



