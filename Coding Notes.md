##Coding Notes

You cannot use namespaces in Unreal classes 
* there are exceptions but just don’t do it
*Instead of*
```C++
	using namespace std;
	string variableName = “example text”;
```
*Use*
```C++
	std::string variableName = “example text”;
```

Use FString instead of string