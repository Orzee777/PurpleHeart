# Coding Notes
##### These notes are useful for some basic dos/don'ts of this project


#### You cannot use namespaces in Unreal classes 
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

#### Use ```FString``` instead of ```string```

## Custom C++ blueprint functions

#### Use ```static```

#### Add ```UFUNCTION(BlueprintCallable, Category = "Trial")``` to all callable functions