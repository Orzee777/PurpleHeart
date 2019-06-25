## Coding Notes

You cannot use namespaces in Unreal classes 
* there are exceptions but just don’t do it

*Instead of*
```cpp
using namespace std;
string variableName = “example text”;
```
*Use*
```cpp
std::string variableName = “example text”;
```

Use FString instead of string
